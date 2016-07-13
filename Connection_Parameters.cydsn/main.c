/*******************************************************************************
* File Name: main.c
*
* Version: 1.0
*
* Description:
*  This is the source code for the BLE connection parameters update request demo
*  project.
*
* Hardware Dependency:
*  CY8CKIT-042 BLE
*
********************************************************************************
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
*******************************************************************************/

/*****************************************************************************
* Included headers
*****************************************************************************/
#include <project.h>
#include "debug.h"
#include "OTAMandatory.h"
/*****************************************************************************
* Connection Parameters structure
*****************************************************************************/
CYBLE_GAP_CONN_UPDATE_PARAM_T connectionParameters1 = 
{
#if 0  
    400,                /* Minimum connection interval - 400 x 1.25 = 500 ms */
    400,                /* Maximum connection interval - 400 x 1.25 = 500 ms */
    1,                  /* Slave latency - 1 */
    500                 /* Supervision timeout - 500 x 10 = 5000 ms */
#endif
    200,                /* Minimum connection interval - 400 x 1.25 = 500 ms */
    220,                /* Maximum connection interval - 400 x 1.25 = 500 ms */
    1,                  /* Slave latency - 1 */
    500                 /* Supervision timeout - 500 x 10 = 5000 ms */
};

CYBLE_GAP_CONN_UPDATE_PARAM_T connectionParameters2 = 
{
    20,                /* Minimum connection interval - 400 x 1.25 = 500 ms */
    45,                /* Maximum connection interval - 400 x 1.25 = 500 ms */
    2,//4,                  /* Slave latency - 1 */
    500                 /* Supervision timeout - 500 x 10 = 5000 ms */
};
CYBLE_GAP_CONN_UPDATE_PARAM_T connectionParameters = 
{
    250,                /* Minimum connection interval - 400 x 1.25 = 500 ms */
    275,                /* Maximum connection interval - 400 x 1.25 = 500 ms */
    0,                  /* Slave latency - 1 */
    500                 /* Supervision timeout - 500 x 10 = 5000 ms */
};

CYBLE_GAP_CONN_UPDATE_PARAM_T currentConnParam;
CYBLE_GAP_CONN_UPDATE_PARAM_T PrintfConnParam;

/*****************************************************************************
* Function Definitions
*****************************************************************************/
#define DEVICE_WATCH_DOG_TIMER_COUNTER0_VALUE            (0xFFFF)

