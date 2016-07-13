/*******************************************************************************
* File Name: Bootloader_Service_Activation.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Bootloader_Service_Activation_H) /* Pins Bootloader_Service_Activation_H */
#define CY_PINS_Bootloader_Service_Activation_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Bootloader_Service_Activation_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} Bootloader_Service_Activation_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Bootloader_Service_Activation_Read(void);
void    Bootloader_Service_Activation_Write(uint8 value);
uint8   Bootloader_Service_Activation_ReadDataReg(void);
#if defined(Bootloader_Service_Activation__PC) || (CY_PSOC4_4200L) 
    void    Bootloader_Service_Activation_SetDriveMode(uint8 mode);
#endif
void    Bootloader_Service_Activation_SetInterruptMode(uint16 position, uint16 mode);
uint8   Bootloader_Service_Activation_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Bootloader_Service_Activation_Sleep(void); 
void Bootloader_Service_Activation_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Bootloader_Service_Activation__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Bootloader_Service_Activation_DRIVE_MODE_BITS        (3)
    #define Bootloader_Service_Activation_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Bootloader_Service_Activation_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Bootloader_Service_Activation_SetDriveMode() function.
         *  @{
         */
        #define Bootloader_Service_Activation_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Bootloader_Service_Activation_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Bootloader_Service_Activation_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Bootloader_Service_Activation_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Bootloader_Service_Activation_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Bootloader_Service_Activation_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Bootloader_Service_Activation_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Bootloader_Service_Activation_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Bootloader_Service_Activation_MASK               Bootloader_Service_Activation__MASK
#define Bootloader_Service_Activation_SHIFT              Bootloader_Service_Activation__SHIFT
#define Bootloader_Service_Activation_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Bootloader_Service_Activation_SetInterruptMode() function.
     *  @{
     */
        #define Bootloader_Service_Activation_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Bootloader_Service_Activation_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Bootloader_Service_Activation_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Bootloader_Service_Activation_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Bootloader_Service_Activation__SIO)
    #define Bootloader_Service_Activation_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Bootloader_Service_Activation__PC) && (CY_PSOC4_4200L)
    #define Bootloader_Service_Activation_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Bootloader_Service_Activation_USBIO_DISABLE              ((uint32)(~Bootloader_Service_Activation_USBIO_ENABLE))
    #define Bootloader_Service_Activation_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Bootloader_Service_Activation_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Bootloader_Service_Activation_USBIO_ENTER_SLEEP          ((uint32)((1u << Bootloader_Service_Activation_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Bootloader_Service_Activation_USBIO_SUSPEND_DEL_SHIFT)))
    #define Bootloader_Service_Activation_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Bootloader_Service_Activation_USBIO_SUSPEND_SHIFT)))
    #define Bootloader_Service_Activation_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Bootloader_Service_Activation_USBIO_SUSPEND_DEL_SHIFT)))
    #define Bootloader_Service_Activation_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Bootloader_Service_Activation__PC)
    /* Port Configuration */
    #define Bootloader_Service_Activation_PC                 (* (reg32 *) Bootloader_Service_Activation__PC)
#endif
/* Pin State */
#define Bootloader_Service_Activation_PS                     (* (reg32 *) Bootloader_Service_Activation__PS)
/* Data Register */
#define Bootloader_Service_Activation_DR                     (* (reg32 *) Bootloader_Service_Activation__DR)
/* Input Buffer Disable Override */
#define Bootloader_Service_Activation_INP_DIS                (* (reg32 *) Bootloader_Service_Activation__PC2)

/* Interrupt configuration Registers */
#define Bootloader_Service_Activation_INTCFG                 (* (reg32 *) Bootloader_Service_Activation__INTCFG)
#define Bootloader_Service_Activation_INTSTAT                (* (reg32 *) Bootloader_Service_Activation__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Bootloader_Service_Activation_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Bootloader_Service_Activation__SIO)
    #define Bootloader_Service_Activation_SIO_REG            (* (reg32 *) Bootloader_Service_Activation__SIO)
#endif /* (Bootloader_Service_Activation__SIO_CFG) */

/* USBIO registers */
#if !defined(Bootloader_Service_Activation__PC) && (CY_PSOC4_4200L)
    #define Bootloader_Service_Activation_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Bootloader_Service_Activation_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Bootloader_Service_Activation_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Bootloader_Service_Activation_DRIVE_MODE_SHIFT       (0x00u)
#define Bootloader_Service_Activation_DRIVE_MODE_MASK        (0x07u << Bootloader_Service_Activation_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Bootloader_Service_Activation_H */


/* [] END OF FILE */
