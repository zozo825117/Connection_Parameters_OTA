/***************************************************************************//**
* \file CYBLE_bts.c
* \version 3.10
* 
* \brief
*  Contains the source code for the Bootloader service.
* 
********************************************************************************
* \copyright
* Copyright 2015-2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "BLE_eventHandler.h"

uint8  cyBle_cmdReceivedFlag = 0u;
uint16 cyBle_cmdLength = 0u;
uint8  *cyBle_btsBuffPtr;

/* Generated code */
const CYBLE_BTSS_T cyBle_btss =
{
    0x001Fu,    /* Handle of the BTS service */
    {
        
        /* Command characteristic */
        {
            0x0021u, /* Handle of the Packet characteristic */ 
            
            /* Array of Descriptors handles */
            {
                0x0022u, /* Handle of the Client Characteristic Configuration descriptor */ 
            }, 
        }, 
    },
};


/******************************************************************************
* Function Name: CyBle_BtsWriteEventHandler
***************************************************************************//**
* 
*  Handles a Write Request event for the Bootloader Service.
* 
*  \param CYBLE_GATTS_WRITE_REQ_PARAM_T * eventParam: The pointer to data that came
*                                              with a Write Request for BTS.
* 
* \return
*  Return a value of type CYBLE_GATT_ERR_CODE_T:
*   * CYBLE_GATT_ERR_NONE - A function finished successfully.
*   * CYBLE_GATT_ERR_INVALID_HANDLE - The Handle of the Bootloader
*                                     Characteristic's Client Configuration
*                                     Characteristic Descriptor is not valid.
*   * CYBLE_GATT_ERR_WRITE_NOT_PERMITTED - Write operation is not permitted on 
*                                          this attribute.
*   * CYBLE_GATT_ERR_UNLIKELY_ERROR - An Internal Stack error occurred.
*   * CYBLE_GATT_ERR_INVALID_OFFSET - Offset value is invalid.
*   * CYBLE_GATT_ERR_REQUEST_NOT_SUPPORTED - The notification property of the
*                                            Bootloader Characteristic's Client
*                                            Configuration Characteristic
*                                            Descriptor is disabled.
******************************************************************************/
CYBLE_GATT_ERR_CODE_T CyBle_BtsWriteEventHandler(CYBLE_GATTS_WRITE_REQ_PARAM_T *eventParam)
{
    CYBLE_GATT_ERR_CODE_T gattErr = CYBLE_GATT_ERR_NONE;
    
    /* Client Characteristic Configuration descriptor Write Request */
    if(eventParam->handleValPair.attrHandle == cyBle_btss.btServiceInfo[0u].btServiceCharDescriptors[0u])
    {
        /* Verify that notification property is enabled for Bootloader Characteristic */
        if(CYBLE_IS_NOTIFICATION_SUPPORTED(cyBle_btss.btServiceInfo[0u].btServiceCharHandle))
        {   
            gattErr = CyBle_GattsWriteAttributeValue(&eventParam->handleValPair, 0u, 
                &eventParam->connHandle, CYBLE_GATT_DB_PEER_INITIATED);
        }
        else
        {
            gattErr = CYBLE_GATT_ERR_REQUEST_NOT_SUPPORTED;
        }

        /* Indicate that request was handled */
        cyBle_eventHandlerFlag &= (uint8)~CYBLE_CALLBACK;
    }
    else if(eventParam->handleValPair.attrHandle == cyBle_btss.btServiceInfo[0u].btServiceCharHandle)
    {
        /* Write value to GATT database */
        gattErr = CyBle_GattsWriteAttributeValue(&eventParam->handleValPair, 0u, 
                &eventParam->connHandle, CYBLE_GATT_DB_PEER_INITIATED);
        
        cyBle_btsBuffPtr = 
                CYBLE_GATT_DB_ATTR_GET_ATTR_GEN_PTR(cyBle_btss.btServiceInfo[0u].btServiceCharHandle);

        /* Extract length of command data and add control bytes to data 
        * length to get command length.
        */
        cyBle_cmdLength = (((uint16)(((uint16) cyBle_btsBuffPtr[CYBLE_BTS_COMMAND_DATA_LEN_OFFSET + 1u]) << 8u)) | 
                            (uint16) cyBle_btsBuffPtr[CYBLE_BTS_COMMAND_DATA_LEN_OFFSET]) +
                                CYBLE_BTS_COMMAND_CONTROL_BYTES_NUM;

        /* Set flag for bootloader to know that command is received from host */
        cyBle_cmdReceivedFlag = 1u;

        /* Indicate that request was handled */
        cyBle_eventHandlerFlag &= (uint8)~CYBLE_CALLBACK;
    }
    else
    {
    }
    
    return(gattErr);
}


