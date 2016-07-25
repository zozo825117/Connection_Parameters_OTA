/*******************************************************************************
* File Name: OTAMandatory.h
*
* Version 1.30
*
* Description:
*  Contains the function prototypes and constants available to the example
*  project. They are mandatory for OTA functionality.
*
********************************************************************************
* Copyright 2014-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/
#include <cytypes.h>

#ifndef SHARED_BLE_HEADER
#define SHARED_BLE_HEADER
/* This section contains #defines, enums, functions prototypes collected across BLE component
 * source code
 */  

typedef struct
{
    /* Pointer to the value to be packed */
    uint8*   val;

    /* Length of Value to be packed */
    uint16   len;

    /* Out Parameter Indicating Actual Length Packed. Actual length
       can be less than or equal to the 'len' parameter value. */
    uint16   actualLen;

}CYBLE_GATT_VALUE_T;

/* Common error codes received as API result */
typedef enum
{
    /* No Error occurred */
    CYBLE_ERROR_OK = 0x00u,
    
    /* At least one of the input parameters is invalid */
    CYBLE_ERROR_INVALID_PARAMETER,
    
    /* Operation is not permitted */
    CYBLE_ERROR_INVALID_OPERATION,
    
    /* An internal error occurred in the stack */
    CYBLE_ERROR_MEMORY_ALLOCATION_FAILED,
    
    /* Insufficient resources to perform requested operation */
    CYBLE_ERROR_INSUFFICIENT_RESOURCES,
    
    /* OOB data not available */
    CYBLE_ERROR_OOB_NOT_AVAILABLE,
    
    /* Connection is required to perform requested operation. Connection not 
       present */
    CYBLE_ERROR_NO_CONNECTION,
    
    /* No device entity to perform requested operation */
    CYBLE_ERROR_NO_DEVICE_ENTITY,
    
    /* Attempted repeat operation is not allowed */
    CYBLE_ERROR_REPEATED_ATTEMPTS,
    
    /* GAP role is incorrect */
    CYBLE_ERROR_GAP_ROLE,
    
    /* Error reading TC power */
    CYBLE_ERROR_TX_POWER_READ,
    
    /* BLE Initialization failed */
    CYBLE_ERROR_BT_ON_NOT_COMPLETED,
    
    /* Security operation failed */
    CYBLE_ERROR_SEC_FAILED,

    /*L2CAP error codes*/
    
    /* L2CAP PSM encoding is incorrect */
    CYBLE_ERROR_L2CAP_PSM_WRONG_ENCODING = 0x0Du,
    
    /* L2CAP PSM has already been registered */
    CYBLE_ERROR_L2CAP_PSM_ALREADY_REGISTERED,
    
    /* L2CAP PSM has not been registered */
    CYBLE_ERROR_L2CAP_PSM_NOT_REGISTERED,
    
    /* L2CAPconnection entity not found */
    CYBLE_ERROR_L2CAP_CONNECTION_ENTITY_NOT_FOUND,
    
    /* L2CAP channel not found */
    CYBLE_ERROR_L2CAP_CHANNEL_NOT_FOUND,
    
    /* L2CAP not enough credits */
    CYBLE_ERROR_L2CAP_NOT_ENOUGH_CREDITS,
    
    /* Specified PSM is out of range */
    CYBLE_ERROR_L2CAP_PSM_NOT_IN_RANGE,

    /*GATT DB error codes*/
    
    /* Invalid offset specified while accessing the GATT Database */
    CYBLE_ERROR_GATT_DB_INVALID_OFFSET = 0x14u,
    
    /* NULL parameter is not allowed for this operation on the GATT Database */
    CYBLE_ERROR_GATT_DB_NULL_PARAMETER_NOT_ALLOWED,
    
    /* Unsupported group type specified */
    CYBLE_ERROR_GATT_DB_UNSUPPORTED_GROUP_TYPE,
    
    /* Insufficient buffer length */
    CYBLE_ERROR_GATT_DB_INSUFFICIENT_BUFFER_LEN,
    
    /* More matching results found */
    CYBLE_ERROR_GATT_DB_MORE_MATCHING_RESULT_FOUND,
    
    /* No matching result */
    CYBLE_ERROR_GATT_DB_NO_MATCHING_RESULT,
    
    /* Specified handle is not found in the GATT Database */
    CYBLE_ERROR_GATT_DB_HANDLE_NOT_FOUND,
    
    /* Specified handle is out of range */
    CYBLE_ERROR_GATT_DB_HANDLE_NOT_IN_RANGE,
    
    /* Specified handle is in group range */
    CYBLE_ERROR_GATT_DB_HANDLE_IN_GROUP_RANGE,
    
    /* Invalid operation on the GATT Database */
    CYBLE_ERROR_GATT_DB_INVALID_OPERATION,
    
    /* Specified UUID is not in Bluetooth address space */
    CYBLE_ERROR_GATT_DB_UUID_NOT_IN_BT_SPACE,
    
    /* Invalid attribute handle */
    CYBLE_ERROR_GATT_DB_INVALID_ATTR_HANDLE,
    
    /* Cannot access attribute due to insufficient security */
    CYBLE_ERROR_GATT_DB_INSUFFICIENT_SECURITY,
    
    /* Cannot access attribute due to insufficient encryption key size */
    CYBLE_ERROR_GATT_DB_INSUFFICIENT_ENC_KEY_SIZE,
    
    /* Invalid instance */
    CYBLE_ERROR_GATT_DB_INVALID_INSTANCE,
    
    /* Incorrect UUID format */
    CYBLE_ERROR_GATT_DB_INCORRECT_UUID_FRMT,
    
    /* Specified UUID format is not supported */
    CYBLE_ERROR_GATT_DB_UUID_FRMT_UNSUPPORTED,
    
    /* Type mismatch */
    CYBLE_ERROR_GATT_DB_TYPE_MISMATCH,
    
    /* Cannot access attribute due to insufficient encryption */
    CYBLE_ERROR_GATT_DB_INSUFFICIENT_ENCRYPTION,
    
    /* Other Codes.  */
    
    /* Device cannot be added to whitelist as it has already been added */
    CYBLE_ERROR_DEVICE_ALREADY_EXISTS = 0x27u,
    
    /* Write to flash is not permitted */
    CYBLE_ERROR_FLASH_WRITE_NOT_PERMITED = 0x28u,
    
	CYBLE_ERROR_MIC_AUTH_FAILED = 0x29u,	
    
    /* All other errors not covered in the above list map to this error code */
    CYBLE_ERROR_MAX = 0xFFu,
    
    /* DOM-IGNORE-BEGIN */
    /* Profile level API_RESULT codes will be here */
    CYBLE_INCL_DISC_DONE,
    CYBLE_CHAR_DISC_DONE,
    CYBLE_DESCR_DISC_DONE,
    CYBLE_ERROR_NTF_DISABLED,
    CYBLE_ERROR_IND_DISABLED,
    CYBLE_ERROR_CHAR_IS_NOT_DISCOVERED,
    CYBLE_ERROR_INVALID_STATE
    /* DOM-IGNORE-END */
}CYBLE_API_RESULT_T;

/* Bluetooth Device Address size  */
#define CYBLE_GAP_BD_ADDR_SIZE              0x06u

/* Bluetooth Device Address  */
typedef struct
{
    uint8     bdAddr[CYBLE_GAP_BD_ADDR_SIZE]; /* Bluetooth device address */
    uint8     type; /*public = 0, Random = 1*/
}CYBLE_GAP_BD_ADDR_T;

/* Authentication Failed Error Codes */
typedef enum
{
	/* No Error */
	CYBLE_GAP_AUTH_ERROR_NONE  = 0x00u,

	/* User input of passkey failed, for example, the user cancelled the operation */
	CYBLE_GAP_AUTH_ERROR_PASSKEY_ENTRY_FAILED,

	/* Out Of Band data is not available, applicable if NFC is supported */
	CYBLE_GAP_AUTH_ERROR_OOB_DATA_NOT_AVAILABLE,

	/* Pairing procedure cannot be performed as authentication
       requirements cannot be met due to IO capabilities of one or both devices. */
	CYBLE_GAP_AUTH_ERROR_AUTHENTICATION_REQ_NOT_MET,

	/* Confirm value does not match the calculated compare value  */
	CYBLE_GAP_AUTH_ERROR_CONFIRM_VALUE_NOT_MATCH,

	/* Pairing is not supported by the device */
	CYBLE_GAP_AUTH_ERROR_PAIRING_NOT_SUPPORTED,

	/* Insufficient key size for the security requirements of this device */
	CYBLE_GAP_AUTH_ERROR_INSUFFICIENT_ENCRYPTION_KEY_SIZE,

	/* command received is not supported */
	CYBLE_GAP_AUTH_ERROR_COMMAND_NOT_SUPPORTED,

	/* Pairing failed due to an unspecified reason */
	CYBLE_GAP_AUTH_ERROR_UNSPECIFIED_REASON,

	/* Pairing or authentication procedure is disallowed because too little time
 	   has elapsed since last pairing request or security request. */
	CYBLE_GAP_AUTH_ERROR_REPEATED_ATTEMPTS,

	/* Invalid Parameters in Request - Invalid Command length and Parameter value outside range */
	CYBLE_GAP_AUTH_ERROR_INVALID_PARAMETERS = 0x0Au,

	/* Authentication process timeout */
	CYBLE_GAP_AUTH_ERROR_AUTHENTICATION_TIMEOUT = 0x15u,

	/* Link disconnected */
	CYBLE_GAP_AUTH_ERROR_LINK_DISCONNECTED = 0x18u
	
}CYBLE_GAP_AUTH_FAILED_REASON_T;


/* Authentication Parameters Information  */
typedef struct 
{
	/* Security Mode setting will be as follows:
	    * (CYBLE_GAP_SEC_MODE_1 | CYBLE_GAP_SEC_LEVEL_1)
	    * (CYBLE_GAP_SEC_MODE_1 | CYBLE_GAP_SEC_LEVEL_2)
	    * (CYBLE_GAP_SEC_MODE_1 | CYBLE_GAP_SEC_LEVEL_3)
	    * (CYBLE_GAP_SEC_MODE_2 | CYBLE_GAP_SEC_LEVEL_2)
	    * (CYBLE_GAP_SEC_MODE_2 | CYBLE_GAP_SEC_LEVEL_3)
	 */
    uint8    						security;     

	/* Bonding type setting:
	     * CYBLE_GAP_BONDING_NONE
	     * CYBLE_GAP_BONDING
	 */
    uint8    						bonding;      

	/* Encryption Key Size (octets)
	     * Minimum = 7 
	     * maximum = 16
     */
	uint8    						ekeySize;  

 	/* Parameter to say it authentication is accepted or rejected with reason.
	   accepted = CYBLE_GAP_AUTH_ERROR_NONE or error code CYBLE_GAP_AUTH_FAILED_REASON_T. */	
	CYBLE_GAP_AUTH_FAILED_REASON_T    	authErr;	    
	
} CYBLE_GAP_AUTH_INFO_T;

