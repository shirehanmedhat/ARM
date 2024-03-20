/*
 * SysTick.c
 *
 *  Created on: Mar 13, 2024
 *      Author: NoteBook
 */
#if 0
#include "RCC/RCC.h"

#include"../MCAL/SYSTICK/SYSTICK.h"
#include "LED/LED.h"
void SysTick_Handler_Toggle(void);
int main (void)
{

	RCC_EnableSystemClock(Clock_HSI);
	RCC_SelectSystemClock(Clock_HSI);
	RCC_EnablePeripheral(RCC_GPIOA);
    STK_EnableInterrupt();
	STK_SetCallBack(&SysTick_Handler_Toggle);
	LED_init();
	STK_Init(AHB);
	STK_SetTime_ms(500);
	 STK_Start();

	while(1)
	{
		/*
		   // static Flag =0;
			//static counter =0;
			//counter++;
			if (Flag==0  )
			{
				LED_SetStatus (LED_ONE , LED_STATUS_ON);
				 STK_Start();
				Flag=1;
				//counter=0;

			}
			else if (Flag==1 )
			{
				LED_SetStatus (LED_ONE , LED_STATUS_OFF);
				 STK_Start();

				Flag=0;
				//counter=0;

			}*/

	}
}
void SysTick_Handler_Toggle(void)
{
	static int Flag =0;
	static int counter =0;
	counter++;
	if (Flag==0 && counter==2 )
	{
		LED_SetStatus (LED_ONE , LED_STATUS_ON);
		Flag=1;
		counter=0;

	}
	else if (Flag==1 && counter==2)
	{
		LED_SetStatus (LED_ONE , LED_STATUS_OFF);
		Flag=0;
		counter=0;

	}


}
#endif
