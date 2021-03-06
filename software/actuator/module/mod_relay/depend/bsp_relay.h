//++++++++++++++++++++++++++++++start+++++++++++++++++++++++++++++++++++++++++++
#ifndef _BSP_RELAY_H
#define _BSP_RELAY_H
//------------------------------E N D-------------------------------------------


//++++++++++++++++++++++++++++++start+++++++++++++++++++++++++++++++++++++++++++
#ifndef  __Snail_DataRetype__
#include ".\SnailDataTypedef.h"
#endif


//------------------------------E N D-------------------------------------------



//++++++++++++++++++++++++++++++start+++++++++++++++++++++++++++++++++++++++++++
//Init
//名称: bsp_relay_configure
//功能: 继电器IO口初始化
//入口: 无
//出口: 无
void bsp_relay_configure(void);
//------------------------------E N D-------------------------------------------


//++++++++++++++++++++++++++++++start+++++++++++++++++++++++++++++++++++++++++++
//Function
//名称: bsp_relayX_on
//功能: 继电器打开
//入口: 无
//出口: 无
void bsp_relay1_on(void);
void bsp_relay2_on(void);
void bsp_relay3_on(void);
void bsp_relay4_on(void);
//------------------------------E N D-------------------------------------------

//++++++++++++++++++++++++++++++start+++++++++++++++++++++++++++++++++++++++++++
//Function
//名称: bsp_relayX_off
//功能: 继电器关闭
//入口: 无
//出口: 无
void bsp_relay1_off(void);
void bsp_relay2_off(void);
void bsp_relay3_off(void);
void bsp_relay4_off(void);
//------------------------------E N D-------------------------------------------

#endif

//-----------------------BSP_RelayPWM.h--END------------------------------------
