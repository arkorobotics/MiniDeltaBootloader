/************************************************************************************//**
* \file         Source\uart.h
* \brief        Bootloader UART communication interface header file.
* \ingroup      Core
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
#ifndef UART_H
#define UART_H

#if (BOOT_COM_UART_ENABLE > 0)
/****************************************************************************************
* Function prototypes
****************************************************************************************/
void     UartInit(void);
void     UartTransmitPacket(blt_int8u *data, blt_int8u len);
blt_bool UartReceivePacket(blt_int8u *data);
#endif /* BOOT_COM_UART_ENABLE > 0 */


#endif /* UART_H */
/*********************************** end of uart.h *************************************/
