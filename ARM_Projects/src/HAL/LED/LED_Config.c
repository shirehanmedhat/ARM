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
		[LED_GREEN] =
		{
				.Port = GPIOB ,
				.Pin = GPIO_PIN3,
				.Connection = LED_CONNECTION_FORWARD,
				.InitState = LED_STATUS_OFF

		}
		/*,
		[LED_YELLOW] =
				{
						.Port = GPIOB ,
						.Pin = GPIO_PIN3,
						.Connection = LED_CONNECTION_FORWARD,
						.InitState = LED_STATUS_OFF

				},
		[LED_RED] =
						{
								.Port = GPIOA ,
								.Pin = GPIO_PIN6,
								.Connection = LED_CONNECTION_FORWARD,
								.InitState = LED_STATUS_OFF

						},
		[LED_ONE] =
						{
							.Port = GPIOB ,
							.Pin = GPIO_PIN6,
							.Connection = LED_CONNECTION_FORWARD,
							.InitState = LED_STATUS_OFF

							}*/

};


