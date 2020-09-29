#include ".\SnailDataTypedef.h"
#include ".\SnailMacro.h"
#include "intrinsics.h"
#include "DeviceSelect.h"

#include "ddl.h"
#include <stdbool.h>
#include "stdint.h"


void bsp_system_clock_cfg(void)
{
    volatile uint32_t u32Val = 0;
    u32Val = Clk_GetHClkFreq();
    Clk_SwitchTo(ClkRCL);
    Clk_SetRCHFreq(ClkFreq16Mhz);
    Clk_SwitchTo(ClkRCH);
    u32Val = Clk_GetHClkFreq();   
}


uint32_t bsp_system_clock_getFrqe(void)
{
    return Clk_GetHClkFreq();
}


void bsp_hsi_adj_scanTask(void)
{
    
}

