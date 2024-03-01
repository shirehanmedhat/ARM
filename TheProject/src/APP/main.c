
/*
#include <stdio.h>
#include <stdlib.h>
#include "diag/Trace.h"
#include "RCC/RCC.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"
RCC_PLLConfiguration_t PLL_CONFIG = {
    .SelectedClock = Select_HSE,
    .P = PLL_P_6,
    .N = PLL_N_USER_CONFIG,
    .M = PLL_M_USER_CONFIG

};

int main(int argc, char* argv[])
{
  // At this stage the system clock should have already been configured
  // at high speed.

  // Infinite loop
	RCC_EnableSystemClock (Clock_HSI);

	RCC_EnableSystemClock (Clock_HSE);
	RCC_ConfigurePLL (&PLL_CONFIG);
	RCC_DisableSystemClock (Clock_HSI);
	RCC_SelectSystemClock (Clock_HSE);
	RCC_DisableSystemClock (Clock_HSI);



 /* while (1)
    {
       // Add your code here.
    }
}

#pragma GCC diagnostic pop
*/
// ----------------------------------------------------------------------------
