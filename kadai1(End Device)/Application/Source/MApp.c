/*****************************************************************************
* MyWirelessApp Demo Beacon End Device application.
*
* (c) Copyright 2008, Freescale, Inc. All rights reserved.
*
*
* No part of this document must be reproduced in any form - including copied,
* transcribed, printed or by any electronic means - without specific written
* permission from Freescale Semiconductor.
*
*****************************************************************************/

#include "MApp.h"
#include "Sound.h"
#include "NVM_Interface.h"

/************************************************************************************
*************************************************************************************
* Private macros
*************************************************************************************
************************************************************************************/

/* If there are too many pending packets to be send over the air, */
/* receive mMaxKeysToReceive_c chars. */
/* The chars will be send over the air when there are no pending packets*/
#define mMaxKeysToReceive_c 32

/************************************************************************************
*************************************************************************************
* Private prototypes
*************************************************************************************
************************************************************************************/

/* Forward declarations of helper functions */
static void    UartRxCallBack(void);
static uint8_t App_StartScan(uint8_t scanType);
static uint8_t App_HandleScanPassiveConfirm(nwkMessage_t *pMsg);
static uint8_t App_WaitMsg(nwkMessage_t *pMsg, uint8_t msgType);
static uint8_t App_SendAssociateRequest(void);
static uint8_t App_HandleAssociateConfirm(nwkMessage_t *pMsg);
static uint8_t App_SetMacPib(uint8_t attribute, uint8_t *pValue);
static void    App_HandleMcpsInput(mcpsToNwkMessage_t *pMsgIn);
static void    App_TransmitUartData(void);
#if (gMC1323xMatrixKBD_d == TRUE)
static void    App_HandleKeys(uint8_t events, uint8_t pressedKey);
#else
static void    App_HandleKeys(key_event_t events);
#endif //gMC1323xMatrixKBD_d

static uint8_t App_HandleMlmeInput(nwkMessage_t *pMsg);
//static uint8_t App_SendSyncRequest(void);
/************************************************************************************
*************************************************************************************
* Private memory declarations
*************************************************************************************
************************************************************************************/
//Default Pan ID
static const uint8_t coordinaterPanId[2] = { (mDefaultValueOfPanId_c & 0xff), (mDefaultValueOfPanId_c >> 8)};


/************************************************************************************
*************************************************************************************
* Private memory declarations
*************************************************************************************
************************************************************************************/

/* Information about the PAN we are part of */
static panDescriptor_t mCoordInfo;

/* This is either the short address assigned by the PAN coordinator
   during association, or our own extended MAC address. */
static uint8_t maMyAddress[8];

/* The devices address mode. If 2 (gAddrModeShort_c), then maMyAddress
   contains the short address assigned by the PAN coordinator. If 3
   (gAddrModeLong_c), then maMyAddress is equal to the extended address. */
static uint8_t mAddrMode;

/* Data request packet for sending UART input to the coordinator */
static nwkToMcpsMessage_t *mpPacket;

/* The MSDU handle is a unique data packet identifier */
static uint8_t mMsduHandle;

/* Number of pending data packets */
static uint8_t mcPendingPackets;

/* Application input queues */
static anchor_t mMlmeNwkInputQueue;
static anchor_t mMcpsNwkInputQueue;

/************************************************************************************
*************************************************************************************
* Public memory declarations
*************************************************************************************
************************************************************************************/

/* The current state of the applications state machine */
uint8_t gState;

/* This data set contains application variables to be preserved across resets */
NvDataItemDescription_t const gaNvAppDataSet[] = {
  {NULL, 0}       /* Required end-of-table marker. */
};

/************************************************************************************
*************************************************************************************
* Public functions
*************************************************************************************
************************************************************************************/

void DeepSleepWakeupStackProc(void);

/*****************************************************************************
* Initialization function for the App Task. This is called during
* initialization and should contain any application specific initialization
* (ie. hardware initialization/setup, table initialization, power up
* notificaiton.
*
* Interface assumptions: None
*
* Return value: None
*
*****************************************************************************/
void MApp_init(void)
{ 
  
  /* The initial application state */
  gState = stateInit;    
  /* Reset number of pending packets */
  mcPendingPackets = 0;

  /* Initialize the MAC 802.15.4 extended address */
  Init_MacExtendedAddress();
  /* register keyboard callback function */
  KBD_Init(App_HandleKeys);
  /* Initialize SPI Module */
  SPI_Init();
  /* initialize LCD Module */
  LCD_Init();
  /* initialize LED Module */
  LED_Init();
  /* Initialize the LPM module */
  PWRLib_Init();
  /* Initialize the UART so that we can print out status messages */
  UartX_SetBaud(gUartDefaultBaud_c);
  UartX_SetRxCallBack(UartRxCallBack);
  
  /* initialize buzzer (NCB, SRB only) */  
  BuzzerInit();  
  /* Prepare input queues.*/
  MSG_InitQueue(&mMlmeNwkInputQueue); 
  MSG_InitQueue(&mMcpsNwkInputQueue);  
  /* Enable MCU interrupts */
  IrqControlLib_EnableAllIrqs();
  /*signal app ready*/  
  Led1Flashing();
  Led2Flashing();
  Led3Flashing();
  Led4Flashing();
    
  UartUtil_Print("\n\rPress any switch on board to start running the application.\n\r", gAllowToBlock_d);  
  
  LCD_WriteString(1,"Press any key");
  LCD_WriteString(2,"to start.");
}

