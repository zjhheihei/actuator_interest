#include "intrinsics.h"
#include "clk.h"
#include <stdbool.h>
#include "stdint.h"


static volatile uint8_t SystickCount;

uint8_t bsp_systick_getTick(void)
{
    uint8_t Read_Int8u;    
    Read_Int8u = SystickCount;
    return(Read_Int8u);
}

void bsp_systick_cfg(void)
{
    stc_clk_systickcfg_t stcCfg;
    DDL_ZERO_STRUCT(stcCfg);
    stcCfg.enClk = ClkRCH;       //hclk/8
    stcCfg.u32LoadVal = 16000;     //1ms
    Clk_SysTickConfig(&stcCfg);
    SysTick_Config(stcCfg.u32LoadVal);
}

void SysTick_Handler(void)
{
    SystickCount++;
}