/*****************************************************************************
* Function Name: StackEventHandler()
******************************************************************************
* Summary:
* Event handler for the BLE events processing.
*
* Parameters:
* uint32 eventCode: The event to be processed
* void * eventParam: Pointer to hold the additional information associated 
*                    with an event
*
* Return:
* None
*
* Theory:
* The function is responsible for handling the events generated by the stack.
* In addition to handling general events for BLE advertisement, connection, 
* and disconnection, this function handles the BLE connection parameter
* update response event.
*
* Side Effects:
* None
*
*****************************************************************************/
void StackEventHandler(uint32 eventCode, void * eventParam)
{
    static uint8 ledToggle = 0;
    
    switch(eventCode)
    {
        /* Stack is initialized. Start advertisement. */
        case CYBLE_EVT_STACK_ON:
            Debug_Print(DEBUG_MESSAGE_LEVEL_4,"CYBLE_EVT_STACK_ON\r\n");
            CyBle_GappStartAdvertisement(CYBLE_ADVERTISING_FAST);

            /* Turn OFF all LEDs */
            Led_Red_Write(1);
            Led_Green_Write(1);
            Led_Blue_Write(1);
            break;
            
        /* Advertisement timed out. Restart advertisement. */
        case CYBLE_EVT_GAPP_ADVERTISEMENT_START_STOP:
            Debug_Print(DEBUG_MESSAGE_LEVEL_4,"CYBLE_EVT_GAPP_ADVERTISEMENT_START_STOP\r\n");
            if(CyBle_GetState() == CYBLE_STATE_DISCONNECTED)
            {
                CyBle_GappStartAdvertisement(CYBLE_ADVERTISING_FAST);
            }
            break;
            
        case CYBLE_EVT_GAP_DEVICE_CONNECTED:
            Debug_Print(DEBUG_MESSAGE_LEVEL_4,"CYBLE_EVT_GAP_DEVICE_CONNECTED\r\n");
            if(((CYBLE_GAP_CONN_PARAM_UPDATED_IN_CONTROLLER_T *)eventParam)->status == 0)
            {
                currentConnParam.connIntvMin = ((CYBLE_GAP_CONN_PARAM_UPDATED_IN_CONTROLLER_T *)eventParam)->connIntv;
                currentConnParam.connIntvMax = ((CYBLE_GAP_CONN_PARAM_UPDATED_IN_CONTROLLER_T *)eventParam)->connIntv;
                currentConnParam.connLatency = ((CYBLE_GAP_CONN_PARAM_UPDATED_IN_CONTROLLER_T *)eventParam)->connLatency;
                currentConnParam.supervisionTO = ((CYBLE_GAP_CONN_PARAM_UPDATED_IN_CONTROLLER_T *)eventParam)->supervisionTO;
            }
						Debug_Print(DEBUG_MESSAGE_LEVEL_4,"connIntv = %d us \r\n",currentConnParam.connIntvMin * 1000* 5u /4u);
						Debug_Print(DEBUG_MESSAGE_LEVEL_4,"connLatency = %d  \r\n",currentConnParam.connLatency);
						Debug_Print(DEBUG_MESSAGE_LEVEL_4,"supervisionTO = %d  \r\n",currentConnParam.supervisionTO);
            break;
            
        /* Device is disconnected. Restart advertisement. */
        case CYBLE_EVT_GAP_DEVICE_DISCONNECTED:
            CyBle_GappStartAdvertisement(CYBLE_ADVERTISING_FAST);

            /* Turn OFF all LEDs */
            Led_Red_Write(1);
            Led_Green_Write(1);
            Led_Blue_Write(1);
            break;

            
        /* This event is generated when a response is received for the 
         * connection parameter update request.
         * If the request is accepted by the Master, one of the Green and Blue
         * LEDs is turned ON. Each time the SW2 switch is pressed, a new request
         * is sent to the Master, and upon every acceptance, the LED toggles 
         * between Green and Blue color.
         * If the request is rejected by the Master, the Green and Blue LEDs are
         * turned OFF and the Red LED is turned ON.
         */
        case CYBLE_EVT_L2CAP_CONN_PARAM_UPDATE_RSP:
            Debug_Print(DEBUG_MESSAGE_LEVEL_4,"CYBLE_EVT_L2CAP_CONN_PARAM_UPDATE_RSP\r\n");
            if(*(uint8 *)eventParam == 0x00)
            {
                /* Connection parameter update request accepted by Master */
                Debug_Print(DEBUG_MESSAGE_LEVEL_4,"accepted\r\n");
                /* Turn OFF Red LED */
                Led_Red_Write(1);
                
                /* Toggle between Green and Blue LED */
                if(ledToggle == 0)
                {
                    ledToggle = 1;
                    Led_Blue_Write(1);
                    Led_Green_Write(0);
                }
                else if(ledToggle == 1)
                {
                    ledToggle = 0;
                    Led_Green_Write(1);
                    Led_Blue_Write(0);
                }
            }
            else if(*(uint8 *)eventParam == 0x01)
            {
                /* Connection parameter update request rejected by Master */
                Debug_Print(DEBUG_MESSAGE_LEVEL_4,"rejected\r\n");
                /* Turn ON Red LED; Turn OFF Green and Blue LEDs */
                Led_Green_Write(1);
                Led_Blue_Write(1);
                Led_Red_Write(0);
            }
            break;
            
        case CYBLE_EVT_GAP_CONNECTION_UPDATE_COMPLETE:
						Debug_Print(DEBUG_MESSAGE_LEVEL_4,"CYBLE_EVT_GAP_CONNECTION_UPDATE_COMPLETE\r\n");
            if(((CYBLE_GAP_CONN_PARAM_UPDATED_IN_CONTROLLER_T *)eventParam)->status == 0)
            {
                currentConnParam.connIntvMin = ((CYBLE_GAP_CONN_PARAM_UPDATED_IN_CONTROLLER_T *)eventParam)->connIntv;
                currentConnParam.connIntvMax = ((CYBLE_GAP_CONN_PARAM_UPDATED_IN_CONTROLLER_T *)eventParam)->connIntv;
                currentConnParam.connLatency = ((CYBLE_GAP_CONN_PARAM_UPDATED_IN_CONTROLLER_T *)eventParam)->connLatency;
                currentConnParam.supervisionTO = ((CYBLE_GAP_CONN_PARAM_UPDATED_IN_CONTROLLER_T *)eventParam)->supervisionTO;
								Debug_Print(DEBUG_MESSAGE_LEVEL_4,"connIntv = %d us \r\n",currentConnParam.connIntvMin * 1000* 5u /4u);
								Debug_Print(DEBUG_MESSAGE_LEVEL_4,"connLatency = %d  \r\n",currentConnParam.connLatency);
								Debug_Print(DEBUG_MESSAGE_LEVEL_4,"supervisionTO = %d  \r\n",currentConnParam.supervisionTO);

						}

            break;
        case CYBLE_EVT_GAP_AUTH_FAILED:
						Debug_Print(DEBUG_MESSAGE_LEVEL_4,"CYBLE_EVT_GAP_AUTH_FAILED\r\n");
            /* Remote the Bond information if the AUTH failed */
            if((*(CYBLE_GAP_AUTH_FAILED_REASON_T *)eventParam == CYBLE_GAP_AUTH_ERROR_INSUFFICIENT_ENCRYPTION_KEY_SIZE) || 
                (*(CYBLE_GAP_AUTH_FAILED_REASON_T *)eventParam == CYBLE_GAP_AUTH_ERROR_CONFIRM_VALUE_NOT_MATCH))
            {
            }
            break;
            
        case CYBLE_EVT_GAP_AUTH_COMPLETE:    
						Debug_Print(DEBUG_MESSAGE_LEVEL_4,"CYBLE_EVT_GAP_AUTH_COMPLETE\r\n");
#ifndef DISABLE_BLE_ENCYRPTION
            //isAuthCompleted = true;
#endif /* DISABLE_BLE_ENCYRPTION */

            if(((CYBLE_GAP_AUTH_INFO_T *)eventParam)->bonding)
            {

            }

            break;  
        default:
            break;
    }
}


