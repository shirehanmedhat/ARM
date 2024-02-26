/*
 * switch_led_test.c
 *
 *  Created on: Feb 26, 2024
 *      Author: NoteBook
 */



#include "RCC/RCC.h"

#include "LED/LED.h"
#include "SWITCH/SWITCH.h"

int main (void)
{
	RCC_EnableSystemClock(Clock_HSE);
	RCC_SelectSystemClock(Clock_HSE);
	RCC_EnablePeripheral(RCC_GPIOA);
	RCC_EnablePeripheral(RCC_GPIOB);
	RCC_EnablePeripheral(RCC_GPIOC);
	Switch_init();
	LED_init();
    uint32 counter=0;
	uint32 switch_check = SWITCH_RELEASED;
	while (1)
	{
		GetSwitchValue (Switch_One , &switch_check );
		if  (switch_check != SWITCH_RELEASED)
		{
			LED_SetStatus (LED_ONE , LED_STATUS_ON);
		}
		else
		{
			LED_SetStatus (LED_ONE , LED_STATUS_OFF);
		}


	}



	return 0;
}

