#include ".\APP_Cfg.h"



void main(void)
{
//    #ifdef NDEBUG
//    #ifndef __WIFI_CONTROL__
//    mod_watchdog_cfg();       
//    #endif 
//    mod_watchdog_reload();
//    #endif
    mod_system_clock_cfg();
    mod_systick_cfg();
//    app_sto_eeprom_configure();
    __enable_interrupt(); 
//    app_control_init();
    app_backLigth_on();
    while(1)
    {
//        #ifdef NDEBUG
//        mod_watchdog_reload();
//        #endif      
        mod_system_tick_scanTask();  
        app_backlight_task();
        mod_system_task();
        mod_ntc3380_scanTask();
//        app_backlight_scanTask();
//        app_control_scanTask();
//        app_outputLogic_scanTask();
//        app_sto_eeprom_scanTask();           
//        app_display_scanTask();
//        app_key_scanTask();
//        app_relayOut_scanTask();                
//        app_timming_scanTask();       
//        #ifdef __WIFI_CONTROL__  
//        HSICalibration_Task();
//        app_wifi_scanTask();
//        app_updateViaWIFI_task();
//        app_tuyaInterface_task();
//        app_interval_scanTask();
//        app_softRtc_sacnTask();
//        #endif
    }
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++