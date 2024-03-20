/*
 * Sched_Config.c
 *
 *  Created on: Mar 17, 2024
 *      Author: NoteBook
 */

#include "SCHED/Sched.h"


extern void TrafficLights(void);
extern void App1_Runnable (void);

volatile Runnable_t Runnables_Arr[_Max_RUNNABLE_NUM] =
{
    [Runnable_1] = {
        .name = "Traffic_Runnable",
        .PeriodicityMs = 1000,
        .Priority = 0,
        .CallBack = TrafficLights,
        .DelayMs = 0
    },

    [Runnable_2] = {
        .name = "App2_Runnable",
        .PeriodicityMs = 2000,
        .Priority = 1,
        .CallBack = App1_Runnable,
        .DelayMs = 0
    }
};
