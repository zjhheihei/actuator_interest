//++++++++++++++++++++++++++++++start+++++++++++++++++++++++++++++++++++++++++++
#ifndef _MOD_LED_H
#define _MOD_LED_H
//------------------------------E N D-------------------------------------------
#include <stdbool.h>
#include "stdint.h"

typedef enum
{
    LED_RUN_OFF   =(uint8_t)0x00, 
    LED_RUN_ON, 
    LED_RUN_BLINK_500MS,
    LED_RUN_BLINK_1000MS,
    LED_RUN_BLINK_2000MS,
}ledRunStatus_t;
//++++++++++++++++++++++++++++++start+++++++++++++++++++++++++++++++++++++++++++
//Function
//名称: 设置背光点亮时间
//功能: 点亮背光
//入口: _in_secondLedOn  背光点亮时间，秒级  <<-------------------------传入
//出口: 无
void mod_led_action(uint8_t ledNum, ledRunStatus_t status);

//++++++++++++++++++++++++++++++start+++++++++++++++++++++++++++++++++++++++++++
//task
//名称: 背光任务
//功能: 定时扫描，确定背光是否点亮
//入口: _in_msTick 扫描周期，毫秒级 <<-----------------------------------传入
//出口: 无
void mod_led_task(uint16_t ms_tick);
#endif
//-----------------------Mod_Backlight.h--END-----------------------------------
