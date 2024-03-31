/*
 * APP1.c
 *
 *  Created on: Mar 14, 2024
 *      Author: NoteBook
 */
#if 0
#include "LED/LED.h"





void App1_Runnable (void)
{
static int Flag =0;

if (Flag==0  )
{
	LED_SetStatus (LED_ONE , LED_STATUS_ON);
	Flag=1;

}
else if (Flag==1 )
{
	LED_SetStatus (LED_ONE , LED_STATUS_OFF);
	Flag=0;

}


}



#endif






