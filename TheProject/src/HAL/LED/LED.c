/*
 * LED.c
 *
 *  Created on: Feb 24, 2024
 *      Author: NoteBook
 */

#include "LED/LED.h"
#include "GPIO/GPIO.h"
#define x	2
#define x	2
extern const Led_Config_t LEDS [_Led_Num];

LED_EnumErrorState LED_init (void)
{
	LED_EnumErrorState  LED_LocalErrorState = LED_OK;
	GPIO_strPin_t Temp_Led;
	Temp_Led.Mode = Output_PushPull ;
	Temp_Led.speed = High_Speed;

	for (u8 indx =0 ; indx < _Led_Num ; indx++)
	{
		Temp_Led.Pin = LEDS[indx].Pin;
		Temp_Led.Port = LEDS[indx].Port;
		GPIO_initPin (&Temp_Led);
	//	GPIO_SetPinValue (LEDS[indx].Pin,LEDS[indx].Port,LEDS[indx].Connection ^ LED_STATUS_ON);

	}
	return LED_LocalErrorState;
}


LED_EnumErrorState LED_SetStatus (uint32 LED , u8 Status)
{
	LED_EnumErrorState  LED_LocalErrorState = LED_NOK;
	if ((Status == LED_STATUS_ON) || (Status == LED_STATUS_OFF))
	{
	LED_LocalErrorState = LED_OK;

	GPIO_SetPinValue (LEDS[LED].Pin,LEDS[LED].Port,LEDS[LED].Connection ^ (Status));
	}

	return LED_LocalErrorState;

}


