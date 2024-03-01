/*
 * LED.h
 *
 *  Created on: Feb 24, 2024
 *      Author: NoteBook
 */

#ifndef LED_H_
#define LED_H_
#include "LED/LED_Config.h"
typedef unsigned char u8;
typedef unsigned int uint32;
#define NULL ((void *)0)

typedef enum
{
	LED_NOK,
	LED_OK
}LED_EnumErrorState;



#define LED_STATUS_ON	1
#define LED_STATUS_OFF	0


#define LED_CONNECTION_REVERSED		1
#define LED_CONNECTION_FORWARD		0

typedef struct
{
	uint32* Port;
	uint32 Pin;
	u8 Connection;
	u8 InitState;

}Led_Config_t;
LED_EnumErrorState LED_init (void);

LED_EnumErrorState LED_SetStatus (uint32 LED , u8 Status);


#endif /* LED_H_ */