/* Host stack events.
   * Generic events: 0x01 to 0x1F
   * GAP events: 0x20 to 0x3F
   * GATT events: 0x40 to 6F
   * L2AP events: 0x70 to 0x7F  
   * Future use: 0x80 to 0xFF
*/
typedef enum
{
    /** This event is triggered by BLE stack when stack is in a bad state, Restarting stack is the 
	only way to get out of the state */
    CYBLE_EVT_HOST_INVALID = 0x00u,

    /* Range for Generic events - 0x01 to 0x1F */

    /** This event is received when BLE stack is initialized and turned ON by invoking CyBle_StackInit () function.*/
    CYBLE_EVT_STACK_ON = 0x01u,

    /** This event is received when there is a timeout and application needs to handle the event. 
       Timeout reason is defined by CYBLE_TO_REASON_CODE_T. */
    CYBLE_EVT_TIMEOUT,

    /** This event indicates that some internal hardware error has occurred. Reset of the hardware may be required. */
    CYBLE_EVT_HARDWARE_ERROR,

    /** This event is triggered by 'Host Stack' if 'Controller' responds with an error code for any HCI command.
       Event parameter returned will be an HCI error code as defined in Bluetooth 4.1 core specification, Volume 2,
       Part D, section 1.3. This event will be received only if there is an error. */
    CYBLE_EVT_HCI_STATUS,

    /** This event is triggered by host stack if BLE stack is busy or not. 
       Event Parameter corresponding to this event will indicate the state of BLE stack's internal protocol buffers
       for the application to safely initiate data transactions (GATT, GAP Security, and L2CAP transactions)
       with the peer BLE device.
       Event parameter is of type uint8.

        * CYBLE_STACK_STATE_BUSY (0x01) = CYBLE_STACK_STATE_BUSY indicates application that BLE stack's internal buffers
        *                   are about to be filled, and the remaining buffers are required to respond peer BLE device
        *                   After this event, application shall not initiate (GATT, GAP Security and L2CAP data transactions). 
        *                   However application shall respond to peer initiated transactions to prevent BLE protocol timeouts
        *                   to occur.
        *                   Application initiated data transactions can be resumed after CYBLE_EVT_STACK_BUSY_STATUS
        *                   event with parameter 'CYBLE_STACK_STATE_FREE' is received.
        *
        * CYBLE_STACK_STATE_FREE (0x00) = CYBLE_STACK_STATE_FREE indicates application that pending transactions are completed
        *                   and sufficient buffers are available to process application initiated transactions.
        *                   The 'CYBLE_EVT_STACK_BUSY_STATUS' event with 'CYBLE_STACK_STATE_FREE' is indicated to 
        *                   application if BLE Stack's internal buffer state has transitioned from 'CYBLE_STACK_STATE_BUSY'
        *                   to 'CYBLE_STACK_STATE_FREE'.
        *
       To increase BLE stack's internal buffers count and achieve better throughput for attribute MTU greater then 32, 
       use MaxAttrNoOfBuffer parameter in the Expression view of the Advanced tab.    
    */
    CYBLE_EVT_STACK_BUSY_STATUS,
	
	/** This event is received when stack wants application to provide memory to process remote request.
       Event parameter is of type CYBLE_MEMORY_REQUEST_T.
       This event is automatically handled by the component for the CYBLE_PREPARED_WRITE_REQUEST request. 
       The component allocates sufficient memory for the long write request with assumption that attribute MTU size 
       is negotiated to the minimum possible value. Application could use dynamic memory allocation to save static 
       RAM memory consumption. To enable this event for application level, set EnableExternalPrepWriteBuff parameter
       in the Expression view of the Advanced tab to the true.    
    */
	CYBLE_EVT_MEMORY_REQUEST,

    /* Range for GAP events - 0x20 to 0x3F */

    /** This event is triggered every time a device is discovered; pointer to structure of type CYBLE_GAPC_ADV_REPORT_T 
        is returned as the event parameter. */
    CYBLE_EVT_GAPC_SCAN_PROGRESS_RESULT = 0x20u,

    /** This event is received by Peripheral and Central devices. When it is received by Peripheral, peripheral 
        needs to Call CyBle_GappAuthReqReply() to reply to authentication request from Central.

        When this event is received by Central, that means the slave has requested Central to initiate authentication
        procedure. Central needs to call CyBle_GappAuthReq() to initiate authentication procedure.
        Pointer to structure of type CYBLE_GAP_AUTH_INFO_T is returned as the event parameter. */
    CYBLE_EVT_GAP_AUTH_REQ,

    /** This event indicates that the device has to send passkey to be used during the pairing procedure. 
       CyBle_GapAuthPassKeyReply() is required to be called with valid parameters on receiving this event.

       Refer to Bluetooth Core Spec. 4.1, Part H, Section 2.3.5.1 Selecting STK Generation Method.

       Nothing is returned as part of the event parameter. */
    CYBLE_EVT_GAP_PASSKEY_ENTRY_REQUEST,

    /** This event indicates that the device needs to display passkey during the pairing procedure.

       Refer to Bluetooth Core Spec. 4.1, Part H, Section 2.3.5.1 Selecting STK Generation Method.

       Pointer to data of type 'uint32' is returned as part of the event parameter. Passkey can
       be any 6-decimal-digit value. */
    CYBLE_EVT_GAP_PASSKEY_DISPLAY_REQUEST,

     /** This event indicates that the authentication procedure has been completed.

     The event parameter contains the security information as defined by CYBLE_GAP_AUTH_INFO_T.
     This event is generated at the end of the following three operations:
    	* Authentication is initiated with a newly connected device
    	* Encryption is initiated with a connected device that is already bonded
    	* Re-Encryption is initiated with a connected device with link already encrypted
     During encryption/re-encryption, the Encryption Information exchanged during the pairing process
     is used to encrypt/re-encrypt the link. As this does not modify any of the authentication 
     parameters with which the devices were paired, this event is generated with NULL event data
     and the result of the encryption operation. */
    CYBLE_EVT_GAP_AUTH_COMPLETE,

    /** Authentication process failed between two devices. The return value of type 
       CYBLE_GAP_AUTH_FAILED_REASON_T indicates the reason for failure. */
    CYBLE_EVT_GAP_AUTH_FAILED,

    /** Peripheral device has started/stopped advertising. 
       This event is generated after making a call to CyBle_GappEnterDiscoveryMode and 
       CyBle_GappExitDiscoveryMode functions. The event parameter contains the status
       which is of type 'uint8'.
       
       If the data is '0x00', it indicates 'success'; Anything else indicates 'failure'. */
    CYBLE_EVT_GAPP_ADVERTISEMENT_START_STOP,
    
    /** This event is generated at the GAP Peripheral end after connection is completed with peer Central device.
    	For GAP Central device, this event is generated as in acknowledgment of receiving this event successfully
    	by BLE Controller. Once connection is done, no more event is required but if fails to establish connection,
    	'CYBLE_EVT_GAP_DEVICE_DISCONNECTED' is passed to application. ' CYBLE_EVT_GAP_ENHANCE_CONN_COMPLETE'
    	event is triggered instead of 'CYBLE_EVT_GAP_DEVICE_CONNECTED', if Link Layer Privacy is enabled in component customizer.   
	Event parameter is a pointer to a structure of type CYBLE_GAP_CONN_PARAM_UPDATED_IN_CONTROLLER_T. */
    CYBLE_EVT_GAP_DEVICE_CONNECTED,

	/** Disconnected from remote device or failed to establish connection. Parameter returned with the event 
	contains pointer to the reason for disconnection, which is of type uint8. For details refer
	core spec 4.2, vol2, part D */
    CYBLE_EVT_GAP_DEVICE_DISCONNECTED,

    /** Encryption change event for active connection. 'evParam' can be decoded as
         * evParam[0] = 0x00 -> Encryption OFF
         * evParam[0] = 0x01 -> Encryption ON
    	 * Any other value of evParam[0] -> Error
     
       This is an informative event for application when there is a change in encryption. 
       Application may choose to ignore it. */
    CYBLE_EVT_GAP_ENCRYPT_CHANGE,

    /** This event is generated at the GAP Central and the Peripheral end after connection parameter update
		is requested from the host to the controller. Event parameter is a pointer to a structure of type CYBLE_GAP_CONN_PARAM_UPDATED_IN_CONTROLLER_T. */
    CYBLE_EVT_GAP_CONNECTION_UPDATE_COMPLETE,

    /** Central device has started/stopped scanning. 
       This event is generated after making a call to CyBle_GapcStartDiscovery and 
       CyBle_GapcStopDiscovery APIs. The event parameter contains the status, which is of type 'uint8'.
       
       If the data is '0x00', it indicates 'success'; Anything else indicates 'failure'. */
    CYBLE_EVT_GAPC_SCAN_START_STOP,

    /** Indication that the SMP keys exchange with peer device is complete, the event handler
       is expected to store the peer device keys, especially IRK which is used to resolve the
       peer device after the connection establishment.
       
       Event parameter returns data of type CYBLE_GAP_SMP_KEY_DIST_T containing the peer device keys. */
    CYBLE_EVT_GAP_KEYINFO_EXCHNGE_CMPLT,
    
    /** This event indicates that the device needs to display passkey during 
        secure connection pairing procedure. CyBle_GapAuthPassKeyReply() is
        required to be called with valid parameters on receiving this event.
        Since no key to be entered by the user for Numeric comparison, 
        parameter passkey for the function CyBle_GapAuthPassKeyReply will be 
        ignored.
        Event parameter is a pointer to a 6 digit Passkey value. */
    CYBLE_EVT_GAP_NUMERIC_COMPARISON_REQUEST,
    
    /** This event is generated when keypress (Secure connections) is received
       from peer device. */
    CYBLE_EVT_GAP_KEYPRESS_NOTIFICATION,

    /** This event is generated when OOB generation for Secure connections is complete.  
       Event parameter is of type 'CYBLE_GAP_OOB_DATA_T' */
    CYBLE_EVT_GAP_OOB_GENERATED_NOTIFICATION,
    
    /** The LE Data Length Change event notifies the Host of a change to either the maximum Payload length or 
       the maximum transmission time of Data Channel PDUs in either direction. The values reported are the maximum
       that will actually be used on the connection following the change. Event parameter is of type 
       'CYBLE_GAP_CONN_DATA_LENGTH_T' */
    CYBLE_EVT_GAP_DATA_LENGTH_CHANGE,

    /** The LE Enhanced Connection Complete event indicates application that a new connection has been created when 
        Link Layer Privacy is enabled in component customizer. 
       Event parameter is of type 'CYBLE_GAP_ENHANCE_CONN_COMPLETE_T' */
    CYBLE_EVT_GAP_ENHANCE_CONN_COMPLETE,
	
    /** The LE Direct Advertising Report event indicates that directed advertisements have been received where 
       the advertiser is using a resolvable private address for the InitA field in the ADV_DIRECT_IND PDU and the
       Scanning_Filter_Policy is equal to 0x02 or 0x03. Event parameter is of type 'CYBLE_GAPC_DIRECT_ADV_REPORT_T' */
    CYBLE_EVT_GAPC_DIRECT_ADV_REPORT,

    /** SMP negotiated auth info event is raised as soon as SMP has completed pairing properties (feature exchange)
     * negotiation. The event parameter is CYBLE_GAP_AUTH_INFO_T. CYBLE_GAP_AUTH_INFO_T will have the 
     * negotiated parameter, the pairing should either pass with these negotiated parameters or may fail. This event
     * is applicable to both GAP Central and GAP Peripheral devices. In GAP Peripheral, this event is called from 
     * API-CyBle_GappAuthReqReply context.
     */
    CYBLE_EVT_GAP_SMP_NEGOTIATED_AUTH_INFO,

    /* Range for GATT events - 0x40 to 6F */

    /** The event is received by the Client when the Server cannot perform the requested 
       operation and sends out an error response. Event parameter is a pointer to a structure
       of type CYBLE_GATTC_ERR_RSP_PARAM_T. */
    CYBLE_EVT_GATTC_ERROR_RSP = 0x40u,

    /** This event is generated at the GAP Peripheral end after connection is completed with peer Central device.
    	For GAP Central device, this event is generated as in acknowledgment of receiving this event successfully
    	by BLE Controller. Once connection is done, no more event is required but if fails to establish connection,
    	'CYBLE_EVT_GATT_DISCONNECT_IND' is passed to application.      
	Event parameter is a pointer to a structure of type CYBLE_CONN_HANDLE_T. */
    CYBLE_EVT_GATT_CONNECT_IND,

    /** GATT is disconnected. Nothing is returned as part of the event parameter. */
    CYBLE_EVT_GATT_DISCONNECT_IND,

    /** 'GATT MTU Exchange Request' received from GATT client device. Event parameter 
       contains the MTU size of type CYBLE_GATT_XCHG_MTU_PARAM_T. */
    CYBLE_EVT_GATTS_XCNHG_MTU_REQ,

    /** 'GATT MTU Exchange Response' received from server device. Event parameter is a
       pointer to a structure of type CYBLE_GATT_XCHG_MTU_PARAM_T. */
    CYBLE_EVT_GATTC_XCHNG_MTU_RSP,

    /** 'Read by Group Type Response' received from server device. Event parameter
       is a pointer to a structure of type CYBLE_GATTC_READ_BY_GRP_RSP_PARAM_T. */
    CYBLE_EVT_GATTC_READ_BY_GROUP_TYPE_RSP,

    /** 'Read by Type Response' received from server device. Event parameter is a
       pointer to a structure of type CYBLE_GATTC_READ_BY_TYPE_RSP_PARAM_T. */
    CYBLE_EVT_GATTC_READ_BY_TYPE_RSP,

    /** 'Find Information Response' received from server device. Event parameter is
       a pointer to a structure of type 'CYBLE_GATTC_FIND_INFO_RSP_PARAM_T. */
    CYBLE_EVT_GATTC_FIND_INFO_RSP,

    /** 'Find by Type Value Response' received from server device. Event parameter is
       a pointer to a structure of type CYBLE_GATTC_FIND_BY_TYPE_RSP_PARAM_T. */
    CYBLE_EVT_GATTC_FIND_BY_TYPE_VALUE_RSP,

    /** 'Read Response' from server device. Event parameter is a pointer to a
       structure of type CYBLE_GATTC_READ_RSP_PARAM_T. */
    CYBLE_EVT_GATTC_READ_RSP,

    /** 'Read Blob Response' from server. Event parameter is a pointer to a
       structure of type CYBLE_GATTC_READ_RSP_PARAM_T. */
    CYBLE_EVT_GATTC_READ_BLOB_RSP,

    /** 'Read Multiple Responses' from server. Event parameter is a pointer
       to a structure of type CYBLE_GATTC_READ_RSP_PARAM_T. The 'actualLen' field
       should be ignored as it is unused in this event response. */
    CYBLE_EVT_GATTC_READ_MULTI_RSP,

    /** 'Write Request' from client device. Event parameter is a pointer to
       a structure of type CYBLE_GATTS_WRITE_REQ_PARAM_T . */
    CYBLE_EVT_GATTS_WRITE_REQ,

    /** 'Write Response' from server device. Event parameter is a pointer
       to a structure of type CYBLE_CONN_HANDLE_T. */
    CYBLE_EVT_GATTC_WRITE_RSP,

    /** 'Write Command' Request from client device. Event parameter is a 
       pointer to a structure of type CYBLE_GATTS_WRITE_CMD_REQ_PARAM_T. */
    CYBLE_EVT_GATTS_WRITE_CMD_REQ,

    /** 'Prepare Write' Request from client device. Event parameter is a
       pointer to a structure of type CYBLE_GATTS_PREP_WRITE_REQ_PARAM_T. */
    CYBLE_EVT_GATTS_PREP_WRITE_REQ, 

    /** 'Execute Write' request from client device. Event parameter is a
       pointer to a structure of type 'CYBLE_GATTS_EXEC_WRITE_REQ_T'
       This event will be triggered before GATT DB is modified. GATT Db will be updated 
       only if there is no error condition provided by application. In case of error condition triggered
       during stack validation, partial write will occur. Write will be canceled from that handle where 
       error has occurred and error response corresponding to that handle will be sent to remote.
       If at any point of time 'CYBLE_GATT_EXECUTE_WRITE_CANCEL_FLAG' is received in 
       execWriteFlag fields of 'CYBLE_GATTS_EXEC_WRITE_REQ_T' structure, then all previous 
       writes are canceled. For execute cancel scenario, all elements of 
       'CYBLE_GATTS_EXEC_WRITE_REQ_T' should be ignored except execWriteFlag and connHandle.
     */
    CYBLE_EVT_GATTS_EXEC_WRITE_REQ,

    /** 'Execute Write' response from server device. Event parameter is a
       pointer to a structure of type CYBLE_GATTC_EXEC_WRITE_RSP_T. */
    CYBLE_EVT_GATTC_EXEC_WRITE_RSP,

    /** Notification data received from server device. Event parameter
       is a pointer to a structure of type CYBLE_GATTC_HANDLE_VALUE_NTF_PARAM_T. */
    CYBLE_EVT_GATTC_HANDLE_VALUE_NTF,

    /** Indication data received from server device. Event parameter is
       a pointer to a structure of type CYBLE_GATTC_HANDLE_VALUE_IND_PARAM_T. */
    CYBLE_EVT_GATTC_HANDLE_VALUE_IND,

    /** Confirmation to indication response from client device. Event
       parameter is a pointer to a structure of type CYBLE_CONN_HANDLE_T. */
    CYBLE_EVT_GATTS_HANDLE_VALUE_CNF,

    /** Confirmation to indication response from client device. Event
       parameter is a pointer to a structure of type CYBLE_GATTS_SIGNED_WRITE_CMD_REQ_PARAM_T. 
       if value.val parameter is set to Zero, then signature is not matched and ignored by stack */
    CYBLE_EVT_GATTS_DATA_SIGNED_CMD_REQ,

    /** Event indicating that GATT group procedure has stopped or completed, this event occurs
       only if application has called CyBle_GattcStopCmd API. 
       Event parameters shall be ignored */
    CYBLE_EVT_GATTC_STOP_CMD_COMPLETE,

   /** Event parameter type is CYBLE_GATTS_CHAR_VAL_READ_REQ_T. It is triggered on server side 
       when client sends read request and when characteristic has CYBLE_GATT_DB_ATTR_CHAR_VAL_RD_EVENT 
       property set. This event could be ignored by application unless it need to response by error response which
       needs to be set in gattErrorCode field of event parameter. */
    CYBLE_EVT_GATTS_READ_CHAR_VAL_ACCESS_REQ,

	/** Event indicates that GATT long procedure is end and stack will not send any further
    * requests to peer. Either this event or 'CYBLE_EVT_GATTC_ERROR_RSP' will be received
    * by application. This event may get triggered for below GATT long procedures:
    * 	1. CyBle_GattcDiscoverAllPrimaryServices
	* 	2. CyBle_GattcDiscoverPrimaryServiceByUuid
	* 	3. CyBle_GattcFindIncludedServices
	* 	4. CyBle_GattcDiscoverAllCharacteristics
	* 	5. CyBle_GattcDiscoverCharacteristicByUuid
	* 	6. CyBle_GattcDiscoverAllCharacteristicDescriptors
	* 	7. CyBle_GattcReadLongCharacteristicValues
	* 	8. CyBle_GattcReadLongCharacteristicDescriptors	\n
	* 	Event parameter is ATT opcode for the corresponding long GATT Procedure.
	*/
	CYBLE_EVT_GATTC_LONG_PROCEDURE_END,

    /* Range for L2CAP events - 0x70 to 0x7F */

    /** This event indicates the connection parameter update received
       from the remote device. The application is expected to reply to L2CAP using the
       CyBle_L2capLeConnectionParamUpdateResponse() function to respond to the remote
       device, whether parameters are accepted or rejected.
       
       Event Parameter pointer points to data of type 'CYBLE_GAP_CONN_UPDATE_PARAM_T' */
    CYBLE_EVT_L2CAP_CONN_PARAM_UPDATE_REQ = 0x70u,

    /** This event indicates the connection parameter update response received
       from the master. Event Parameter pointer points to data with two possible values:
    	* Accepted = 0x0000
    	* Rejected  = 0x0001

       Data is of type unit16. */
    CYBLE_EVT_L2CAP_CONN_PARAM_UPDATE_RSP,

    /** This event indicates that the request send over l2cap signaling has been
       rejected. Event parameter is a pointer to a structure of type
       CYBLE_L2CAP_COMMAND_REJ_REASON_T. */
    CYBLE_EVT_L2CAP_COMMAND_REJ,

    /** This event is used to inform application of the incoming L2CAP CBFC
       Connection Request. Event parameter is a pointer to a structure of type
       CYBLE_L2CAP_CBFC_CONN_IND_PARAM_T is returned. */
    CYBLE_EVT_L2CAP_CBFC_CONN_IND,

    /** This event is used to inform application of the L2CAP CBFC Connection
       Response/Confirmation. Event parameter is a pointer to a structure of
       type CYBLE_L2CAP_CBFC_CONN_CNF_PARAM_T is returned. */
    CYBLE_EVT_L2CAP_CBFC_CONN_CNF,

    /** This event is used to inform application of the L2CAP CBFC Disconnection
       Request received from the Peer device. Event parameter is a pointer to
       Local CID of type unit16. */
    CYBLE_EVT_L2CAP_CBFC_DISCONN_IND,

    /** This event is used to inform application of the L2CAP CBFC Disconnection
       confirmation/Response received from the Peer device. Event parameter is a
       pointer to a structure of type CYBLE_L2CAP_CBFC_DISCONN_CNF_PARAM_T. */
    CYBLE_EVT_L2CAP_CBFC_DISCONN_CNF,

    /** This event is used to inform application of data received over L2CAP
       CBFC channel. Event parameter is a pointer to a structure of type
       CYBLE_L2CAP_CBFC_RX_PARAM_T. */
    CYBLE_EVT_L2CAP_CBFC_DATA_READ,

    /** This event is used to inform the application of receive credits reached
       low mark. After receiving L2CAP data/payload from peer device for a
       specification Channel, the available credits are calculated.
       
       If the credit count goes below the low mark, this event is called to inform
       the application of the condition, so that if the application wants it can
       send more credits to the peer device.
       
       Event parameter is a pointer to a structure of type
       CYBLE_L2CAP_CBFC_LOW_RX_CREDIT_PARAM_T. */
    CYBLE_EVT_L2CAP_CBFC_RX_CREDIT_IND,

    /** This event is used to inform application of having received transmit
       credits. This event is called on receiving LE Flow Control Credit from peer
       device.
       
       Event parameter is a pointer to a structure of type
       CYBLE_L2CAP_CBFC_LOW_TX_CREDIT_PARAM_T.
       
       If the 'result' field of the received data is non-zero, this indicates an
       error. If the sum of 'credit' field value and the previously available credit
       at the peer device receiving credit information exceeds 65535, it indicates a
       'credit overflow' error.
       
       In case of error, the peer device receiving this event should initiate
       disconnection of the L2CAP channel by invoking CyBle_L2capDisconnectReq () 
       function. */
    CYBLE_EVT_L2CAP_CBFC_TX_CREDIT_IND,

    /** This event is used to inform application of data transmission completion over L2CAP CBFC
       channel. Event parameter is of type 'CYBLE_L2CAP_CBFC_DATA_WRITE_PARAM_T' 
       This event will be deprecated in future. It is only kept for backward compatibility.
       It is not recommended to be used by new design */
    CYBLE_EVT_L2CAP_CBFC_DATA_WRITE_IND,

#ifdef CYBLE_HOST_QUALIFICATION
	/** Tester to manipulate pairing request or response PDU. Event parameter is a pointer to 1 bytes data.
	    Tester can manipulate the bits of the byte */
	CYBLE_EVT_QUAL_SMP_PAIRING_REQ_RSP = 0x80u,

	/** Tester to manipulate local Public Key. Event parameter is a pointer to local public key of size 64 Bytes.
		Tester can manipulate the bits/bytes */
	CYBLE_EVT_QUAL_SMP_LOCAL_PUBLIC_KEY,

	/** Tester to assign pairing failed error code. Event parameter is a pointer to 16 bits value.
		Tester should assign error code to lower bits */
	CYBLE_EVT_QUAL_SMP_PAIRING_FAILED_CMD,

#endif /* CYBLE_HOST_QUALIFICATION */

    /*##Range for for future use - 0x90 to 0xFF*/

    /** This event is used to inform application that flash write is pending
        Stack internal data structures are modified and require backup. */
    CYBLE_EVT_PENDING_FLASH_WRITE = 0xFA,

    /** LE PING Authentication Timeout Event to indicate that peer device has not responded
        with the valid MIC packet within the application configured ping authentication time. */
    CYBLE_EVT_LE_PING_AUTH_TIMEOUT = 0xFB,

	/** Maximum value of CYBLE_EVENT_T type */
    CYBLE_EVT_MAX = 0xFF

}CYBLE_EVENT_T;

#define CYBLE_ADVERTISING_FAST                      (0x00u)
#define CYBLE_ADVERTISING_SLOW                      (0x01u)
#define CYBLE_ADVERTISING_CUSTOM                    (0x02u)

    /* Event handler state machine type */
typedef enum
{
    CYBLE_STATE_STOPPED,                        /* BLE is turned off */
    CYBLE_STATE_INITIALIZING,                   /* Initializing state */
    CYBLE_STATE_CONNECTED,                      /* Peer device is connected */
    CYBLE_STATE_ADVERTISING,                    /* Advertising process */
    CYBLE_STATE_DISCONNECTED                    /* Essentially idle state */
} CYBLE_STATE_T;

/* Connection Handle */
typedef struct
{
    /* Identifies the peer instance */
    uint8     	bdHandle;

    /* Identifies the ATT Instance */
    uint8       attId;

}CYBLE_CONN_HANDLE_T;

typedef uint16 		CYBLE_GATT_DB_ATTR_HANDLE_T;

/* GATT handle - value pair type */
typedef struct
{
	/* Attribute Value	*/
    CYBLE_GATT_VALUE_T          	value;      

	/* Attribute Handle */
    CYBLE_GATT_DB_ATTR_HANDLE_T	  	attrHandle;     

}CYBLE_GATT_HANDLE_VALUE_PAIR_T;

/* Write request parameter received from Client */
typedef struct
{
	/* Connection handle */
	CYBLE_CONN_HANDLE_T 				connHandle; 

	/* handle value pair */
    CYBLE_GATT_HANDLE_VALUE_PAIR_T    	handleValPair; 
	
}CYBLE_GATTS_WRITE_REQ_PARAM_T;

#define CYBLE_EVT_GAPC_CONNECTION_UPDATE_COMPLETE   CYBLE_EVT_GAP_CONNECTION_UPDATE_COMPLETE

/* BLE power modes */
typedef enum
{
    /* Link Layer engine and Digital modem clocked from ECO. 
        The CPU can access the BLE Sub-System (BLESS) registers.
        This mode collectively denotes Tx Mode, Rx Mode, and 
        Idle mode of BLESS.
    */
    CYBLE_BLESS_ACTIVE = 0x01u,
    
    /* The clock to the link layer engine and digital modem
        is gated. The ECO continues to run to maintain the 
        link layer timing.
    */
    CYBLE_BLESS_SLEEP,
    
    /* The ECO is stopped and WCO is used to maintain link layer
        timing. RF transceiver is turned off completely to reduce
        leakage current. BLESS logic is kept powered ON from the
        SRSS deep sleep regulator for retention.
    */
    CYBLE_BLESS_DEEPSLEEP,
    
    /* External power is available but all internal LDOs are
        turned off.
    */
    CYBLE_BLESS_HIBERNATE,
    
    /* Invalid mode */
    CYBLE_BLESS_INVALID = 0xFFu
} CYBLE_LP_MODE_T;

typedef enum
{
    CYBLE_BLESS_STATE_ACTIVE = 0x01,
    CYBLE_BLESS_STATE_EVENT_CLOSE,
    CYBLE_BLESS_STATE_SLEEP,
    CYBLE_BLESS_STATE_ECO_ON,
    CYBLE_BLESS_STATE_ECO_STABLE,
    CYBLE_BLESS_STATE_DEEPSLEEP,
    CYBLE_BLESS_STATE_HIBERNATE,
    CYBLE_BLESS_STATE_INVALID = 0xFFu
} CYBLE_BLESS_STATE_T;

/* Control-point attributes */
#define CYBLE_HIDS_CP_SUSPEND                           (0x00u)
#define CYBLE_HIDS_CP_EXIT_SUSPEND                      (0x01u)

typedef void (* CYBLE_CALLBACK_T) (uint32 eventCode, void *eventParam);

/* ScPS Characteristic indexes */
typedef enum
{
    CYBLE_SCPS_SCAN_INT_WIN,                        /* Scan Interval Window characteristic index */
    CYBLE_SCPS_SCAN_REFRESH,                        /* Scan Refresh characteristic index */
    CYBLE_SCPS_CHAR_COUNT                           /* Total count of characteristics */
}CYBLE_SCPS_CHAR_INDEX_T;

/* Scan Parameters Service Characteristic Value parameter structure */
typedef struct
{
    CYBLE_CONN_HANDLE_T connHandle;                         /* Peer device handle */
    CYBLE_SCPS_CHAR_INDEX_T charIndex;                      /* Index of service characteristic */
    CYBLE_GATT_VALUE_T *value;                              /* Characteristic value */
} CYBLE_SCPS_CHAR_VALUE_T;

/* ScPS Characteristic Descriptors indexes */
typedef enum
{
    CYBLE_SCPS_SCAN_REFRESH_CCCD,                   /* Client Characteristic Configuration descriptor index */
    CYBLE_SCPS_DESCR_COUNT                          /* Total count of descriptors */
}CYBLE_SCPS_DESCR_INDEX_T;

/* Client Characteristic Configuration Descriptor values */
#define CYBLE_CCCD_DEFAULT                           (0x0000u)
#define CYBLE_CCCD_NOTIFICATION                      (0x0001u)
#define CYBLE_CCCD_INDICATION                        (0x0002u)
#define CYBLE_CCCD_LEN                               (0x02u)

/* Server Characteristic Configuration Descriptor values */
#define CYBLE_SCCD_DEFAULT                           (0x0000u)
#define CYBLE_SCCD_BROADCAST                         (0x0001u)
#define CYBLE_SCCD_LEN                               (0x02u)

/* Boot Report indexes */
#define CYBLE_HIDS_BOOT_KYBRD_IN_REP_INDX               (0x00u)
#define CYBLE_HIDS_BOOT_KYBRD_OUT_REP_INDX              (0x01u)
#define CYBLE_HIDS_BOOT_MOUSE_IN_REP_INDX               (0x02u)

/* Report Type values */
#define CYBLE_HIDS_PROTOCOL_MODE_BOOT                   (0x00u)
#define CYBLE_HIDS_PROTOCOL_MODE_REPORT                 (0x01u)
#define CYBLE_HIDS_PROTOCOL_DEFAULT                     CYBLE_HIDS_PROTOCOL_MODE_REPORT

/* Report Type values */
#define CYBLE_HIDS_REPORT_TYPE_INPUT                    (0x01u)
#define CYBLE_HIDS_REPORT_TYPE_OUTPUT                   (0x02u)
#define CYBLE_HIDS_REPORT_TYPE_FEATURE                  (0x03u)

/* Control-point attributes */
#define CYBLE_HIDS_CP_SUSPEND                           (0x00u)
#define CYBLE_HIDS_CP_EXIT_SUSPEND                      (0x01u)

/* Information charasteristic value flags */
#define CYBLE_HIDS_INFO_FLAG_REMOTE_WAKE_MASK           (0x01u)
#define CYBLE_HIDS_INFO_FLAG_NORMALLY_CONNECTABLE_MASK  (0x02u)

#define CYBLE_HIDS_PM_CHAR_LEN                          (0x01u)
#define CYBLE_HIDS_CP_CHAR_LEN                          (0x01u)
#define CYBLE_HIDS_RRD_LEN                              (0x02u)