/****************************************************************************** 
* Function Name: CyBle_BtssPrepareWriteRequestEventHandler
***************************************************************************//**
* 
*  Handles a Prepare Write Request event for the Bootloader Service.
* 
*  \param CYBLE_GATTS_PREP_WRITE_REQ_PARAM_T *eventParam: The pointer to the data
*                                                  received with a Prepare Write
*                                                  Request event for the
*                                                  Bootloader service.
* 
* \return
*  None.
* 
******************************************************************************/
void CyBle_BtssPrepareWriteRequestEventHandler(const CYBLE_GATTS_PREP_WRITE_REQ_PARAM_T *eventParam)
{
    if(eventParam->baseAddr[0u].handleValuePair.attrHandle == cyBle_btss.btServiceInfo[0u].btServiceCharHandle)
    {
        if(eventParam->currentPrepWriteReqCount == 1u)
        {
            /* Send Prepare Write Response which identifies acknowledgement for
            *  long characteristic value write.
            */
            CyBle_GattsPrepWriteReqSupport(CYBLE_GATTS_PREP_WRITE_SUPPORT);
            
            cyBle_cmdLength = 0u;
        }

        /* Indicate that request was handled */
        cyBle_eventHandlerFlag &= (uint8)~CYBLE_CALLBACK;
    }
}


/****************************************************************************** 
* Function Name: CyBle_BtssExecuteWriteRequestEventHandler
***************************************************************************//**
* 
*  Handles an Execute Write Request event for the Bootloader Service.
* 
*  \param CYBLE_GATTS_EXEC_WRITE_REQ_T *eventParam: The pointer to the data that came 
*                                            with a Write Request for the
*                                            Bootloader service.
* 
* \return
*  None.
* 
******************************************************************************/
void CyBle_BtssExecuteWriteRequestEventHandler(CYBLE_GATTS_EXEC_WRITE_REQ_T *eventParam)
{
    if(eventParam->baseAddr[0u].handleValuePair.attrHandle == cyBle_btss.btServiceInfo[0u].btServiceCharHandle)
    {        
        /* Check the execWriteFlag before execute or cancel write long operation */
        if(eventParam->execWriteFlag == CYBLE_GATT_EXECUTE_WRITE_EXEC_FLAG)
        {
            cyBle_btsBuffPtr = eventParam->baseAddr[0u].handleValuePair.value.val;
            
            /* Extract length of command data and add control bytes to data 
            * length to get command length.
            */
            cyBle_cmdLength = (((uint16)(((uint16) cyBle_btsBuffPtr[CYBLE_BTS_COMMAND_DATA_LEN_OFFSET + 1u]) << 8u)) | 
                                (uint16) cyBle_btsBuffPtr[CYBLE_BTS_COMMAND_DATA_LEN_OFFSET]) +
                                CYBLE_BTS_COMMAND_CONTROL_BYTES_NUM;
            
            if(cyBle_cmdLength > CYBLE_BTS_COMMAND_MAX_LENGTH)
            {
                cyBle_cmdLength = CYBLE_BTS_COMMAND_MAX_LENGTH;
            }

            /* Set flag for bootloader to know that command is received from host */
            cyBle_cmdReceivedFlag = 1u;
        }

        /* Indicate that request was handled */
        cyBle_eventHandlerFlag &= (uint8)~CYBLE_CALLBACK;
    }
}


/******************************************************************************
* Function Name: CyBtldrCommStart
***************************************************************************//**
* 
*  This function does nothing but it is required for code consistency.
* 
*  None.
* 
* \return
*  None.
* 
******************************************************************************/
void CyBLE_CyBtldrCommStart(void)
{
}


/******************************************************************************
* Function Name: CyBtldrCommStop
***************************************************************************//**
* 
*  This function disconnects from the peer device and stops BLE component.
* 
*  None.
* 
* \return
*  None.
* 
******************************************************************************/
void CyBLE_CyBtldrCommStop(void)
{
    /* Initiate disconnection from the peer device*/
    if(CyBle_GapDisconnect(cyBle_connHandle.bdHandle) == CYBLE_ERROR_OK)
    {
        /* Wait for disconnection event */
        while(CyBle_GetState() == CYBLE_STATE_CONNECTED)
        {
            /* Process BLE events */
            CyBle_ProcessEvents();
        }
    }
    /* Stop BLE component */
    CyBle_Stop();
}


/******************************************************************************
* Function Name: CyBtldrCommReset
***************************************************************************//**
* 
*  This function does nothing but it is required for code consistency.
* 
*  None.
* 
* \return
*  None.
* 
******************************************************************************/
void CyBLE_CyBtldrCommReset(void)
{
}


