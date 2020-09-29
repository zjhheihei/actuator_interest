/*******************************************************************************
*
*	模块名称 : Mod背光模块
*	文件名称 : Mod_Backlight.c
*	版    本 : V1.0
*	说    明 : 1、模块独立，不主动访问其他模块。
                   2、映射BSP中的文件供其他函数调用
	           
*	修改记录 :
*		版本号  日期        作者     说明
*		V1.0    2018-07-06  zhoujh  正式发布
*	Copyright (C), 2015-2022,   menredGroup
*
*******************************************************************************/
//++++++++++++++++++++++++++++++start+++++++++++++++++++++++++++++++++++++++++++
#include ".\depend\bsp_led.h"
#include ".\mod_led.h"
//------------------------------E N D-------------------------------------------
#define BLINK_500_MS    0X01
#define BLINK_1000_MS   0X02
#define BLINK_2000_MS   0X04
static ledRunStatus_t ledRunStatus[5];
static uint8_t blinkStatus = 0;

void mod_led_action(uint8_t ledNum,ledRunStatus_t status)
{
    if(5 > ledNum)
    {
        ledRunStatus[ledNum] = status;
    }    
}

bool blink_handle(uint16_t ms_tick)
{
    static uint16_t blink_cyc[3];
    uint16_t passTime = 0;
    uint8_t  i = 0;
    bool retFlag = false;
    for(; i < 3; i++)
    {
        passTime = ms_tick - blink_cyc[i];
        if(passTime >= (500 * (0x01 << i)))
        {
            blink_cyc[i] = ms_tick;
            if((0x01 << i) & blinkStatus)
            {
                blinkStatus &= ~(0x01 << i);
            }
            else
            {
                blinkStatus |= (0x01 << i);
            }
            if(0 == i)
            {
                retFlag = true;
            }
        }       
    }
    return retFlag;
}

void mod_led_task(uint16_t ms_tick)
{  
    static bool initFlag = true; 
    if(initFlag)
    {
        initFlag = false;
        bsp_led_cfg();
    }
    else
    {
        if(blink_handle(ms_tick))
        {
            uint8_t i = 0;
            for(;i < 5;i++)
            {
                switch(ledRunStatus[i])
                {
                    case LED_RUN_OFF:bsp_led_action(i,true);break;
                    case LED_RUN_ON: bsp_led_action(i,false);break;
                    case LED_RUN_BLINK_500MS:
                    case LED_RUN_BLINK_1000MS:
                    case LED_RUN_BLINK_2000MS:
                    {
                        if((0x01 << ((uint8_t)ledRunStatus[i] - 2)) & blinkStatus)
                        {
                            bsp_led_action(i,false);
                        }
                        else
                        {
                            bsp_led_action(i,true);
                        }
                        break;
                    }
                    default:break;
                }
            }   
        }
    }
}



//-----------------------Mod_Backlight.c--END------------------------------------



