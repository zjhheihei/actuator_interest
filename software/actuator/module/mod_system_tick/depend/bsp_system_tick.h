//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef _BSP_SYSTEM_TICK_H
#define _BSP_SYSTEM_TICK_H
#include <stdbool.h>
#include "stdint.h"
//------------------------------------------------------------------------------
//Task
//------------------------------------------------------------------------------
//Event
//------------------------------------------------------------------------------
//Status
//------------------------------------------------------------------------------
//Function
void bsp_systick_cfg(void);
//-----------------------------------------------------------------------------
//名称:获取系统计数
//入口:无
//
//出口:1ms的系统计数

uint8_t bsp_systick_getTick(void);
#endif
//++++++++++++++++++++++++++++++++++End++++++++++++++++++++++++++++++++++++++++