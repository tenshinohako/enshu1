/************************************************************************************
* Header file for interface between MAC and PHY layer.
* The functionality declared in this file all resides in the PHY layer of ZigBee
*
* (c) Copyright 2007, Freescale, Inc.  All rights reserved.
*
* No part of this document must be reproduced in any form - including copied,
* transcribed, printed or by any electronic means - without specific written
* permission from Freescale Semiconductor.
*
************************************************************************************/

#ifndef _MACPHY_H_
#define _MACPHY_H_

/************************************************************************************
*************************************************************************************
* Includes
*************************************************************************************
************************************************************************************/
#ifdef PROCESSOR_MC1323X
  #include "MacPhyMC1323X.h"
#else  

#include "MacPhyFLib.h"
#include "PhyMacMsg.h"

/************************************************************************************
*************************************************************************************
* Public macros
*************************************************************************************
************************************************************************************/

  // Get the offset from the beginning of a structure to the member variable
#define GetRelAddr(strct, member) ((uint8_t)((uint32_t)&(((strct *)(void *)0)->member))) 
#define GetRelAddr_16(strct, member) ((uint16_t)((uint32_t)&(((strct *)(void *)0)->member))) 

/************************************************************************************
*************************************************************************************
* New types and defines! Everybody must change to these!
*************************************************************************************
************************************************************************************/

#ifdef I_AM_A_SNIFFER
  struct rxPacketSniffer_tag {
    uint8_t frameLength;
    uint8_t linkQuality;
    uint8_t headerLength;
    uint8_t timeStampAbelLSB1;
    uint8_t timeStampAbelLSB0;
    uint8_t timeStampMCU;
    uint8_t rxData[gMaxRxTxDataLength_c];
    zbClock24_t timeStamp;  
  };                                                    

  typedef struct rxPacketSniffer_tag rxPacket_t;
#else
  typedef struct rxPacket_tag rxPacket_t;
#endif // I_AM_A_SNIFFER
typedef struct txPacket_tag txPacket_t;

/* Place it in NON_BANKED memory */
#ifdef MEMORY_MODEL_BANKED
#pragma CODE_SEG __NEAR_SEG NON_BANKED
#else
#pragma CODE_SEG DEFAULT
#endif /* MEMORY_MODEL_BANKED */
void validateWaitLength(uint8_t cmpValue);
#pragma CODE_SEG DEFAULT

#define EXIT_IF_RXINDEX_NOT_REACHED(cmpValue) {\
  uint8_t cmpLength = gRxDataIndexOffset_c + (cmpValue);\
  if(cmpLength > gPhyMacDataRxIndex) {\
    validateWaitLength(cmpValue);\
    return;\
  }\
}

  // For accessing fixed location fields in (MPDU/SPDU) rx/txData in rx/txPacket_t:
#define gFrameControlLsbPos_c   (GetRelAddr(hdrGenericHeaderType_t, frameControlLsb)) // Position in rx/txData in rx/txPacket_t
#define gFrameControlMsbPos_c   (GetRelAddr(hdrGenericHeaderType_t, frameControlMsb)) // Position in rx/txData in rx/txPacket_t
#define gSeqNumberPos_c         (GetRelAddr(hdrGenericHeaderType_t, seqNr)) // Position in rx/txData in rx/txPacket_t
#define gAddrFieldsStartPos_c   (GetRelAddr(hdrGenericHeaderType_t, addrFieldsStart)) // Position in rx/txData in rx/txPacket_t

  // For accessing txInfo info:
#define gTxInfoCommandFrameFlag_c               ((uint8_t)(1 << 0))
#define gTxInfoDataReqFlag_c                    ((uint8_t)(1 << 1))
#define gTxInfoIndirectFlag_c                   ((uint8_t)(1 << 2))
#define gTxInfoConfirmFlag_c                    ((uint8_t)(1 << 3)) // If set then a data indication will be sent after the frame has completed.
#define gTxInfoGtsFlag_c                        ((uint8_t)(1 << 4))
#define gTxInfoHiPriDataFlag_c                  ((uint8_t)(1 << 5)) // If set then this marks a high priority data frame that should be placed first in the direct queue
#define gTxInfoTreemodeRouteFlag_c              ((uint8_t)(1 << 6)) 
#define gTxInfoFramePendingModifyAllowFlag_c    ((uint8_t)(1 << 7))

  // Difference between Frame length (in rx/txPacket_t) and total packet legth over
  // the air is Preamble sequence, Start of frame delimiter and the Frame length
  // fields
#define gFrameLengthToTotalPhyLengthDiff_c (6)

