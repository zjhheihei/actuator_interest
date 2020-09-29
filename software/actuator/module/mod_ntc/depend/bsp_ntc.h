#ifndef _BSP_NTC_H
#define _BSP_NTC_H

#include <stdbool.h>
#include "stdint.h"


#define MAX_ADC_CHANNEL        2
#define InsideNumber           1
#define OutsideNumber          2


//++++++++++++++++++++++++++++++start+++++++++++++++++++++++++++++++++++++++++++
//Init
//名称:  bsp_ntc_cfg
//功能:  配置ADC硬件和软件 
//入口:  无
//出口:  true:配置成功  false：配置失败
bool bsp_ntc_cfg(void);
//------------------------------E N D-------------------------------------------



//++++++++++++++++++++++++++++++start+++++++++++++++++++++++++++++++++++++++++++
//Function
//名称:  bsp_ntc_task
//功能:  获取ADC的值
//入口:  uint16_t类型指针 ---------------------------------->>传出
//出口:  true:获取有效值 false：无效
bool bsp_ntc_getAdc(uint16_t *_out_adc);
//------------------------------E N D-------------------------------------------
#endif

//-----------------------BSP_NTC3380.h--END------------------------------------