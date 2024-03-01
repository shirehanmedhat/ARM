/*
 * main_led.c
 *
 *  Created on: Feb 25, 2024
 *      Author: NoteBook
 */


/*
#include "RCC/RCC.h"

#include "LED/LED.h"


int main (void)
{
	RCC_EnableSystemClock(Clock_HSE);
	RCC_SelectSystemClock(Clock_HSE);
	RCC_EnablePeripheral(RCC_GPIOA);
	RCC_EnablePeripheral(RCC_GPIOB);
	RCC_EnablePeripheral(RCC_GPIOC);

	LED_init();


	while (1)
	{
		uint32 counter =3000;

		LED_SetStatus (LED_ONE , LED_STATUS_ON);
		while (!counter);
		counter =3000;
		LED_SetStatus (LED_ONE , LED_STATUS_OFF);
		while (!counter);

	}



	return 0;
}
*/
