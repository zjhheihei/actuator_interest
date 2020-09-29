
/*******************************************************************************
*	模块名称 : ADC模块
*	文件名称 : BSP_NTC3380.c
*	版    本 : V1.0
*	说    明 : 1、配置ADC硬件和软件
*                  2、采集采用中断方式
*                  3、采集完成触发事件和发出ADC值 
*	修改记录 :
*		版本号  日期        作者     说明
*		V1.0   2018-08-02  jinzh  正式发布
*	Copyright (C), 2015-2020,   menredGroup    
*******************************************************************************/


#include "intrinsics.h"
#include "ddl.h"
#include <stdbool.h>
#include "stdint.h"

#define ADC_PORT          2
#define ADC_PIN           6
#define SCAN_CHANNLE_1    AdcExInputCH1

static bool       finishFlag = false;
static uint32_t   add_dat  = 0;

static uint16_t average_16times(uint32_t addDat)
{
    uint32_t mainDat = 0;
    uint16_t point = 0;
    mainDat   = addDat; 
    point     = mainDat & 0x000f;
    mainDat >>= 4;
    if(7 < point)
    {
        mainDat += 1;
    }
    return (uint16_t)mainDat;
}

void AdcContIrqCallback(void)
{     
    Adc_GetAccResult(&add_dat);
    Adc_ClrAccResult();
    finishFlag = true;
    // Adc_ClrContIrqState();    
}

void AdcRegIrqCallback(void)
{    
    // 中断标志位判断和清零，已在库函数中处理Adc_IRQHandler();
    
    
    // Adc_ClrRegIrqState();    
}

void AdcHhtIrqCallback(void)
{    
    // 中断标志位判断和清零，已在库函数中处理Adc_IRQHandler();
    
    // Adc_ClrHhtIrqState();
}

void AdcLltIrqCallback(void)
{    
    // 中断标志位判断和清零，已在库函数中处理Adc_IRQHandler();
    
    
    // Adc_ClrLltIrqState();
}

void bsp_ntc_start(void)
{
     Adc_Start();
}

bool bsp_ntc_cfg(void)
{
    stc_adc_cfg_t             stcAdcCfg;
    stc_adc_cont_cfg_t        stcAdcContCfg;
    stc_adc_irq_t             stcAdcIrq;
    stc_adc_irq_calbakfn_pt_t stcAdcIrqCalbaks;
    
    
    DDL_ZERO_STRUCT(stcAdcCfg);
    DDL_ZERO_STRUCT(stcAdcContCfg);
    DDL_ZERO_STRUCT(stcAdcIrq);
    DDL_ZERO_STRUCT(stcAdcIrqCalbaks);   
    Clk_SetPeripheralGate(ClkPeripheralGpio, TRUE);              //GPIO 外设时钟使能
   
    if (Ok != Clk_SetPeripheralGate(ClkPeripheralAdcBgr, TRUE))  //ADCBGR 外设时钟使能
    {
        return false;
    }    

    Gpio_SetAnalog(ADC_PORT, ADC_PIN, TRUE);

    
    //ADC配置
    Adc_Enable();
    M0P_BGR->CR_f.BGR_EN = 0x1u;  //BGR必须使能
    M0P_BGR->CR_f.TS_EN = 0x0u;   //内置温度传感器，视使用需求
    ///delay100us(1);
    volatile uint8_t i = 250;
    while(i--);
    
    stcAdcCfg.enAdcOpMode = AdcContMode;                //连续采样模式
    stcAdcCfg.enAdcClkSel = AdcClkSysTDiv1;             //PCLK
    stcAdcCfg.enAdcSampTimeSel = AdcSampTime8Clk;       //8个采样时钟
    // stcAdcCfg.enAdcRefVolSel = RefVolSelInBgr2p5;    //参考电压:内部2.5V(avdd>3V,SPS<=200kHz)
    stcAdcCfg.enAdcRefVolSel = RefVolSelAVDD;           //参考电压:AVDD
    // stcAdcCfg.bAdcInBufEn = TRUE;
    stcAdcCfg.bAdcInBufEn = FALSE;                      //电压跟随器如果使能，SPS采样速率 <=200K
    stcAdcCfg.enAdcTrig0Sel = AdcTrigDisable;           //ADC转换自动触发设置
    stcAdcCfg.enAdcTrig1Sel = AdcTrigDisable;
    Adc_Init(&stcAdcCfg);    
    
    stcAdcIrq.bAdcIrq = TRUE;                            //转换完成中断函数入口配置使能
    stcAdcIrq.bAdcRegCmp = FALSE;
    stcAdcIrq.bAdcHhtCmp = FALSE;
    stcAdcIrq.bAdcLltCmp = FALSE;
    stcAdcIrqCalbaks.pfnAdcContIrq = AdcContIrqCallback; //转换完成中断入口函数
    stcAdcIrqCalbaks.pfnAdcRegIrq  = AdcRegIrqCallback;
    stcAdcIrqCalbaks.pfnAdcHhtIrq  = AdcHhtIrqCallback;
    stcAdcIrqCalbaks.pfnAdcLltIrq  = AdcLltIrqCallback;
    Adc_ConfigIrq(&stcAdcIrq, &stcAdcIrqCalbaks);        //转换中断入口函数配置
    Adc_EnableIrq();                                     //中断使能
    Adc_CmpCfg(&stcAdcIrq);                              //结果比较中断使能/禁止配置       
    stcAdcContCfg.enAdcContModeCh = SCAN_CHANNLE_1;      //通道0 P24
    stcAdcContCfg.u8AdcSampCnt    = 15;                  //P24 连续累加次数(次数 = 0x09+1)
    stcAdcContCfg.bAdcResultAccEn = TRUE;                //累加使能
    Adc_ConfigContMode(&stcAdcCfg, &stcAdcContCfg);
    bsp_ntc_start();
    return  true;
}

bool bsp_ntc_getAdc(uint16_t *_out_adc)
{
    if(finishFlag)
    {           
        finishFlag = false;
        *_out_adc = average_16times(add_dat);
        bsp_ntc_start();
        return true;
    }
    return false;
}





//------------------------------E N D-------------------------------------------