/*******************************************************************************
* File Name: MDKInfo.c
*
* Version: 
*
* Description:
*
*
* Hardware Dependency:
* 
*
********************************************************************************
* Copyright 2014-2015, Cypress Semiconductor Corporation. All rights reserved.
* This software is owned by Cypress Semiconductor Corporation and is protected
* by and subject to worldwide patent and copyright laws and treaties.
* Therefore, you may use this software only as provided in the license agreement
* accompanying the software package from which you obtained this software.
* CYPRESS AND ITS SUPPLIERS MAKE NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* WITH REGARD TO THIS SOFTWARE, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT,
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*******************************************************************************/

#if defined(__ARMCC_VERSION)
#include <cytypes.h> 

/* Provide APIs to allow bootloadable to initialize SRAM for BLE without getting stuck in bootloader */
__attribute__ ((section(".bootloaderruntype"), zero_init))
volatile uint32 CyReturnToBootloaddableAddress;
static void CyReturnToBootloaddable(uint32 appAddr);
    
__asm static void CyReturnToBootloaddable(uint32 appAddr)
{
    BX  R0
    ALIGN
}

void _platform_post_lib_init()
{
    uint32 addr;
    if (0u != CyReturnToBootloaddableAddress)
    {
        addr = CyReturnToBootloaddableAddress;
        CyReturnToBootloaddableAddress = 0u;
        CyReturnToBootloaddable(addr);
    }
}


#endif /* __ARMCC_VERSION */

/* [] END OF FILE */
