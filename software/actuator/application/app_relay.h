#ifndef _APP_RELAY_H
#define _APP_RELAY_H



//++++++++++++++++++++++++++++++start+++++++++++++++++++++++++++++++++++++++++++
//task  
//名称: app_relayOut_scanTask
//功能: 继电器输出扫描任务
//入口: 无                          
//出口: 无
void app_relayOut_scanTask(void);
//------------------------------E N D-------------------------------------------


//++++++++++++++++++++++++++++++start+++++++++++++++++++++++++++++++++++++++++++
//func
//名称: relay_out_limitFlag
//功能: 返回内控外限
//入口: 无
//出口: true 限温状态  false 无
bool relay_out_limitFlag(void);
//------------------------------E N D-------------------------------------------


#endif



