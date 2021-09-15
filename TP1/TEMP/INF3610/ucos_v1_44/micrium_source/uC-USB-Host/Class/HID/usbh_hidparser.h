/*
*********************************************************************************************************
*                                             uC/USB-Host
*                                     The Embedded USB Host Stack
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
*                                 HUMAN INTERFACE DEVICE CLASS PARSER
*
* Filename : usbh_hidparser.h
* Version  : V3.41.07
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                               MODULE
*********************************************************************************************************
*/

#ifndef  USBH_HIDPARSER_MODULE_PRESENT
#define  USBH_HIDPARSER_MODULE_PRESENT


/*
*********************************************************************************************************
*                                            INCLUDE FILES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                               EXTERNS
*********************************************************************************************************
*/

#ifdef   USBH_HIDPARSER_MODULE
#define  USBH_HIDPARSER_EXT
#else
#define  USBH_HIDPARSER_EXT   extern
#endif


/*
*********************************************************************************************************
*                                               DEFINES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                             DATA TYPES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                          GLOBAL VARIABLES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                               MACROS
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                         FUNCTION PROTOTYPES
*********************************************************************************************************
*/

USBH_ERR             USBH_HID_ParserGlobalInit(void);

USBH_ERR             USBH_HID_ItemParser      (USBH_HID_DEV  *p_hid_dev,
                                               CPU_INT08U    *p_report_desc,
                                               CPU_INT32U     desc_len);

USBH_ERR             USBH_HID_CreateReportID  (USBH_HID_DEV  *p_hid_dev);

USBH_HID_REPORT_ID  *USBH_HID_MaxReport       (USBH_HID_DEV  *p_hid_dev,
                                               CPU_INT08U     type);


/*
*********************************************************************************************************
*                                        CONFIGURATION ERRORS
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                             MODULE END
*********************************************************************************************************
*/

#endif