/*****************************************************************************
* Function Name: UserSwitchIsr()
******************************************************************************
* Summary:
* ISR for the user switch GPIO interrupt.
*
* Parameters:
* None
*
* Return:
* None
*
* Theory:
* This ISR is triggered everytime the SW2 switch is pressed on the
* CY8CKIT-042 BLE Pioneer Kit. If the device is connected to a peer BLE device,
* a connection parameter update request is sent to the peer device. The 
* parameters are defined in the structure 'connectionParameters' defined above 
* in this file.
*
* Side Effects:
* None
*
*****************************************************************************/
CY_ISR(UserSwitchIsr)
{
    /* On every switch press, if the device is connected, send a BLE
     * connection parameter update request. 
     */
  
  CYBLE_API_RESULT_T api_result;

  Debug_Print(DEBUG_MESSAGE_LEVEL_4,"KEY IS ON\r\n");
    if(CyBle_GetState() == CYBLE_STATE_CONNECTED)
    {
        /* The parameters to the API are  - 
         * 1. Peer device's BD handle
         * 2. Pointer to 'connectionParameters' structure defined in this file
         */
        Debug_Print(DEBUG_MESSAGE_LEVEL_4,"ParamUpdateRequest IS start\r\n");
        Debug_Print(DEBUG_MESSAGE_LEVEL_4,"addr is = %x\r\n",&CyBle_L2capLeConnectionParamUpdateRequest);
        //key_state = 1;
        api_result = CyBle_L2capLeConnectionParamUpdateRequest(cyBle_connHandle.bdHandle, &connectionParameters);
        Debug_Print(DEBUG_MESSAGE_LEVEL_4,"ParamUpdateresult is = %d\r\n",api_result);
    }
    
    /* Clear pending interrupt */
    SW2_ClearInterrupt();
}

void Watch_Dog_Timer_Init(uint32 counter0Value)
{
    CySysWdtUnlock();
    /* Changing the WDT clock to WCO for this Application */
    CySysWdtWriteMode(CY_SYS_WDT_COUNTER0, CY_SYS_WDT_MODE_INT_RESET);
    CySysWdtWriteMatch(CY_SYS_WDT_COUNTER0, counter0Value);
    CySysWdtWriteClearOnMatch(CY_SYS_WDT_COUNTER0, 1u);

    /* Enable WDT counters 0 and 1 */
    CySysWdtEnable(CY_SYS_WDT_COUNTER0_MASK);
    CySysWdtLock();
}