/*****************************************************************************
*Mac Application Task event processor.  This function is called to
* process all events for the task. Events include timers, messages and any
* other user defined events
*
* Interface assumptions: None
*
* Return value: None
*****************************************************************************/
void AppTask(event_t events) 
{ 

  /* Pointer for storing the messages from MLME, MCPS, and ASP. */
  void *pMsgIn;
  /* Stores the status code returned by some functions. */
  uint8_t rc;
  pMsgIn = NULL;
  
  /* Dequeue the MLME message */
  if (events & gAppEvtMessageFromMLME_c)
  {
    /* Get the message from MLME */
    pMsgIn = MSG_DeQueue(&mMlmeNwkInputQueue);
    
    /* Any time a beacon might arrive. Always handle the beacon frame first */
    if (pMsgIn)
    {               
      rc = App_WaitMsg(pMsgIn, gNwkBeaconNotifyInd_c);
      if(rc == errorNoError)
      {
        /* ALWAYS free the beacon frame contained in the beacon notify indication.*/
        /* ALSO the application can use the beacon payload.*/
        MSG_Free(((nwkMessage_t *)pMsgIn)->msgData.beaconNotifyInd.pBufferRoot);
        UartUtil_Print("Received an MLME-Beacon Notify Indication\n\r", gAllowToBlock_d);
      }
    }
  }
  /* The application state machine */
  switch(gState)
  {
  case stateInit:    
    /* Print a welcome message to the UART */
    UartUtil_Print("\n\rMyWirelessApp Demo Beacon End Device application is initialized and ready.\n\r\n\r", gAllowToBlock_d);            
    /* Goto Passive Scan state. */
    gState = stateScanPassiveStart;
    TS_SendEvent(gAppTaskID_c, gAppEvtDummyEvent_c);
    break;
    
  case stateScanPassiveStart:
    /* Start the Passive scan, and goto wait for confirm state. */
    UartUtil_Print("Start scanning for a PAN coordinator\n\r", gAllowToBlock_d);
    /*print a message on the LCD also*/
    LCD_ClearDisplay();
    LCD_WriteString(1,"Start scanning");
    LCD_WriteString(2,"for coordinator");
    rc = App_StartScan(gScanModePassive_c);
    if(rc == errorNoError)
    {
      gState = stateScanPassiveWaitConfirm;
    }
    break;
    
  case stateScanPassiveWaitConfirm:
    /* Stay in this state until the Scan confirm message
       arrives, and then goto the associate state. */
    if (events & gAppEvtMessageFromMLME_c)
    {
      if (pMsgIn)
      {                            
        rc = App_WaitMsg(pMsgIn, gNwkScanCnf_c);
        if(rc == errorNoError)
        {
          rc = App_HandleScanPassiveConfirm(pMsgIn);
          if(rc == errorNoError)
          {
            UartUtil_Print("Found a coordinator with the following properties:\n\r", gAllowToBlock_d);
            UartUtil_Print("----------------------------------------------------", gAllowToBlock_d);
            UartUtil_Print("\n\rAddress............0x", gAllowToBlock_d); UartUtil_PrintHex(mCoordInfo.coordAddress, 
                                                                 mCoordInfo.coordAddrMode == gAddrModeShort_c ? 2 : 8, 0);
            UartUtil_Print("\n\rPAN ID.............0x", gAllowToBlock_d); UartUtil_PrintHex(mCoordInfo.coordPanId, 2, 0);
            UartUtil_Print("\n\rLogical Channel....0x", gAllowToBlock_d); UartUtil_PrintHex(&mCoordInfo.logicalChannel, 1, 0);
            UartUtil_Print("\n\rBeacon Spec........0x", gAllowToBlock_d); UartUtil_PrintHex(mCoordInfo.superFrameSpec, 2, 0);
            UartUtil_Print("\n\rLink Quality.......0x", gAllowToBlock_d); UartUtil_PrintHex(&mCoordInfo.linkQuality, 1, 0);
            UartUtil_Print("\n\r\n\r", gAllowToBlock_d);

            /* Go to the Associate state */
            gState = stateAssociate;
            TS_SendEvent(gAppTaskID_c, gAppEvtDummyEvent_c);
          }
          else
          {
            UartUtil_Print("Scan did not find a suitable coordinator\n\r", gAllowToBlock_d);
            /*print a message on the LCD also*/
            LCD_ClearDisplay();
            LCD_WriteString(1,"No coordinator");
            LCD_WriteString(2,"found");
          }            
        }
      }
    }
    break;

  case stateAssociate:
    /* Associate to the PAN coordinator */
    UartUtil_Print("Associating to PAN coordinator on channel 0x", gAllowToBlock_d);
    UartUtil_PrintHex(&(mCoordInfo.logicalChannel), 1, gPrtHexNewLine_c);
    /*print a message on the LCD also*/
    LCD_ClearDisplay();
    LCD_WriteString(1,"Associating to ");
    LCD_WriteString(2,"PAN coordinator");

    rc = App_SendAssociateRequest();
    if(rc == errorNoError)
      gState = stateAssociateWaitConfirm;
    break; 

  case stateAssociateWaitConfirm:
    /* Stay in this state until the Associate confirm message
       arrives, and then goto the Listen state. */
    if (events & gAppEvtMessageFromMLME_c)
    {
      if (pMsgIn)
      {   
        rc = App_WaitMsg(pMsgIn, gNwkAssociateCnf_c);    
        if(rc == errorNoError)
        {
          rc = App_HandleAssociateConfirm(pMsgIn);
          if (rc == errorNoError)
          { 
              UartUtil_Print("Successfully associated with the coordinator.\n\r", gAllowToBlock_d);
              UartUtil_Print("We were assigned the short address 0x", gAllowToBlock_d);
              UartUtil_PrintHex(maMyAddress, mAddrMode == gAddrModeShort_c ? 2 : 8, 0);
              UartUtil_Print("\n\r\n\rReady to send and receive data over the UART.\n\r\n\r", gAllowToBlock_d);
              /*print a message on the LCD also*/
              LCD_ClearDisplay();
              LCD_WriteString(1,"Ready to send");
              LCD_WriteString(2,"and receive data");      
              
              gState = stateListen;
              TS_SendEvent(gAppTaskID_c, gAppEvtDummyEvent_c);
          } 
          else 
          {
          
          UartUtil_Print("\n\rAssociate Confirm wasn't successful... \n\r\n\r", gAllowToBlock_d);
          gState = stateScanPassiveStart;
          TS_SendEvent(gAppTaskID_c, gAppEvtDummyEvent_c);
          }
        }
      }
    }
    break; 
    
  case stateListen:
    /* Transmit to coordinator data received from UART. */
    if (events & gAppEvtMessageFromMLME_c)
    {  
      if (pMsgIn)
      {  
        /* Process it */
        rc = App_HandleMlmeInput(pMsgIn);
      }
    } 
    
    if (events & gAppEvtRxFromUart_c)
    {      
      /* get byte from UART */
      App_TransmitUartData();
    
    }  
    break;
  }
  
  if (pMsgIn)
  {
    /* Messages must always be freed. */ 
    MSG_Free(pMsgIn);
  }
  
   /* Handle MCPS confirms and transmit data from UART */
  if (events & gAppEvtMessageFromMCPS_c)
  {      
    /* Get the message from MCPS */
    pMsgIn = MSG_DeQueue(&mMcpsNwkInputQueue);
    if (pMsgIn)
    {              
      /* Process it */
      App_HandleMcpsInput(pMsgIn);
      /* Messages from the MCPS must always be freed. */
      MSG_Free(pMsgIn);
    }
  }
  
  /* Check for pending messages in the Queue */ 
  if(MSG_Pending(&mMcpsNwkInputQueue))
    TS_SendEvent(gAppTaskID_c, gAppEvtMessageFromMCPS_c);
  if(MSG_Pending(&mMlmeNwkInputQueue))
    TS_SendEvent(gAppTaskID_c, gAppEvtMessageFromMLME_c);  
}

