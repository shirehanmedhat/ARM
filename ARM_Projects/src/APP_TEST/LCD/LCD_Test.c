/*
 * LCD_Test.c
 *
 *  Created on: Mar 24, 2024
 *      Author: NoteBook
 */


#include "SCHED/Sched.h"
#include "RCC/RCC.h"
#include "LCD/LCD.h"
#include "LED/LED.h"
int main (void)
{
	//Enable RCC Peripheral
	    RCC_EnableSystemClock(Clock_HSE);
		RCC_SelectSystemClock(Clock_HSE);
		RCC_EnablePeripheral(RCC_GPIOA);
		RCC_EnablePeripheral(RCC_GPIOB);
		LCD_Init();
		Sched_init();
		LCD_initSm();
		LCD_WriteString("Shirehan",8);
		LCD_ClearScreen();
		LCD_SetPosition(1,7);
		LCD_WriteString(" Medhat",7);
		LCD_ClearScreen();
		LCD_WriteNumber(125);
		Sched_Start();







	return 0;
}
