/*******************************************************************************
*
*	模块名称 : APP背光模块
*	文件名称 : APP.Backlight.c
*	版    本 : V1.0
*	说    明 : 1、传出压入背光数据
*                  2、背光扫描
*                  
*	修改记录 :
*		版本号  日期        作者     说明
*		V1.0    2018-11-27  Linzl  正式发布
*	Copyright (C), 2015-2020,   menredGroup
*
*******************************************************************************/
#include ".\APP_Cfg.h"
/******************************************************************************/
void app_backLigth_on(void)
{    
    //mod_led_action(0,LED_RUN_OFF)  ;   
    //mod_led_action(1,LED_RUN_OFF)  ;
    mod_led_action(2,LED_RUN_BLINK_2000MS)  ;
    mod_led_action(3,LED_RUN_BLINK_1000MS)  ;
    mod_led_action(4,LED_RUN_BLINK_500MS)  ;
}


void app_backlight_task(void)
{
    mod_led_task(GetSysTickMillisecond());
}
//------------------------APP.Backlight.C--END----------------------------------


