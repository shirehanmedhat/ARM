/*
 * LED_Config.c
 *
 *  Created on: Feb 24, 2024
 *      Author: NoteBook
 */

#include "LED/LED.h"
#include "GPIO/GPIO.h"

const Led_Config_t LEDS [_Led_Num] =
{
		[LED_ONE] =
		{
				.Port = GPIOA ,
				.Pin = GPIO_PIN2,
				.Connection = LED_CONNECTION_REVERSED,
				.InitState = LED_STATUS_OFF

		}

};