#define gMacDataAndCommandThreshold_c 128
/*ClockManager defines*/
#define aCCATime_b (10) //[bytes]
#define aMinUnslottedRxSize_b (11+4) //[bytes]
#define aAckUnslottedSize_b  (11) //[bytes]
#define gEndtimeGuard_c (1) // [bytes]
#define gEarlyRxStart_c (0) // [symbols] @RNI: special GTS fix
#define aAckSlottedRxSlack aUnitBackoffPeriod_b // 10 [bytes], preferably 19 sym, but rounding is ok


  // Events to be used in the status field of the action_t.
  // Valid only for the SeqActionCompleteInd and SeqActionFailInd primitives.
  // NOT used in the SeqActionStartInd!!
enum {
  gSeqMemAcUndefined_c = gMacDataAndCommandThreshold_c, // Dummy: Only used for error handling. 
                              // Enum must start with 128, because data frames uses the Id field
                              // as the length field (frame lengths are always less than 128). 
                              // MLME to MEM id's are located in the range from 128 to 255.
                              // Values from 0 to 127 denotes a MAC frame of that size.
                              // This is taken advantage of in the MEM input handler.
  gSeqMemAcSuccess_c,
  gSeqMemAcRxTimeout_c,       // Rx ended with timeout
  gSeqMemAcRxPollNoTxData_c,
  gSeqMemAcTxPollNoRxData_c,
  gSeqMemAcTxChannelBusy_c,// CCA response (for TX too)
  gSeqMemAcTxAckMissing_c, // Tx data completed without acknowledge
  gSeqMemStatusLastEntry_c // THIS MUST BE THE LAST ENTRY IN THE ENUMERATION
};

  // Must NOT overlap other MEM event opcodes (gMlmeMemScanEdReq_c > gSeqMemStatusLastEntry_c)
enum {
  gMlmeMemScanEdReq_c = 180,  // The four Scan-related opcodes MUST follow each other
  gMlmeMemScanActiveReq_c,    // in the following order: energy, active, passive, orphan.
  gMlmeMemScanPassiveReq_c,
  gMlmeMemScanOrphanReq_c,
  gMlmeMemScanAbortReq_c,
  gMlmeMemStartReq_c,
  gMlmeMemTimerReq_c,
  gMlmeMemRxOnWhenIdleChanged_c,
  gMlmeMemSyncReq_c,
  gMlmeMemRxEnableReq_c,
  gMemCmdIdLastEntry // MUST BE THE LAST ENTRY
};
  // This is internal MEM events. Add-on to the memSeqStatus_t and gMemEventId_t 
  // structures.
  // Must NOT overlap other MEM event opcodes (gMemIntNoEvent_c > gMemCmdIdLastEntry)
enum {
  gMemIntNoEvent_c = 200, // A dummy event used for event buffering.
  gSeqMemActionFail_c, 
  gSeqMemActionFinish_c,
  gSeqMemDataInd_c,
  gMcpsDirectDataOrPollReq_c,
  gMemLwrAbortAll,
  gMemLwrTrigDataStateMachine_c,
  gMemCtrlDataStateMachineDone_c,
  gMemLwrTrigBeaconStateMachine_c,
  gMemLwrBeaconStateMachineDone_c,
  gMemCtrlAbortAllDone_c,
  gMemCtrlEdScanDone_c,
  gMemCtrlScanDone_c,
  gMemCtrlTimeout_c,
  gMemCtrlRxEnableDone_c,
  gMemIntLastEntry_c
};
typedef uint8_t memEventId_t;

  // Note: This enum contains all possible "timer related" status values. The timer
  // is currently only used during association. More status values can be added as
  // needed (currently only a single value is used although two are defined!)
enum {
  gTimerSuccess_c = 0,
  gTimerFailure_c
};



  // A header type with the generic information
typedef struct hdrGenericHeaderType_tag {
  uint8_t frameControlLsb;
  uint8_t frameControlMsb;
  uint8_t seqNr;
  uint8_t addrFieldsStart;
} hdrGenericHeaderType_t;


//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------
// New types and defines block end...
//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------

#define CHANNELS_SUPPORTED_31_24 (0x07)
#define CHANNELS_SUPPORTED_23_16 (0xFF)
#define CHANNELS_SUPPORTED_15_8  (0xF8)
#define CHANNELS_SUPPORTED_7_0   (0x00)

typedef enum ePhyEnums_tag {
  cBusy,
  cBusy_Rx,
  cBusy_Tx,
  cForce_Trx_Off,
  cIdle,
  cInvalid_Parameter,
  cRx_On,
  cSuccess,
  cTrx_Off,
  cTx_On,
  cUnsupported_Attribute,

    // New enums
  cCcaTx,
  cCcaCcaTx,
  cRxED,
  cRxCCA,
  cBusy_Wait,
  cMaxPhyEnums
} ePhyEnums_t;