/******************************************************************************
* Function Name: CyBtldrCommWrite
***************************************************************************//**
* 
*  Requests that the provided size (number of bytes) should be written from the
*  input data buffer to the host device. This function in turn invokes the
*  CyBle_GattsNotification() API to sent the data. If a notification is
*  accepted, the function returns CYRET_SUCCESS. The timeOut parameter is ignored
*  in this case.
* 
*  \param data: The pointer to the buffer containing data to be written.
*  \param size: The number of bytes from the data buffer to write.
*  \param count: The pointer to where the BLE component will write the number 
*         of written bytes, generally the same as the size.
*  \param timeOut: Ignored. Used for consistency.
* 
* \return
*  The return value is of type cystatus:
*     * CYRET_SUCCESS - Indicates if a notification is successful.
*     * CYRET_LOCKED - Notifications are disabled.
*     * CYRET_UNKNOWN - Failed to send notification to the host.
* 
******************************************************************************/
cystatus CyBLE_CyBtldrCommWrite(const uint8 data[], uint16 size, uint16 *count, uint8 timeOut)
{
    cystatus locStatus = CYRET_LOCKED;
    uint8 *btCmdCharacteristicPtr;
    CYBLE_GATTS_HANDLE_VALUE_NTF_T ntfParam;

    if(CYBLE_IS_NOTIFICATION_ENABLED(cyBle_btss.btServiceInfo[0u].btServiceCharDescriptors[0u]))
    {
        /* Get pointer to Bootloader Characteristic value to store response there */
        btCmdCharacteristicPtr =
            CYBLE_GATT_DB_ATTR_GET_ATTR_GEN_PTR(cyBle_btss.btServiceInfo[0u].btServiceCharHandle);
        
        /* Prepare and send notification with the bootloader packet emulator
        * response if notifications are enabled.
        */
        (void)memcpy((void *)btCmdCharacteristicPtr, (const void *)data, size);

        /* Fill notification parameters structure to be send with  
        * CyBle_GattsNotification().
        */
        ntfParam.value.len = size;
        ntfParam.value.val = btCmdCharacteristicPtr;
        ntfParam.attrHandle = cyBle_btss.btServiceInfo[0u].btServiceCharHandle;
        
        if(CyBle_GattsNotification(cyBle_connHandle, &ntfParam) == CYBLE_ERROR_OK)
        {
            *count = size;
            locStatus = CYRET_SUCCESS;
        }
        else
        {
            *count = 0u;
            locStatus = CYRET_UNKNOWN;
        }
    }

    /* Unreferenced variable warning workaround */
    if(timeOut != 0u)
    {
    }
    
    return(locStatus);
}


/******************************************************************************
* Function Name: CyBtldrCommRead
***************************************************************************//**
* 
*  Requests that the provided size (number of bytes) is read from the host device
*  and stored in the provided data buffer. Once the read is done, the "count" is
*  endorsed with the number of bytes written. The timeOut parameter is used to
*  provide an upper bound on the time that the function is allowed to operate. If
*  the read completes early, it should return success code as soon as possible.
*  If the read was not successful before the allocated time has expired, it
*  should return an error.
* 
*  \param uint8 *data: The pointer to the buffer to store data from the host controller.
*  \param uint16 size: The number of bytes to read into the data buffer.
*  \param uint16 *count: The pointer to where the BLE component will write the count of the
*                 number of read bytes.
*  \param uint8 timeOut: The amount of time (in units of 10 milliseconds) for which the
*                 BLE component should wait before indicating communications
*                 timed out.
* 
* \return
*  The return value is of type cystatus:
*     * CYRET_SUCCESS - A command was successfully read.
*     * CYRET_BAD_DATA - The size of the command exceeds the buffer.
*     * CYRET_TIMEOUT - The host controller did not respond to the read in 10 
*                       milliseconds * timeOut milliseconds.
* 
* \sideeffect
*  CyBle_ProcessEvents() is called as a part of this function.
* 
******************************************************************************/
cystatus CyBLE_CyBtldrCommRead(uint8 data[], uint16 size, uint16 *count, uint8 timeOut)
{
    uint32 timeoutUs;
    cystatus locStatus = CYRET_TIMEOUT;

    /* Convert from 10ms units to 100us units */
    timeoutUs = ((uint32) 100u * timeOut);
    
    while(0u != timeoutUs)
    {
        /* Process BLE events */
        CyBle_ProcessEvents();
        
        if(cyBle_cmdReceivedFlag == 1u)
        {
            /* Clear command receive flag */
            cyBle_cmdReceivedFlag = 0u;

            if(cyBle_cmdLength < size)
            {
                (void)memcpy((void *) data, (const void *) cyBle_btsBuffPtr, cyBle_cmdLength);

                /* Return actual received command length */
                *count = cyBle_cmdLength;
                
                locStatus = CYRET_SUCCESS;
            }
            else
            {
                data = NULL;
                *count = 0u;
                locStatus = CYRET_BAD_DATA;
            }
            break;
        }
        /* Wait 100 us and update timeout counter */
        CyDelayUs(CYBLE_BTS_TIMEOUT_PERIOD);
        timeoutUs -= CYBLE_BTS_TIMEOUT_PERIOD;
    }
    
    /* Process BLE events */
    CyBle_ProcessEvents();

    return(locStatus);
}


/* [] END OF FILE */
