//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include ".\depend\bsp_system_clock.h"
#include ".\mod_system_clock.h"

volatile static uint32_t hsi_freq = 12;

uint32_t mod_system_clock_getFreq(void)
{   
    return(hsi_freq);
}

void mod_system_clock_cfg(void)
{
    bsp_system_clock_cfg();
}

void mod_system_task(void)
{
    hsi_freq = bsp_system_clock_getFrqe();
}