#define gMacMinHeaderLengthAck_c  (5) /* Smallest packet (ACK) excluding FCS */
#define gMacMinHeaderLength_c     (9) /* Smallest packet (ACK) excluding FCS */


/************************************************************************************
*************************************************************************************
* Public prototypes
*************************************************************************************
************************************************************************************/


/************************************************************************************
*************************************************************************************
* Private prototypes
*************************************************************************************
************************************************************************************/


/************************************************************************************
*************************************************************************************
* Private type definitions
*************************************************************************************
************************************************************************************/
/************************************************************************************
*************************************************************************************
* Private macros
*************************************************************************************
************************************************************************************/

#define gRxDataIndexOffset_c (GetRelAddr(rxPacket_t, rxData))

/************************************************************************************
*************************************************************************************
* Public memory declarations
*************************************************************************************
************************************************************************************/
extern uint8_t gPhyMacDataRxIndex;
extern uint8_t gPhyMacDataTxIndex;
extern rxPacket_t *gpPhyRxData;
extern uint8_t *gpPhyTxPacket;

  // gRxTimeStamp holds the timestamp (16bit of the last received packet) 
extern zbClock16_t gRxTimeStamp;
extern zbClock24_t gRxTimeStamp24;
extern bool_t gStopAsyncRx;
extern bool_t gBeaconWithBadSrcDetected;
extern uint8_t gCurrentPALevel;
extern uint8_t *gpaPowerLevelLimits;

/************************************************************************************
*************************************************************************************
* Private memory declarations
*************************************************************************************
************************************************************************************/

/************************************************************************************
*************************************************************************************
* Public functions
*************************************************************************************
************************************************************************************/
// Mac-Phy Interface functions
#ifdef MEMORY_MODEL_BANKED
#pragma CODE_SEG __NEAR_SEG NON_BANKED
#else
#pragma CODE_SEG DEFAULT
#endif /* MEMORY_MODEL_BANKED */
void PhyPlmeEdRequest(void);
void PhyPlmeCcaRequest(void);
void PhyPlmeWaitRequest(void);
void PhyPlmeRxRequest(void);
void PhyPlmeTxRequest(void);
void PhyPlmeForceTrxOffRequest(void);
void PhyPdDataRequest(txPacket_t *pTxData);
void PhyPlmeSetCurrentChannelRequest(uint8_t channel);


// Phy-Mac Interface functions
void PhyPlmeCcaConfirm(bool_t channelInUse);
void PhyPlmeEdConfirm(uint8_t energyLevel);
void PhyPlmeRxTimeoutIndication(void);
void PhyPlmeSyncLossIndication(void);
void PhyPlmeB2BIndication(void);
void PhyPdDataConfirm(void);
void PhyPdDataIndication(void);


void ReStartRx(void);
void PhySyncSetEventTrigger(uint16_t startTime);
void PhySyncSetEventTimeout(zbClock24_t *pEndTime);
void DisableEventTimeout(void);
void RxTimeout(void);
void PollForRx(void);
void RestartRxOrTimeout(void);


extern void InitRxPointers(void);
extern void InitRxFastAction(void);
void SetCorrThresholdNormal(void);
void SetCorrThresholdHigh(void);
bool_t IsCurrentActionExtRx(void);
bool_t IsCurrentActionAutoRx(void);

void LowLevelReadClockSync(zbClock24_t *pRetClk);
void LowLevelReadClockASync(zbClock24_t *pRetClk);
extern void __near DummyFastIsr(void);
extern void IrqAsyncRxFilterEntry(void);
extern void IrqStreamingRxFirst(void);
#pragma CODE_SEG DEFAULT

#ifdef MEMORY_MODEL_BANKED
extern void __near(* __near gIsrFastAction)(void);
extern void __near(* __near gIsrPendingFastAction)(void);
extern void __near(* __near gIsrAsyncTailFunction)(void);
#else
extern void (* __near gIsrFastAction)(void);
extern void (* __near gIsrPendingFastAction)(void);
extern void (* __near gIsrAsyncTailFunction)(void);
#endif /* MEMORY_MODEL_BANKED */

void InitializePhy(void);
void Phy_InitOnStartup(uint16_t phyRfCalibration, bool_t useDualAntenna);
void InitializeMac(bool_t resetPib);







/************************************************************************************
*************************************************************************************
* Private functions
*************************************************************************************
************************************************************************************/

/***********************************************************************************/

#endif /* PROCESSOR_MC1323X */

#endif /* _MACPHY_H_  */
