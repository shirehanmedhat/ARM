/*
 * Switch.c
 *
 *  Created on: Feb 24, 2024
 *      Author: NoteBook
 */
#include"LIB/STD_TYPES.h"
#include "SWITCH/SWITCH.h"
#include "GPIO/GPIO.h"
extern const SwitchConfig_t Switches [_Switch_Num];
static uint32_t SwitchState[_Switch_Num];

SWITCH_EnumErrorState Switch_init(void)
{
	SWITCH_EnumErrorState  SWITCH_LocalErrorState = SWITCH_OK;
	GPIO_strPin_t Temp_Switch ;

	for (u8 indx =0 ; indx< _Switch_Num ; indx++)
	{
		Temp_Switch.Mode = Switches[indx].Connection;
		Temp_Switch.Port = Switches[indx].Port;
		Temp_Switch.Pin = Switches[indx].Pin;
		GPIO_initPin (&Temp_Switch);

	}


	return SWITCH_LocalErrorState;

}

/*
SWITCH_EnumErrorState GetSwitchValue(u8 Switch , uint32* ReadedValue)
{
	SWITCH_EnumErrorState  SWITCH_LocalErrorState = SWITCH_NOK;
	if ((ReadedValue != NULL) && (Switch < _Switch_Num) )
	{
		uint32 tempRead=0;
		SWITCH_LocalErrorState = SWITCH_OK;
		switch(Switches[Switch].Connection)
		{
		case SW_Input_PullUp:
			GPIO_GetPinValue (Switches[Switch].Pin , Switches[Switch].Port , &tempRead );
			*ReadedValue = !tempRead;
			break;
		case SW_Input_PullDown:
			GPIO_GetPinValue (Switches[Switch].Pin , Switches[Switch].Port , ReadedValue );
			break;
		default:
			break;
		}

	}
	else
	{
		//Do Nothing
	}




	return SWITCH_LocalErrorState;


}

*/
#define SW_Input_PullUp_Offset	2
/*
SWITCH_EnumErrorState GetSwitchValue(u8 Switch , uint32* ReadedValue)
{
	SWITCH_EnumErrorState  SWITCH_LocalErrorState = SWITCH_NOK;
	if ((ReadedValue != NULL) && (Switch < _Switch_Num) )
	{
		uint32 tempRead=0;
		SWITCH_LocalErrorState = SWITCH_OK;


			GPIO_GetPinValue (Switches[Switch].Pin , Switches[Switch].Port , &tempRead );
			*ReadedValue =  tempRead ^ ( (Switches[Switch].Connection & SW_Input_PullUp) >> SW_Input_PullUp_Offset);

		}

	else
	{
		//Do Nothing
	}




	return SWITCH_LocalErrorState;


}
*/


SWITCH_EnumErrorState GetSwitchValue(u8 Switch , uint32* ReadedValue)
{
	SWITCH_EnumErrorState  SWITCH_LocalErrorState = SWITCH_NOK;
	if ((ReadedValue != NULL) && (Switch < _Switch_Num) )
	{
		uint32 tempRead=0;
		SWITCH_LocalErrorState = SWITCH_OK;



			*ReadedValue = SwitchState[Switch];

		}

	else
	{
		//Do Nothing
	}




	return SWITCH_LocalErrorState;


}



void SW_Runnable (void)
{
	u8 Current;
	static u8 Prev[_Switch_Num];
	static uint32_t Counter[_Switch_Num] = {0};
	for (uint32_t idx =0; idx<_Switch_Num ; idx++)
	{
	GPIO_GetPinValue (Switches[idx].Pin , Switches[idx].Port , &Current );
	Current =  Current ^ ( (Switches[idx].Connection & SW_Input_PullUp) >> SW_Input_PullUp_Offset);
	if (Current == Prev[idx] )
	{
		Counter[idx]++;
	}
	else
	{
		Counter[idx] = 0;
	}

	if (Counter[idx] == 5)
	{
		SwitchState[idx] = Current;
		Counter[idx] = 0;
	}

	Prev[idx] = Current;

	}

}


