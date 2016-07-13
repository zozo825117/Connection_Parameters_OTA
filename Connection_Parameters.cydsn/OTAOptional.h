/*******************************************************************************
* File Name: OTAOptional.h
*
* Version 1.30
*
* Description:
*  Contains the function prototypes and constants available to the example
*  project. They are optional for OTA functionality.
*
********************************************************************************
* Copyright 2014-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "common.h"
#include "OTAMandatory.h"


extern void InitializeBootloaderSRAM(void);
#if 0
extern const CYBLE_CUSTOMS_T cyBle_customs[1];
extern const CYBLE_HIDSS_T cyBle_hidss[0x01u];
extern const CYBLE_DISS_T cyBle_diss;
extern const CYBLE_BASS_T cyBle_bass[0x01u];
extern const CYBLE_SCPSS_T cyBle_scpss;
#endif
extern volatile uint32 mainTimer;

CY_ISR(Timer_Interrupt);
void WDT_Start(void);
void WDT_Stop(void);
void WDT_Interrupt_StartEx(cyisraddress address);
void PrintProjectHeader(void);

/* [] END OF FILE */