/************************************************************************************
*************************************************************************************
* Private functions
*************************************************************************************
************************************************************************************/

/*****************************************************************************
* UartRxCallBack
*
* This callback is triggered when a new byte is received over the UART
*
*****************************************************************************/
static void UartRxCallBack(void) 
{
  uint8_t pressedKey;
	if(stateListen == gState){
    TS_SendEvent(gAppTaskID_c, gAppEvtRxFromUart_c);
  }else{
	  (void)UartX_GetByteFromRxBuffer(&pressedKey);
  }
}

/******************************************************************************
* The App_HandleMlmeInput(nwkMessage_t *pMsg) function will handle various
* messages from the MLME, e.g. Beacon notifications; 
*
* The function may return either of the following values:
*   errorNoError:   The message was processed.
*   errorNoMessage: The message pointer is NULL.
*
******************************************************************************/
static uint8_t App_HandleMlmeInput(nwkMessage_t *pMsg)
{
  if(pMsg == NULL)
    return errorNoMessage;
  
  /* Handle the incoming message. The type determines the sort of processing. */
  switch(pMsg->msgType)
  {
    case gNwkBeaconNotifyInd_c:   
      /* Always free pBufferRoot */    
      MSG_Free(((nwkMessage_t *)pMsg)->msgData.beaconNotifyInd.pBufferRoot);
      break;  
            
  }
  return errorNoError;
}
/************************************************************************************
*************************************************************************************
* Private functions
*************************************************************************************
************************************************************************************/