#define CYBLE_HIDSC_HOST_ROLE_BOOT                      (0x00u)
#define CYBLE_HIDSC_HOST_ROLE_REPORT                    (0x01u)
#define CYBLE_HIDSC_HOST_ROLE_BOOT_AND_REPORT           (0x02u)


#define CYBLE_HIDSS_REPORT_COUNT             (0x04u)
#define CYBLE_HIDS_REPORT_COUNT      CYBLE_HIDSS_REPORT_COUNT

/** HIDS characteristic indexes */
typedef enum
{
    CYBLE_HIDS_PROTOCOL_MODE,                        /**< Protocol Mode Characteristic index */
    CYBLE_HIDS_INFORMATION,                          /**< HID Information Characteristic index */
    CYBLE_HIDS_CONTROL_POINT,                        /**< HID Control Point Characteristic index */
    CYBLE_HIDS_REPORT_MAP,                           /**< Report Map Characteristic index */
    CYBLE_HIDS_BOOT_KYBRD_IN_REP,                    /**< Boot Keyboard Input Report Characteristic index */
    CYBLE_HIDS_BOOT_KYBRD_OUT_REP,                   /**< Boot Keyboard Output Report Characteristic index */
    CYBLE_HIDS_BOOT_MOUSE_IN_REP,                    /**< Boot Mouse Input Report Characteristic index */
    CYBLE_HIDS_REPORT,                               /**< Report Characteristic index */
	/* Human Interface Device service Report characteristics indexes */
    CYBLE_HUMAN_INTERFACE_DEVICE_REPORT_KEYBOARD = CYBLE_HIDS_REPORT, /* Report_Keyboard characteristic index */
    CYBLE_HUMAN_INTERFACE_DEVICE_REPORT_MULTIMEDIA,  /* Report_Multimedia characteristic index */
    CYBLE_HUMAN_INTERFACE_DEVICE_REPORT_POWER,       /* Report_Power characteristic index */
    CYBLE_HUMAN_INTERFACE_DEVICE_REPORT_GAMEPAD,     /* Report_Gamepad characteristic index */
    CYBLE_HIDS_REPORT_END = CYBLE_HIDS_REPORT + CYBLE_HIDS_REPORT_COUNT - 1,    /**< Index of last Report Char */
    CYBLE_HIDS_CHAR_COUNT                              /**< Total count of characteristics */
}CYBLE_HIDS_CHAR_INDEX_T;


/* HID Service Characteristic value parameter structure */
typedef struct
{
    CYBLE_CONN_HANDLE_T connHandle;         /* Peer device handle */
    uint8 serviceIndex;                     /* Index of HID Service */
    CYBLE_HIDS_CHAR_INDEX_T charIndex;      /* Index of HID Service Characteristic */
    CYBLE_GATT_VALUE_T *value;              /* Pointer to Characteristic value */
} CYBLE_HIDS_CHAR_VALUE_T;

/* HID Service Characteristic Descriptors indexes */
typedef enum
{
    CYBLE_HIDS_REPORT_CCCD,                         /* Client Characteristic Configuration descriptor index */
    CYBLE_HIDS_REPORT_RRD,                          /* Report Reference descriptor index */
    CYBLE_HIDS_REPORT_MAP_ERRD,                     /* Report Map External Report Reference descriptor index */
    CYBLE_HIDS_DESCR_COUNT                          /* Total count of descriptors */
}CYBLE_HIDS_DESCR_T;

/* HID Service Characteristic descriptor value parameter structure */
typedef struct
{
    CYBLE_CONN_HANDLE_T connHandle;         /* Peer device handle */
    uint8 serviceIndex;                     /* Index of HID Service */
    CYBLE_HIDS_CHAR_INDEX_T charIndex;      /* Index of HID Service Characteristic */
    CYBLE_HIDS_DESCR_T descrIndex;          /* Service Characteristic Descriptor index */
    CYBLE_GATT_VALUE_T *value;              /* Pointer to value of Service Characteristic Descriptor value */
} CYBLE_HIDS_DESCR_VALUE_T;

/* Maximum supported count of HID services and reports */
#define CYBLE_HIDSS_SERVICE_COUNT            (0x01u)
//#define CYBLE_HIDSS_REPORT_COUNT             (0x02u)

typedef enum
{
    CYBLE_HUMAN_INTERFACE_DEVICE_SERVICE_INDEX,
}CYBLE_HIDSS_INDEXES;

#define CYBLE_STACK_STATE_BUSY		   	0x01u
#define CYBLE_STACK_STATE_FREE		   	0x00u

/* BAS Characteristic indexes */
typedef enum
{
    CYBLE_BAS_BATTERY_LEVEL,                            /* Battery Level characteristic index */
    CYBLE_BAS_CHAR_COUNT                                /* Total count of characteristics */
}CYBLE_BAS_CHAR_INDEX_T;

typedef enum
{
    CYBLE_BATTERY_SERVICE_SERVICE_INDEX,
}CYBLE_BASS_INDEXES;

/* BAS Characteristic Descriptors indexes */
typedef enum
{
    CYBLE_BAS_BATTERY_LEVEL_CCCD,                       /* Client Characteristic Configuration descriptor index */
    CYBLE_BAS_BATTERY_LEVEL_CPFD,                       /* Characteristic Presentation Format descriptor index */
    CYBLE_BAS_DESCR_COUNT                               /* Total count of descriptors */
}CYBLE_BAS_DESCR_INDEX_T;

/* Battery Service Characteristic Value parameter structure */
typedef struct
{
    CYBLE_CONN_HANDLE_T connHandle;                         /* Peer device handle */
    uint8 serviceIndex;                                     /* Service instance */
    CYBLE_BAS_CHAR_INDEX_T charIndex;                       /* Index of a service characteristic */
    CYBLE_GATT_VALUE_T *value;                              /* Characteristic value */
} CYBLE_BAS_CHAR_VALUE_T;

/* Security modes  */
#define CYBLE_GAP_SEC_MODE_1                    0x10u
#define CYBLE_GAP_SEC_MODE_2                    0x20u
#define CYBLE_GAP_SEC_MODE_MASK                 0xF0u

/* Security Levels  */
typedef enum
{
	/* Level 1
	    * Mode 1 - No Security (No Authentication & No Encryption)
	    * Mode 2 - N/A
	 */
	CYBLE_GAP_SEC_LEVEL_1 =	0x00u,
	
	/* Level 2
	    * Mode 1 - Unauthenticated pairing with encryption (No MITM)
	    * Mode 2 - Unauthenticated pairing with data signing (No MITM)
	 */
	CYBLE_GAP_SEC_LEVEL_2,
	
	/* Level 3
	    * Mode 1 - Authenticated pairing with encryption (With MITM)
	    * Mode 2 - Authenticated pairing with data signing (With MITM)
	 */
	CYBLE_GAP_SEC_LEVEL_3,
	
	/* LE Security Level Mask */
	CYBLE_GAP_SEC_LEVEL_MASK =0x0Fu

}CYBLE_GAP_SEC_LEVEL_T;

/* No Bonding support */
#define CYBLE_GAP_BONDING_NONE                          0x00u

/* Bonding support */
#define CYBLE_GAP_BONDING                               0x01u

/* Structure with Generic Attribute Service (GATTS) attribute handles */
typedef struct
{
    CYBLE_GATT_DB_ATTR_HANDLE_T serviceHandle;              /* Service handle*/
    CYBLE_GATT_DB_ATTR_HANDLE_T serviceChangedHandle;       /* Handle of the Service Changed characteristic */
    CYBLE_GATT_DB_ATTR_HANDLE_T cccdHandle;                 /* Client Characteristic Configuration descriptor handle */
} CYBLE_GATTS_T;

#define CYBLE_GAP_MAX_ADV_DATA_LEN              31u

/* Advertising data   */
typedef struct
{
	/*GAP Advertisement Parameters which includes Flags, Service UUIDs and short name*/
	uint8      advData[CYBLE_GAP_MAX_ADV_DATA_LEN]; 

	/*length of the advertising data. This should be made zero if there is no data */
	uint8      advDataLen;	
	
} CYBLE_GAPP_DISC_DATA_T;

/* Advertisement type  */
typedef enum
{
	/* Connectable undirected advertising */
	CYBLE_GAPP_CONNECTABLE_UNDIRECTED_ADV = 0x00u,

	/* Connectable high duty cycle directed advertising */
	CYBLE_GAPP_CONNECTABLE_HIGH_DC_DIRECTED_ADV,

	/* Scannable undirected advertising */
	CYBLE_GAPP_SCANNABLE_UNDIRECTED_ADV,

	/* Non connectable undirected advertising */
	CYBLE_GAPP_NON_CONNECTABLE_UNDIRECTED_ADV,

	/* Connectable low duty cycle directed advertising */
	CYBLE_GAPP_CONNECTABLE_LOW_DC_DIRECTED_ADV
	
}CYBLE_GAPP_ADV_T;

/* Advertising parameters   */
typedef struct
{
	/* Minimum advertising interval for undirected 
	   and low duty cycle directed advertising.
	   	 - Time Range: 20 ms to 10.24 sec
	 */
	uint16     				advIntvMin; 

	/* Maximum advertising interval for undirected 
	   and low duty cycle directed advertising.
	   	- Time Range: 20 ms to 10.24 sec
	 */	
	uint16     				advIntvMax; 

	/* Type of advertisement
	   	- Connectable undirected advertising (0x00)
	   	- Connectable high duty cycle directed advertising (0x01)
	   	- Scannable undirected advertising (0x02)
	   	- Non connectable undirected advertising (0x03)
	   	- Connectable low duty cycle directed advertising (0x04)
	 */	
	CYBLE_GAPP_ADV_T      	advType;		

	/* Own BD Address Type											
	    - CYBLE_GAP_ADDR_TYPE_PUBLIC (Public device address)
        - CYBLE_GAP_ADDR_TYPE_RANDOM (Random device address)
     */	
	uint8      				ownAddrType;	

	/* Address type of the Bluetooth device address being used for 
	   directed advertising, not applicable otherwise
	    - CYBLE_GAP_ADDR_TYPE_PUBLIC (Public device address)
        - CYBLE_GAP_ADDR_TYPE_RANDOM (Random device address)
	 */
	uint8      				directAddrType;	

	/* 	This parameter specifies Bluetooth device address of the 
	  	device to be connected while using directed advertising.
	  	In case of none direct advertising, parameter will be 0 
	 */	
	uint8     				directAddr[CYBLE_GAP_BD_ADDR_SIZE];		

	/* Advertising channels that shall be used when transmitting advertising packets. 
	   Channel map selection:
	   	   - Enable channel 37 = bitmask. xxxxxxx1b
	   	   - Enable channel 38 = bitmask. xxxxxx1xb
	   	   - Enable channel 39 = bitmask. xxxxx1xxb 
	 */
	uint8      				advChannelMap;

	/* Advertising Filter Policy
	   	- CYBLE_SCAN_ANY_CONN_ANY (Allow Scan Request from Any, Allow Connect Request
           from Any (Default))
	   	- CYBLE_SCAN_WHITELIST_CONN_ANY (Allow Scan Request from White List Only, 
           Allow Connect Request)
	   	- CYBLE_SCAN_ANY_CONN_WHITELIST (Allow Scan Request from Any, Allow Connect
           Request from White List Only)
	   	- CYBLE_SCAN_WHITELIST_CONN_ANY (Allow Scan Request from White List Only, 
           Allow Connect Request from White List Only)
	 */	
	uint8      				advFilterPolicy;
	
}CYBLE_GAPP_DISC_PARAM_T;

#define CYBLE_GAP_MAX_SCAN_RSP_DATA_LEN         31u

/* Scan response data   */
typedef struct
{
	/* Static user data transmitted in scan response. This should be made NULL if 
    there is no data. Maximum length of the data is equal to 31 bytes */
	uint8     scanRspData[CYBLE_GAP_MAX_SCAN_RSP_DATA_LEN];

	/* Length of the scan response data. This should be made zero if there is no data */
	uint8     scanRspDataLen; 	
	
} CYBLE_GAPP_SCAN_RSP_DATA_T;

/* Advertising information   */
typedef struct
{
	/* Broadcaster and discoverable mode 
	    - CYBLE_GAPP_NONE_DISC_BROADCAST_MODE
           (Applicable for Broadcaster or non-discoverable mode)
	    - CYBLE_GAPP_LTD_DISC_MODE (Limited discovery mode)
	    - CYBLE_GAPP_GEN_DISC_MODE (General discovery mode)
	 */
	uint8      						discMode;

	/* Advertisement parameters */
	CYBLE_GAPP_DISC_PARAM_T*   		advParam;
    /* Advertisement data */
	CYBLE_GAPP_DISC_DATA_T*    		advData;
    /* Scan Response data */
	CYBLE_GAPP_SCAN_RSP_DATA_T*	 	scanRspData;

	/* Advertisement timeout is in seconds. If timeout is set to 0,
        then there will not be any timeout. Parameter 'advTo' can 
        be used for all GAP timeouts related to peripheral operation.
        For General discoverable mode, this timer will be ignored.
        Application is expected to exit from discoverable mode
        explicitly by calling CyBle_GappExitDiscoveryMode() function.
        For Limited discoverable mode, 'advTo' should not exceed 180 Sec.
	 */
	uint16 							advTo; 
	
} CYBLE_GAPP_DISC_MODE_INFO_T;

/* BLESS Power enum reflecting power level values supported by BLESS radio */
typedef enum
{
    CYBLE_LL_PWR_LVL_NEG_18_DBM = 0x01u, /* ABS PWR = -18dBm, PA_Gain = 0x01 */
    CYBLE_LL_PWR_LVL_NEG_12_DBM,         /* ABS PWR = -12dBm, PA_Gain = 0x02 */
    CYBLE_LL_PWR_LVL_NEG_6_DBM,          /* ABS PWR = -6dBm, PA_Gain = 0x03 */
    CYBLE_LL_PWR_LVL_NEG_3_DBM,          /* ABS PWR = -3dBm, PA_Gain = 0x04 */
    CYBLE_LL_PWR_LVL_NEG_2_DBM,          /* ABS PWR = -2dBm, PA_Gain = 0x05 */
    CYBLE_LL_PWR_LVL_NEG_1_DBM,          /* ABS PWR = -1dBm, PA_Gain = 0x06 */
    CYBLE_LL_PWR_LVL_0_DBM,              /* ABS PWR = 0dBm, PA_Gain = 0x07 */
    CYBLE_LL_PWR_LVL_MAX
} CYBLE_BLESS_PWR_LVL_T;

/* BLE channel group ID */
typedef enum
{
    /* Advertisement channel type */
    CYBLE_LL_ADV_CH_TYPE = 0x00u,
    /* Connectipn channel type */
    CYBLE_LL_CONN_CH_TYPE,
    /* Maximum value of CYBLE_BLESS_PHY_CH_GRP_ID_T type */
    CYBLE_LL_MAX_CH_TYPE
} CYBLE_BLESS_PHY_CH_GRP_ID_T;

/* Structure to set/get BLE radio power */
typedef struct
{
    /* Output Power level */
    CYBLE_BLESS_PWR_LVL_T           blePwrLevelInDbm;
    /* Channel group ID for which power level is to be read/written */
    CYBLE_BLESS_PHY_CH_GRP_ID_T     bleSsChId;
} CYBLE_BLESS_PWR_IN_DB_T;

#define CYBLE_GATT_MTU                               (0x0090u)
#define CYBLE_DEFAULT_HEAP_SIZE				(16 + 2196 + 1008)

#define CYBLE_STACK_HEAP_SIZE           (CYBLE_DEFAULT_HEAP_SIZE + (CYBLE_GATT_MTU - (CYBLE_GATT_MTU % 4u) - 20u) * 2u)

/* HID Server Report characteristic */
typedef struct
{
    CYBLE_GATT_DB_ATTR_HANDLE_T reportHandle;       /* Handle of Report characteristic value */
    CYBLE_GATT_DB_ATTR_HANDLE_T cccdHandle;         /* Handle of Client Characteristic Configuration descriptor */
    CYBLE_GATT_DB_ATTR_HANDLE_T rrdHandle;          /* Handle of Report Reference descriptor */
} CYBLE_HIDSS_REPORT_T;

typedef CYBLE_GATT_HANDLE_VALUE_PAIR_T CYBLE_GATTS_HANDLE_VALUE_NTF_T;
typedef CYBLE_GATT_HANDLE_VALUE_PAIR_T CYBLE_GATTS_HANDLE_VALUE_IND_T;

/* GATT profile error codes */
typedef enum
{
	/* No Error	*/
	CYBLE_GATT_ERR_NONE = 0x00u,

	/* Invalid Handle error code is used in the case when the ATT handle in the
	   ATT request PDU is invalid. */
	CYBLE_GATT_ERR_INVALID_HANDLE,

	/* Read Not Permitted error code is used in the case when the permission to
       read the value of an ATT handle is not permitted on the ATT server. */
	CYBLE_GATT_ERR_READ_NOT_PERMITTED,

	/* Write Not Permitted error code is used in the case when the permission to
       write the value of an ATT handle is not permitted on the ATT server. */
	CYBLE_GATT_ERR_WRITE_NOT_PERMITTED,

	/* Invalid PDU error code is used in the case when the format of the PDU sent
       from the ATT Client is incorrect. */
	CYBLE_GATT_ERR_INVALID_PDU,

	/* Insufficient Authentication error code is used in the case when
       an access to a handle is attempted on a un-authenticated link but the
       attribute requires that the link be authenticated before any client can access it. */
	CYBLE_GATT_ERR_INSUFFICIENT_AUTHENTICATION,

	/* Request not supported error code is used in the case when
       the server does not support the processing of an ATT request sent from the client. */
	CYBLE_GATT_ERR_REQUEST_NOT_SUPPORTED,

	/* Invalid Offset error code is used in the case when
       the offset sent by the client in the Read blob/Prepare Write Request is
       invalid with respect to the length of the value in the server. */
	CYBLE_GATT_ERR_INVALID_OFFSET,

	/* Insufficient Authorization error code is used in the case when
       the ATT server does not Authorize the client and hence prohibiting the
       client from reading the handle value. */
	CYBLE_GATT_ERR_INSUFFICIENT_AUTHORIZATION,

	/* Write queue full error code is used when there is no more space left in the
       prepare write queue on the server to entertain any more prepare writes from a
       client. */
	CYBLE_GATT_ERR_PREPARE_WRITE_QUEUE_FULL,

	/* Attribute not found error is used when the ATT server cannot find any handles
       that belong to the Attribute type in the given range of handles that the
       client specified in its request. This error code can be sent to the client in
       response to the following request PDUs - Find Information, Find by Type Value,
       Read by Type, Read by Group Type requests. */
	CYBLE_GATT_ERR_ATTRIBUTE_NOT_FOUND,

	/* Attribute Not Long error code is used when the client tries to read or write
       a Attribute handle's value which cannot be read or written through Read Blob
       or multiple prepare write requests. */
	CYBLE_GATT_ERR_ATTRIBUTE_NOT_LONG,

	/* Insufficient encryption key size error code is used when the client tries to
       access an Attribute Handle's Value for which the link need to be encrypted
       with a key of certain minimum key size and the current link is encrypted
       with a key of lesser size than the minimum required. */
	CYBLE_GATT_ERR_INSUFFICIENT_ENC_KEY_SIZE,

	/*
      Invalid Attribute length error code is used when the Attribute value's
      length is not correct to process the request containing the value.
	*/
	CYBLE_GATT_ERR_INVALID_ATTRIBUTE_LEN,

	/*
      Unlikely error is used when the processing of the Attribute request has
      encountered an error that is not covered by any other error code.
	*/
	CYBLE_GATT_ERR_UNLIKELY_ERROR,

	/* Insufficient encryption error code is used when the client tries to read or
       write an Attribute handle which requires the link to be encrypted and the
       link is currently not encrypted. */
	CYBLE_GATT_ERR_INSUFFICIENT_ENCRYPTION,

	/* Unsupported Group Type error code is used when the Attribute type requested
       in the Read by Group Type request is not a valid grouping attribute on the
       server. */
	CYBLE_GATT_ERR_UNSUPPORTED_GROUP_TYPE,

	/* Insufficient Resources error code is used when the ATT server does not have
      enough resources such as memory etc. to process the request from the client. */
	CYBLE_GATT_ERR_INSUFFICIENT_RESOURCE = 0x11,
    
    /* Other Error Groups for ATT - GATT
     * Reserved: GATT-ATT Error codes 0x12 to 0x7F are reserved for 
     * Application Specific Error Code Range: 0x80 to 0x9F
     * Reserved: 0xA0 to 0xDF 
     * Common Profile & Service Error Code : 0xE0 to 0xFF 
     */

    /* Heart Rate Control Point Not Supported error code is used when a unsupported
       code is written into Heart Rate service Control Point characteristic. */
    CYBLE_GATT_ERR_HEART_RATE_CONTROL_POINT_NOT_SUPPORTED = 0x80u,
    
    /* The notifications of the Cycling Power Vector characteristic cannot be sent 
       due to inappropriate connection parameters. */
    CYBLE_GATT_ERR_CPS_INAPPROPRIATE_CONNECTION_PARAMETERS = 0x80u,

    /* Procedure Already in Progress error code is used when a profile or service
       request cannot be serviced because an operation that has been previously
       triggered is still in progress. */
	CYBLE_GATTS_ERR_PROCEDURE_ALREADY_IN_PROGRESS = 0x80u,
    
    /* Client Characteristic Configuration Descriptor Improperly Configured error
       code is used when a Client Characteristic Configuration descriptor is not
       configured according to the requirements of the profile or service. */
	CYBLE_GATTS_ERR_CCCD_IMPROPERLY_CONFIGURED = 0x81u,
	
	/* Command Not Supported used by the Alert Notification Server when the Client
       sends incorrect value of the Command ID or Category ID of to the Alert
       Notification Control Point Characteristic. */
    CYBLE_GATT_ERR_ANS_COMMAND_NOT_SUPPORTED = 0xA0u,

    /* Client Characteristic Configuration Descriptor Improperly Configured error
       code is used when a Client Characteristic Configuration descriptor is not
       configured according to the requirements of the profile or service. */
	CYBLE_GATT_ERR_CCCD_IMPROPERLY_CONFIGURED = 0xFDu,

	/* The Procedure Already in Progress error code is used when a profile or service
       request cannot be serviced because an operation that has been previously
       triggered is still in progress. */
	CYBLE_GATT_ERR_PROCEDURE_ALREADY_IN_PROGRESS = 0xFEu,
	
	/* Out of Range error code is used when an attribute value is out of range as
	   defined by a profile or service specification. */
	CYBLE_GATT_ERR_OUT_OF_RANGE = 0xFFu

}CYBLE_GATT_ERR_CODE_T;

