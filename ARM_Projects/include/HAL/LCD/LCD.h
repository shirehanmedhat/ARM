/*
 * LCD.h
 *
 *  Created on: Mar 20, 2024
 *      Author: NoteBook
 */

typedef unsigned char u8;
typedef unsigned int uint32_t;
typedef struct
{
    	uint32_t* Port;
		uint32_t Pin;
		uint32_t Mode;
		u8 InitState;
}LCD_PinConig_t;
typedef enum
{
	 LCD_0,
	_NUM_OF_LCDs
}LCD_NumOfLCDs_t;

typedef enum
{
	LCD_D0,
	LCD_D1,
	LCD_D2,
	LCD_D3,
	LCD_D4,
	LCD_D5,
	LCD_D6,
	LCD_D7,
	LCD_RS,
	LCD_RW,
	LCD_ENABLE,
	NUM_OF_PINs_PER_LCD
}LCD_PINS;

typedef enum {
	LCD_NOK,
	LCD_OK

}LCD_ErrorState_t;

#define FUNCTIONAL_SET	0X00
void InitializeTheBufferRquest (void);
void LCD_Init (void);
void LCD_WriteCommand (u8 Command);
void LCD_initSm (void);

LCD_ErrorState_t LCD_ClearScreen (void);
LCD_ErrorState_t LCD_SetPosition (u8 X , u8 Y);
LCD_ErrorState_t LCD_WriteNumber (u8 Number);

//void LCD_WriteCharacter (u8 Data);
void LCD_TASK (void);