/******************************************************************************
* The App_StartScan(scanType) function will start the scan process of the
* specified type in the MAC. This is accomplished by allocating a MAC message,
* which is then assigned the desired scan parameters and sent to the MLME
* service access point.
* The function may return either of the following values:
*   errorNoError:          The Scan message was sent successfully.
*   errorInvalidParameter: The MLME service access point rejected the
*                          message due to an invalid parameter.
*   errorAllocFailed:      A message buffer could not be allocated.
*
******************************************************************************/
static uint8_t App_StartScan(uint8_t scanType)
{
  mlmeMessage_t *pMsg;
  mlmeScanReq_t *pScanReq;

  UartUtil_Print("Sending the MLME-Scan Request message to the MAC...", gAllowToBlock_d);

  /* Allocate a message for the MLME (We should check for NULL). */
  pMsg = MSG_AllocType(mlmeMessage_t);
  if(pMsg != NULL)
  {
    /* This is a MLME-SCAN.req command */
    pMsg->msgType = gMlmeScanReq_c;
    /* Create the Scan request message data. */
    pScanReq = &pMsg->msgData.scanReq;
    /* gScanModeED_c, gScanModeActive_c, gScanModePassive_c, or gScanModeOrphan_c */
    pScanReq->scanType = scanType;
    /* ChannelsToScan & 0xFF - LSB, always 0x00 */
    pScanReq->scanChannels[0] = (uint8_t)((mDefaultValueOfChannel_c)     & 0xFF);
    /* ChannelsToScan>>8 & 0xFF  */
    pScanReq->scanChannels[1] = (uint8_t)((mDefaultValueOfChannel_c>>8)  & 0xFF);
    /* ChannelsToScan>>16 & 0xFF  */
    pScanReq->scanChannels[2] = (uint8_t)((mDefaultValueOfChannel_c>>16) & 0xFF);
    /* ChannelsToScan>>24 & 0xFF - MSB */
    pScanReq->scanChannels[3] = (uint8_t)((mDefaultValueOfChannel_c>>24) & 0xFF);
    /* Duration per channel 0-14 (dc). T[sec] = (16*960*((2^dc)+1))/1000000.
       A scan duration of 2 on 16 channels approximately takes 1.2 secs. */
    /* We know beforehand that we will talk to a coordinator with a Beacon
       order of 1. Thus, choosing a Scan Duration of 2 per channel gives us
       a very good chance (100% assuming no interference) of finding the
       coordinator. 1 should be fine too though in an RF quiet environment. */
    pScanReq->scanDuration = mDefaultValueOfScanDuration_c;
#ifdef gMAC2006_d
	pScanReq->securityLevel = 0;
#endif //gMAC2006_d	
    
    /* Send the Scan request to the MLME. */
    if(MSG_Send(NWK_MLME, pMsg) == gSuccess_c)
    {
      UartUtil_Print("Done\n\r", gAllowToBlock_d);
      return errorNoError;
    }
    else
    {
      UartUtil_Print("Invalid parameter!\n\r", gAllowToBlock_d);
      return errorInvalidParameter;
    }
  }
  else
  {
    /* Allocation of a message buffer failed. */
    UartUtil_Print("Message allocation failed!\n\r", gAllowToBlock_d);
    return errorAllocFailed;
  }
}