/* GATT Server Error Response parameter type */
typedef struct
{
    /* Handle in which error is generated */
    CYBLE_GATT_DB_ATTR_HANDLE_T    	attrHandle;

    /* Opcode which has resulted in Error 
       Information on ATT/GATT opcodes is available in the 
       Bluetooth specification.
    */
    uint8              				opcode;

    /* Error Code describing cause of error */
    CYBLE_GATT_ERR_CODE_T			errorCode;
	
}CYBLE_GATTS_ERR_PARAM_T;
/**************************************
##  CyBle_custom.h
**************************************/
/* Maximum supported Custom Services */
#define CYBLE_CUSTOMS_SERVICE_COUNT                  (0x01u)
#define CYBLE_CUSTOMC_SERVICE_COUNT                  (0x00u)
#define CYBLE_CUSTOM_SERVICE_CHAR_COUNT              (0x04u)
#define CYBLE_CUSTOM_SERVICE_CHAR_DESCRIPTORS_COUNT  (0x02u)

/* Below are the indexes and handles of the defined Custom Services and their characteristics */
#define CYBLE_CUSTOM_SERVICE_SERVICE_INDEX   (0x00u) /* Index of Custom Service service in the cyBle_customs array */
#define CYBLE_CUSTOM_SERVICE_NOW_ML_CHAR_INDEX   (0x00u) /* Index of Now ML characteristic */
#define CYBLE_CUSTOM_SERVICE_NOW_ML_CUSTOM_DESCRIPTOR_DESC_INDEX   (0x00u) /* Index of Custom Descriptor descriptor */
#define CYBLE_CUSTOM_SERVICE_NOW_ML_CLIENT_CHARACTERISTIC_CONFIGURATION_DESC_INDEX   (0x01u) /* Index of Client Characteristic Configuration descriptor */
#define CYBLE_CUSTOM_SERVICE_TMP_ML_CHAR_INDEX   (0x01u) /* Index of Tmp ML characteristic */
#define CYBLE_CUSTOM_SERVICE_TMP_ML_CUSTOM_DESCRIPTOR_DESC_INDEX   (0x00u) /* Index of Custom Descriptor descriptor */
#define CYBLE_CUSTOM_SERVICE_TMP_ML_CLIENT_CHARACTERISTIC_CONFIGURATION_DESC_INDEX   (0x01u) /* Index of Client Characteristic Configuration descriptor */
#define CYBLE_CUSTOM_SERVICE_RECALIBATION_CHAR_INDEX   (0x02u) /* Index of ReCalibation characteristic */
#define CYBLE_CUSTOM_SERVICE_RECALIBATION_CUSTOM_DESCRIPTOR_DESC_INDEX   (0x00u) /* Index of Custom Descriptor descriptor */
#define CYBLE_CUSTOM_SERVICE_BUTTON_UPDATA_CHAR_INDEX   (0x03u) /* Index of Button updata characteristic */
#define CYBLE_CUSTOM_SERVICE_BUTTON_UPDATA_CUSTOM_DESCRIPTOR_DESC_INDEX   (0x00u) /* Index of Custom Descriptor descriptor */
#define CYBLE_CUSTOM_SERVICE_BUTTON_UPDATA_CLIENT_CHARACTERISTIC_CONFIGURATION_DESC_INDEX   (0x01u) /* Index of Client Characteristic Configuration descriptor */


#define CYBLE_CUSTOM_SERVICE_SERVICE_HANDLE   (0x000Cu) /* Handle of Custom Service service */
#define CYBLE_CUSTOM_SERVICE_NOW_ML_DECL_HANDLE   (0x000Du) /* Handle of Now ML characteristic declaration */
#define CYBLE_CUSTOM_SERVICE_NOW_ML_CHAR_HANDLE   (0x000Eu) /* Handle of Now ML characteristic */
#define CYBLE_CUSTOM_SERVICE_NOW_ML_CUSTOM_DESCRIPTOR_DESC_HANDLE   (0x000Fu) /* Handle of Custom Descriptor descriptor */
#define CYBLE_CUSTOM_SERVICE_NOW_ML_CLIENT_CHARACTERISTIC_CONFIGURATION_DESC_HANDLE   (0x0010u) /* Handle of Client Characteristic Configuration descriptor */
#define CYBLE_CUSTOM_SERVICE_TMP_ML_DECL_HANDLE   (0x0011u) /* Handle of Tmp ML characteristic declaration */
#define CYBLE_CUSTOM_SERVICE_TMP_ML_CHAR_HANDLE   (0x0012u) /* Handle of Tmp ML characteristic */
#define CYBLE_CUSTOM_SERVICE_TMP_ML_CUSTOM_DESCRIPTOR_DESC_HANDLE   (0x0013u) /* Handle of Custom Descriptor descriptor */
#define CYBLE_CUSTOM_SERVICE_TMP_ML_CLIENT_CHARACTERISTIC_CONFIGURATION_DESC_HANDLE   (0x0014u) /* Handle of Client Characteristic Configuration descriptor */
#define CYBLE_CUSTOM_SERVICE_RECALIBATION_DECL_HANDLE   (0x0015u) /* Handle of ReCalibation characteristic declaration */
#define CYBLE_CUSTOM_SERVICE_RECALIBATION_CHAR_HANDLE   (0x0016u) /* Handle of ReCalibation characteristic */
#define CYBLE_CUSTOM_SERVICE_RECALIBATION_CUSTOM_DESCRIPTOR_DESC_HANDLE   (0x0017u) /* Handle of Custom Descriptor descriptor */
#define CYBLE_CUSTOM_SERVICE_BUTTON_UPDATA_DECL_HANDLE   (0x0018u) /* Handle of Button updata characteristic declaration */
#define CYBLE_CUSTOM_SERVICE_BUTTON_UPDATA_CHAR_HANDLE   (0x0019u) /* Handle of Button updata characteristic */
#define CYBLE_CUSTOM_SERVICE_BUTTON_UPDATA_CUSTOM_DESCRIPTOR_DESC_HANDLE   (0x001Au) /* Handle of Custom Descriptor descriptor */
#define CYBLE_CUSTOM_SERVICE_BUTTON_UPDATA_CLIENT_CHARACTERISTIC_CONFIGURATION_DESC_HANDLE   (0x001Bu) /* Handle of Client Characteristic Configuration descriptor */

/** Contains information about Custom Characteristic structure */
typedef struct
{
    /** Custom Characteristic handle */
    CYBLE_GATT_DB_ATTR_HANDLE_T customServCharHandle;
    /** Custom Characteristic Descriptors handles */
    CYBLE_GATT_DB_ATTR_HANDLE_T customServCharDesc[     /* MDK doesn't allow array with zero length */
        CYBLE_CUSTOM_SERVICE_CHAR_DESCRIPTORS_COUNT == 0u ? 1u : CYBLE_CUSTOM_SERVICE_CHAR_DESCRIPTORS_COUNT];
} CYBLE_CUSTOMS_INFO_T;

/** Structure with Custom Service attribute handles. */
typedef struct
{
    /** Handle of a Custom Service */
    CYBLE_GATT_DB_ATTR_HANDLE_T customServHandle;
    
    /** Information about Custom Characteristics */
    CYBLE_CUSTOMS_INFO_T customServInfo[                /* MDK doesn't allow array with zero length */
        CYBLE_CUSTOM_SERVICE_CHAR_COUNT == 0u ? 1u : CYBLE_CUSTOM_SERVICE_CHAR_COUNT];
} CYBLE_CUSTOMS_T;

extern const CYBLE_CUSTOMS_T cyBle_customs[CYBLE_CUSTOMS_SERVICE_COUNT];


/* DIS characteristic index */
typedef enum
{
    CYBLE_DIS_MANUFACTURER_NAME,                    /* Manufacturer Name String characteristic index */
    CYBLE_DIS_MODEL_NUMBER,                         /* Model Number String characteristic index */
    CYBLE_DIS_SERIAL_NUMBER,                        /* Serial Number String characteristic index*/
    CYBLE_DIS_HARDWARE_REV,                         /* Hardware Revision String characteristic index */
    CYBLE_DIS_FIRMWARE_REV,                         /* Firmware Revision String characteristic index */
    CYBLE_DIS_SOFTWARE_REV,                         /* Software Revision String characteristic index */
    CYBLE_DIS_SYSTEM_ID,                            /* System ID characteristic index */
    CYBLE_DIS_REG_CERT_DATA,                        /* IEEE 11073-20601 characteristic index */
    CYBLE_DIS_PNP_ID,                               /* PnP ID characteristic index */
    CYBLE_DIS_CHAR_COUNT                            /* Total count of DIS characteristics */

}CYBLE_DIS_CHAR_INDEX_T;

/* Structure with Device Information Service attribute handles */
typedef struct
{
    /* Device Information Service handle */
    CYBLE_GATT_DB_ATTR_HANDLE_T serviceHandle;
    
    /* Device Information Service Characteristic handles */
    CYBLE_GATT_DB_ATTR_HANDLE_T charHandle[CYBLE_DIS_CHAR_COUNT];
} CYBLE_DISS_T;

/* Structure with HID Service attribute handles */
typedef struct
{
    CYBLE_GATT_DB_ATTR_HANDLE_T serviceHandle;         /* Handle of HID service */
    CYBLE_GATT_DB_ATTR_HANDLE_T protocolModeHandle;    /* Handle of Protocol Mode Characteristic */
    uint8 reportCount;                                 /* Number of report Characteristics */
    const CYBLE_HIDSS_REPORT_T *reportArray;           /* Info about report Characteristics */
    CYBLE_HIDSS_REPORT_T bootReportArray[3u]; /* Info about Boot Report Characteristics */
    CYBLE_GATT_DB_ATTR_HANDLE_T reportMapHandle;       /* Handle of Report Map Characteristic */
    CYBLE_GATT_DB_ATTR_HANDLE_T reportMapErrdHandle;   /* Handle of Report Map External Report Reference descr. */
    CYBLE_GATT_DB_ATTR_HANDLE_T informationHandle;     /* Handle of HID Information Characteristic */
    CYBLE_GATT_DB_ATTR_HANDLE_T controlPointHandle;    /* Handle of HID Control Point Characteristic */
} CYBLE_HIDSS_T;

/* Structure with Battery Service attribute handles */
typedef struct
{
    CYBLE_GATT_DB_ATTR_HANDLE_T serviceHandle;              /* Battery Service handle */
    CYBLE_GATT_DB_ATTR_HANDLE_T batteryLevelHandle;         /* Battery Level characteristic handle */
    CYBLE_GATT_DB_ATTR_HANDLE_T cpfdHandle;                 /* Characteristic Presentation Format Descriptor handle */
    CYBLE_GATT_DB_ATTR_HANDLE_T cccdHandle;                 /* Client Characteristic Configuration descriptor handle */
} CYBLE_BASS_T;

/* Data Element for Group Response */
typedef struct
{
    /* atribute handle value pair */
    uint8              * attrValue;

    /* Length of each Attribute Data Element including the Handle Range */
    uint16             length;

    /* Total Length of Attribute Data */
    uint16             attrLen;
}CYBLE_GATTC_GRP_ATTR_DATA_LIST_T;

/* Read By Group Response received from Server*/
typedef struct
{
	/* Connection handle */
	CYBLE_CONN_HANDLE_T 		  		connHandle; 

	/*group attribute data list*/
	CYBLE_GATTC_GRP_ATTR_DATA_LIST_T 	attrData;
	
}CYBLE_GATTC_READ_BY_GRP_RSP_PARAM_T;

/* GATT read by type response received from server*/
typedef CYBLE_GATTC_READ_BY_GRP_RSP_PARAM_T CYBLE_GATTC_READ_BY_TYPE_RSP_PARAM_T;

/* GATT list of Handle UUID pair parameter type */
typedef struct
{
	/* Handle - UUID Pair list
	   This is a packed byte stream, hence it needs to be unpacked and decoded. */
    uint8  	*list; 	

	/* Number of elements in the list in bytes */
    uint16  byteCount;
	
}CYBLE_GATTC_HANDLE_UUID_LIST_PARAM_T;


/* GATT find info response received from Server*/
typedef struct
{
	/* Connection handle */
	CYBLE_CONN_HANDLE_T 					connHandle;
	
	/* Handle Value List */	
    CYBLE_GATTC_HANDLE_UUID_LIST_PARAM_T   	handleValueList;  

	/* Format indicating, 16 bit (0x01) or 128 bit (0x02) UUIDs */	
    uint8                   				uuidFormat;     	
	
}CYBLE_GATTC_FIND_INFO_RSP_PARAM_T;

/* Opcode which has resulted in error */
typedef enum
{
	/* Error Response PDU */
	CYBLE_GATT_ERROR_RSP = 0x01u,

	/* Exchange MTU Request PDU */
	CYBLE_GATT_XCNHG_MTU_REQ,

	/* Exchange MTU Response PDU */
	CYBLE_GATT_XCHNG_MTU_RSP,

	/* Find Information Request PDU */
	CYBLE_GATT_FIND_INFO_REQ,

	/* Find Information Response PDU */
	CYBLE_GATT_FIND_INFO_RSP,

	/* Find By Type Value Request PDU */
	CYBLE_GATT_FIND_BY_TYPE_VALUE_REQ,

	/* Find By Type Value Response PDU */
	CYBLE_GATT_FIND_BY_TYPE_VALUE_RSP,

	/* Read By Type Request PDU */
	CYBLE_GATT_READ_BY_TYPE_REQ,

	/* Read By Type Response PDU */
	CYBLE_GATT_READ_BY_TYPE_RSP,

	/* Read Request PDU */
	CYBLE_GATT_READ_REQ,

	/* Read Response PDU */
	CYBLE_GATT_READ_RSP,

	/* Read Blob Request PDU */
	CYBLE_GATT_READ_BLOB_REQ,

	/* Read Blob Response PDU */
	CYBLE_GATT_READ_BLOB_RSP,

	/* Read Multiple Request PDU */
	CYBLE_GATT_READ_MULTIPLE_REQ,

	/* Read Multiple Response PDU */
	CYBLE_GATT_READ_MULTIPLE_RSP,

	/* Read Group Type Request PDU */
	CYBLE_GATT_READ_BY_GROUP_REQ,

	/* Read Group Type Response PDU */
	CYBLE_GATT_READ_BY_GROUP_RSP,

	/* Write Request PDU */
	CYBLE_GATT_WRITE_REQ,

	/* Write Response PDU */
	CYBLE_GATT_WRITE_RSP,

	/* Write Command PDU */
	CYBLE_GATT_WRITE_CMD = 0x52u,

	/* Prepare Write Request PDU */
	CYBLE_GATT_PREPARE_WRITE_REQ = 0x16u,

	/* Prepare Write Response PDU */
	CYBLE_GATT_PREPARE_WRITE_RSP,

	/* Execute Write Request PDU */
	CYBLE_GATT_EXECUTE_WRITE_REQ,

	/* Execute Write Response PDU */
	CYBLE_GATT_EXECUTE_WRITE_RSP,

	/* Handle Value Notification PDU */
	CYBLE_GATT_HANDLE_VALUE_NTF = 0x1Bu,

	/* Handle Value Indication PDU */
	CYBLE_GATT_HANDLE_VALUE_IND = 0x1Du,

	/* Handle Value Confirmation PDU */
	CYBLE_GATT_HANDLE_VALUE_CNF = 0x1Eu,

	/*Signed Write Command PDU */
	CYBLE_GATT_SIGNED_WRITE_CMD = 0xD2,
    
	/* Unknown or Unhandled PDU */
	CYBLE_GATT_UNKNOWN_PDU_IND = 0xFFu

}CYBLE_GATT_PDU_T;


typedef struct
{
	/* Connection handle */ 
	CYBLE_CONN_HANDLE_T 			connHandle;

    /* Opcode which has resulted in Error */
    CYBLE_GATT_PDU_T    			opCode;

    /* Attribute Handle in which error is generated */
    CYBLE_GATT_DB_ATTR_HANDLE_T    	attrHandle;

    /* Error Code describing cause of error */
    CYBLE_GATT_ERR_CODE_T			errorCode;
	
}CYBLE_GATTC_ERR_RSP_PARAM_T;

#define CYBLE_HID_SERVICE_HANDLE      (0x000cu)
#define CYBLE_DIS_SERVICE_HANDLE      (0x0021u)
#define CYBLE_BAS_SERVICE_HANDLE      (0x0028u)
#define CYBLE_SCPS_SERVICE_HANDLE     (0x002Du)
#define CYBLE_BTS_SERVICE_HANDLE      (0x0033u)

/* Structure with Scan Parameters Service attribute handles */
typedef struct
{
    CYBLE_GATT_DB_ATTR_HANDLE_T serviceHandle;            /* Scan Parameter Service handle*/
    CYBLE_GATT_DB_ATTR_HANDLE_T intervalWindowCharHandle; /* Handle of Scan Interval Window Characteristic */
    CYBLE_GATT_DB_ATTR_HANDLE_T refreshCharHandle;        /* Handle of Scan Refresh Characteristic */
    CYBLE_GATT_DB_ATTR_HANDLE_T refreshCccdHandle;        /* Handle of Client Characteristic Configuration Descriptor */
} CYBLE_SCPSS_T;


/* Bootloader #defines */
/***************************************
##Conditional Compilation Parameters
***************************************/

/* Maximum supported Custom Services */
#define CYBLE_BT_SERVICE_COUNT                       (0x01u)
#define CYBLE_BT_SERVICE_CHAR_COUNT                  (0x01u)
#define CYBLE_BT_SERVICE_CHAR_DESCRIPTORS_COUNT      (0x01u)
    

/***************************************
##Data Struct Definition
***************************************/

/* Contains information about Bootloader Characteristic structure */
typedef struct
{
    /* Bootloader Characteristic handle */
    CYBLE_GATT_DB_ATTR_HANDLE_T btServiceCharHandle;
    /* Bootloader Characteristic Descriptors handles */
    CYBLE_GATT_DB_ATTR_HANDLE_T btServiceCharDescriptors[CYBLE_BT_SERVICE_CHAR_DESCRIPTORS_COUNT];
} CYBLE_BTS_INFO_T;

/* Structure with Bootloader Service attribute handles. */
typedef struct
{
    /* Handle of a Bootloader Service */
    CYBLE_GATT_DB_ATTR_HANDLE_T btServiceHandle;
    
    /* Information about Bootloader Characteristics */
    CYBLE_BTS_INFO_T btServiceInfo[CYBLE_BT_SERVICE_CHAR_COUNT];
} CYBLE_BTSS_T;


/***************************************
##API Constants
***************************************/

#define CYBLE_BTS_COMMAND_DATA_LEN_OFFSET                 (2u)
#define CYBLE_BTS_COMMAND_CONTROL_BYTES_NUM               (7u)
#define CYBLE_BTS_MTU_OVERHEAD                            (5u)
#define CYBLE_BTS_COMMAND_MAX_LENGTH                      (144u)


