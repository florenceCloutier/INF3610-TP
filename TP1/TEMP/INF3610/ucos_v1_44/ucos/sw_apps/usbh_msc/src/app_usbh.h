/*
*********************************************************************************************************
*                                             uCOS XSDK BSP                               
*                                                                                         
*                      (c) Copyright 2014-2019; Silicon Laboratories Inc.,                
*                             400 W. Cesar Chavez, Austin, TX 78701                       
*                                                                                         
*                All rights reserved. Protected by international copyright laws.          
*                                                                                         
*               Your use of this software is subject to your acceptance of the terms      
*               of a Silicon Labs Micrium software license, which can be obtained by      
*               contacting info@micrium.com. If you do not agree to the terms of this     
*               license, you may not use this software.                                   
*                                                                                         
*               Please help us continue to provide the Embedded community with the finest 
*               software available. Your honesty is greatly appreciated.                  
*                                                                                         
*                 You can find our product's documentation at: doc.micrium.com            
*                                                                                         
*                       For more information visit us at: www.micrium.com                 
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                   USB APPLICATION INITIALIZATION
*
* File : app_usbh.h
*********************************************************************************************************
*/

#ifndef  APP_USBH_MODULE_PRESENT
#define  APP_USBH_MODULE_PRESENT


/*
*********************************************************************************************************
*                                              INCLUDE FILES
*********************************************************************************************************
*/

#include  <cpu.h>
#include  <lib_def.h>


/*
*********************************************************************************************************
*                                                 EXTERNS
*********************************************************************************************************
*/

#ifdef   APP_USBH_MODULE
#define  APP_USBH_MODULE_EXT
#else
#define  APP_USBH_MODULE_EXT  extern
#endif


/*
*********************************************************************************************************
*                                                 DEFINES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                      CONDITIONAL INCLUDE FILES
*********************************************************************************************************
*/

#include    "app_usbh_msc.h"


/*
*********************************************************************************************************
*                                               DATA TYPES
*********************************************************************************************************
*/

typedef  CPU_STK  USBH_STK;                                     /* Task's stack data type.                              */


/*
*********************************************************************************************************
*                                            GLOBAL VARIABLES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                                 MACRO'S
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                           FUNCTION PROTOTYPES
*********************************************************************************************************
*/

CPU_BOOLEAN  App_USBH_Init (void);


/*
*********************************************************************************************************
*                                             MODULE END
*********************************************************************************************************
*/

#endif
