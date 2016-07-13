/*****************************************************************************
* File Name: debug.h
*
* Version: 1.0
*
* Description:
* This file contains Debug API functions.
*
* Note:
* Defining ENABLE_DEBUG_PIN in platform.h to enable macro for toggling the debug_pin
* Defining DEBUG_PRINT in platform.h to enable debug print module
* Defining SOFTWARE_UART in platform.h to enable debug print over Software Uart 
* else SCB configured as UART is enabled 
*
* Owner: MRAO
* 
* Related Document:
* UART component datasheet
* SW_Tx_UART component datasheet
*
* Hardware Dependency:
* 
*
* Code Tested With:
* 1. PSoC Creator 3.1 
* 2. ARM GCC 4.8.4
******************************************************************************
* Copyright (2015), Cypress Semiconductor Corporation.
******************************************************************************
* This software is owned by Cypress Semiconductor Corporation (Cypress) and is
* protected by and subject to worldwide patent protection (United States and
* foreign), United States copyright laws and international treaty provisions.
* Cypress hereby grants to licensee a personal, non-exclusive, non-transferable
* license to copy, use, modify, create derivative works of, and compile the
* Cypress Source Code and derivative works for the sole purpose of creating
* custom software in support of licensee product to be used only in conjunction
* with a Cypress integrated circuit as specified in the applicable agreement.
* Any reproduction, modification, translation, compilation, or representation of
* this software except as specified above is prohibited without the express
* written permission of Cypress.
*
* Disclaimer: CYPRESS MAKES NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, WITH
* REGARD TO THIS MATERIAL, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. 
* Cypress reserves the right to make changes without further notice to the
* materials described herein. Cypress does not assume any liability arising out
* of the application or use of any product or circuit described herein. Cypress
* does not authorize its products for use as critical components in life-support
* systems where a malfunction or failure may reasonably be expected to result in
* significant injury to the user. The inclusion of Cypress' product in a life-
* support systems application implies that the manufacturer assumes all risk of
* such use and in doing so indemnifies Cypress against all charges. Use may be
* limited by and subject to the applicable Cypress software license agreement.
*****************************************************************************/
#ifndef _DEBUG_H_
#define _DEBUG_H_

#include <project.h>
  
#define DEBUG_PRINT
#define SOFTWARE_UART

/* Macros for the toggling the GPIO */
#ifdef ENABLE_DEBUG_PIN
#define DEBUG_PIN_LOW                   Debug_Pin_Write(0)
#define DEBUG_PIN_HIGH                  Debug_Pin_Write(1)
#define DEBUG_PIN_VALUE(x)              Debug_Pin_Write(x)
#define DEBUG_PIN_TOGGLE()              Debug_Pin_Write(!Debug_Pin_Read())
#ifdef ENABLE_DEBUG_PIN_2
#define DEBUG_PIN_2_LOW                 Debug_Pin_2_Write(0)
#define DEBUG_PIN_2_HIGH                Debug_Pin_2_Write(1)
#define DEBUG_PIN_2_VALUE(x)            Debug_Pin_2_Write(x)
#define DEBUG_PIN_2_TOGGLE()            Debug_Pin_2_Write(!Debug_Pin_2_Read())
#else
#define DEBUG_PIN_2_LOW
#define DEBUG_PIN_2_HIGH
#define DEBUG_PIN_2_VALUE(x)            
#define DEBUG_PIN_2_TOGGLE()
#endif /* ENABLE_DEBUG_PIN_2 */
#else
#define DEBUG_PIN_LOW
#define DEBUG_PIN_HIGH
#define DEBUG_PIN_VALUE(x)
#define DEBUG_PIN_TOGGLE()
#define DEBUG_PIN_2_LOW
#define DEBUG_PIN_2_HIGH
#define DEBUG_PIN_2_VALUE(x)
#define DEBUG_PIN_2_TOGGLE()           
#endif /* ENABLE_DEBUG_PIN  */

/* Different level of the debug message */
#define DEBUG_MESSAGE_LEVEL_0             (00u)
#define DEBUG_MESSAGE_LEVEL_1             (01u)
#define DEBUG_MESSAGE_LEVEL_2             (02u)
#define DEBUG_MESSAGE_LEVEL_3             (03u)
#define DEBUG_MESSAGE_LEVEL_4             (04u)
#define DEBUG_MESSAGE_LEVEL_5             (05u)
#define DEBUG_MESSAGE_LEVEL_6             (06u)
#define DEBUG_MESSAGE_LEVEL_7             (07u)

#define DEBUG_PORT												0
#define DEBUG_PIN													4

#ifdef DEBUG_PRINT
/*****************************************************************************
* Function Name: Debug_Print_Start()
******************************************************************************
* Summary:
* This function is used to initialize debug functionality.
*
* Parameters:
* uint8 level - Level for printing the debug message
*
* Return:
* None
*
*****************************************************************************/
extern void Debug_Print_Start(uint8 debug_level);

/*****************************************************************************
* Function Name: Debug_Print()
******************************************************************************
* Summary:
* This function is used to print the logs on the UART.
*
* Parameters:
* uint8 level - Level of the debug message
* char8 *pszFmt - Message to be print
*
* Return:
* None
*
*****************************************************************************/
extern void Debug_Print(uint8 level, char8 *pszFmt,...);

#else
#define Debug_Print_Start(x)
#define Debug_Print(x,pszFmt,...)
#endif /* DEBUG_PRINT */

#endif /* _DEBUG_H_ */