/******************************************************************************
* The App_HandleScanPassiveConfirm(nwkMessage_t *pMsg) function will handle the
* Passive Scan confirm message received from the MLME when the Passive scan has
* completed. The message contains a list of PAN descriptors. Based on link
* quality information in the pan descriptors the nearest coordinator is chosen.
* The corresponding pan descriptor is stored in the global variable mCoordInfo. 
*
* If a suitable coordinator was found, we synchronize to it immediately.
*
* The function may return either of the following values:
*   errorNoError:       A suitable pan descriptor was found.
*   errorNoScanResults: No scan results were present in the confirm message.
*
******************************************************************************/
static uint8_t App_HandleScanPassiveConfirm(nwkMessage_t *pMsg)
{
  void    *pBlock;
  uint8_t panDescListSize = pMsg->msgData.scanCnf.resultListSize;
  uint8_t rc = errorNoScanResults;
  uint8_t j;
  uint8_t bestLinkQuality = 0;  
  panDescriptorBlock_t *pDescBlock = pMsg->msgData.scanCnf.resList.pPanDescriptorBlocks;  
  panDescriptor_t *pPanDesc;      
 
  /* Check if the scan resulted in any coordinator responses. */  
  
  if (panDescListSize > 0)
  {    
    /* Check all PAN descriptors. */
    while (NULL != pDescBlock)
    {
      for (j = 0; j < pDescBlock->descriptorCount; j++)
      {            
        pPanDesc = &pDescBlock->descriptorList[j];

        /* Only attempt to associate if the coordinator accepts associations. */
        if( pPanDesc->superFrameSpec[1] & gSuperFrameSpecMsbAssocPermit_c) 
        {        
            
          if ((pPanDesc->coordPanId[1]==coordinaterPanId[1])&&
          	 (pPanDesc->coordPanId[0]==coordinaterPanId[0]))
          {
            /* Find the nearest coordinator using the link quality measure. */
            if(pPanDesc->linkQuality > bestLinkQuality)
            {
              /* Save the information of the coordinator candidate. If we
                 find a better candiate, the information will be replaced. */
              FLib_MemCpy(&mCoordInfo, pPanDesc, sizeof(panDescriptor_t));
              bestLinkQuality = pPanDesc->linkQuality;
              rc = errorNoError;
            }
          }
        }      
      }
      
      /* Free current block */
      pBlock = pDescBlock;
      pDescBlock = pDescBlock->pNext;              
      MSG_Free(pBlock);
    }
  }

  if(rc == errorNoError)
  {
    /* If we have found a beaconing coodinator we must setup the MAC to
       synchronize to the beacon frames. This requires us to set the
       PAN ID attribute of the MAC PIB to the PAN ID of the coordinator.
       Furthermore, if we want to take advantage of the automatic
       polling feature we must set the Auto Request MAC PIB attribute. */
    if((mCoordInfo.superFrameSpec[0] & gSuperFrameSpecLsbBO_c) < 0xF) 
    {
      mlmeMessage_t *pMsgOut = MSG_AllocType(mlmeMessage_t);
      if(pMsgOut != NULL)
      {
        uint8_t value = TRUE;
        uint8_t mBeaconOrder;
		uint8_t mSuperFrameOrder;
        /* Set MAC PIB auto request to TRUE. In this way the device will
           automatically poll for data if the pending address list of the 
           beacon frame contains our address. */
        pMsgOut->msgType = gMlmeSetReq_c;
        pMsgOut->msgData.setReq.pibAttribute = gMPibAutoRequest_c;
        pMsgOut->msgData.setReq.pibAttributeValue = &value;
        /* Get/Set/Reset Request messages are NOT freed by the MLME. */
        (void)MSG_Send(NWK_MLME, pMsgOut);
        
        /* Since we are going to receive data from the coordinator 
           using automatic polling we must synchronize to the beacon
           and keep tracking it. Before synchronizing it is required
           that the MAC PIB PAN ID, and the MAC PIB coordinator
           address is set. */
        pMsgOut->msgData.setReq.pibAttribute = gMPibPanId_c;
        pMsgOut->msgData.setReq.pibAttributeValue = mCoordInfo.coordPanId;
        /* Get/Set/Reset Request messages are NOT freed by the MLME. */
        (void)MSG_Send(NWK_MLME, pMsgOut);

        /* Set coordinator address PIB attribute according the the 
           address mode of the coordinator (short or long address). */
        pMsgOut->msgData.setReq.pibAttribute = 
          mCoordInfo.coordAddrMode == gAddrModeShort_c ? gMPibCoordShortAddress_c :
                                                        gMPibCoordExtendedAddress_c;
        pMsgOut->msgData.setReq.pibAttributeValue = mCoordInfo.coordAddress;
        /* Get/Set/Reset Request messages are NOT freed by the MLME. */
        (void)MSG_Send(NWK_MLME, pMsgOut);


        /* Set macBeaconOrder PIB attribute according to the 
           value found in beacon.*/
        mBeaconOrder = (mCoordInfo.superFrameSpec[0] & 0x0F);   
        pMsgOut->msgData.setReq.pibAttribute = gMPibBeaconOrder_c;                                             
        pMsgOut->msgData.setReq.pibAttributeValue = &mBeaconOrder;
        /* Get/Set/Reset Request messages are NOT freed by the MLME. */
        (void)MSG_Send(NWK_MLME, pMsgOut);

        /* Set macSuperFrameOrder PIB attribute according to the 
           value found in beacon.*/
        mSuperFrameOrder = (mCoordInfo.superFrameSpec[0] & 0xF0);   
        pMsgOut->msgData.setReq.pibAttribute = gMPibSuperFrameOrder_c;                                             
        pMsgOut->msgData.setReq.pibAttributeValue = &mSuperFrameOrder;
        /* Get/Set/Reset Request messages are NOT freed by the MLME. */
        (void)MSG_Send(NWK_MLME, pMsgOut);  
        
        /* Now send the MLME-Sync Request. We choose to let the MAC track
           the beacons on the logical channel obtained by the passive scan.*/
        pMsgOut->msgType = gMlmeSyncReq_c;
        pMsgOut->msgData.syncReq.trackBeacon = TRUE;
        pMsgOut->msgData.syncReq.logicalChannel = mCoordInfo.logicalChannel;
        (void)MSG_Send(NWK_MLME, pMsgOut);
      }
    }
  }
  
  return rc;
}


