/*****************************************************************************
* This module configures function to return the reset reasons
*
*
* (c) Copyright 2005, Freescale, Inc. All rights reserved.
*
*
* No part of this document must be reproduced in any form - including copied,
* transcribed, printed or by any electronic means - without specific written
* permission from Freescale Semiconductor.
*
*****************************************************************************/
#include "EmbeddedTypes.h" /*Typedef for Data types*/
#include "IoConfig.h"
#include "RST_Interface.h"

/*****************************************************************************
******************************************************************************
* Private macros
******************************************************************************
*****************************************************************************/

/*****************************************************************************
******************************************************************************
* Private prototypes
******************************************************************************
*****************************************************************************/
/*None*/

/*****************************************************************************
******************************************************************************
* Private type definitions
******************************************************************************
*****************************************************************************/
/*None*/

/*****************************************************************************
******************************************************************************
* Private memory declarations
******************************************************************************
*****************************************************************************/
uint8_t gRSTResetStatus;/*illopcode and COP reset sets this variable*/

/*****************************************************************************
******************************************************************************
* Public functions
******************************************************************************
*****************************************************************************/

/*****************************************************************************
* Sets a global variable according to the reset reason detected.
*
* Interface assumptions:
*
* Return value:
* None
*
*****************************************************************************/

void RST_GetResetStatus(void){
    gRSTResetStatus = SIMRS;
}

/*****************************************************************************
******************************************************************************
* Private functions
******************************************************************************
*****************************************************************************/
/*None*/

/*****************************************************************************
******************************************************************************
* Private Debug stuff
******************************************************************************
*****************************************************************************/
/*None*/
