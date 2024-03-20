/*
 * RCC.h
 *
 *  Created on: Feb 12, 2024
 *      Author: NoteBook
 */

#ifndef RCC_H_
#define RCC_H_
typedef unsigned char u8;
typedef unsigned int uint32;

/*********************#DEFINES_SECTION*******************/

/***#Defines For The PLL Struct Configuration***/

/**1- Set the PLL_P value from the following options*/
#define PLL_P_2	  0x00000000
#define PLL_P_4   0x00010000
#define PLL_P_6   0x00020000
#define PLL_P_8   0x00030000

/**2- Set The M value to be from 1 to 64*/
#define PLL_M_USER_CONFIG	    10
/**3- Set This value to be from 1 to 433 or from 434 to 510*/
#define PLL_N_USER_CONFIG		200

/*Prescalers*/
#define AHB_PRESCALE_2   0b1000
#define AHB_PRESCALE_4   0b1001
#define AHB_PRESCALE_8   0b1010
#define AHB_PRESCALE_16  0b1011
#define AHB_PRESCALE_64  0b1100
#define AHB_PRESCALE_128 0b1101
#define AHB_PRESCALE_256 0b1110
#define AHB_PRESCALE_512 0b1111


#define APB1_PRESCALE_2   0b100
#define APB1_PRESCALE_4   0b101
#define APB1_PRESCALE_8   0b110
#define APB1_PRESCALE_16  0b111



#define APB2_PRESCALE_2   0b100
#define APB2_PRESCALE_4   0b101
#define APB2_PRESCALE_8   0b110
#define APB2_PRESCALE_16  0b111



#define RCC_AHB1ENR_MAX_ENUM_ID 32
#define RCC_AHB2ENR_MAX_ENUM_ID 64
#define RCC_APB1ENR_MAX_ENUM_ID 96
#define RCC_APB2ENR_MAX_ENUM_ID 128
/*********************TYPEDEFS SECTION******************/
/*PLL Config Clocks */
typedef enum
{
	Select_HSI,
	Select_HSE
}RCC_PLLSelectedClock_t;
/*Error Status Types*/
typedef enum {
				RCC_NOK,
				RCC_OK
}RCC_ErrorState_t;

/*available Clocks*/
typedef enum
{
	Clock_HSI,
	Clock_HSE,
	Clock_PLL,
	Clock_HSEBYP
}RCC_Clock_t;

/*Struct for PLL Configurations*/
typedef struct
{
	RCC_PLLSelectedClock_t SelectedClock;
	uint32 P;
	uint32 M;
	uint32 N;

}RCC_PLLConfiguration_t;


/*Mapping For the peripheral clock enable registers */

typedef enum
{
    /* AHB1 Peripherals */
    RCC_GPIOA  = 0,
    RCC_GPIOB  = 1,
    RCC_GPIOC  = 2,
    RCC_CRC    = 12,
    RCC_DMA1   = 21,
    RCC_DMA2   = 22,

    /* AHB2 Peripherals*/
    RCC_OTGFS   = 39,

    /* APB1 Peripherals */
    RCC_TIM2   = 64,
    RCC_TIM3   = 65,
    RCC_TIM4   = 66,
    RCC_TIM5   = 67,
    RCC_WWDG   = 75,
    RCC_SPI2   = 78,
    RCC_SPI3   = 79,
    RCC_USART2 = 81,
    RCC_I2C1   = 85,
    RCC_I2C2   = 85,
    RCC_I2C3   = 87,
    RCC_PWR    = 92,

    /* APB2 Peripherals */
    RCC_TIM1   = 96,
    RCC_USART1 = 100,
    RCC_USART6 = 101,
    RCC_SDIO   = 107,
    RCC_SPI1   = 108,
    RCC_SPI4   = 109,
    RCC_SYSCFG = 110,
    RCC_TIM9   = 112,
    RCC_TIM10   = 113,
    RCC_TIM11   = 114,

}RCC_Peripheral_Enable_t;

RCC_ErrorState_t RCC_EnableSystemClock (RCC_Clock_t Clock);
RCC_ErrorState_t RCC_EnableSystemClock_II (uint32 Clock);
RCC_ErrorState_t RCC_DisableSystemClock (RCC_Clock_t Clock);
RCC_ErrorState_t RCC_SelectSystemClock (RCC_Clock_t Clock);
RCC_ErrorState_t RCC_ConfigurePLL (RCC_PLLConfiguration_t* Configuration);
RCC_ErrorState_t RCC_SETAHB (u8 prescaler);
RCC_ErrorState_t RCC_SETAPB1 (u8 prescaler);
RCC_ErrorState_t RCC_SETAPB2 (u8 prescaler);
RCC_ErrorState_t RCC_EnablePeripheral (RCC_Peripheral_Enable_t Peripheral_ID);
RCC_ErrorState_t RCC_DisablePeripheral (RCC_Peripheral_Enable_t Peripheral_ID);
#endif /* RCC_H_ */
