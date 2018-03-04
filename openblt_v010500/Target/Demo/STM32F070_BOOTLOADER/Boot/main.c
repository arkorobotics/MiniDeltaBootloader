//
// STM32F070CB - Simple Bootloader
// By: Arko
//
/************************************************************************************//**
* \file         Demo\ARMCM0_STM32F0_Nucleo_F091RC_GCC\Boot\main.c
* \brief        Bootloader application source file.
* \ingroup      Boot_ARMCM0_STM32F0_Nucleo_F091RC_GCC
* \internal
*----------------------------------------------------------------------------------------
*                          C O P Y R I G H T
*----------------------------------------------------------------------------------------
*   Copyright (c) 2016  by Feaser    http://www.feaser.com    All rights reserved
*
*----------------------------------------------------------------------------------------
*                            L I C E N S E
*----------------------------------------------------------------------------------------
* This file is part of OpenBLT. OpenBLT is free software: you can redistribute it and/or
* modify it under the terms of the GNU General Public License as published by the Free
* Software Foundation, either version 3 of the License, or (at your option) any later
* version.
*
* OpenBLT is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
* without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
* PURPOSE. See the GNU General Public License for more details.
*
* You have received a copy of the GNU General Public License along with OpenBLT. It
* should be located in ".\Doc\license.html". If not, contact Feaser to obtain a copy.
*
* \endinternal
****************************************************************************************/

/****************************************************************************************
* Include files
****************************************************************************************/
#include "boot.h"                                /* bootloader generic header          */
#include "stm32f0xx.h"                           /* STM32 registers and drivers        */


/****************************************************************************************
* Function prototypes
****************************************************************************************/

/************************************************************************************//**
** \brief     This is the entry point for the bootloader application and is called
**            by the reset interrupt vector after the C-startup routines executed.
** \return    Program return code.
**
****************************************************************************************/
int main(void)
{
  /* initialize the microcontroller */
  CpuInit();
  /* initialize the millisecond timer */
  TimerInit();

  // Poorly Written Delay Routine
  // --> This emulates the delay of the original bootloader
  blt_int32u start_time = TimerGet();
  blt_int32u current_time = TimerGet();

  while((current_time - start_time) < 118)
  {
  	current_time = TimerGet();
  }
  
  // Magic words
  *(uint32_t*)0x20000400 = 0xDEADBEEF;

  // Load vector table and start the applicaiton
  CpuStartUserProgram();

  /* program should never get here */
  return 0;
} /*** end of main ***/


/*********************************** end of main.c *************************************/
