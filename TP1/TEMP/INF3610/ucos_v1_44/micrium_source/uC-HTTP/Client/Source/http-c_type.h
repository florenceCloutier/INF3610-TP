/*
*********************************************************************************************************
*                                               uC/HTTP
*                                     Hypertext Transfer Protocol
*
*                         (c) Copyright 2004-2019; Silicon Laboratories Inc.,
*                                400 W. Cesar Chavez, Austin, TX 78701
*
*                   All rights reserved. Protected by international copyright laws.
*
*                  Your use of this software is subject to your acceptance of the terms
*                  of a Silicon Labs Micrium software license, which can be obtained by
*                  contacting info@micrium.com. If you do not agree to the terms of this
*                  license, you may not use this software.
*
*                  Please help us continue to provide the Embedded community with the finest
*                  software available. Your honesty is greatly appreciated.
*
*                    You can find our product's documentation at: doc.micrium.com
*
*                          For more information visit us at: www.micrium.com
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*
*                                             HTTP CLIENT
*
* Filename : http-c_type.h
* Version  : V3.00.07
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*********************************************************************************************************
*                                               MODULE
*
* Note(s) : (1) This main network protocol suite header file is protected from multiple pre-processor
*               inclusion through use of the HTTPc module present pre-processor macro definition.
*********************************************************************************************************
*********************************************************************************************************
*/

#ifndef  HTTPc_TYPE_MODULE_PRESENT                              /* See Note #1.                                         */
#define  HTTPc_TYPE_MODULE_PRESENT

/*
*********************************************************************************************************
*********************************************************************************************************
*                                         HTTPc INCLUDE FILES
*********************************************************************************************************
*********************************************************************************************************
*/

#include  <cpu.h>
#include  <Source/net_type.h>


/*
*********************************************************************************************************
*********************************************************************************************************
*                                              DATA TYPES
*********************************************************************************************************
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                       CONFIGURATION DATA TYPE
*********************************************************************************************************
*/

typedef  struct  httpc_cfg {

/*
*--------------------------------------------------------------------------------------------------------
*                                      TASK CONFIGURATION
*--------------------------------------------------------------------------------------------------------
*/

    CPU_INT08U                 TaskDly_ms;                      /* Task Delay in milliseconds.                          */


/*
*--------------------------------------------------------------------------------------------------------
*                                   CONNECTION CONFIGURATION
*--------------------------------------------------------------------------------------------------------
*/
    CPU_INT08U                 MsgQ_Size;                       /* Message Queue Size.                                  */
    CPU_INT16U                 ConnConnectTimeout_ms;           /* Connection Connect Timeout.                          */
    CPU_INT16U                 ConnInactivityTimeout_s;         /* Connection Inactivity Timeout.                       */
    CPU_BOOLEAN                ConnIsKeepAlive;                 /* Configure the connection to use keep-alive probes.   */
} HTTPc_CFG;


/*
*********************************************************************************************************
*********************************************************************************************************
*                                             MODULE END
*********************************************************************************************************
*********************************************************************************************************
*/

#endif  /* HTTPc_TYPE_MODULE_PRESENT  */
