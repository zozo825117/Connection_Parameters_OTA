/*******************************************************************************
* File Name: UART.h
* Version 1.50
*
* Description:
*  This file provides constants and parameter values for the Software Transmit
*  UART Component.
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#ifndef CY_SW_TX_UART_UART_H
#define CY_SW_TX_UART_UART_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"

#define UART_BAUD_RATE                      (115200u)
#define UART_PIN_STATIC_MODE                (1u)


/***************************************
*        Function Prototypes
***************************************/
#if(UART_PIN_STATIC_MODE == 1u)
    void UART_Start(void) ;
#else
    void UART_StartEx(uint8 port, uint8 pin) ;
#endif /* (UART_PIN_STATIC_MODE == 1u) */

void UART_Stop(void) ;
void UART_PutChar(uint8 txDataByte) ;
void UART_PutString(const char8 string[]) ;
void UART_PutArray(const uint8 array[], uint32 byteCount) ;
void UART_PutHexByte(uint8 txHexByte) ;
void UART_PutHexInt(uint16 txHexInt) ;
void UART_PutCRLF(void) ;

#endif /* CY_SW_TX_UART_UART_H */


/* [] END OF FILE */