/******************************************************************************
* The App_SendAssociateRequest(void) will create an Associate Request message
* and send it to the coordinator it wishes to associate to. The function uses
* information gained about the coordinator during the scan procedure.
*
* The function may return either of the following values:
*   errorNoError:          The Associate Request message was sent successfully.
*   errorInvalidParameter: The MLME service access point rejected the
*                          message due to an invalid parameter.
*   errorAllocFailed:      A message buffer could not be allocated.
*
******************************************************************************/
static uint8_t App_SendAssociateRequest(void)
{
  mlmeMessage_t *pMsg;
  mlmeAssociateReq_t *pAssocReq;

  UartUtil_Print("Sending the MLME-Associate Request message to the MAC...", gAllowToBlock_d);
  
  /* Allocate a message for the MLME message. */
  pMsg = MSG_AllocType(mlmeMessage_t);
  if(pMsg != NULL)
  {
    /* This is a MLME-ASSOCIATE.req command. */
    pMsg->msgType = gMlmeAssociateReq_c;
    
    /* Create the Associate request message data. */
    pAssocReq = &pMsg->msgData.associateReq;
 
    /* Use the coordinator info we got from the Passive Scan. */
    FLib_MemCpy(pAssocReq->coordAddress, mCoordInfo.coordAddress, 8);
    FLib_MemCpy(pAssocReq->coordPanId,   mCoordInfo.coordPanId, 2);
    pAssocReq->coordAddrMode      = mCoordInfo.coordAddrMode;
    pAssocReq->logicalChannel     = mCoordInfo.logicalChannel;
#ifndef gMAC2006_d
    pAssocReq->securityEnable     = FALSE;
#else
	pAssocReq->securityLevel = 0;
#endif //gMAC2006_d	
    /* We want the coordinator to assign a short address to us. */
    pAssocReq->capabilityInfo     = gCapInfoAllocAddr_c;
      
    /* Send the Associate Request to the MLME. */
    if(MSG_Send(NWK_MLME, pMsg) == gSuccess_c)
    {
      UartUtil_Print("Done\n\r", gAllowToBlock_d);
      return errorNoError;
    }
    else
    {
      /* One or more parameters in the message were invalid. */
      UartUtil_Print("Invalid parameter!\n\r", gAllowToBlock_d);
      return errorInvalidParameter;
    }
  }
  else
  {
    /* Allocation of a message buffer failed - 
       the state machine will call us again. */
    UartUtil_Print("Message allocation failed - retrying...\n\r", gAllowToBlock_d);
    return errorAllocFailed;
  }
}

/******************************************************************************
* The App_HandleAssociateConfirm(nwkMessage_t *pMsg) function will handle the
* Associate confirm message received from the MLME when the Association
* procedure has completed. The message contains the short address that the
* coordinator has assigned to us. This address is 0xfffe if we did not specify
* the gCapInfoAllocAddr_c flag in the capability info field of the Associate
* request. The address and address mode are saved in global variables. They
* will be used in the next demo application when sending data.
*
******************************************************************************/
static uint8_t App_HandleAssociateConfirm(nwkMessage_t *pMsg)
{
  /* This is our own extended address (MAC address). It cannot be modified. */
  extern uint8_t aExtendedAddress[8];
  
  uint8_t pValue = TRUE;
  (void)App_SetMacPib((uint8_t)0x52, &pValue);
  
  /* If the coordinator assigns a short address of 0xfffe then,
     that means we must use our own extended address in all
     communications with the coordinator. Otherwise, we use
     the short address assigned to us. */
  if ( pMsg->msgData.associateCnf.status == gSuccess_c) 
  {

    if( (pMsg->msgData.associateCnf.assocShortAddress[0] >= 0xFE) && 
        (pMsg->msgData.associateCnf.assocShortAddress[1] == 0xFF) )
    {
      mAddrMode = gAddrModeLong_c;
      FLib_MemCpy(maMyAddress, (void *)aExtendedAddress, 8);
    }
    else
    {
      mAddrMode = gAddrModeShort_c;
      FLib_MemCpy(maMyAddress, pMsg->msgData.associateCnf.assocShortAddress, 2);
    }
    return gSuccess_c;
  } 
  
  else 
  {
  return pMsg->msgData.associateCnf.status; 
  }
  
}

