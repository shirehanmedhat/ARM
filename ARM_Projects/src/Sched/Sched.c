/*
 * Sched.c
 *
 *  Created on: Mar 14, 2024
 *      Author: NoteBook
 */
#include "SCHED/Sched.h"
#include "MCAL/SYSTICK/SYSTICK.h"
#include "../HAL/LCD/LCD.h"
extern volatile Runnable_t Runnables_Arr[_Max_RUNNABLE_NUM];


//Strcut To Contain The RunTime info
//if there is no Time Stamp Global Variable then you will need this structure
//But If The Architect determined a fixed Time Stamp , Then No Need For This Struct
//thats why we say that there are two types of design
//1- The Remaining Time Implementation
//2- The Time Stamp Implementation

	uint32_t RemainTimeMs[_Max_RUNNABLE_NUM];
	static uint8_t PendingTicks =0;

void SetPendingTicksFlag (void)
{
	PendingTicks++;

}
static void Sched (void)
{
	uint32_t idx;
	for (idx=0; idx<_Max_RUNNABLE_NUM  ; idx++)
	{
		if (   ( RemainTimeMs[idx] == 0 ) )
		{
			Runnables_Arr[idx].CallBack();
			RemainTimeMs[idx] = Runnables_Arr[idx].PeriodicityMs;

		}

		RemainTimeMs[idx] -= TICK_MS;
	}

}

void Sched_init(void)
{
	uint32_t idx;
	for (idx=0; idx<_Max_RUNNABLE_NUM  ; idx++)
	{
		RemainTimeMs[idx] = Runnables_Arr[idx].DelayMs;

	}
	STK_Init(AHB_8);
	STK_EnableInterrupt();
	STK_SetTime_ms(TICK_MS);
	STK_SetCallBack(Sched);
}

void Sched_Start(void)
{
	STK_Start();
	while (1)
	{
		if (PendingTicks ==1)
		{
			PendingTicks--;
			Sched();

		}

	}

}