void Watch_Dog_Timer_Clear(void)
{
    CySysWdtUnlock();
    CySysWdtResetCounters(CY_SYS_WDT_COUNTER0_RESET);
    CySysWdtLock();
}
volatile uint32 SysTickTimer = 0,LastTimer;
uint8 InterruptHpn;
CY_ISR(InterruptHandler)
{
    /* Check interrupt source and clear Inerrupt */
    InterruptHpn = TCPWM_1_GetInterruptSourceMasked();
   	if (InterruptHpn == TCPWM_1_INTR_MASK_CC_MATCH)
    {
        TCPWM_1_ClearInterrupt(TCPWM_1_INTR_MASK_CC_MATCH);      
        //test_1_Write(~ test_1_Read());
    }
    else
    {
        TCPWM_1_ClearInterrupt(TCPWM_1_INTR_MASK_TC);
        //test_2_Write(~ test_2_Read());
				SysTickTimer++;
				 //Debug_Print(DEBUG_MESSAGE_LEVEL_4,"SysTickTimer is = %d\r\n",SysTickTimer);
    }
}
/*****************************************************************************
* Function Name: main()
******************************************************************************
* Summary:
* Main function for the application.
*
* Parameters:
* None
*
* Return:
* None
*
* Theory:
* This function initializes the BLE component and the SW2 switch interrupt, 
* and then processes the BLE events routinely, while also implementing low
* power in the system.
*
* Side Effects:
* None
*
*****************************************************************************/
int main()
{
    CYBLE_LP_MODE_T bleState;
    uint8 interruptStatus;
    CYBLE_API_RESULT_T api_result;
    static uint16 interval = 0; 
    static uint16 Latency = 0;
		
#if !defined(__ARMCC_VERSION)
    InitializeBootloaderSRAM();
#endif  
    /* Enable global interrupts */
    CyGlobalIntEnable; 


    /* Start BLE component */
    CyBle_Start(StackEventHandler);
    
    /* Configure User switch interrupt */
   // SW2_Interrupt_StartEx(UserSwitchIsr);
    
    Debug_Print_Start(DEBUG_MESSAGE_LEVEL_4);
    Debug_Print(DEBUG_MESSAGE_LEVEL_4,"This is the source code for the BLE connection parameters update request demo\r\n");
    Watch_Dog_Timer_Init(DEVICE_WATCH_DOG_TIMER_COUNTER0_VALUE);
    
		/* Enable the Interrupt component connected to interrupt */
		tc_isr_1_StartEx(InterruptHandler);
		
		/* Start the components*/ 
		TCPWM_1_Start();  
    
    for(;;)
    {
      Watch_Dog_Timer_Clear();
        /* Routinely called every connection interval to process
         * pending BLE events. */
        CyBle_ProcessEvents();
        
        
        /* Low Power Implementation with BLE */
        //bleState = CyBle_EnterLPM(CYBLE_BLESS_DEEPSLEEP);
        interruptStatus = CyEnterCriticalSection();
        if(bleState == CYBLE_BLESS_DEEPSLEEP)
        {
            if((CyBle_GetBleSsState() == CYBLE_BLESS_STATE_ECO_ON) || 
               (CyBle_GetBleSsState() == CYBLE_BLESS_STATE_DEEPSLEEP))
            {
                //CySysPmDeepSleep();
            }
        }
        else
        {
            if(CyBle_GetBleSsState() != CYBLE_BLESS_STATE_EVENT_CLOSE)
            {
                CySysPmSleep();
            }
            
            if(CyBle_GetState() == CYBLE_STATE_CONNECTED)
            {
                    if(SysTickTimer - LastTimer > 100) // 10s
                    {
                      //Debug_Print(DEBUG_MESSAGE_LEVEL_4,"LastTimer is = %d\r\n",LastTimer);
        			        //Debug_Print(DEBUG_MESSAGE_LEVEL_4,"connIntv = %d us \r\n",connectionParameters.connIntvMin * 1000* 5u /4u);
      								//Debug_Print(DEBUG_MESSAGE_LEVEL_4,"connLatency = %d  \r\n",connectionParameters.connLatency);
      								//Debug_Print(DEBUG_MESSAGE_LEVEL_4,"supervisionTO = %d  \r\n",connectionParameters.supervisionTO);
                      
                      //api_result = CyBle_L2capLeConnectionParamUpdateRequest(cyBle_connHandle.bdHandle, &connectionParameters);
                      //Debug_Print(DEBUG_MESSAGE_LEVEL_4,"ParamUpdateresult is = %d\r\n",api_result);
                      #if 0
                      interval +=6;
                        
                      if(interval>500)
                      {
                       interval = 10; 
                       Latency +=1;
                      }
                  
                      connectionParameters.connIntvMax =interval;
                      connectionParameters.connIntvMin =interval;
                      connectionParameters.connLatency =Latency;
                      #endif
                      
                      if(currentConnParam.connIntvMin < PrintfConnParam.connIntvMin || currentConnParam.connIntvMin > PrintfConnParam.connIntvMax\
                        || (currentConnParam.connLatency != PrintfConnParam.connLatency))
                      {
                        Debug_Print(DEBUG_MESSAGE_LEVEL_4,"last time updata failed\r\n");
                      }
                      else
                      {
                        Debug_Print(DEBUG_MESSAGE_LEVEL_4,"last time updata ok\r\n");
                      }
                      
                      if(interval==0)
                      {
                        Debug_Print(DEBUG_MESSAGE_LEVEL_4,"0 step\r\n");
                        PrintfConnParam.connIntvMax =connectionParameters.connIntvMax;
                        PrintfConnParam.connIntvMin =connectionParameters.connIntvMin;
                        PrintfConnParam.connLatency =connectionParameters.connLatency; 
                        api_result = CyBle_L2capLeConnectionParamUpdateRequest(cyBle_connHandle.bdHandle, &connectionParameters);
                        Debug_Print(DEBUG_MESSAGE_LEVEL_4,"ParamUpdateresult is = %d\r\n",api_result);
                      }
                      else if(interval==1)
                      {
                        Debug_Print(DEBUG_MESSAGE_LEVEL_4,"1 step\r\n");
                        PrintfConnParam.connIntvMax =connectionParameters1.connIntvMax;
                        PrintfConnParam.connIntvMin =connectionParameters1.connIntvMin;
                        PrintfConnParam.connLatency =connectionParameters1.connLatency; 
                        api_result = CyBle_L2capLeConnectionParamUpdateRequest(cyBle_connHandle.bdHandle, &connectionParameters1);
                        Debug_Print(DEBUG_MESSAGE_LEVEL_4,"ParamUpdateresult is = %d\r\n",api_result);
                      }
                      else if(interval==2)
                      {
                        Debug_Print(DEBUG_MESSAGE_LEVEL_4,"2 step\r\n");
                        PrintfConnParam.connIntvMax =connectionParameters2.connIntvMax;
                        PrintfConnParam.connIntvMin =connectionParameters2.connIntvMin;
                        PrintfConnParam.connLatency =connectionParameters2.connLatency; 
                        api_result = CyBle_L2capLeConnectionParamUpdateRequest(cyBle_connHandle.bdHandle, &connectionParameters2);
                        Debug_Print(DEBUG_MESSAGE_LEVEL_4,"ParamUpdateresult is = %d\r\n",api_result);

                        
                      }
                      
                      interval++;
                      if(interval == 3)interval = 0;
                        
        			        Debug_Print(DEBUG_MESSAGE_LEVEL_4,"print connIntv = %d us \r\n",PrintfConnParam.connIntvMin * 1000* 5u /4u);
      								Debug_Print(DEBUG_MESSAGE_LEVEL_4,"print connLatency = %d  \r\n",PrintfConnParam.connLatency);
      								Debug_Print(DEBUG_MESSAGE_LEVEL_4,"print supervisionTO = %d  \r\n",PrintfConnParam.supervisionTO);
                      
                    
                      LastTimer = SysTickTimer;    
                    }
            }            
            
            
        }
        CyExitCriticalSection(interruptStatus);

        
    }
}

/* [] END OF FILE */
