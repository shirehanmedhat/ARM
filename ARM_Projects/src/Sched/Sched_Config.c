/*
 * Sched_Config.c
 *
 *  Created on: Mar 17, 2024
 *      Author: NoteBook
 */

#include "SCHED/Sched.h"


//extern void TrafficLights(void);
//extern void App1_Runnable (void);
extern void LCD_TASK (void);
volatile Runnable_t Runnables_Arr[_Max_RUNNABLE_NUM] =
{
    [Runnable_1] = {
        .name = "LCD",
        .PeriodicityMs = 2,
        .Priority = 0,
        .CallBack = LCD_TASK,
        .DelayMs = 0
    },


};
