/*
 * LCD_Config.c
 *
 *  Created on: Mar 20, 2024
 *      Author: NoteBook
 */
//#include "LIB/STD_TYPES.h"
#include "LCD/LCD.h"
#include "GPIO/GPIO.h"


LCD_PinConig_t LCD_ARRAY [_NUM_OF_LCDs][NUM_OF_PINs_PER_LCD] = {

		[LCD_0][LCD_D0]	= {
				.Pin = GPIO_PIN0,
				.Port = GPIOA,
				.Mode = Output_PushPull,
				.InitState =GPIO_LOW
		},
		[LCD_0][LCD_D1]	= {
						.Pin = GPIO_PIN1,
						.Port = GPIOA,
						.Mode = Output_PushPull,
						.InitState =GPIO_LOW
				},
		[LCD_0][LCD_D2]	= {
						.Pin = GPIO_PIN2,
						.Port = GPIOA,
						.Mode = Output_PushPull,
						.InitState =GPIO_LOW
				},

		[LCD_0][LCD_D3]	= {
						.Pin = GPIO_PIN3,
						.Port = GPIOA,
						.Mode = Output_PushPull,
						.InitState =GPIO_LOW
				},

		[LCD_0][LCD_D4]	= {
						.Pin = GPIO_PIN4,
						.Port = GPIOA,
						.Mode = Output_PushPull,
						.InitState =GPIO_LOW
				},

		[LCD_0][LCD_D5]	= {
						.Pin = GPIO_PIN5,
						.Port = GPIOA,
						.Mode = Output_PushPull,
						.InitState =GPIO_LOW
				},
		[LCD_0][LCD_D6]	= {
					    .Pin = GPIO_PIN6,
					    .Port = GPIOA,
					    .Mode = Output_PushPull,
					    .InitState =GPIO_LOW
				},
		[LCD_0][LCD_D7]	= {
					    .Pin = GPIO_PIN7,
					    .Port = GPIOA,
					    .Mode = Output_PushPull,
					    .InitState =GPIO_LOW
				},
		[LCD_0][LCD_RS]	= {
						.Pin = GPIO_PIN0,
						.Port = GPIOB,
						.Mode = Output_PushPull,
						.InitState =GPIO_LOW
				 },

		[LCD_0][LCD_RW]	= {
				 	.Pin = GPIO_PIN1,
				 	.Port = GPIOB,
				 	.Mode = Output_PushPull,
				 	.InitState =GPIO_LOW
				 },
		[LCD_0][LCD_ENABLE]	= {
					.Pin = GPIO_PIN2,
					.Port = GPIOB,
					.Mode = Output_PushPull,
					.InitState =GPIO_LOW
				}

};
