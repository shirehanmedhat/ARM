/*
 * GPIO_test.c
 *
 *  Created on: Feb 25, 2024
 *      Author: NoteBook
 */


#if 0
#include "RCC/RCC.h"
#include "LED/LED.h"
#include "GPIO/GPIO.h"


int main (void)
{
	RCC_EnableSystemClock(Clock_HSE);
	RCC_SelectSystemClock(Clock_HSE);
	RCC_EnablePeripheral(RCC_GPIOA);
	RCC_EnablePeripheral(RCC_GPIOB);
	RCC_EnablePeripheral(RCC_GPIOC);

	//LED_init();
	GPIO_strPin_t Pin = {GPIO_PIN1 , GPIOA, Output_PushPull , High_Speed};


	GPIO_initPin(&Pin);


	uint32 counter;
	while (1)
	{

		counter =3000;
		GPIO_SetPinValue (PIN1,GPIOA,GPIO_LOW);

		GPIO_SetPinValue (PIN1,GPIOA,GPIO_HIGH);


	}



	return 0;
}
#endif