static uint8_t App_SetMacPib(uint8_t attribute, uint8_t *pValue){
  mlmeMessage_t mlmeSet;
	
  /* Create and execute the Set request */
  mlmeSet.msgType = gMlmeSetReq_c;
  mlmeSet.msgData.setReq.pibAttribute = attribute;
  mlmeSet.msgData.setReq.pibAttributeValue = pValue;
	
  return MSG_Send(NWK_MLME, &mlmeSet);
}


/******************************************************************************
* The App_HandleMcpsInput(mcpsToNwkMessage_t *pMsgIn) function will handle 
* messages from the MCPS, e.g. Data Confirm, and Data Indication.
*
******************************************************************************/
static void App_HandleMcpsInput(mcpsToNwkMessage_t *pMsgIn)
{
  switch(pMsgIn->msgType)
  {
    /* The MCPS-Data confirm is sent by the MAC to the network 
       or application layer when data has been sent. */
  case gMcpsDataCnf_c:
    if(mcPendingPackets)
      mcPendingPackets--;
    break;

  case gMcpsDataInd_c:
    /* Copy the received data to the UART. */
    UartUtil_Tx(pMsgIn->msgData.dataInd.pMsdu, pMsgIn->msgData.dataInd.msduLength);
    break;
  }
}

/******************************************************************************
* The App_WaitMsg(nwkMessage_t *pMsg, uint8_t msgType) function does not, as
* the name implies, wait for a message, thus blocking the execution of the
* state machine. Instead the function analyzes the supplied message to 
* determine whether or not the message is of the expected type.
* The function may return either of the following values:
*   errorNoError: The message was of the expected type.
*   errorNoMessage: The message pointer is NULL.
*   errorWrongConfirm: The message is not of the expected type.
*
******************************************************************************/
static uint8_t App_WaitMsg(nwkMessage_t *pMsg, uint8_t msgType)
{
  /* Do we have a message? If not, the exit with error code */
  if(pMsg == NULL)
    return errorNoMessage;

  /* Is it the expected message type? If not then exit with error code */
  if(pMsg->msgType != msgType)
    return errorWrongConfirm;

  /* Found the expected message. Return with success code */
  return errorNoError;
}

/******************************************************************************
* The App_TransmitUartData() function will perform (single/multi buffered)
* data transmissions of data received by the UART. Data could also come from
* other sources such as sensors etc. This is completely determined by the
* application. The constant mDefaultValueOfMaxPendingDataPackets_c determine the maximum
* number of packets pending for transmission in the MAC. A global variable
* is incremented each time a data packet is sent to the MCPS, and decremented
* when the corresponding MCPS-Data Confirm message is received. If the counter
* reaches the defined maximum no more data buffers are allocated until the
* counter is decreased below the maximum number of pending packets.
*
* The function uses the coordinator information gained during the Passive Scan,
* and the short address assigned to us by coordinator, for building an MCPS-
* Data Request message. The message is sent to the MCPS service access point
* in the MAC.
******************************************************************************/
static void App_TransmitUartData(void)
{   
  static uint8_t keysBuffer[mMaxKeysToReceive_c];
  static uint8_t keysReceived = 0;
  
  const uint8_t broadcastaddress[8] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};//added
  
  /* get data from UART */
  if( keysReceived < mMaxKeysToReceive_c ) 
  {
    if(UartX_GetByteFromRxBuffer(&keysBuffer[keysReceived])) 
    {
    keysReceived++;
    }
  }
	/* Use multi buffering for increased TX performance. It does not really
     have any effect at a UART baud rate of 19200bps but serves as an
     example of how the throughput may be improved in a real-world 
     application where the data rate is of concern. */
  if( (mcPendingPackets < mDefaultValueOfMaxPendingDataPackets_c) && (mpPacket == NULL) ) 
  {
    /* If the maximum number of pending data buffes is below maximum limit 
       and we do not have a data buffer already then allocate one. */
    mpPacket = MSG_Alloc(gMaxRxTxDataLength_c);
  }

  if(mpPacket != NULL)
  {
    /* get data from UART */        
      mpPacket->msgData.dataReq.pMsdu = (uint8_t*)(&(mpPacket->msgData.dataReq.pMsdu)) + sizeof(uint8_t*);
      FLib_MemCpy(mpPacket->msgData.dataReq.pMsdu, (uint8_t*) keysBuffer, keysReceived);
      /* Data was available in the UART receive buffer. Now create an
         MCPS-Data Request message containing the UART data. */
      mpPacket->msgType = gMcpsDataReq_c;
      /* Create the header using coordinator information gained during 
         the scan procedure. Also use the short address we were assigned
         by the coordinator during association. */
      //FLib_MemCpy(mpPacket->msgData.dataReq.dstAddr, mCoordInfo.coordAddress, 8);
      FLib_MemCpy(mpPacket->msgData.dataReq.dstAddr, broadcastaddress, 2);//changed
      FLib_MemCpy(mpPacket->msgData.dataReq.srcAddr, maMyAddress, 8);
      FLib_MemCpy(mpPacket->msgData.dataReq.dstPanId, mCoordInfo.coordPanId, 2);
      FLib_MemCpy(mpPacket->msgData.dataReq.srcPanId, mCoordInfo.coordPanId, 2);
      mpPacket->msgData.dataReq.dstAddrMode = mCoordInfo.coordAddrMode;
      mpPacket->msgData.dataReq.srcAddrMode = mAddrMode;
      mpPacket->msgData.dataReq.msduLength = keysReceived;
      /* Request MAC level acknowledgement of the data packet */
      //mpPacket->msgData.dataReq.txOptions = gTxOptsAck_c;
      mpPacket->msgData.dataReq.txOptions = 0;//changed
      /* Give the data packet a handle. The handle is
         returned in the MCPS-Data Confirm message. */
      mpPacket->msgData.dataReq.msduHandle = mMsduHandle++;
#ifdef gMAC2006_d
	  mpPacket->msgData.dataReq.securityLevel = 0;
#endif //gMAC2006_d	  
      
      /* Send the Data Request to the MCPS */
      (void)MSG_Send(NWK_MCPS, mpPacket);
      /* Prepare for another data buffer */
      mpPacket = NULL;
      mcPendingPackets++;
      /* Receive another pressed keys */
      keysReceived = 0;
  }
      
  /* If the keysBuffer[] wasn't send over the air because there are too many pending packets, */
  /* try to send it later   */
  if (keysReceived)
  {
  TS_SendEvent(gAppTaskID_c, gAppEvtRxFromUart_c);
  }

}

