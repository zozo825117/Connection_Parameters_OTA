/*******************************************************************************
* File Name: Bootloader_Service_Activation.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Bootloader_Service_Activation_ALIASES_H) /* Pins Bootloader_Service_Activation_ALIASES_H */
#define CY_PINS_Bootloader_Service_Activation_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Bootloader_Service_Activation_0			(Bootloader_Service_Activation__0__PC)
#define Bootloader_Service_Activation_0_PS		(Bootloader_Service_Activation__0__PS)
#define Bootloader_Service_Activation_0_PC		(Bootloader_Service_Activation__0__PC)
#define Bootloader_Service_Activation_0_DR		(Bootloader_Service_Activation__0__DR)
#define Bootloader_Service_Activation_0_SHIFT	(Bootloader_Service_Activation__0__SHIFT)
#define Bootloader_Service_Activation_0_INTR	((uint16)((uint16)0x0003u << (Bootloader_Service_Activation__0__SHIFT*2u)))

#define Bootloader_Service_Activation_INTR_ALL	 ((uint16)(Bootloader_Service_Activation_0_INTR))


#endif /* End Pins Bootloader_Service_Activation_ALIASES_H */


/* [] END OF FILE */
