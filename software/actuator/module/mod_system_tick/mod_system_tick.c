#include ".\depend\bsp_system_tick.h"
#include ".\mod_system_tick.h"

             
typedef struct
{
    uint16_t millisecond;          
    uint16_t second;
    uint16_t minute;
}systick_t;

systick_t systick;


void para_reset(void)
{
    systick.millisecond = 0;
    systick.minute      = 0;
    systick.second      = 0;
}

void mod_system_tick_scanTask(void)
{
    static uint8_t  lastTick;
    static uint8_t  run_second; 
    static uint16_t run_ms;
           uint8_t  currentTick;
           uint8_t  passTick;           
    currentTick = bsp_systick_getTick();
    passTick = currentTick - lastTick;
    lastTick = currentTick;    
    if(passTick <= 200)
    {
        systick.millisecond += passTick;
        run_ms += passTick;
        if(1000 <= run_ms)
        {
            run_ms -= 1000; 
            systick.second++;           
            if(++run_second > 59)
            {
                run_second = 0;
                systick.minute++;               
            }
        }
    }
    else
    {
        lastTick = 0;
        run_second = 0;
        run_ms = 0;
        para_reset();
    }
}

uint16_t GetSysTickMillisecond(void)
{
    return(systick.millisecond);
}

uint16_t passTick_handle(uint16_t currentTick,uint16_t *keepTick)
{
    uint16_t passTick = currentTick - *keepTick;
    *keepTick = currentTick;
    return passTick;
}

void delayTickClock_run(delayPara_t* delayPara)
{
    uint16_t *currentTick;
    uint16_t passTick;
    currentTick = &systick.millisecond; 
    currentTick += (uint8_t)delayPara->delayType;
    passTick = passTick_handle(*currentTick,&delayPara->stoTick);       
    
    if(delayPara->runTick > passTick)
    {
        delayPara->runTick -= passTick;
    }
    else
    {
        delayPara->runTick = 0;
    }      
}

void dealyTickClock_reload(delayPara_t* delayPara,uint16_t delayTime)
{
    delayTickClock_run(delayPara);
    delayPara->runTick = delayTime;
    delayPara->onceTrigger = true;
}

bool delayTickClock_status(delayPara_t* delayPara,bool onceFlag)
{
    if(delayPara->runTick)
    {
        return false;
    }
    
    if(onceFlag)
    {
       if(delayPara->onceTrigger)
       {
          delayPara->onceTrigger = false;
          return true;
       }      
       return false;      
    }
    else
    {
       return true;
    }   
}

void mod_systick_cfg(void)
{
    bsp_systick_cfg();
}