/*****************************************************************************
* Function to handle a generic key press. Called for all keys.
*****************************************************************************/
static void App_HandleGenericKey(void)
{
  if(gState == stateInit)
  {
   StopLed1Flashing();
   StopLed2Flashing();
   StopLed3Flashing();
   StopLed4Flashing();
   Led1Off();
   Led2Off();
   Led3Off();
   Led4Off();
   LCD_ClearDisplay();
   LCD_WriteString(1,"Application");
   LCD_WriteString(2,"    started");     
   TS_SendEvent(gAppTaskID_c, gAppEvtDummyEvent_c);       
  }
}

/*****************************************************************************
* Handles all key events for this device.
* Interface assumptions: None
* Return value: None
*****************************************************************************/
#if (gMC1323xMatrixKBD_d == TRUE)
static void App_HandleKeys(uint8_t events, uint8_t pressedKey)   
{
 (void)events;
 (void)pressedKey;
 App_HandleGenericKey();
}
#else
static void App_HandleKeys(key_event_t events)
{
  switch ( events ) 
    { 
      case gKBD_EventSW1_c:
      case gKBD_EventSW2_c:
      case gKBD_EventSW3_c:
      case gKBD_EventSW4_c:
      case gKBD_EventLongSW1_c:
      case gKBD_EventLongSW2_c:
      case gKBD_EventLongSW3_c:
      case gKBD_EventLongSW4_c:
       App_HandleGenericKey();
	  break; 
    }    
}
#endif //gMC1323xMatrixKBD_d

/*****************************************************************************
* The DeepSleepWakeupStackProc(void) function is called each time the 
* application exits the DeepSleep mode .
* 
* Return value:
*     None
*****************************************************************************/
void DeepSleepWakeupStackProc(void){
  return;
}

/******************************************************************************
* The following functions are called by the MAC to put messages into the
* Application's queue. They need to be defined even if they are not used
* in order to avoid linker errors.
******************************************************************************/

uint8_t MLME_NWK_SapHandler(nwkMessage_t * pMsg)
{
  /* Put the incoming MLME message in the applications input queue. */
  MSG_Queue(&mMlmeNwkInputQueue, pMsg);
  TS_SendEvent(gAppTaskID_c, gAppEvtMessageFromMLME_c);
  return gSuccess_c;
}

uint8_t MCPS_NWK_SapHandler(mcpsToNwkMessage_t *pMsg)
{
  /* Put the incoming MCPS message in the applications input queue. */
  MSG_Queue(&mMcpsNwkInputQueue, pMsg);
  TS_SendEvent(gAppTaskID_c, gAppEvtMessageFromMCPS_c);
  return gSuccess_c;
}

uint8_t ASP_APP_SapHandler(aspToAppMsg_t *pMsg)
{
  /* If the message is not handled anywhere it must be freed. */
  MSG_Free(pMsg);
  return gSuccess_c;
}

/******************************************************************************/
