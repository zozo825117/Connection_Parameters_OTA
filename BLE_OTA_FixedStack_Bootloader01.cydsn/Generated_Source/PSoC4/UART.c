/*******************************************************************************
* File Name: UART.c
* Version 1.50
*
* Description:
*  This file provides the source code to the API for the Software Transmit UART.
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "UART_PVT.h"

#if(UART_PIN_STATIC_MODE == 1u)
    uint32 UART_pinNumber = UART_PIN_NUMBER;
    uint32 UART_pinPortNumber = UART_PIN_PORT_NUMBER;
    #if(CY_PSOC3)
        uint32 pdata UART_pinDrAdress = UART_PIN_DR;
    #else
        uint32 UART_pinDrAdress = UART_PIN_DR;
    #endif /* (CY_PSOC3) */
#else
    uint32 UART_pinNumber;
    uint32 UART_pinPortNumber;
    #if(CY_PSOC3)
        uint32 pdata UART_pinDrAdress;
    #else
        uint32 UART_pinDrAdress;
    #endif /* (CY_PSOC3) */
#endif /* (UART_PIN_STATIC_MODE == 1u) */


#if(UART_PIN_STATIC_MODE == 1u)
    /*******************************************************************************
    * Function Name: UART_Start
    ********************************************************************************
    *
    * Summary:
    *  Empty function. Included for consistency with other
    *  components. This API is not available when PinAssignmentMethod
    *  is set to Dynamic.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void UART_Start(void) 
    {

    }
#else
    /*******************************************************************************
    * Function Name: UART_StartEx
    ********************************************************************************
    *
    * Summary:
    *  Configures the SW Tx UART to use the pin specified
    *  by the parameters. This API is only available when
    *  PinAssignmentMethod is set to Dynamic.
    *
    * Parameters:
    *  port:  Port number for dynamic pin assignment
    *  pin:   Pin number for dynamic pin assignment
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void UART_StartEx(uint8 port, uint8 pin) 
    {
        uint32 portConfigAddr;

        #if (CY_PSOC4)
            uint32 portDataRegAddr;
        #endif /* (CY_PSOC4) */

        if ((pin <= UART_MAX_PIN_NUMBER) && (port <= UART_MAX_PORT_NUMBER))
        {
            #if (!CY_PSOC4)
                portConfigAddr = UART_PORT_CNF_BASE;
                portConfigAddr += ((uint32)port * (UART_MAX_PIN_NUMBER + 1u)) + pin;
                CyPins_SetPinDriveMode(portConfigAddr, CY_PINS_DM_STRONG);
                CyPins_SetPin(portConfigAddr);
                UART_pinDrAdress = portConfigAddr;
            #else
                portConfigAddr = UART_PORT_CNF_BASE + (UART_PORT_CNF_SIZE * port) +
                                                                                UART_PORT_CNF_MODE_OFFSET;
                CY_SYS_PINS_SET_DRIVE_MODE(portConfigAddr, pin, CY_SYS_PINS_DM_STRONG);
                portDataRegAddr = UART_PORT_CNF_BASE + (UART_PORT_CNF_SIZE * port) +
                                                                                UART_PORT_CNF_DR_OFFSET;
                CY_SYS_PINS_SET_PIN(portDataRegAddr, pin);
                UART_pinDrAdress = portDataRegAddr;
            #endif /* (!CY_PSOC4) */
            UART_pinNumber = pin;
            UART_pinPortNumber = port;
        }
    }
#endif /* (UART_PIN_STATIC_MODE == 1u) */


/*******************************************************************************
* Function Name: UART_Stop
********************************************************************************
*
* Summary:
*  Empty function. Included for consistency with other components.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void UART_Stop(void) 
{

}


/*******************************************************************************
* Function Name: UART_PutString
********************************************************************************
*
* Summary:
*  Sends a NULL terminated string via the Tx pin.
*
* Parameters:
*  string: Pointer to the null terminated string to send
*
* Return:
*  None
*
*******************************************************************************/
void UART_PutString(const char8 string[]) 
{
    uint8 stringIndex = 1u;
    char8 current = *string;

    /* Until null is reached, print next character */
    while((char8) '\0' != current)
    {
        UART_PutChar((uint8)current);
        current = string[stringIndex];
        stringIndex++;
    }
}


/*******************************************************************************
* Function Name: UART_PutArray
********************************************************************************
*
* Summary:
*  Sends byteCount bytes from a memory array via the Tx pin.
*
* Parameters:
*  data: Pointer to the memory array
*  byteCount: Number of bytes to be transmitted
*
* Return:
*  None
*
*******************************************************************************/
void UART_PutArray(const uint8 array[], uint32 byteCount) 
{
    uint32 arrayIndex;

    for (arrayIndex = 0u; arrayIndex < byteCount; arrayIndex++)
    {
        UART_PutChar(array[arrayIndex]);
    }
}


/*******************************************************************************
* Function Name: UART_PutHexByte
********************************************************************************
*
* Summary:
*  Sends a byte in Hex representation (two characters, uppercase for A-F) via
*  the Tx pin.
*
* Parameters:
*  TxHexByte: The byte to be converted to ASCII characters and
*             sent via the Tx pin.
*
* Return:
*  None
*
*******************************************************************************/
void UART_PutHexByte(uint8 txHexByte) 
{
    static char8 const CYCODE UART_hex[] = "0123456789ABCDEF";

    UART_PutChar((uint8) UART_hex[txHexByte >> UART_BYTE_UPPER_NIBBLE_SHIFT]);
    UART_PutChar((uint8) UART_hex[txHexByte & UART_BYTE_LOWER_NIBBLE_MASK]);
}


/*******************************************************************************
* Function Name: UART_PutHexInt
********************************************************************************
*
* Summary:
*  Sends a 16-bit unsigned integer in Hex representation (four characters,
*  uppercase for A-F) via the Tx pin.
*
* Parameters:
*  TxHexInt: The uint16 to be converted to ASCII characters and sent via
*            the Tx pin.
*
* Return:
*  None
*
*******************************************************************************/
void UART_PutHexInt(uint16 txHexInt) 
{
    UART_PutHexByte((uint8)(txHexInt >> UART_U16_UPPER_BYTE_SHIFT));
    UART_PutHexByte((uint8)(txHexInt & UART_U16_LOWER_BYTE_MASK));
}


/*******************************************************************************
* Function Name: UART_PutCRLF
********************************************************************************
*
* Summary:
*  Sends a carriage return (0x0D) and a line feed (0x0A) via the Tx pin.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void UART_PutCRLF(void) 
{
    UART_PutChar(0x0Du);
    UART_PutChar(0x0Au);
}


/* [] END OF FILE */
