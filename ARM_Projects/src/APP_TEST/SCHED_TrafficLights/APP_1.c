/*
 * APP.c
 *
 *  Created on: Mar 17, 2024
 *      Author: NoteBook
 */
#if 0
#include "APP_1.h"
#include"LIB/STD_TYPES.h"
#include "RCC/RCC.h"
#include "LED/LED.h"

LedState_t State = GREEN;
#define Task_Periodicity 2

void TrafficLights_init (void)
{
	RCC_EnableSystemClock(Clock_HSE);
	RCC_SelectSystemClock(Clock_HSE);
	RCC_EnablePeripheral(RCC_GPIOA);
	RCC_EnablePeripheral(RCC_GPIOB);
	LED_init();

}
static  void GreenStateAction (void)
{
	LED_SetStatus (LED_GREEN , LED_STATUS_ON );
	LED_SetStatus (LED_YELLOW , LED_STATUS_OFF );
	LED_SetStatus (LED_RED , LED_STATUS_OFF );

}

static  void YellowStateAction (void)
{
	LED_SetStatus (LED_GREEN , LED_STATUS_OFF );
	LED_SetStatus (LED_YELLOW , LED_STATUS_ON );
	LED_SetStatus (LED_RED , LED_STATUS_OFF );

}

static  void RedStateAction (void)
{
	LED_SetStatus (LED_GREEN , LED_STATUS_OFF);
	LED_SetStatus (LED_YELLOW , LED_STATUS_OFF );
	LED_SetStatus (LED_RED , LED_STATUS_ON );

}


void TrafficLights (void)
{
	static uint32_t Sec=0;
	static LedState_t Prev;
	Sec += Task_Periodicity;
	switch(State)
	{
	case GREEN:
	{
		//TWO
		GreenStateAction();
		if (Sec ==4)
		{
			Sec=0;
			Prev=GREEN;
			State = YELLOW;
		}
	}break;

	case YELLOW:
		{
			//4SEC
			YellowStateAction();
			if ((Sec ==8) && (Prev == GREEN))
			{
				Sec=0;
				Prev=YELLOW;
				State = RED;
			}
			else if ((Sec ==8) && (Prev == RED))
			{
				Sec=0;
				Prev=YELLOW;
				State = GREEN;
			}
		}break;


	case RED:
		{
			//6SEC
			RedStateAction();
			if (Sec == 12)
			{
				Sec=0;
				Prev=RED;
				State = YELLOW;
			}
		}break;

	}

}

#endif
