/*****************************************************************************
* File Name: debug.c
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
*
* Hardware Dependency:
* UART PSoC Creator Component
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

#include "debug.h"

#ifdef DEBUG_PRINT

static uint8 debug_level;
/*****************************************************************************
* Function Name: Putc()
******************************************************************************
* Summary:
* This function is used to print a character on the UART.
*
* Parameters:
* uint8 ch - character value
*
* Return:
* None
*
* Theory:
* Send a character to the uart
*
* Side Effects:
* None 
*
* Note:
* None
*****************************************************************************/
static void Putc(char8 ch)
{
    /*This function has to be replaced by user */
#ifndef SOFTWARE_UART
    Debug_Uart_SpiUartWriteTxData(ch);
#else
    SW_Tx_UART_PutChar(ch);
#endif /* SOFTWARE_UART */
}

/*****************************************************************************
* Function Name: Byte_To_ASCII()
******************************************************************************
* Summary:
* This function is used to map the byte to its ASCII chacter value.
*
* Parameters:
* uint32 index - byte value
*
* Return:
* uint8 * - pointers to the ASCII character value
*
* Theory:
* Converts the byte into ascii character value using look up table method 
*
* Side Effects:
* None 
*
* Note:
* None
*****************************************************************************/
static uint8* Byte_To_ASCII(uint32 Index)
{
    return (uint8*)("0123456789abcdef" + Index);
}

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
* Theory:
* Starts the UART component and stores the debug_level for further procecssing
*
* Side Effects:
* debug_level is updated 
*
* Note:
* None
*****************************************************************************/
void Debug_Print_Start(uint8 level)
{
#ifndef SOFTWARE_UART
    Debug_Uart_Start();
#else

#if(SW_Tx_UART_PIN_STATIC_MODE == 1u)
				SW_Tx_UART_Start() ;
#else
				SW_Tx_UART_StartEx(DEBUG_PORT,DEBUG_PIN);
#endif /* (SW_Tx_UART_PIN_STATIC_MODE == 1u) */

#endif /* SOFTWARE_UART */
    debug_level = level;
}

/*****************************************************************************
* Function Name: Debug_Print()
******************************************************************************
* Summary:
* This function is used to print the logs on the UART.
*
* Parameters:
* uint8 level - Level of the debug message
* uint8 *pszFmt - Message to be print
*
* Return:
* None
*
* Theory:
* The message will be printed if the level specified is above the debug level 
* set during the Debug_Statt()
*
* Side Effects:
* None
*
* Note:
* None
*****************************************************************************/
void Debug_Print(uint8 level, char8 *pszFmt,...)
{
    uint8 *pszVal;
    uint32 iVal, xVal, i = 0, buffer[12], index = 1;
    uint8 cVal;
    uint32 *pArg;
		int32 dbuf;
    pArg =(uint32 *)&pszFmt;
    if(level >= debug_level)
    {
        while(*pszFmt)
        {
            if('%' != *pszFmt)
            {
                Putc(*pszFmt);
                pszFmt++;
                continue;
            }
            pszFmt++;

            if(*pszFmt == 's')
            {
                pszVal = (uint8*)pArg[index++];
                for(; *pszVal != '\0'; pszVal++)
                    Putc(*pszVal);
                pszFmt++;
                continue;
            }
            if(*pszFmt == 'd')
            {
            		dbuf = pArg[index++];
								if(dbuf<0)
									{
										Putc('-');
										iVal = -dbuf;
									}
								else
									iVal = dbuf;
                //iVal = pArg[index++];
                i = 0;
                do{
                    buffer[i++] = iVal % 10;
                    iVal /= 10;
                }while(iVal);
                while(i > 0)
                {
                    i--;
                    Putc(*Byte_To_ASCII(buffer[i]));
                }
                pszFmt++;
                continue;
            }
            if(*pszFmt == 'c')
            {
                cVal = pArg[index++];
                Putc(cVal);
                pszFmt++;
                continue;
            }
            if(*pszFmt == 'x')
            {
                xVal = pArg[index++];
                i = 0;
                do{
                    buffer[i++] = xVal % 16;
                    xVal /= 16;
                }while(xVal);
                if(i%2!=0)
                    buffer[i++]=0;
                if(i<2)
                    buffer[i++]=0;

                while(i > 0)
                {
                    i--;
                    Putc(*Byte_To_ASCII(buffer[i]));
                }
                pszFmt++;
                continue;
            }
            if(pszFmt == '\0')
            {
                break;
            }
        }
    }
}

#endif /* DEBUG */
