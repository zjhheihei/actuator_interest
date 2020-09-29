
/*******************************************************************************
*
*	模块名称 : BSP背光模块
*	文件名称 : BSP_Backlight.c
*	版    本 : V1.0
*	说    明 : 1、模块独立，不访问其他任何模块
*                  2、供Mod_Backlight调用
                   3、硬件配置。
*	修改记录 :
*		版本号  日期        作者     说明
*		V1.0   2018-07-2  zhoujh  正式发布
*	Copyright (C), 2015-2020,   menredGroup
*             
*******************************************************************************/
#include "intrinsics.h"
#include "ddl.h"
#include <stdbool.h>
#include "stdint.h"



#define LED_1_PORT            3
#define LED_1_PIN             1
#define LED_2_PORT            2
#define LED_2_PIN             7

#define LED_3_PORT            3
#define LED_3_PIN             4
#define LED_4_PORT            3
#define LED_4_PIN             5
#define LED_5_PORT            3
#define LED_5_PIN             2


void bsp_led_cfg(void)
{
    //Gpio_InitIO(LED_1_PORT,LED_1_PIN,GpioDirOut);
    //Gpio_InitIO(LED_2_PORT,LED_2_PIN,GpioDirOut);
    Gpio_InitIO(LED_3_PORT,LED_3_PIN,GpioDirOut);
    Gpio_InitIO(LED_4_PORT,LED_4_PIN,GpioDirOut); 
    Gpio_InitIO(LED_5_PORT,LED_5_PIN,GpioDirOut); 
}



void bsp_led_action(uint8_t ledNum,bool action)
{
    switch(ledNum)
    {
        case 0:Gpio_SetIO(LED_1_PORT,LED_1_PIN,(boolean_t)(!action));break;
        case 1:Gpio_SetIO(LED_2_PORT,LED_2_PIN,(boolean_t)(!action));break;
        case 2:Gpio_SetIO(LED_3_PORT,LED_3_PIN,(boolean_t)(!action));break;
        case 3:Gpio_SetIO(LED_4_PORT,LED_4_PIN,(boolean_t)(!action));break;
        case 4:Gpio_SetIO(LED_5_PORT,LED_5_PIN,(boolean_t)(!action));break;
        default:break;
    }   
}