/**************************************
##BLE event codes
**************************************/
/* Service specific events  */
typedef enum
{
    /****************************************
     Security Events
     ***************************************/
    /* \cond IGNORE */

    CYBLE_AUTHENTICATION_REQUEST_REPLY = CYBLE_EVT_MAX + 1, /* 0x100 */
    CYBLE_PASSKEY_ENTRY_REQUEST_REPLY,
    CYBLE_LONG_TERM_KEY_REQUEST_REPLY,
    CYBLE_KEY_EXCHANGE_INFO_REQUEST_REPLY,
    /* \endcond */
    
    /****************************************
     GATT Service Events
     ***************************************/
    
    /** GATT Server - Notifications for GATT Service's "Service Changed"
        Characteristic were enabled. The parameter of this event is a structure of
        CYBLE_GATTS_WRITE_REQ_PARAM_T type.
    */
    CYBLE_EVT_GATTS_INDICATION_ENABLED,
    
    /** GATT Server - Notifications for GATT Service's "Service Changed"
        Characteristic were disabled. The parameter of this event is a structure of
        CYBLE_GATTS_WRITE_REQ_PARAM_T type.
    */
    CYBLE_EVT_GATTS_INDICATION_DISABLED,
    
    /** GATT Client - GATT Service's "Service Changed" Characteristic Indications 
        were received. The parameter of this event is a structure
        of CYBLE_GATTC_HANDLE_VALUE_IND_PARAM_T type.
    */
    CYBLE_EVT_GATTC_INDICATION,
    
    
    /****************************************
     Service Discovery Events
     ***************************************/
    
    /** GATT Client - Service discovery procedure failed. This event may
        be generated on calling CyBle_GattcDiscoverAllPrimaryServices().
        No parameters passed for this event.
    */
    CYBLE_EVT_GATTC_SRVC_DISCOVERY_FAILED,
    
    /** GATT Client - Discovery of included services failed. This event may
        be generated on calling CyBle_GattcFindIncludedServices().
        No parameters passed for this event.
    */
    CYBLE_EVT_GATTC_INCL_DISCOVERY_FAILED,
    
    /** GATT Client - Discovery of service's characteristics failed. This event may
        be generated on calling CyBle_GattcDiscoverAllCharacteristics() or
        CyBle_GattcReadUsingCharacteristicUuid(). 
        No parameters passed for this event.
    */
    CYBLE_EVT_GATTC_CHAR_DISCOVERY_FAILED,
    
    /** GATT Client - Discovery of service's characteristics failed. This event may
        be generated on calling CyBle_GattcDiscoverAllCharacteristicDescriptors().
        No parameters passed for this event.
    */
    CYBLE_EVT_GATTC_DESCR_DISCOVERY_FAILED,
    
    /** GATT Client - Duplicate service record was found during server device
        discovery. The parameter of this event is a structure of uint16 (UUID16)
        type.
    */
    CYBLE_EVT_GATTC_SRVC_DUPLICATION,
    
    /** GATT Client - Duplicate service's characteristic record was found during 
        server device discovery. The parameter of this event is a structure
        of uint16 (UUID16) type.
    */
    CYBLE_EVT_GATTC_CHAR_DUPLICATION,
    
    /** GATT Client - Duplicate service's characteristic descriptor record was found
        during server device discovery. The parameter of this event is a structure
        of uint16 (UUID16) type.
    */
    CYBLE_EVT_GATTC_DESCR_DUPLICATION,
    
    /** GATT Client - Service discovery procedure completed successfully. This
        event may be generated on calling CyBle_GattcDiscoverAllPrimaryServices().
        No parameters passed for this event.
    */
    CYBLE_EVT_GATTC_SRVC_DISCOVERY_COMPLETE,
    
    /** GATT Client - Included services discovery is completed
        successfully. This event may be generated on calling
        CyBle_GattcFindIncludedServices().
        No parameters passed for this event.
    */
    CYBLE_EVT_GATTC_INCL_DISCOVERY_COMPLETE,
    
    /** GATT Client - Discovery of service's characteristics discovery is completed
        successfully. This event may be generated on calling
        CyBle_GattcDiscoverAllCharacteristics() or
        CyBle_GattcReadUsingCharacteristicUuid().
        No parameters passed for this event.
    */
    CYBLE_EVT_GATTC_CHAR_DISCOVERY_COMPLETE,
    
    /** GATT Client - Discovery of remote device completed successfully.
        No parameters passed for this event.
    */
    CYBLE_EVT_GATTC_DISCOVERY_COMPLETE,
    
    
    /****************************************
     ANCS Service Events
     ***************************************/
    
    /** ANCS Server - Notifications for Apple Notification Center Service Characteristic
        were enabled. The parameter of this event is a structure of
        CYBLE_ANCS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_ANCSS_NOTIFICATION_ENABLED,
    
    /** ANCS Server - Notifications for Apple Notification Center Service Characteristic
        were disabled. The parameter of this event is a structure of
        CYBLE_ANCS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_ANCSS_NOTIFICATION_DISABLED,

    /** ANCS Server - Write Request for Apple Notification Center Service Characteristic 
        was received. The parameter of this event is a structure
        of CYBLE_ANCS_CHAR_VALUE_T type.
    */  
    CYBLE_EVT_ANCSS_WRITE_CHAR,
    
    /** ANCS Client - Apple Notification Center Characteristic Service Notification 
        was received. The parameter of this event is a structure
        of CYBLE_ANCS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_ANCSC_NOTIFICATION,
    
    /** ANCS Client - Read Response for Apple Notification Center Service Characteristic
        Value. The parameter of this event is a structure of 
        CYBLE_ANCS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_ANCSC_READ_CHAR_RESPONSE,

    /** ANCS Client - Write Response for Write Request for Apple Notification Center Service
        Characteristic Value. The parameter of this event is a structure of 
        CYBLE_ANCS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_ANCSC_WRITE_CHAR_RESPONSE,

    /** ANCS Client - Read Response for Read Request for Apple Notification Center Service
        Characteristic Descriptor Read Request. The parameter of this event is a
        structure of CYBLE_ANCS_DESCR_VALUE_T type.
    */
    CYBLE_EVT_ANCSC_READ_DESCR_RESPONSE,

    /** ANCS Client - Write Response for Write Request for Apple Notification Center Service
        Client Characteristic Configuration Descriptor Value. The parameter of
        this event is a structure of CYBLE_ANCS_DESCR_VALUE_T type.
    */
    CYBLE_EVT_ANCSC_WRITE_DESCR_RESPONSE,
    
    /** ANCS Client - Error Response for Write Request for Apple Notification Center Service
        Characteristic Value. The parameter of this event is a structure of 
        CYBLE_ANCS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_ANCSC_ERROR_RESPONSE,
    
    
    /****************************************
     ANS Service Events
     ***************************************/
    
    /** ANS Server - Notifications for Alert Notification Service Characteristic
        were enabled. The parameter of this event is a structure of
        CYBLE_ANS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_ANSS_NOTIFICATION_ENABLED,
    
    /** ANS Server - Notifications for Alert Notification Service Characteristic
        were disabled. The parameter of this event is a structure of
        CYBLE_ANS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_ANSS_NOTIFICATION_DISABLED,

    /** ANS Server - Write Request for Alert Notification Service Characteristic 
        was received. The parameter of this event is a structure
        of CYBLE_ANS_CHAR_VALUE_T type.
    */  
    CYBLE_EVT_ANSS_CHAR_WRITE,
    
    /** ANS Client - Alert Notification Characteristic Service Notification 
        was received. The parameter of this event is a structure
        of CYBLE_ANS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_ANSC_NOTIFICATION,
    
    /** ANS Client - Read Response for Alert Notification Service Characteristic
        Value. The parameter of this event is a structure of 
        CYBLE_ANS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_ANSC_READ_CHAR_RESPONSE,

    /** ANS Client - Write Response for Write Request for Alert Notification Service
        Characteristic Value. The parameter of this event is a structure of 
        CYBLE_ANS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_ANSC_WRITE_CHAR_RESPONSE,

    /** ANS Client - Read Response for Read Request for Alert Notification Service
        Characteristic Descriptor Read Request. The parameter of this event is a
        structure of CYBLE_ANS_DESCR_VALUE_T type.
    */
    CYBLE_EVT_ANSC_READ_DESCR_RESPONSE,

    /** ANS Client - Write Response for Write Request for Alert Notification Service
        Client Characteristic Configuration Descriptor Value. The parameter of
        this event is a structure of CYBLE_ANS_DESCR_VALUE_T type.
    */
    CYBLE_EVT_ANSC_WRITE_DESCR_RESPONSE,

    
    /****************************************
     BAS Service Events
     ***************************************/
    
    /** BAS Server - Notifications for Battery Level Characteristic were enabled. The
        parameter of this event is a structure of CYBLE_BAS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_BASS_NOTIFICATION_ENABLED,
    
    /** BAS Server - Notifications for Battery Level Characteristic were disabled. The
        parameter of this event is a structure of CYBLE_BAS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_BASS_NOTIFICATION_DISABLED,
    
    /** BAS Client - Battery Level Characteristic Notification was received. The 
        parameter of this event is a structure of CYBLE_BAS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_BASC_NOTIFICATION,
    
    /** BAS Client - Read Response for Battery Level Characteristic Value. The 
        parameter of this event is a structure of CYBLE_BAS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_BASC_READ_CHAR_RESPONSE,
    
    /** BAS Client - Read Response for Battery Level Characteristic Descriptor Read 
        Request. The parameter of this event is a structure of 
        CYBLE_BAS_DESCR_VALUE_T type.
    */
    CYBLE_EVT_BASC_READ_DESCR_RESPONSE,
    
    /** BAS Client - Write Response for Battery Level Client Characteristic 
        Configuration Descriptor Value. The parameter of this event is a structure of 
        CYBLE_BAS_DESCR_VALUE_T type.
    */
    CYBLE_EVT_BASC_WRITE_DESCR_RESPONSE,
    
    
    /****************************************
     Body Composition Service Events
     ***************************************/

    /** BCS Server - Indication for Body Composition Service Characteristic
        was enabled. The parameter of this event is a structure 
        of CYBLE_BCS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_BCSS_INDICATION_ENABLED,

    /** BCS Server - Indication for Body Composition Service Characteristic
        was disabled. The parameter of this event is a structure 
        of CYBLE_BCS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_BCSS_INDICATION_DISABLED,

    /** BCS Server - Body Composition Service Characteristic
        Indication was confirmed. The parameter of this event
        is a structure of CYBLE_BCS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_BCSS_INDICATION_CONFIRMED,

    /** BCS Client - Body Composition Service Characteristic
        Indication was received. The parameter of this event
        is a structure of CYBLE_BCS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_BCSC_INDICATION,
    
    /** BCS Client - Read Response for Read Request of Body Composition 
        Service Characteristic value. The parameter of this event
        is a structure of CYBLE_BCS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_BCSC_READ_CHAR_RESPONSE,

    /** BCS Client - Read Response for Read Request of Body Composition
        Service Characteristic Descriptor Read request. The 
        parameter of this event is a structure of
        CYBLE_BCS_DESCR_VALUE_T type.
    */
    CYBLE_EVT_BCSC_READ_DESCR_RESPONSE,

    /** BCS Client - Write Response for Write Request of Body Composition
        Service Characteristic Configuration Descriptor value.
        The parameter of this event is a structure of 
        CYBLE_BCS_DESCR_VALUE_T type.
    */
    CYBLE_EVT_BCSC_WRITE_DESCR_RESPONSE,

    /****************************************
     Blood Pressure Service Events
     ***************************************/
    
    /** BLS Server - Indication for Blood Pressure Service Characteristic was enabled.
        The parameter of this event is a structure of CYBLE_BLS_CHAR_VALUE_T type
    */
    CYBLE_EVT_BLSS_INDICATION_ENABLED,
    
    /** BLS Server - Indication for Blood Pressure Service Characteristic was 
        disabled. The parameter of this event is a structure of 
        CYBLE_BLS_CHAR_VALUE_T type
    */
    CYBLE_EVT_BLSS_INDICATION_DISABLED,

    /** BLS Server - Blood Pressure Service Characteristic Indication was confirmed.
        The parameter of this event is a structure of CYBLE_BLS_CHAR_VALUE_T type
    */
    CYBLE_EVT_BLSS_INDICATION_CONFIRMED,
 
    /** BLS Server - Notifications for Blood Pressure Service Characteristic
        were enabled. The parameter of this event is a structure of
        CYBLE_BLS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_BLSS_NOTIFICATION_ENABLED,
    
    /** BLS Server - Notifications for Blood Pressure Service Characteristic
        were disabled. The parameter of this event is a structure of
        CYBLE_BLS_CHAR_VALUE_T type
    */
    CYBLE_EVT_BLSS_NOTIFICATION_DISABLED,
    
    /** BLS Client - Blood Pressure Service Characteristic Indication was received. 
        The parameter of this event is a structure of CYBLE_BLS_CHAR_VALUE_T type
    */
    CYBLE_EVT_BLSC_INDICATION,
    
    /** BLS Client - Blood Pressure Service Characteristic Notification was received.
        The parameter of this event is a structure of CYBLE_BLS_CHAR_VALUE_T type
    */
    CYBLE_EVT_BLSC_NOTIFICATION,
    
    /** BLS Client - Read Response for Read Request of Blood Pressure Service 
        Characteristic value. The parameter of this event is a structure of
        CYBLE_BLS_CHAR_VALUE_T type
    */
    CYBLE_EVT_BLSC_READ_CHAR_RESPONSE,
    
    /** BLS Client - Read Response for Read Request of Blood Pressure Service 
        Characteristic Descriptor Read request. The parameter of this event is a
        structure of CYBLE_BLS_DESCR_VALUE_T type
    */
    CYBLE_EVT_BLSC_READ_DESCR_RESPONSE,
    
    /** BLS Client - Write Response for Write Request of Blood Pressure Service
        Characteristic Configuration Descriptor value. The parameter of this event
        is a structure of CYBLE_BLS_DESCR_VALUE_T type
    */
    CYBLE_EVT_BLSC_WRITE_DESCR_RESPONSE,
    

    /****************************************
     Bond Management Service Events
     ***************************************/
    
    /** BMS Server - Write Request for Glucose Service 
        was received. The parameter of this event is a structure
        of CYBLE_BMS_CHAR_VALUE_T type.
    */    
    CYBLE_EVT_BMSS_WRITE_CHAR,
    
    /** BMS Client - Read Response for Read Request of Bond Management Service 
        Characteristic value. The parameter of this event is a structure of
        CYBLE_BMS_CHAR_VALUE_T type
    */
    CYBLE_EVT_BMSC_READ_CHAR_RESPONSE,
    
    /** BMS Client - Write Response for Write Request of Bond Management
        Service Characteristic value. The 
        parameter of this event is a structure of
        CYBLE_BMS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_BMSC_WRITE_CHAR_RESPONSE,
    
    /** BMS Client - Read Response for Read Request of Bond Management Service 
        Characteristic Descriptor Read request. The parameter of this event is a
        structure of CYBLE_BMS_DESCR_VALUE_T type.
    */
    CYBLE_EVT_BMSC_READ_DESCR_RESPONSE,
    
    
    /****************************************
     CGM Service Events
     ***************************************/
    
    /** CGMS Server - Indication for Glucose Service Characteristic
        was enabled. The parameter of this event is a structure 
        of CYBLE_CGMS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_CGMSS_INDICATION_ENABLED,
    
    /** CGMS Server - Indication for Glucose Service Characteristic
        was disabled. The parameter of this event is a structure 
        of CYBLE_CGMS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_CGMSS_INDICATION_DISABLED,
    
    /** CGMS Server - Glucose Service Characteristic
        Indication was confirmed. The parameter of this event
        is a structure of CYBLE_CGMS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_CGMSS_INDICATION_CONFIRMED,
    
    /** CGMS Server - Notifications for Glucose Service Characteristic
        was enabled. The parameter of this event is a structure of
        CYBLE_CGMS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_CGMSS_NOTIFICATION_ENABLED,
    
    /** CGMS Server - Notifications for Glucose Service Characteristic
        were disabled. The parameter of this event is a structure 
        of CYBLE_CGMS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_CGMSS_NOTIFICATION_DISABLED,
    
    /** CGMS Server - Write Request for Glucose Service 
        was received. The parameter of this event is a structure
        of CYBLE_CGMS_CHAR_VALUE_T type.
    */    
    CYBLE_EVT_CGMSS_WRITE_CHAR,
    
    /** CGMS Client - Glucose Service Characteristic
        Indication was received. The parameter of this event
        is a structure of CYBLE_CGMS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_CGMSC_INDICATION,
    
    /** CGMS Client - Glucose Service Characteristic
        Notification was received. The parameter of this event
        is a structure of CYBLE_CGMS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_CGMSC_NOTIFICATION,
    
    /** CGMS Client - Read Response for Read Request of Glucose 
        Service Characteristic value. The parameter of this event
        is a structure of CYBLE_CGMS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_CGMSC_READ_CHAR_RESPONSE,
    
    /** CGMS Client - Write Response for Write Request of Glucose
        Service Characteristic value. The 
        parameter of this event is a structure of
        CYBLE_CGMS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_CGMSC_WRITE_CHAR_RESPONSE,
    
    /** CGMS Client - Read Response for Read Request of Glucose
        Service Characteristic Descriptor Read request. The 
        parameter of this event is a structure of
        CYBLE_CGMS_DESCR_VALUE_T type.
    */
    CYBLE_EVT_CGMSC_READ_DESCR_RESPONSE,
    
    /** CGMS Client - Write Response for Write Request of Glucose
        Service Characteristic Configuration Descriptor value.
        The parameter of this event is a structure of 
        CYBLE_CGMS_DESCR_VALUE_T type.
    */
    CYBLE_EVT_CGMSC_WRITE_DESCR_RESPONSE,
    
    
    /****************************************
     CPS Service Events
     ***************************************/
    
    /** CPS Server - Notifications for Cycling Power Service Characteristic
        was enabled. The parameter of this event is a structure of
        CYBLE_CPS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_CPSS_NOTIFICATION_ENABLED,
    
    /** CPS Server - Notifications for Cycling Power Service Characteristic
        were disabled. The parameter of this event is a structure 
        of CYBLE_CPS_CHAR_VALUE_T type
    */
    CYBLE_EVT_CPSS_NOTIFICATION_DISABLED,
    
    /** CPS Server - Indication for Cycling Power Service Characteristic
        was enabled. The parameter of this event is a structure 
        of CYBLE_CPS_CHAR_VALUE_T type
    */
    CYBLE_EVT_CPSS_INDICATION_ENABLED,
    
    /** CPS Server - Indication for Cycling Power Service Characteristic
        was disabled. The parameter of this event is a structure 
        of CYBLE_CPS_CHAR_VALUE_T type
    */
    CYBLE_EVT_CPSS_INDICATION_DISABLED,
    
    /** CPS Server - Cycling Power Service Characteristic
        Indication was confirmed. The parameter of this event
        is a structure of CYBLE_CPS_CHAR_VALUE_T type
    */
    CYBLE_EVT_CPSS_INDICATION_CONFIRMED,
    
    /** CPS Server - Broadcast for Cycling Power Service Characteristic
        was enabled. The parameter of this event
        is a structure of CYBLE_CPS_CHAR_VALUE_T type
    */
    CYBLE_EVT_CPSS_BROADCAST_ENABLED,
    
    /** CPS Server - Broadcast for Cycling Power Service Characteristic
        was disabled. The parameter of this event
        is a structure of CYBLE_CPS_CHAR_VALUE_T type
    */
    CYBLE_EVT_CPSS_BROADCAST_DISABLED,
    
    /** CPS Server - Write Request for Cycling Power Service Characteristic 
        was received. The parameter of this event is a structure
        of CYBLE_CPS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_CPSS_CHAR_WRITE,
    
    /** CPS Client - Cycling Power Service Characteristic
        Notification was received. The parameter of this event
        is a structure of CYBLE_CPS_CHAR_VALUE_T type
    */
    CYBLE_EVT_CPSC_NOTIFICATION,
    
    /** CPS Client - Cycling Power Service Characteristic
        Indication was received. The parameter of this event
        is a structure of CYBLE_CPS_CHAR_VALUE_T type
    */
    CYBLE_EVT_CPSC_INDICATION,
    
    /** CPS Client - Read Response for Read Request of Cycling Power Service
        Characteristic value. The parameter of this event
        is a structure of CYBLE_CPS_CHAR_VALUE_T type
    */
    CYBLE_EVT_CPSC_READ_CHAR_RESPONSE,

    /** CPS Client - Write Response for Write Request of Cycling Power Service
        Characteristic value. The parameter of this event
        is a structure of CYBLE_CPS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_CPSC_WRITE_CHAR_RESPONSE,
    
    /** CPS Client - Read Response for Read Request of Cycling Power
        Service Characteristic Descriptor Read request. The 
        parameter of this event is a structure of
        CYBLE_CPS_DESCR_VALUE_T type.
    */
    CYBLE_EVT_CPSC_READ_DESCR_RESPONSE,
    
    /** CPS Client - Write Response for Write Request of Cycling Power
        Service Characteristic Configuration Descriptor value.
        The parameter of this event is a structure of 
        CYBLE_CPS_DESCR_VALUE_T type.
    */
    CYBLE_EVT_CPSC_WRITE_DESCR_RESPONSE,

    /** CPS Client - This event is triggered every time a device receive
        non-connectable undirected advertising event.
        The parameter of this event is a structure of 
        CYBLE_CPS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_CPSC_SCAN_PROGRESS_RESULT,
    
    /****************************************
     Cycling Speed and Cadence Service Events
     ***************************************/
    
    /** CSCS Server - Notifications for Cycling Speed and Cadence Service
        Characteristic were enabled. The parameter of this event is a structure of
        CYBLE_CSCS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_CSCSS_NOTIFICATION_ENABLED,

    /** CSCS Server - Notifications for Cycling Speed and Cadence Service
        Characteristic were disabled. The parameter of this event is a structure of
        CYBLE_CSCS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_CSCSS_NOTIFICATION_DISABLED,

    /** CSCS Server - Indication for Cycling Speed and Cadence Service Characteristic
        was enabled. The parameter of this event is a structure of
        CYBLE_CSCS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_CSCSS_INDICATION_ENABLED,

    /** CSCS Server - Indication for Cycling Speed and Cadence Service Characteristic
        was disabled. The parameter of this event is a structure of
        CYBLE_CSCS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_CSCSS_INDICATION_DISABLED,

    /** CSCS Server - Cycling Speed and Cadence Service Characteristic
        Indication was confirmed. The parameter of this event is a structure of 
        CYBLE_CSCS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_CSCSS_INDICATION_CONFIRMATION,

    /** CSCS Server - Write Request for Cycling Speed and Cadence Service
        Characteristic was received. The parameter of this event is a structure of
        CYBLE_CSCS_CHAR_VALUE_T type.
    */    
    CYBLE_EVT_CSCSS_CHAR_WRITE,

    /** CSCS Client - Cycling Speed and Cadence Service Characteristic
        Notification was received. The parameter of this event is a structure of
        CYBLE_CSCS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_CSCSC_NOTIFICATION,

    /** CSCS Client - Cycling Speed and Cadence Service Characteristic
        Indication was received. The parameter of this event is a structure of 
        CYBLE_CSCS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_CSCSC_INDICATION,

    /** CSCS Client - Read Response for Read Request of Cycling Speed and Cadence 
        Service Characteristic value. The parameter of this event is a structure of
        CYBLE_CSCS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_CSCSC_READ_CHAR_RESPONSE,
    
    /** CSCS Client - Write Response for Write Request of Cycling Speed and Cadence 
        Service Characteristic value. The parameter of this event is a structure of
        CYBLE_CSCS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_CSCSC_WRITE_CHAR_RESPONSE,
    
    /** CSCS Client - Read Response for Read Request of Cycling Speed and Cadence
        Service Characteristic Descriptor Read request. The parameter of this event
        is a structure of CYBLE_CSCS_DESCR_VALUE_T type.
    */
    CYBLE_EVT_CSCSC_READ_DESCR_RESPONSE,

    /** CSCS Client - Write Response for Write Request of Cycling Speed and Cadence
        Service Characteristic Configuration Descriptor value. The parameter of
        this event is a structure of  CYBLE_CSCS_DESCR_VALUE_T type.
    */
    CYBLE_EVT_CSCSC_WRITE_DESCR_RESPONSE,
    
    
    /****************************************
     Current Time Service Events
     ***************************************/
    
    /** CTS Server - Notification for Current Time Characteristic was enabled. The
        parameter of this event is a structure of CYBLE_CTS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_CTSS_NOTIFICATION_ENABLED,
    
    /** CTS Server - Notification for Current Time Characteristic was disabled. The
        parameter of this event is a structure of CYBLE_CTS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_CTSS_NOTIFICATION_DISABLED,
    
    /** CTS Server - Write Request for Current Time Service
        Characteristic was received. The parameter of this event is a structure of
        CYBLE_CTS_CHAR_VALUE_T type. When this event is received the user is 
        responsible for performing any kind of data verification and writing the 
        data to the GATT database in case of successful verification or setting
        the error using CyBle_SetGattError() in case of data verification failure.
    */    
    CYBLE_EVT_CTSS_CHAR_WRITE,
    
    /** CTS Client - Current Time Characteristic Notification was received. The
        parameter of this event is a structure of CYBLE_CTS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_CTSC_NOTIFICATION,
    
    /** CTS Client - Read Response for Current Time Characteristic
        Value Read Request. The parameter of this event is a 
        structure of CYBLE_CTS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_CTSC_READ_CHAR_RESPONSE,
    
    /** CTS Client - Read Response for Current Time Client
        Characteristic Configuration Descriptor Value Read 
        Request. The parameter of this event is a 
        structure of CYBLE_CTS_DESCR_VALUE_T type.
    */
    CYBLE_EVT_CTSC_READ_DESCR_RESPONSE,
    
    /** CTS Client - Write Response for Current Time Characteristic
        Configuration Descriptor Value. The parameter of this 
        event is a structure of CYBLE_CTS_DESCR_VALUE_T type.
    */
    CYBLE_EVT_CTSC_WRITE_DESCR_RESPONSE,

    /** CTS Client - Write Response for Current Time or Local
        Time Information Characteristic Value. The parameter of this
        event is a structure of CYBLE_CTS_DESCR_VALUE_T type.
    */
    CYBLE_EVT_CTSC_WRITE_CHAR_RESPONSE,
    
    /****************************************
     DIS Service Events
     ***************************************/
    
    /** DIS Client - Read Response for a Read Request for a
        Device Information Service Characteristic. The parameter of this 
        event is a structure of CYBLE_DIS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_DISC_READ_CHAR_RESPONSE,
    
    
    /****************************************
     Environmental Sensing Service Events
     ***************************************/
    
    /** ESS Server - Notifications for Environmental Sensing Service
        Characteristic were enabled. The parameter of this event is a structure of
        CYBLE_ESS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_ESSS_NOTIFICATION_ENABLED,

    /** ESS Server - Notifications for Environmental Sensing Service
        Characteristic were disabled. The parameter of this event is a structure of
        CYBLE_ESS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_ESSS_NOTIFICATION_DISABLED,

    /** ESS Server - Indication for Environmental Sensing Service Characteristic
        was enabled. The parameter of this event is a structure of
        CYBLE_ESS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_ESSS_INDICATION_ENABLED,

    /** ESS Server - Indication for Environmental Sensing Service Characteristic
        was disabled. The parameter of this event is a structure of
        CYBLE_ESS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_ESSS_INDICATION_DISABLED,

    /** ESS Server - Environmental Sensing Service Characteristic
        Indication was confirmed. The parameter of this event is a structure of 
        CYBLE_ESS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_ESSS_INDICATION_CONFIRMATION,

    /** ESS Server - Write Request for Environmental Sensing Service
        Characteristic was received. The parameter of this event is a structure of
        CYBLE_ESS_CHAR_VALUE_T type.
    */    
    CYBLE_EVT_ESSS_CHAR_WRITE,
    
    /** ESS Server - Execute Write Request for Environmental Sensing Service
        Characteristic was received. The parameter of this event is a structure of
        CYBLE_ESS_DESCR_VALUE_T type.
    */    
    CYBLE_EVT_ESSS_EXEC_WRITE_REQ,

    /** ESS Server - Write Request for Environmental Sensing Service
        Characteristic Descriptor was received. The parameter of this event is a structure of
        CYBLE_ESS_DESCR_VALUE_T type. This event is generated only when write for
        CYBLE_ESS_CHAR_USER_DESCRIPTION_DESCR, CYBLE_ESS_ES_TRIGGER_SETTINGS_DESCR or
        CYBLE_ESS_ES_CONFIG_DESCR occured.
    */    
    CYBLE_EVT_ESSS_DESCR_WRITE,
    
    /** ESS Client - Environmental Sensing Service Characteristic
        Notification was received. The parameter of this event is a structure of
        CYBLE_ESS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_ESSC_NOTIFICATION,

    /** ESS Client - Environmental Sensing Service Characteristic
        Indication was received. The parameter of this event is a structure of 
        CYBLE_ESS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_ESSC_INDICATION,

    /** ESS Client - Read Response for Read Request of Environmental Sensing 
        Service Characteristic value. The parameter of this event is a structure of
        CYBLE_ESS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_ESSC_READ_CHAR_RESPONSE,
    
    /** ESS Client - Write Response for Write Request of Environmental Sensing 
        Service Characteristic value. The parameter of this event is a structure of
        CYBLE_ESS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_ESSC_WRITE_CHAR_RESPONSE,
    
    /** ESS Client - Read Response for Read Request of Environmental Sensing
        Service Characteristic Descriptor Read request. The parameter of this event
        is a structure of CYBLE_ESS_DESCR_VALUE_T type.
    */
    CYBLE_EVT_ESSC_READ_DESCR_RESPONSE,

    /** ESS Client - Write Response for Write Request of Environmental Sensing
        Service Characteristic Configuration Descriptor value. The parameter of
        this event is a structure of  CYBLE_ESS_DESCR_VALUE_T type.
    */
    CYBLE_EVT_ESSC_WRITE_DESCR_RESPONSE,
    
    
    /****************************************
     Glucose Service Events
     ***************************************/
    
    /** GLS Server - Indication for Glucose Service Characteristic
        was enabled. The parameter of this event is a structure 
        of CYBLE_GLS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_GLSS_INDICATION_ENABLED,
    
    /** GLS Server - Indication for Glucose Service Characteristic
        was disabled. The parameter of this event is a structure 
        of CYBLE_GLS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_GLSS_INDICATION_DISABLED,
    
    /** GLS Server - Glucose Service Characteristic
        Indication was confirmed. The parameter of this event
        is a structure of CYBLE_GLS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_GLSS_INDICATION_CONFIRMED,
    
    /** GLS Server - Notifications for Glucose Service Characteristic
        was enabled. The parameter of this event is a structure of
        CYBLE_GLS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_GLSS_NOTIFICATION_ENABLED,
    
    /** GLS Server - Notifications for Glucose Service Characteristic
        were disabled. The parameter of this event is a structure 
        of CYBLE_GLS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_GLSS_NOTIFICATION_DISABLED,
    
    /** GLS Server - Write Request for Glucose Service 
        was received. The parameter of this event is a structure
        of CYBLE_GLS_CHAR_VALUE_T type.
    */    
    CYBLE_EVT_GLSS_WRITE_CHAR,
    
    /** GLS Client - Glucose Service Characteristic
        Indication was received. The parameter of this event
        is a structure of CYBLE_GLS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_GLSC_INDICATION,
    
    /** GLS Client - Glucose Service Characteristic
        Notification was received. The parameter of this event
        is a structure of CYBLE_GLS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_GLSC_NOTIFICATION,
    
    /** GLS Client - Read Response for Read Request of Glucose 
        Service Characteristic value. The parameter of this event
        is a structure of CYBLE_GLS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_GLSC_READ_CHAR_RESPONSE,
    
    /** GLS Client - Write Response for Write Request of Glucose
        Service Characteristic value. The 
        parameter of this event is a structure of
        CYBLE_GLS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_GLSC_WRITE_CHAR_RESPONSE,
    
    /** GLS Client - Read Response for Read Request of Glucose
        Service Characteristic Descriptor Read request. The 
        parameter of this event is a structure of
        CYBLE_GLS_DESCR_VALUE_T type.
    */
    CYBLE_EVT_GLSC_READ_DESCR_RESPONSE,
    
    /** GLS Client - Write Response for Write Request of Glucose
        Service Characteristic Configuration Descriptor value.
        The parameter of this event is a structure of 
        CYBLE_GLS_DESCR_VALUE_T type.
    */
    CYBLE_EVT_GLSC_WRITE_DESCR_RESPONSE,

    
    /****************************************
     HIDS Service Events
     ***************************************/
    
    /** HIDS Server - Notifications for HID service were
        enabled. The parameter of this event is a 
        structure of CYBLE_HIDS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_HIDSS_NOTIFICATION_ENABLED,
    
    /** HIDS Server - Notifications for HID service were
        disabled. The parameter of this event is a 
        structure of CYBLE_HIDS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_HIDSS_NOTIFICATION_DISABLED,
    
    /** HIDS Server - Enter boot mode request. The
        parameter of this event is a structure of
        CYBLE_HIDS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_HIDSS_BOOT_MODE_ENTER,
    
    /** HIDS Server - Enter report mode request. The
        parameter of this event is a structure of
        CYBLE_HIDS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_HIDSS_REPORT_MODE_ENTER,
    
    /** HIDS Server - Enter suspend mode request. The
        parameter of this event is a structure of
        CYBLE_HIDS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_HIDSS_SUSPEND,
    
    /** HIDS Server - Exit suspend mode request. The
        parameter of this event is a structure of
        CYBLE_HIDS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_HIDSS_EXIT_SUSPEND,
    
    /** HIDS Server - Write Report characteristic 
        request. The parameter of this event is a
        structure of CYBLE_HIDSS_REPORT_VALUE_T type.
    */
    CYBLE_EVT_HIDSS_REPORT_CHAR_WRITE,
    
    /** HIDS Client - HID Service Characteristic
        Notification was received. The parameter of this
        event is a structure of CYBLE_HIDS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_HIDSC_NOTIFICATION,
    
    /** HIDS Client - Read Response for Read Request of HID
        Service Characteristic value. The parameter of this
        event is a structure of CYBLE_HIDS_DESCR_VALUE_T type.
    */
    CYBLE_EVT_HIDSC_READ_CHAR_RESPONSE,
    
    /** HIDS Client - Write Response for Write Request of
        HID Service Characteristic value. The parameter
        of this event is a structure of 
        CYBLE_HIDS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_HIDSC_WRITE_CHAR_RESPONSE,
    
    /** HIDS Client - Read Response for Read Request of HID
        Service Characteristic Descriptor Read request. The 
        parameter of this event is a structure of 
        CYBLE_HIDS_DESCR_VALUE_T type.
    */
    CYBLE_EVT_HIDSC_READ_DESCR_RESPONSE,
    
    /** HIDS Client - Write Response for Write Request of HID
        Service Characteristic Configuration Descriptor value. 
        The parameter of this event is a structure of 
        CYBLE_HIDS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_HIDSC_WRITE_DESCR_RESPONSE,
    
    
    /****************************************
     HRS Service Events
     ***************************************/
    
    /** HRS Server - Reset Energy Expended. The parameter of 
        this event is a structure of CYBLE_HRS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_HRSS_ENERGY_EXPENDED_RESET,
    
    /** HRS Server - Notification for Heart Rate Measurement
        Characteristic was enabled. The parameter of this 
        event is a structure of CYBLE_HRS_CHAR_VALUE_T type.
    */

    CYBLE_EVT_HRSS_NOTIFICATION_ENABLED,
    
    /** HRS Server - Notification for Heart Rate Measurement
        Characteristic was disabled. The parameter of this 
        event is a structure of CYBLE_HRS_CHAR_VALUE_T type.
    */    
    CYBLE_EVT_HRSS_NOTIFICATION_DISABLED,
    
    /** HRS Client - Heart Rate Measurement Characteristic
        Notification was received. The parameter of this event
        is a structure of CYBLE_HRS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_HRSC_NOTIFICATION,
    
    /** HRS Client - Read Response for Read Request of HRS 
        Service Characteristic value. The parameter of this event
        is a structure of CYBLE_HRS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_HRSC_READ_CHAR_RESPONSE,
    
    /** HRS Client - Write Response for Write Request of HRS 
        Service Characteristic value. The parameter of this event
        is a structure of CYBLE_HRS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_HRSC_WRITE_CHAR_RESPONSE,
    
    /** HRS Client - Read Response for Read Request of HRS
        Service Characteristic Descriptor Read request. The 
        parameter of this event is a structure of
        CYBLE_HRS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_HRSC_READ_DESCR_RESPONSE,
    
    /** HRS Client - Write Response for Write Request of HRS
        Service Characteristic Configuration Descriptor value.
        The parameter of this event is a structure of 
        CYBLE_HRS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_HRSC_WRITE_DESCR_RESPONSE,
    
    
    /****************************************
     HTS Service Events
     ***************************************/

    /** HTS Server - Notifications for Health Thermometer Service Characteristic
        were enabled. The parameter of this event is a structure of
        CYBLE_HTS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_HTSS_NOTIFICATION_ENABLED,

    /** HTS Server - Notifications for Health Thermometer Service Characteristic
        were disabled. The parameter of this event is a structure 
        of CYBLE_HTS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_HTSS_NOTIFICATION_DISABLED,

    /** HTS Server - Indication for Health Thermometer Service Characteristic
        was enabled. The parameter of this event is a structure 
        of CYBLE_HTS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_HTSS_INDICATION_ENABLED,

    /** HTS Server - Indication for Health Thermometer Service Characteristic
        was disabled. The parameter of this event is a structure 
        of CYBLE_HTS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_HTSS_INDICATION_DISABLED,

    /** HTS Server - Health Thermometer Service Characteristic
        Indication was confirmed. The parameter of this event
        is a structure of CYBLE_HTS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_HTSS_INDICATION_CONFIRMED,

    /** HTS Server - Write Request for Health Thermometer Service Characteristic
        was received. The parameter of this event is a structure
        of CYBLE_HTS_CHAR_VALUE_T type.
    */    
    CYBLE_EVT_HTSS_CHAR_WRITE,

    /** HTS Client - Health Thermometer Service Characteristic
        Notification was received. The parameter of this event
        is a structure of CYBLE_HTS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_HTSC_NOTIFICATION,

    /** HTS Client - Health Thermometer Service Characteristic
        Indication was received. The parameter of this event
        is a structure of CYBLE_HTS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_HTSC_INDICATION,

    /** HTS Client - Read Response for Read Request of Health Thermometer 
        Service Characteristic value. The parameter of this event
        is a structure of CYBLE_HTS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_HTSC_READ_CHAR_RESPONSE,

    /** HTS Client - Write Response for Write Request of Health Thermometer 
        Service Characteristic value. The parameter of this event
        is a structure of CYBLE_HTS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_HTSC_WRITE_CHAR_RESPONSE,

    /** HTS Client - Read Response for Read Request of Health Thermometer
        Service Characteristic Descriptor Read request. The 
        parameter of this event is a structure of
        CYBLE_HTS_DESCR_VALUE_T type.
    */
    CYBLE_EVT_HTSC_READ_DESCR_RESPONSE,

    /** HTS Client - Write Response for Write Request of Health Thermometer
        Service Characteristic Configuration Descriptor value.
        The parameter of this event is a structure of 
        CYBLE_HTS_DESCR_VALUE_T type.
    */
    CYBLE_EVT_HTSC_WRITE_DESCR_RESPONSE,
    
    
    /****************************************
     Immediate Alert Service Events
     ***************************************/
    
    /** IAS Server - Write command request for Alert Level
        Characteristic. The parameter of this event
        is a structure of CYBLE_IAS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_IASS_WRITE_CHAR_CMD,
    
    
    /****************************************
     Link Loss Service Events
     ***************************************/
    
    /** LLS Server - Write request for Alert Level Characteristic. 
        The parameter of this event is a structure of 
        CYBLE_LLS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_LLSS_WRITE_CHAR_REQ,
    
    /** LLS Client - Read response for Alert Level Characteristic.
        The parameter of this event is a structure of 
        CYBLE_LLS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_LLSC_READ_CHAR_RESPONSE,
    
    /** LLS Client - Write response for write request of Alert
        Level Characteristic. The parameter of this event is a
        structure of CYBLE_LLS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_LLSC_WRITE_CHAR_RESPONSE,
    
    
    /****************************************
     Location and Navigation Service Events
     ***************************************/

    /** LNS Server - Indication for Location and Navigation Service Characteristic
        was enabled. The parameter of this event is a structure 
        of CYBLE_LNS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_LNSS_INDICATION_ENABLED,

    /** LNS Server - Indication for Location and Navigation Service Characteristic
        was disabled. The parameter of this event is a structure 
        of CYBLE_LNS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_LNSS_INDICATION_DISABLED,

    /** LNS Server - Location and Navigation Service Characteristic
        Indication was confirmed. The parameter of this event
        is a structure of CYBLE_LNS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_LNSS_INDICATION_CONFIRMED,

    /** LNS Server - Notifications for Location and Navigation Service Characteristic
        were enabled. The parameter of this event is a structure of
        CYBLE_LNS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_LNSS_NOTIFICATION_ENABLED,

    /** LNS Server - Notifications for Location and Navigation Service Characteristic
        were disabled. The parameter of this event is a structure 
        of CYBLE_LNS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_LNSS_NOTIFICATION_DISABLED,

    /** LNS Server - Write Request for Location and Navigation Service Characteristic 
        was received. The parameter of this event is a structure
        of CYBLE_LNS_CHAR_VALUE_T type.
    */    
    CYBLE_EVT_LNSS_WRITE_CHAR,

    /** LNS Client - Location and Navigation Service Characteristic
        Indication was received. The parameter of this event
        is a structure of CYBLE_LNS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_LNSC_INDICATION,

    /** LNS Client - Location and Navigation Service Characteristic
        Notification was received. The parameter of this event
        is a structure of CYBLE_LNS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_LNSC_NOTIFICATION,

    /** LNS Client - Read Response for Read Request of Location and Navigation 
        Service Characteristic value. The parameter of this event
        is a structure of CYBLE_LNS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_LNSC_READ_CHAR_RESPONSE,

    /** LNS Client - Write Response for Write Request of Location and Navigation 
        Service Characteristic value. The parameter of this event
        is a structure of CYBLE_LNS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_LNSC_WRITE_CHAR_RESPONSE,

    /** LNS Client - Read Response for Read Request of Location and Navigation
        Service Characteristic Descriptor Read request. The 
        parameter of this event is a structure of
        CYBLE_LNS_DESCR_VALUE_T type.
    */
    CYBLE_EVT_LNSC_READ_DESCR_RESPONSE,

    /** LNS Client - Write Response for Write Request of Location and Navigation
        Service Characteristic Configuration Descriptor value.
        The parameter of this event is a structure of 
        CYBLE_LNS_DESCR_VALUE_T type.
    */
    CYBLE_EVT_LNSC_WRITE_DESCR_RESPONSE,
    
    
    /****************************************
     Next DST Change Service Events
     ***************************************/
    CYBLE_EVT_NDCSC_READ_CHAR_RESPONSE,
    
    
    /****************************************
     Phone Alert Status Service Events
     ***************************************/

    /** PASS Server - Notifications for Phone Alert Status Service Characteristic
        were enabled. The parameter of this event is a structure of
        CYBLE_PASS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_PASSS_NOTIFICATION_ENABLED,

    /** PASS Server - Notifications for Phone Alert Status Service Characteristic
        were disabled. The parameter of this event is a structure 
        of CYBLE_PASS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_PASSS_NOTIFICATION_DISABLED,

    /** PASS Server - Write Request for Phone Alert Status Service Characteristic 
        was received. The parameter of this event is a structure
        of CYBLE_PASS_CHAR_VALUE_T type.
    */    
    CYBLE_EVT_PASSS_WRITE_CHAR,

    /** PASS Client - Phone Alert Status Service Characteristic
        Notification was received. The parameter of this event
        is a structure of CYBLE_PASS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_PASSC_NOTIFICATION,

    /** PASS Client - Read Response for Read Request of Phone Alert Status 
        Service Characteristic value. The parameter of this event
        is a structure of CYBLE_PASS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_PASSC_READ_CHAR_RESPONSE,

    /** PASS Client - Write Response for Write Request of Phone Alert Status 
        Service Characteristic value. The parameter of this event
        is a structure of CYBLE_PASS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_PASSC_WRITE_CHAR_RESPONSE,

    /** PASS Client - Read Response for Read Request of Phone Alert Status
        Service Characteristic Descriptor Read request. The 
        parameter of this event is a structure of
        CYBLE_PASS_DESCR_VALUE_T type.
    */
    CYBLE_EVT_PASSC_READ_DESCR_RESPONSE,

    /** PASS Client - Write Response for Write Request of Phone Alert Status
        Service Characteristic Configuration Descriptor value.
        The parameter of this event is a structure of 
        CYBLE_PASS_DESCR_VALUE_T type.
    */
    CYBLE_EVT_PASSC_WRITE_DESCR_RESPONSE,
    
    
    /****************************************
     Running Speed and Cadence Service Events
     ***************************************/

    /** RSCS Server - Notifications for Running Speed and Cadence Service
        Characteristic were enabled. The parameter of this event is a structure of
        CYBLE_RSCS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_RSCSS_NOTIFICATION_ENABLED,

    /** RSCS Server - Notifications for Running Speed and Cadence Service
        Characteristic was disabled. The parameter of this event is a structure 
        of CYBLE_RSCS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_RSCSS_NOTIFICATION_DISABLED,

    /** RSCS Server - Indication for Running Speed and Cadence Service Characteristic
        was enabled. The parameter of this event is a structure 
        of CYBLE_RSCS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_RSCSS_INDICATION_ENABLED,

    /** RSCS Server - Indication for Running Speed and Cadence Service Characteristic
        was disabled. The parameter of this event is a structure 
        of CYBLE_RSCS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_RSCSS_INDICATION_DISABLED,

    /** RSCS Server - Running Speed and Cadence Service Characteristic
        Indication was confirmed. The parameter of this event
        is a structure of CYBLE_RSCS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_RSCSS_INDICATION_CONFIRMATION,

    /** RSCS Server - Write Request for Running Speed and Cadence Service
        Characteristic was received. The parameter of this event is a structure
        of CYBLE_RSCS_CHAR_VALUE_T type.
    */    
    CYBLE_EVT_RSCSS_CHAR_WRITE,

    /** RSCS Client - Running Speed and Cadence Service Characteristic
        Notification was received. The parameter of this event
        is a structure of CYBLE_RSCS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_RSCSC_NOTIFICATION,

    /** RSCS Client - Running Speed and Cadence Service Characteristic
        Indication was received. The parameter of this event
        is a structure of CYBLE_RSCS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_RSCSC_INDICATION,

    /** RSCS Client - Read Response for Read Request of Running Speed and Cadence 
        Service Characteristic value. The parameter of this event
        is a structure of CYBLE_RSCS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_RSCSC_READ_CHAR_RESPONSE,

    /** RSCS Client - Write Response for Write Request of Running Speed and Cadence 
        Service Characteristic value. The parameter of this event
        is a structure of CYBLE_RSCS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_RSCSC_WRITE_CHAR_RESPONSE,

    /** RSCS Client - Read Response for Read Request of Running Speed and Cadence
        Service Characteristic Descriptor Read request. The 
        parameter of this event is a structure of
        CYBLE_RSCS_DESCR_VALUE_T type.
    */
    CYBLE_EVT_RSCSC_READ_DESCR_RESPONSE,

    /** RSCS Client - Write Response for Write Request of Running Speed and Cadence
        Service Characteristic Configuration Descriptor value.
        The parameter of this event is a structure of 
        CYBLE_RSCS_DESCR_VALUE_T type.
    */
    CYBLE_EVT_RSCSC_WRITE_DESCR_RESPONSE,

    
    /****************************************
     Reference Time Update Service Events
     ***************************************/
    
    /** RTUS Server - Write command request for Reference Time Update
        Characteristic value. The parameter of this event
        is a structure of CYBLE_RTUS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_RTUSS_WRITE_CHAR_CMD,
    
    /** RTUS Client - Read Response for Read Request of Reference Time Update
        Service Characteristic value. The parameter of this event
        is a structure of CYBLE_RTUS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_RTUSC_READ_CHAR_RESPONSE,
    
    
    /****************************************
     Scan Parameters Service Events
     ***************************************/
    
    /** ScPS Server - Notifications for Scan Refresh Characteristic
        were enabled. The parameter of this event is a structure 
        of CYBLE_SCPS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_SCPSS_NOTIFICATION_ENABLED,
    
    /** ScPS Server - Notifications for Scan Refresh Characteristic
        were disabled. The parameter of this event is a structure 
        of CYBLE_SCPS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_SCPSS_NOTIFICATION_DISABLED,
    
    /** ScPS Client - Read Response for Scan Interval Window 
        Characteristic Value of Scan Parameters Service. The 
        parameter of this event is a structure 
        of CYBLE_SCPS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_SCPSS_SCAN_INT_WIN_CHAR_WRITE,
    
    /** ScPS Client - Scan Refresh Characteristic Notification 
        was received. The parameter of this event is a 
        structure of CYBLE_SCPS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_SCPSC_NOTIFICATION,
    
    /** ScPS Client - Read Response for Scan Refresh Characteristic
        Descriptor Read Request. The parameter of this event is a
        structure of CYBLE_SCPS_DESCR_VALUE_T type.
    */
    CYBLE_EVT_SCPSC_READ_DESCR_RESPONSE,
    
    /** ScPS Client - Write Response for Scan Refresh Client 
        Characteristic Configuration Descriptor Value. The
        parameter of this event is a structure of
        CYBLE_SCPS_DESCR_VALUE_T type.
    */
    CYBLE_EVT_SCPSC_WRITE_DESCR_RESPONSE,

    
    /****************************************
     Tx Power Service Events
     ***************************************/
    
    /** TPS Server - Notification for Tx Power Level Characteristic
        was enabled. The parameter of this event is a structure of
        CYBLE_TPS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_TPSS_NOTIFICATION_ENABLED,
    
    /** TPS Server - Notification for Tx Power Level Characteristic
        was disabled. The parameter of this event is a structure of
        CYBLE_TPS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_TPSS_NOTIFICATION_DISABLED,
    
    /** TPS Client - Tx Power Level Characteristic Notification. 
        The parameter of this event is a structure of
        CYBLE_TPS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_TPSC_NOTIFICATION,
    
    /** TPS Client - Read Response for Tx Power Level Characteristic
        Value Read Request. The parameter of this event is a 
        structure of CYBLE_TPS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_TPSC_READ_CHAR_RESPONSE,
    
    /** TPS Client - Read Response for Tx Power Level Client 
        Characteristic Configuration Descriptor Value Read Request. 
        The parameter of this event is a structure of 
        CYBLE_TPS_DESCR_VALUE_T type.
    */
    CYBLE_EVT_TPSC_READ_DESCR_RESPONSE,
    
    /** TPS Client - Write Response for Tx Power Level Characteristic
        Descriptor Value Write Request. The parameter of this event
        is a structure of CYBLE_TPS_DESCR_VALUE_T type.
    */
    CYBLE_EVT_TPSC_WRITE_DESCR_RESPONSE,
    
    
    /****************************************
     User Data Service Events
     ***************************************/

    /** UDS Server - Indication for User Data Service Characteristic
        was enabled. The parameter of this event is a structure 
        of CYBLE_UDS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_UDSS_INDICATION_ENABLED,

    /** UDS Server - Indication for User Data Service Characteristic
        was disabled. The parameter of this event is a structure 
        of CYBLE_UDS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_UDSS_INDICATION_DISABLED,

    /** UDS Server - User Data Service Characteristic
        Indication was confirmed. The parameter of this event
        is a structure of CYBLE_UDS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_UDSS_INDICATION_CONFIRMED,

    /** UDS Server - Notifications for User Data Service Characteristic
        were enabled. The parameter of this event is a structure of
        CYBLE_UDS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_UDSS_NOTIFICATION_ENABLED,

    /** UDS Server - Notifications for User Data Service Characteristic
        were disabled. The parameter of this event is a structure 
        of CYBLE_UDS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_UDSS_NOTIFICATION_DISABLED,
    
    /** UDS Server - Read Request for User Data Service Characteristic 
        was received. The parameter of this event is a structure
        of CYBLE_UDS_CHAR_VALUE_T type.
    */    
    CYBLE_EVT_UDSS_READ_CHAR,
    
    /** UDS Server - Write Request for User Data Service Characteristic 
        was received. The parameter of this event is a structure
        of CYBLE_UDS_CHAR_VALUE_T type.
    */    
    CYBLE_EVT_UDSS_WRITE_CHAR,

    /** UDS Client - User Data Service Characteristic
        Indication was received. The parameter of this event
        is a structure of CYBLE_UDS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_UDSC_INDICATION,

    /** UDS Client - User Data Service Characteristic
        Notification was received. The parameter of this event
        is a structure of CYBLE_UDS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_UDSC_NOTIFICATION,

    /** UDS Client - Read Response for Read Request of User Data 
        Service Characteristic value. The parameter of this event
        is a structure of CYBLE_UDS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_UDSC_READ_CHAR_RESPONSE,

    /** UDS Client - Write Response for Write Request of User Data 
        Service Characteristic value. The parameter of this event
        is a structure of CYBLE_UDS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_UDSC_WRITE_CHAR_RESPONSE,

    /** UDS Client - Read Response for Read Request of User Data
        Service Characteristic Descriptor Read request. The 
        parameter of this event is a structure of
        CYBLE_UDS_DESCR_VALUE_T type.
    */
    CYBLE_EVT_UDSC_READ_DESCR_RESPONSE,

    /** UDS Client - Write Response for Write Request of User Data
        Service Characteristic Configuration Descriptor value.
        The parameter of this event is a structure of 
        CYBLE_UDS_DESCR_VALUE_T type.
    */
    CYBLE_EVT_UDSC_WRITE_DESCR_RESPONSE,
    
    /** UDS Client - Error Response for Write Request for User Data Service
        Characteristic Value. The parameter of this event is a structure of 
        CYBLE_UDS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_UDSC_ERROR_RESPONSE,

    
    /****************************************
*     Wireless Power Transfer Service Events
*     ***************************************/

    /** WPTS Server - Notifications for Wireless Power Transfer Service Characteristic
        were enabled. The parameter of this event is a structure of
        CYBLE_WPTS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_WPTSS_NOTIFICATION_ENABLED,

    /** WPTS Server - Notifications for Wireless Power Transfer Service Characteristic
        were disabled. The parameter of this event is a structure 
        of CYBLE_WPTS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_WPTSS_NOTIFICATION_DISABLED,

    /** WPTS Server - Indication for Wireless Power Transfer Service Characteristic
        was enabled. The parameter of this event is a structure 
        of CYBLE_WPTS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_WPTSS_INDICATION_ENABLED,

    /** WPTS Server - Indication for Wireless Power Transfer Service Characteristic
        was disabled. The parameter of this event is a structure 
        of CYBLE_WPTS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_WPTSS_INDICATION_DISABLED,

    /** WPTS Server - Wireless Power Transfer Service Characteristic
        Indication was confirmed. The parameter of this event
        is a structure of CYBLE_WPTS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_WPTSS_INDICATION_CONFIRMED,

    /** WPTS Server - Write Request for Wireless Power Transfer Service Characteristic 
        was received. The parameter of this event is a structure
        of CYBLE_WPTS_CHAR_VALUE_T type.
    */    
    CYBLE_EVT_WPTSS_WRITE_CHAR,

    /** WPTS Client - Wireless Power Transfer Service Characteristic
        Notification was received. The parameter of this event
        is a structure of CYBLE_WPTS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_WPTSC_NOTIFICATION,

    /** WPTS Client - Wireless Power Transfer Service Characteristic
        Indication was received. The parameter of this event
        is a structure of CYBLE_WPTS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_WPTSC_INDICATION,
    
    /** WPTS Client - Write Response for Read Request of Wireless Power Transfer 
        Service Characteristic value. The parameter of this event
        is a structure of CYBLE_WPTS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_WPTSC_WRITE_CHAR_RESPONSE,
    
    /** WPTS Client - Read Response for Read Request of Wireless Power Transfer 
        Service Characteristic value. The parameter of this event
        is a structure of CYBLE_WPTS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_WPTSC_READ_CHAR_RESPONSE,

    /** WPTS Client - Read Response for Read Request of Wireless Power Transfer
        Service Characteristic Descriptor Read request. The 
        parameter of this event is a structure of
        CYBLE_WPTS_DESCR_VALUE_T type.
    */
    CYBLE_EVT_WPTSC_READ_DESCR_RESPONSE,

    /** WPTS Client - Write Response for Write Request of Wireless Power Transfer
        Service Characteristic Configuration Descriptor value.
        The parameter of this event is a structure of 
        CYBLE_WPTS_DESCR_VALUE_T type.
    */
    CYBLE_EVT_WPTSC_WRITE_DESCR_RESPONSE,

    
    /****************************************
*     Weight Scale Service Events
*     ***************************************/

    /** WSS Server - Indication for Weight Scale Service Characteristic
        was enabled. The parameter of this event is a structure 
        of CYBLE_WSS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_WSSS_INDICATION_ENABLED,

    /** WSS Server - Indication for Weight Scale Service Characteristic
        was disabled. The parameter of this event is a structure 
        of CYBLE_WSS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_WSSS_INDICATION_DISABLED,

    /** WSS Server - Weight Scale Service Characteristic
        Indication was confirmed. The parameter of this event
        is a structure of CYBLE_WSS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_WSSS_INDICATION_CONFIRMED,

    /** WSS Client - Weight Scale Service Characteristic
        Indication was received. The parameter of this event
        is a structure of CYBLE_WSS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_WSSC_INDICATION,
    /** WSS Client - Read Response for Read Request of Weight Scale 
        Service Characteristic value. The parameter of this event
        is a structure of CYBLE_WSS_CHAR_VALUE_T type.
    */
    CYBLE_EVT_WSSC_READ_CHAR_RESPONSE,

    /** WSS Client - Read Response for Read Request of Weight Scale
        Service Characteristic Descriptor Read request. The 
        parameter of this event is a structure of
        CYBLE_WSS_DESCR_VALUE_T type.
    */
    CYBLE_EVT_WSSC_READ_DESCR_RESPONSE,

    /** WSS Client - Write Response for Write Request of Weight Scale
        Service Characteristic Configuration Descriptor value.
        The parameter of this event is a structure of 
        CYBLE_WSS_DESCR_VALUE_T type.
    */
    CYBLE_EVT_WSSC_WRITE_DESCR_RESPONSE,
    
    
    /****************************************
     Debug Events
     ***************************************/
    
    CYBLE_DEBUG_EVT_BLESS_INT = 0xE000u

}CYBLE_EVT_T;

