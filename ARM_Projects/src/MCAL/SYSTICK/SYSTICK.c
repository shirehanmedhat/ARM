/*
 * SYSTICK.c
 *
 *  Created on: Mar 12, 2024
 *      Author: NoteBook
 */
#include"STD_TYPES.h"
#include "SYSTICK/SYSTICK.h"


/**
 * @brief Structure representing the SysTick registers.
 *
 * This structure defines the layout of the SysTick registers.
 */
typedef struct
{
	uint32_t STK_CTRL;
	uint32_t STK_LOAD;
	uint32_t STK_VAL;
	uint32_t STK_CALIB;


}STK_t;


/**
 * @brief Pointer to the callback function for the SysTick timer.
 *
 * This pointer is used to store the callback function for the SysTick timer.
 */
static SysTick_CB_t App_CBF = NULL;

/**
 * @brief Base address of the SysTick peripheral.
 *
 * This macro defines the base address of the SysTick peripheral.
 */
#define STK_Peripheral		(void*)0xE000E010

/**
 * @brief Mask for selecting the Systick clock source.
 *
 * This macro defines the mask used for selecting the Systick clock source.
 */
#define SLK_SOURCE_MASK	4

/**
 * @brief Mask for enabling SysTick interrupt.
 *
 * This macro defines the mask used for enabling the SysTick interrupt.
 */
#define INTERRUPTENABLMASK	2

/**
 * @brief Mask for SysTick count flag.
 *
 * This macro defines the mask used for the SysTick underflow count flag.
 */
#define COUNT_FLAG_MASK	0x00010000

/**
 * @brief Mask for enabling the SysTick counter.
 *
 * This macro defines the mask used for enabling the SysTick counter.
 */
#define COUNTER_ENABLE_MASK	1

/**
 * @brief Maximum value that can be held in the SysTick LOAD register 2power(24)-1.
 *
 * This macro defines the maximum value that can be held in the SysTick LOAD register.
 */
#define MAX_NUM_TICKS_REG	16777215


STK_ErrorState_t STK_Init(uint32_t ClkSource)
{
	STK_ErrorState_t STK_LocalErrorState = STK_OK;
	switch (ClkSource)
	{
	case AHB_8:
		((STK_t*)STK_Peripheral)->STK_CTRL = (((STK_t*)STK_Peripheral)->STK_CTRL) & (~SLK_SOURCE_MASK);
		break;
	case AHB:
		((STK_t*)STK_Peripheral)->STK_CTRL = (((STK_t*)STK_Peripheral)->STK_CTRL) | (SLK_SOURCE_MASK);
		break;
	default:
		STK_LocalErrorState = STK_NOK;
		break;
	}
	return STK_LocalErrorState;

}

STK_ErrorState_t STK_SetTime_ms(uint32_t TimeValue)
{
	STK_ErrorState_t STK_LocalErrorState = STK_NOK;
	uint32_t RequiredTicks=0;
	uint32_t ReloadValue =0;

	/*Calculating Required Ticks For The Given Time In ms */
	/*The Equation :
	 * RequiredTicks = (TimeValue/TickTime) >> this equation should be in seconds
	 * lets breakdown the previous equation step by step ASSUME the frequency = F(MHZ)
	 * RequiredTicks = (TimeValue/1000) *F*1000000
	 * RequiredTicks = (TimeValue) *F*1000
	 * then::
	 *RequiredTicks = (TimeValue)*(frequency/1000)
	 *In The Next lines of code the steps will be divided into multiple steps too
	 * */

	/*Required Ticks */
	RequiredTicks = TimeValue *(STK_CLOCK/1000);
	/*Calculate the ReloadValue :number of ticks to be set which equal to the time required*/
	ReloadValue = RequiredTicks-1;
	if (ReloadValue < MAX_NUM_TICKS_REG)
	{
	STK_LocalErrorState = STK_OK;
	((STK_t*)STK_Peripheral)->STK_LOAD=0x00000000;
	((STK_t*)STK_Peripheral)->STK_LOAD = ReloadValue;
	}
	else
	{
		/*DoNothing*/
	}

	return STK_LocalErrorState;

}






void STK_EnableInterrupt(void)
{
	((STK_t*)STK_Peripheral)->STK_CTRL |= INTERRUPTENABLMASK;
}

void STK_DisableInterrupt(void)
{
	((STK_t*)STK_Peripheral)->STK_CTRL &= (~INTERRUPTENABLMASK);
}

void STK_Start(void)
{
	/*Clear The Current Value*/
	((STK_t*)STK_Peripheral)->STK_VAL=1;
	((STK_t*)STK_Peripheral)->STK_CTRL|= COUNTER_ENABLE_MASK;

}

void STK_Stop(void)
{
	/*Clear The Current Value*/
	((STK_t*)STK_Peripheral)->STK_CTRL&= (~COUNTER_ENABLE_MASK);
}

STK_ErrorState_t STK_SetCallBack (SysTick_CB_t CBF)
{
	STK_ErrorState_t STK_LocalErrorState = STK_NOK;
	if (CBF)
	{
	STK_LocalErrorState = STK_OK;
	App_CBF=CBF;
	}
	else
	{
		/*Do Nothing*/

	}
	return STK_LocalErrorState;

}


void SysTick_Handler (void)
{

	if (App_CBF)
	{
		App_CBF();
	}
}

