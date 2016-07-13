/*******************************************************************************
* File Name: Led_Green.h  
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

#if !defined(CY_PINS_Led_Green_ALIASES_H) /* Pins Led_Green_ALIASES_H */
#define CY_PINS_Led_Green_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Led_Green_0			(Led_Green__0__PC)
#define Led_Green_0_PS		(Led_Green__0__PS)
#define Led_Green_0_PC		(Led_Green__0__PC)
#define Led_Green_0_DR		(Led_Green__0__DR)
#define Led_Green_0_SHIFT	(Led_Green__0__SHIFT)
#define Led_Green_0_INTR	((uint16)((uint16)0x0003u << (Led_Green__0__SHIFT*2u)))

#define Led_Green_INTR_ALL	 ((uint16)(Led_Green_0_INTR))


#endif /* End Pins Led_Green_ALIASES_H */


/* [] END OF FILE */