/**************************************
##  CyBle_StackGap.h
**************************************/
/** GAP Connection Update parameters  */
typedef struct
{
	/** Minimum value for the connection event interval. This shall be less than
	   or equal to conn_Interval_Max. Minimum connection interval will be 
		 connIntvMin * 1.25 ms
        * Time Range: 7.5 ms to 4 sec 									 
	 */
    uint16      connIntvMin;					

	/** Maximum value for the connection event interval. This shall be greater
	   than or equal to conn_Interval_Min. Maximum connection interval will be 
		 connIntvMax * 1.25 ms
	   	* Time Range: 7.5 ms to 4 sec 									 
	 */
    uint16      connIntvMax;					

	/** Slave latency for the connection in number of connection events. 
	 	* Range: 0x0000 to 0x01F4 									 
	 */
    uint16      connLatency;						

	/** Supervision timeout for the LE Link. Supervision timeout will be  
	   supervisionTO * 10 ms
	   	* Time Range: 100 msec to 32 secs 									 
	 */
	uint16      supervisionTO;								

}CYBLE_GAP_CONN_UPDATE_PARAM_T;

/** Current Connection Parameters used by controller */
typedef struct
{
	/** status corresponding to this event will be HCI error code 
    as defined in BLE spec 4.1 */
    uint8      status;					

	/** Connection interval used on this connection. 
	  	* Range: 0x0006 to 0x0C80
	  	* Time Range: 7.5 ms to 4 sec 									 
	 */
    uint16      connIntv;					

	/** Slave latency for the connection in number of connection events. 
	 	* Range: 0x0000 to 0x01F4 									 
	 */
    uint16      connLatency;						

	/** Supervision timeout for the LE Link. Supervision timeout will be  
	   supervisionTO * 10 ms
	   	* Time Range: 100 msec to 32 secs 									 
	 */
	uint16      supervisionTO;								

}CYBLE_GAP_CONN_PARAM_UPDATED_IN_CONTROLLER_T;

