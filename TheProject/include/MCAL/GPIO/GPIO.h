/*
 * GPIO.h
 *
 *  Created on: Feb 18, 2024
 *      Author: NoteBook
 */

#ifndef GPIO_H_
#define GPIO_H_

typedef unsigned char u8;
typedef unsigned int uint32;
#define NULL ((void *)0)

/****************************************************#DEFINES*************************************************/


/****************************************************TYPES***************************************************/

typedef enum
{
	GPIO_NOK,
	GPIO_OK
}GPIO_EnumErrorState;

/*
***************************************************
 *Input Parameter Options of Function : GPIO_SetPinValue();
 *Input Parameter Options of Function : GPIO_GetPinValue();
 *The Input Parameter : uint32 Port
 *Representation      : The Available Ports
 *
****************************************************
#define GPIO_PORTA	0
#define GPIO_PORTB	1
#define GPIO_PORTC	2
*/
/****************************************************************************
 *****************************MOIFICATION************************************
 ****************************************************************************/
/****************************************************************************
 *Input Parameter Options of Function : GPIO_SetPinValue();
 *Input Parameter Options of Function : GPIO_GetPinValue();
 *The Input Parameter :	void* Port
 *Representation      : The base addresses for each GPIO instance
 *Saving Memory wise modification: no array for multi-instances peripherals
 *
*****************************************************************************/
#define GPIOA		(void*)(0x40020000)
#define GPIOB		(void*)(0x40020400)
#define GPIOC		(void*)(0x40020800)
/****************************************************
 *Input Parameter Options of Function : GPIO_SetPinValue();
 *Input Parameter Options of Function : GPIO_GetPinValue();
 *The Input Parameter :	uint32 Pin
 *Representation      : The Available Pins Wrapping The Masks
 *
*****************************************************/

#define GPIO_PIN0 	  0
#define GPIO_PIN1	  1
#define GPIO_PIN2  	  2
#define GPIO_PIN3	  3
#define GPIO_PIN4	  4
#define GPIO_PIN5	  5
#define GPIO_PIN6	  6
#define GPIO_PIN7	  7
#define GPIO_PIN8	  8
#define GPIO_PIN9	  9
#define GPIO_PIN10	  10
#define GPIO_PIN11	  11
#define GPIO_PIN12	  12
#define GPIO_PIN13	  13
#define GPIO_PIN14	  14
#define GPIO_PIN15	  15
#define GPIO_PIN16	  16


/****************************************************
 *Input Parameter Options of Function : GPIO_SetPinValue();
 *Input Parameter Options of Function : GPIO_GetPinValue();
 *The Input Parameter :	uint32 OutValue
 *Representation      : The Logical Pin Values.
 *
*****************************************************/

#define GPIO_LOW	0
#define GPIO_HIGH	1


/****************************************************
 *Input Parameter Options of Function : GPIO_initPin ( GPIO_strPin_t* Pin);
 *The Input Parameter :	uint32 Mode  >> GPIO_strPin_t
 *Representation      : The Available Modes Wrapping The Masks
 *
*****************************************************/
#define Input_Floating  		 			    0b00000000000000000000000000000000
#define Input_PullUp     					    0b00000000000000000000000000000100
#define Input_PullDown  					    0b00000000000000000000000000001000
#define Analog           		 			    0b00000000000000000000000000000011
#define Output_OpenDrain 		 			    0b00000000000000000000000000010001
#define Output_OpenDrain_PullUp  			    0b00000000000000000000000000010101
#define Output_OpenDrain_PullDown			    0b00000000000000000000000000011001

#define Output_PushPull          			    0b00000000000000000000000000000001
#define Output_PushPull_PullUp	 			    0b00000000000000000000000000000101
#define Output_PushPull_PullDown 			    0b00000000000000000000000000001001

#define AlternateFunction_PushPull 			    0b00000000000000000000000000000010
#define AlternateFunction_PushPull_PullUp       0b00000000000000000000000000000110
#define AlternateFunction_PushPull_PullDown     0b00000000000000000000000000001010


#define AlternateFunction_OpenDrain             0b00000000000000000000000000010010
#define AlternateFunction_OpenDrain_PullUp      0b00000000000000000000000000010110
#define AlternateFunction_OpenDrain_PullDown    0b00000000000000000000000000011010



/****************************************************
 *Input Parameter Options of Function : GPIO_initPin ( GPIO_strPin_t* Pin);
 *The Input Parameter :	uint32 Speed  >> GPIO_strPin_t
 *Representation      : The Available Speeds Wrapping The Masks
 *
*****************************************************/


#define Low_Speed	 	0
#define Medium_Speed	1
#define High_Speed		2
#define Very_High_Speed	3


/****************************************************
 *Input Parameter Options of Function : GPIO_initPin ( GPIO_strPin_t* Pin);
 *The Input Parameter :	GPIO_Pin_t Pin  >> GPIO_strPin_t
 *Representation      : The Available Pins , an enum type for Algorithm wise
 *
*****************************************************/

/*typedef enum
{
	GPIO_PIN0,
	GPIO_PIN1,
	GPIO_PIN2,
	GPIO_PIN3,
	GPIO_PIN4,
	GPIO_PIN5,
	GPIO_PIN6,
	GPIO_PIN7,
	GPIO_PIN8,
	GPIO_PIN9,
	GPIO_PIN10,
	GPIO_PIN11,
	GPIO_PIN12,
	GPIO_PIN13,
	GPIO_PIN14,
	GPIO_PIN15,
	GPIO_PIN16
}GPIO_Pin_t;

*/

/****************************************************
 *Input Parameter Options of Function : GPIO_initPin ( GPIO_strPin_t* Pin);
 *The Input Parameter :	GPIO_strPin_t
 *Representation      : Representing the Pin Number , Port , Mode and Speed.
 *
*****************************************************/

typedef struct {

	uint32 Pin;
	void* Port;
	uint32 Mode;
	uint32 speed;
}GPIO_strPin_t;




/********************************************FUNCTION_PROTOTYPES*********************************************/

/*************************/
/* GPIO Initialization Function */
/*************************/
/*
 * @input parameters: GPIO_strPin_t* Pin (Pointer to a structure containing pin information)
 * @output parameters: GPIO_EnumErrorState (Error state indicating success or failure)
 * @description: Initializes a GPIO pin based on the provided configuration in the GPIO_strPin_t structure.
 */
GPIO_EnumErrorState GPIO_initPin ( GPIO_strPin_t* Pin);


/*************************/
/* GPIO Set Pin Value Function */
/*************************/
/*
 * @input parameters: uint32 Pin (Pin number), uint32 Port (Port number), uint32 OutValue (Logical pin value)
 * @output parameters: GPIO_EnumErrorState (Error state indicating success or failure)
 * @description: Sets the logical value (GPIO_LOW or GPIO_HIGH) of a specified pin in a given GPIO port.
 */

GPIO_EnumErrorState GPIO_SetPinValue (uint32 Pin , void* Port , uint32 OutValue);

/*************************/
/* GPIO Get Pin Value Function */
/*************************/
/*
 * @input parameters: uint32 Pin (Pin number), uint32 Port (Port number), uint32* ReadedValue (Pointer to store the read value)
 * @output parameters: GPIO_EnumErrorState (Error state indicating success or failure)
 * @description: Reads the logical value of a specified pin in a given GPIO port and stores it in the variable pointed to by ReadedValue.
 */

GPIO_EnumErrorState GPIO_GetPinValue (uint32 Pin , void* Port , uint32* ReadedValue );
#endif /* GPIO_H_ */