/* Public Device Address */
#define CYBLE_GAP_ADDR_TYPE_PUBLIC              			0x00u
/* Locally initiated operation, needed for local updates based on Attribute
    Handles. */
#define CYBLE_GATT_DB_LOCALLY_INITIATED               0x00u

/* Maximum number of Remote Devices */
#define CYBLE_GAP_MAX_BONDED_DEVICE             0x04u
/** Bluetooth Bonded Device Address list */
typedef struct
{
	/** Number of bonded devices */
    uint8     				count;

	/** Pointer to list of Bluetooth device addresses of bonded devices, of type 
        'CYBLE_GAP_BD_ADDR_T'. 'CYBLE_GAP_MAX_BONDED_DEVICE' is a '#define' to
        be defined during build-time. */
    CYBLE_GAP_BD_ADDR_T     bdAddrList[CYBLE_GAP_MAX_BONDED_DEVICE];
	
}CYBLE_GAP_BONDED_DEV_ADDR_LIST_T;



/**************************************
##  CyBle Stack.h 
**************************************/
/** BLE WCO sleep clock accuracy configuration */
typedef enum
{
    CYBLE_LL_SCA_251_TO_500_PPM = 0x00u,
    CYBLE_LL_SCA_151_TO_250_PPM,
    CYBLE_LL_SCA_101_TO_150_PPM,
    CYBLE_LL_SCA_076_TO_100_PPM,
    CYBLE_LL_SCA_051_TO_075_PPM,
    CYBLE_LL_SCA_031_TO_050_PPM,
    CYBLE_LL_SCA_021_TO_030_PPM,
    CYBLE_LL_SCA_000_TO_020_PPM,    
    CYBLE_LL_SCA_IN_PPM_INVALID
} CYBLE_BLESS_WCO_SCA_CFG_T;

/** BLE ECO clock divider */
typedef enum
{
    /** Link Layer clock divider = 1*/
    CYBLE_LL_ECO_CLK_DIV_1 = 0x00u,
	/** Link Layer clock divider = 2*/
	CYBLE_LL_ECO_CLK_DIV_2,
	/** Link Layer clock divider = 4*/
	CYBLE_LL_ECO_CLK_DIV_4,
	/** Link Layer clock divider = 8*/
	CYBLE_LL_ECO_CLK_DIV_8,
	/** Invalid Link Layer clock divider*/
	CYBLE_LL_ECO_CLK_DIV_INVALID
} CYBLE_BLESS_ECO_CLK_DIV_T;
/** BLE clock configuration parameters */
typedef struct
{
    /** Sleep Clock accuracy in PPM, 32Khz Cycles */
    CYBLE_BLESS_WCO_SCA_CFG_T  bleLlSca;
    /** Link Layer clock divider */
    CYBLE_BLESS_ECO_CLK_DIV_T  bleLlClockDiv;
    /** ECO crystal startup time in multiple of 62.5us */
    uint16 ecoXtalStartUpTime;
} CYBLE_BLESS_CLK_CFG_PARAMS_T;

/** This structure is used to hold version information of the BLE Stack Library */
typedef struct 
{
    /** The major version of the library */
    uint8 majorVersion;     
	/** The minor version of the library */
    uint8 minorVersion;     
	/** The patch number of the library */
    uint8 patch;            
	/** The build number of the library */
    uint8 buildNumber;

} CYBLE_STACK_LIB_VERSION_T;
#define CYBLE_STACK_FLASH_STORAGE_SIZE           (0x09u + (0x9Cu * CYBLE_GAP_MAX_BONDED_DEVICE))

/**************************************
##  CyBle_ias.h
**************************************/

/** Immediate Alert Service Characteristic indexes */
typedef enum
{
    CYBLE_IAS_ALERT_LEVEL,                          /**< Alert Level Characteristic index */
    CYBLE_IAS_CHAR_COUNT                            /**< Total count of characteristics */
}CYBLE_IAS_CHAR_INDEX_T;

/** Immediate Alert Service Characteristic Value parameters structure */
typedef struct
{
    CYBLE_CONN_HANDLE_T         connHandle;         /**< Connection handle */
    CYBLE_IAS_CHAR_INDEX_T      charIndex;          /**< Characteristic index of Immediate Alert Service */
    CYBLE_GATT_VALUE_T          *value;             /**< Pointer to value of Immediate Alert Service characteristic */
} CYBLE_IAS_CHAR_VALUE_T;

/**************************************
##  CyBle_lls.h
**************************************/

/** Link Loss Service Characteristic indexes */
typedef enum
{
    CYBLE_LLS_ALERT_LEVEL,                          /**< Alert Level Characteristic index */
    CYBLE_LLS_CHAR_COUNT                            /**< Total count of characteristics */
}CYBLE_LLS_CHAR_INDEX_T;

/** Link Loss Service Characteristic Value parameter structure */
typedef struct
{
    CYBLE_CONN_HANDLE_T         connHandle;         /**< Connection handle */
    CYBLE_LLS_CHAR_INDEX_T      charIndex;          /**< Characteristic index of Link Loss Service */
    CYBLE_GATT_VALUE_T       *  value;              /**< Pointer to value of Link Loss Service characteristic */
} CYBLE_LLS_CHAR_VALUE_T;

#define CYBLE_GATT_DB_LOCALLY_INITIATED               0x00u

/** Passkey display information */
typedef struct
{
	/** bd handle of the remote device */
    uint8	bdHandle; 

	/** size = 6, not null terminated */
    uint32 	passkey;  
	
}CYBLE_GAP_PASSKEY_DISP_INFO_T;


/**************************************
##  CyBle.h
**************************************/

#define CYBLE_STACK_FLASH_SIZE   (CYBLE_STACK_FLASH_STORAGE_SIZE)

#define CYBLE_FLASH_ROW_ALIGNED __attribute__ ((aligned(CY_FLASH_SIZEOF_ROW)))


/**************************************
##  CyBle_gatt.h
**************************************/
#define CYBLE_NO_ALERT                              (0u)
#define CYBLE_MILD_ALERT                            (1u)
#define CYBLE_HIGH_ALERT                            (2u)
#define CYBLE_GATT_DB_CCCD_COUNT                     (0x16u)
#define CYBLE_GATT_DB_FLASH_CCCD_COUNT          (CYBLE_GATT_DB_CCCD_COUNT)

#define CYBLE_GATT_DB_INDEX_COUNT                    (0x0054u)
/** Structure to store bonding data */
typedef struct 
{
    /** Stack internal bonding data */
    uint8 stackFlashptr[CYBLE_STACK_FLASH_SIZE];
    
	/** CCCD values */
	uint8 attValuesCCCDFlashMemory[CYBLE_GAP_MAX_BONDED_DEVICE + 1u][CYBLE_GATT_DB_FLASH_CCCD_COUNT];
    
	/** Number of CCCD */
	uint8 cccdCount; /* CYBLE_GATT_DB_CCCD_COUNT */
    
	/** Number of bonded devices */
	uint8 boundedDevCount; /*CYBLE_GAP_MAX_BONDED_DEVICE*/
}CY_BLE_FLASH_STORAGE;

extern const CY_BLE_FLASH_STORAGE cyBle_flashStorage;
/* BWC macro */
#define cyBle_attValuesCCCDFlashMemory (cyBle_flashStorage.attValuesCCCDFlashMemory)


/** Attribute value type used in GATT database */
typedef struct
{
    /** Length in number of bytes for attGenericVal */
    uint16 actualLength;

    /** Buffer to the store generic characteristic value based on
       length or complete UUID value if the attribute is of type 128-bit
       UUID and 32-bit UUID type. */
       void * attGenericVal;

}CYBLE_GATTS_ATT_GEN_VAL_LEN_T;

/** Attribute value type used in GATT database */
typedef struct
{
    /** Length in number of bytes for attGenericVal */
    uint16 maxAttrLength;

    /** Buffer to the store generic characteristic value based on
       length or complete UUID value if the attribute is of type 128-bit
       UUID and 32-bit UUID type. */
    CYBLE_GATTS_ATT_GEN_VAL_LEN_T * attGenericValLen;

}CYBLE_GATTS_ATT_PACK_VAL_LEN_T;
/** Attribute value type used in GATT database */
typedef union
{    
   /** Buffer containing 32-bit or 128-bit UUID values for Service and
      Characteristic declaration.
      Attribute format structure: if entry is for characteristic value format, 
      then it has the "attribute format value" of pointer type to represent generic
      structure to cater wide formats of available list of characteristic formats. */
	CYBLE_GATTS_ATT_PACK_VAL_LEN_T  	attFormatValue;

	/** Attribute UUID value */
	uint16 				attValueUuid;

} CYBLE_GATTS_ATT_VALUE_T;
/** GATT database structure used in the GAP Server */
typedef struct
{
	/** Start Handle: Act as an index for querying BLE GATT database */
    uint16 				attHandle;
	
    /** UUID: 16 bit UUID type for an attribute entry, for 32 bit and
       128 bit UUIDs the last 16 bits should be stored in this entry
       GATT DB access layer shall retrieve complete 128 bit UUID from
       CYBLE_GATTS_ATT_GENERIC_VAL_T structure. */
    uint16 				attType;
	
    /** The permission bits are clubbed in to a 32-bit field. These 
        32-bits can be grouped in to 4 bytes. The lowest significant byte
        is byte 0 (B0) and the most significant byte is byte 3 (B3). The 
        bytes where the permissions have been grouped is as given below.
	     * Attribute permissions (B0)
         * Characteristic permissions (B1)
         * Implementation specific permission (B3, B2)
	 */
    uint32 				permission;
	
    /** Attribute end handle, indicating logical boundary of given attribute. */
    uint16 				attEndHandle;
	
    /** Attribute value format, it can be one of following:
        * uint16 16bit - UUID for 16bit service & characteristic declaration
        * CYBLE_GATTS_ATT_GENERIC_VAL_T attFormatValue - Buffer containing 32 bit
            or 128 bit UUID values for service & characteristic declaration
        * CYBLE_GATTS_ATT_GENERIC_VAL_T attFormatValue - Buffer containing generic 
            char definition value, or generic descriptor values
     */
	CYBLE_GATTS_ATT_VALUE_T 	attValue;
 } CYBLE_GATTS_DB_T; 

extern const CYBLE_GATTS_DB_T cyBle_gattDB[CYBLE_GATT_DB_INDEX_COUNT];
    
    /* Macro to get pointer to characteristic generic value */
#define CYBLE_GATT_DB_ATTR_GET_ATTR_GEN_PTR(handle)\
          (uint8 *)(cyBle_gattDB[(handle)-1u].attValue.attFormatValue.attGenericValLen->attGenericVal)
        
#define CyBle_HidssGetProtocolMode(serviceIndex)\
            ((uint8) *CYBLE_GATT_DB_ATTR_GET_ATTR_GEN_PTR(cyBle_hidss[(serviceIndex)].protocolModeHandle))


/**************************************
##  CyBle_StackGatt.h
**************************************/
/* ATT Invalid Attribute Handle Value */
#define CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE    0x0000u

/* Checks Notification bit in attribute value referenced by pointer */
#define CYBLE_IS_NOTIFICATION_ENABLED_IN_PTR(valPtr)\
        ((0u) != (CYBLE_CCCD_NOTIFICATION & CyBle_Get16ByPtr(valPtr)))

/* Checks Notification bit in attribute value referenced by handle */
#define CYBLE_IS_NOTIFICATION_ENABLED(handle)\
        CYBLE_IS_NOTIFICATION_ENABLED_IN_PTR(CYBLE_GATT_DB_ATTR_GET_ATTR_GEN_PTR(handle))

#ifndef SHARED_API_HEADER
#define SHARED_API_HEADER

/* BLE component APIs and variables */
extern CYBLE_CONN_HANDLE_T cyBle_connHandle;
extern CYBLE_API_RESULT_T CyBle_GattGetMtuSize(uint16* mtu);
extern CYBLE_API_RESULT_T CyBle_GattsWriteRsp(CYBLE_CONN_HANDLE_T connHandle);
extern CYBLE_API_RESULT_T CyBle_Start(CYBLE_CALLBACK_T callbackFunc);
extern CYBLE_API_RESULT_T CyBle_GappStartAdvertisement(uint8 advertisingIntervalType);
extern CYBLE_API_RESULT_T CyBle_GetDeviceAddress(CYBLE_GAP_BD_ADDR_T* bdAddr);
extern CYBLE_STATE_T cyBle_state;
#define CyBle_GetState() (cyBle_state)
extern CYBLE_LP_MODE_T CyBle_EnterLPM(CYBLE_LP_MODE_T pwrMode);
extern CYBLE_BLESS_STATE_T CyBle_GetBleSsState(void);
extern void CyBle_ProcessEvents(void);
extern uint8 cyBle_pendingFlashWrite;
extern CYBLE_API_RESULT_T CyBle_StoreBondingData(uint8 isForceWrite);
extern uint16 CyBle_Get16ByPtr(const uint8 ptr[]);
extern void CyBle_ScpsRegisterAttrCallback(CYBLE_CALLBACK_T callbackFunc);
extern CYBLE_API_RESULT_T CyBle_ScpssGetCharacteristicDescriptor(CYBLE_SCPS_CHAR_INDEX_T charIndex,
    CYBLE_SCPS_DESCR_INDEX_T descrIndex, uint8 attrSize, uint8 *attrValue);
extern void CyBle_HidsRegisterAttrCallback(CYBLE_CALLBACK_T callbackFunc);
extern CYBLE_API_RESULT_T CyBle_HidssGetCharacteristicDescriptor(uint8 serviceIndex, CYBLE_HIDS_CHAR_INDEX_T charIndex,
    CYBLE_HIDS_DESCR_T descrIndex, uint8 attrSize, uint8 *attrValue);

extern volatile uint8 cyBle_busyStatus;
#define cyBle_busStatus         cyBle_busyStatus
#define CyBle_GattGetBusStatus() (cyBle_busStatus)
extern CYBLE_API_RESULT_T CyBle_HidssGetCharacteristicValue(uint8 serviceIndex, CYBLE_HIDS_CHAR_INDEX_T charIndex,
    uint8 attrSize, uint8 *attrValue);
extern CYBLE_API_RESULT_T CyBle_HidssSendNotification(CYBLE_CONN_HANDLE_T connHandle,
    uint8 serviceIndex, CYBLE_HIDS_CHAR_INDEX_T charIndex, uint8 attrSize, uint8 *attrValue);
extern void CyBle_BasRegisterAttrCallback(CYBLE_CALLBACK_T callbackFunc);
extern CYBLE_API_RESULT_T CyBle_BassGetCharacteristicDescriptor(uint8 serviceIndex, CYBLE_BAS_CHAR_INDEX_T charIndex,
    CYBLE_BAS_DESCR_INDEX_T descrIndex, uint8 attrSize, uint8 *attrValue);
extern CYBLE_API_RESULT_T CyBle_BassSendNotification(CYBLE_CONN_HANDLE_T connHandle,
    uint8 serviceIndex, CYBLE_BAS_CHAR_INDEX_T charIndex, uint8 attrSize, uint8 *attrValue);
extern CYBLE_API_RESULT_T CyBle_BassSetCharacteristicValue(uint8 serviceIndex, CYBLE_BAS_CHAR_INDEX_T charIndex,
    uint8 attrSize, uint8 *attrValue);
extern CYBLE_API_RESULT_T CyBle_SetTxPowerLevel (CYBLE_BLESS_PWR_IN_DB_T *bleSsPwrLvl);
extern void CyBle_EventHandler(uint8 eventCode, void *eventParam);
extern CYBLE_API_RESULT_T CyBle_GattsNotification(CYBLE_CONN_HANDLE_T connHandle, CYBLE_GATTS_HANDLE_VALUE_NTF_T * ntfParam);
CYBLE_API_RESULT_T CyBle_GattsIndication(CYBLE_CONN_HANDLE_T connHandle, CYBLE_GATTS_HANDLE_VALUE_IND_T * indParam);
CYBLE_API_RESULT_T CyBle_GattsErrorRsp(CYBLE_CONN_HANDLE_T connHandle, CYBLE_GATTS_ERR_PARAM_T * errRspParam);
CYBLE_API_RESULT_T CyBle_GattsExchangeMtuRsp(CYBLE_CONN_HANDLE_T connHandle, uint16 mtu);
CYBLE_API_RESULT_T CyBle_GattsWriteRsp(CYBLE_CONN_HANDLE_T connHandle);

CYBLE_API_RESULT_T CyBle_GapGetPeerBdAddr(uint8 bdHandle, CYBLE_GAP_BD_ADDR_T* peerBdAddr);
CYBLE_GATT_ERR_CODE_T CyBle_GattsWriteAttributeValue
		(
            CYBLE_GATT_HANDLE_VALUE_PAIR_T	* handleValuePair,
            uint16                          offset,
            CYBLE_CONN_HANDLE_T       		* connHandle,
            uint8                           flags
		);

    void CyBle_LlsRegisterAttrCallback(CYBLE_CALLBACK_T callbackFunc);
    void CyBle_IasRegisterAttrCallback(CYBLE_CALLBACK_T callbackFunc);
    void CyBle_TpsRegisterAttrCallback(CYBLE_CALLBACK_T callbackFunc);


CYBLE_API_RESULT_T CyBle_GapGetBondedDevicesList(CYBLE_GAP_BONDED_DEV_ADDR_LIST_T* bondedDevList);
CYBLE_API_RESULT_T CyBle_DissSetCharacteristicValue(CYBLE_DIS_CHAR_INDEX_T charIndex, uint8 attrSize, uint8 *attrValue);
CYBLE_API_RESULT_T CyBle_DissGetCharacteristicValue(CYBLE_DIS_CHAR_INDEX_T charIndex, uint8 attrSize, uint8 *attrValue);
CYBLE_API_RESULT_T CyBle_GapDisconnect(uint8 bdHandle);
CYBLE_LP_MODE_T CyBle_ExitLPM(void);
CYBLE_API_RESULT_T CyBle_SetBleClockCfgParam 
                        (CYBLE_BLESS_CLK_CFG_PARAMS_T *bleSsClockConfig); 
CYBLE_API_RESULT_T CyBle_GapAddDeviceToWhiteList(CYBLE_GAP_BD_ADDR_T* bdAddr);
CYBLE_API_RESULT_T CyBle_SetDeviceAddress(CYBLE_GAP_BD_ADDR_T* bdAddr);

CYBLE_API_RESULT_T CyBle_GapRemoveDeviceFromWhiteList(CYBLE_GAP_BD_ADDR_T* bdAddr);
CYBLE_API_RESULT_T CyBle_StoreAppData 
(
	uint8 			* srcBuff,
	const uint8 	destAddr[],
	uint32  		buffLen,
	uint8 			isForceWrite
);
CYBLE_API_RESULT_T CyBle_GapRemoveOldestDeviceFromBondedList (void);
void CyBle_GappStopAdvertisement(void);
CYBLE_API_RESULT_T CyBle_L2capLeConnectionParamUpdateRequest
           (
               	uint8  	     		 			bdHandle,
				CYBLE_GAP_CONN_UPDATE_PARAM_T	*connParam
           );
CYBLE_API_RESULT_T CyBle_GapUpdateAdvData
(
   CYBLE_GAPP_DISC_DATA_T   	* advDiscData,
   CYBLE_GAPP_SCAN_RSP_DATA_T	* advScanRespData
);
CYBLE_API_RESULT_T CyBle_GetStackLibraryVersion(CYBLE_STACK_LIB_VERSION_T*   stackVersion);


/* Pin APIs */
extern void Bootloader_Service_Activation_Write(uint8 value);
extern uint8 Bootloader_Service_Activation_ClearInterrupt(void);
extern void Bootloader_Service_Activation_SetDriveMode(uint8 mode);
extern void Advertising_LED_1_Write(uint8 value);
extern void Advertising_LED_2_Write(uint8 value);
extern void Advertising_LED_1_SetDriveMode(uint8 mode);
extern void Advertising_LED_2_SetDriveMode(uint8 mode);
#define Advertising_LED_Write(value) Advertising_LED_1_Write(value)
#define Advertising_LED_SetDriveMode(value) Advertising_LED_1_SetDriveMode(value)
#define Disconnect_LED_Write(value) Advertising_LED_2_Write(value)
#define Disconnect_LED_SetDriveMode(value) Advertising_LED_2_SetDriveMode(value)
extern void Bootloading_LED_SetDriveMode(uint8 value);
extern void Bootloading_LED_Write(uint8 value);
#define CapsLock_LED_SetDriveMode(value) Bootloading_LED_SetDriveMode(value)
#define CapsLock_LED_Write(value) Bootloading_LED_Write(value)
/* Interrupt APIs */
extern uint8 Bootloader_Service_Activation_ClearInterrupt(void);
extern uint8 Bootloader_Service_Activation_Read(void);
extern void Wakeup_Interrupt_ClearPending(void);
extern void Wakeup_Interrupt_Start(void);
extern void Wakeup_Interrupt_StartEx(cyisraddress address);

extern void CyBle_EventHandler(uint8 eventCode, void *eventParam);
extern void CyBle_ReadByGroupEventHandler(CYBLE_GATTC_READ_BY_GRP_RSP_PARAM_T *eventParam);
extern void CyBle_ReadByTypeEventHandler(CYBLE_GATTC_READ_BY_TYPE_RSP_PARAM_T *eventParam);
extern void CyBle_FindInfoEventHandler( CYBLE_GATTC_FIND_INFO_RSP_PARAM_T *eventParam);
extern void CyBle_ErrorResponseEventHandler(const CYBLE_GATTC_ERR_RSP_PARAM_T *eventParam);
extern CYBLE_API_RESULT_T CyBle_NextInclDiscovery(void);
extern CYBLE_API_RESULT_T CyBle_NextCharDiscovery(void);
extern CYBLE_API_RESULT_T CyBle_NextCharDscrDiscovery(void);
extern CYBLE_API_RESULT_T CyBle_GapSetLocalName(const char8 name[]);
extern CYBLE_API_RESULT_T CyBle_GapGetLocalName(char8 name[]);
CYBLE_GATT_ERR_CODE_T CyBle_GattsDisableAttribute(CYBLE_GATT_DB_ATTR_HANDLE_T attrHandle);
CYBLE_GATT_ERR_CODE_T CyBle_GattsEnableAttribute(CYBLE_GATT_DB_ATTR_HANDLE_T attrHandle);
extern void CyBle_Stop(void);
extern CYBLE_API_RESULT_T CyBle_StoreStackData(uint8 isForceWrite);
extern CYBLE_API_RESULT_T CyBle_StoreAppData (uint8	* srcBuff, const uint8 destAddr[], uint32 buffLen, uint8 isForceWrite);
extern void CyBle_Shutdown(void);
#define CyBle_SetState(state) (cyBle_state = (state))
extern void CyBtldrCommStart(void);
extern void CyBtldrCommStop(void);
extern void CyBtldrCommReset(void);
extern cystatus CyBtldrCommWrite(uint8 *data, uint16 size, uint16 *count, uint8 timeOut);
extern cystatus CyBtldrCommRead(uint8 *data, uint16 size, uint16 *count, uint8 timeOut);

extern uint8 cyBle_advertisingIntervalType;
extern CYBLE_CALLBACK_T CyBle_ApplCallback;
extern const CYBLE_GATTS_T cyBle_gatts[3];
extern uint8 cyBle_attValues[0x0122u];
extern const uint8 cyBle_attValuesCCCD[0x0Cu];
extern CYBLE_CALLBACK_T CyBle_BasApplCallback;
extern CYBLE_CONN_HANDLE_T cyBle_connHandle;
extern CYBLE_GAP_BD_ADDR_T cyBle_deviceAddress;
extern CYBLE_GAP_BD_ADDR_T * cyBle_sflashDeviceAddress;
extern CYBLE_GAPP_DISC_DATA_T cyBle_discoveryData;
extern CYBLE_GAPP_DISC_PARAM_T cyBle_discoveryParam;
extern CYBLE_GAPP_DISC_PARAM_T cyBle_discoveryParam;
extern CYBLE_GAPP_DISC_DATA_T cyBle_discoveryData;
extern CYBLE_GAPP_SCAN_RSP_DATA_T cyBle_scanRspData;
extern CYBLE_GAPP_DISC_MODE_INFO_T cyBle_discoveryModeInfo;
extern volatile uint8 cyBle_eventHandlerFlag;
extern CYBLE_CALLBACK_T CyBle_HidsApplCallback;
extern uint8  cyBle_initVar;
extern uint8 cyBle_pendingFlashWrite;
extern CYBLE_CALLBACK_T CyBle_ScpsApplCallback;
extern uint8 CyBle_StackState;
extern CYBLE_GAP_AUTH_INFO_T cyBle_authInfo;
extern uint8 cyBle_stackMemoryHeap[CYBLE_STACK_HEAP_SIZE];
extern CYBLE_HIDSS_REPORT_T cyBle_hids1ReportArray[0x02u];
extern const uint8 cyBle_attUuid128[2u][16u];
extern const CYBLE_CUSTOMS_T cyBle_customs[CYBLE_CUSTOMS_SERVICE_COUNT];
extern const CYBLE_DISS_T cyBle_diss;
extern const CYBLE_HIDSS_T cyBle_hidss[0x01u];
extern const CYBLE_BASS_T cyBle_bass[0x01];
extern uint8 cyBle_advertisingIntervalType;
extern uint8  cyBle_cmdReceivedFlag;
extern uint16 cyBle_cmdLength;
extern const CYBLE_BTSS_T cyBle_btss;

void ConfigureSharedPins(void);
void BootloaderSwitch(void);
void ConfigureServices(void);
void InitializeBootloaderSRAM();
#endif /*SHARED_API_HEADER*/

#endif /* OTAMandatory_H */


/* [] END OF FILE */
