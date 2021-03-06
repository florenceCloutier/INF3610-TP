/*
*********************************************************************************************************
*                                            uC/USB-Device
*                                    The Embedded USB Device Stack
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
*                                USB COMMUNICATIONS DEVICE CLASS (CDC)
*                                    ABSTRACT CONTROL MODEL (ACM)
*                                          SERIAL EMULATION
*
* Filename : usbd_acm_serial.h
* Version  : V4.05.05
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                               MODULE
*********************************************************************************************************
*/

#ifndef  USBD_ACM_SERIAL_MODULE_PRESENT
#define  USBD_ACM_SERIAL_MODULE_PRESENT


/*
*********************************************************************************************************
*                                            INCLUDE FILES
*********************************************************************************************************
*/

#include  "../usbd_cdc.h"


/*
*********************************************************************************************************
*                                               DEFINES
*********************************************************************************************************
*/

#define  USBD_ACM_SERIAL_NBR_NONE            DEF_INT_08U_MAX_VAL


/*
*********************************************************************************************************
*                                        PORT SETTINGS DEFINES
*********************************************************************************************************
*/

#define  USBD_ACM_SERIAL_PARITY_NONE                       0u
#define  USBD_ACM_SERIAL_PARITY_ODD                        1u
#define  USBD_ACM_SERIAL_PARITY_EVEN                       2u
#define  USBD_ACM_SERIAL_PARITY_MARK                       3u
#define  USBD_ACM_SERIAL_PARITY_SPACE                      4u


#define  USBD_ACM_SERIAL_STOP_BIT_1                        0u
#define  USBD_ACM_SERIAL_STOP_BIT_1_5                      1u
#define  USBD_ACM_SERIAL_STOP_BIT_2                        2u


/*
*********************************************************************************************************
*                                      LINE EVENTS FLAGS DEFINES
*********************************************************************************************************
*/

#define  USBD_ACM_SERIAL_CTRL_BREAK                   DEF_BIT_00
#define  USBD_ACM_SERIAL_CTRL_RTS                     DEF_BIT_01
#define  USBD_ACM_SERIAL_CTRL_DTR                     DEF_BIT_02

#define  USBD_ACM_SERIAL_STATE_DCD                    DEF_BIT_00
#define  USBD_ACM_SERIAL_STATE_DSR                    DEF_BIT_01
#define  USBD_ACM_SERIAL_STATE_BREAK                  DEF_BIT_02
#define  USBD_ACM_SERIAL_STATE_RING                   DEF_BIT_03
#define  USBD_ACM_SERIAL_STATE_FRAMING                DEF_BIT_04
#define  USBD_ACM_SERIAL_STATE_PARITY                 DEF_BIT_05
#define  USBD_ACM_SERIAL_STATE_OVERUN                 DEF_BIT_06


/*
*********************************************************************************************************
*                                    CALL MANAGEMENT CAPABILITIES
*
* Note(s) : (1) See 'USB, Communications Class, Subclass Specification for PSTN Devices, Revision 1.2,
*               February 9 2007', section '5.3.1 Call Management Functional Descriptor' for more details
*               about the Call Management capabilities.
*********************************************************************************************************
*/

#define  USBD_ACM_SERIAL_CALL_MGMT_DEV                DEF_BIT_00
#define  USBD_ACM_SERIAL_CALL_MGMT_DATA_CCI_DCI       DEF_BIT_01
#define  USBD_ACM_SERIAL_CALL_MGMT_DATA_OVER_DCI     (DEF_BIT_01 | DEF_BIT_00)


/*
*********************************************************************************************************
*                                             DATA TYPES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                        LINE CODING DATA TYPE
*********************************************************************************************************
*/

typedef  struct  usbd_acm_serial_line_coding {
    CPU_INT32U  BaudRate;
    CPU_INT08U  Parity;
    CPU_INT08U  StopBits;
    CPU_INT08U  DataBits;
} USBD_ACM_SERIAL_LINE_CODING;


/*
*********************************************************************************************************
*                                 LINE CTRL CHANGE CALLBACK DATA TYPE
*********************************************************************************************************
*/

typedef  void   (*USBD_ACM_SERIAL_LINE_CTRL_CHNGD) (CPU_INT08U   subclass_nbr,
                                                    CPU_INT08U   event,
                                                    CPU_INT08U   event_chngd,
                                                    void        *p_arg);



/*
*********************************************************************************************************
*                                LINE CODING CHANGE CALLBACK DATA TYPE
*********************************************************************************************************
*/

typedef  CPU_BOOLEAN  (*USBD_ACM_SERIAL_LINE_CODING_CHNGD) (CPU_INT08U                    subclass_nbr,
                                                            USBD_ACM_SERIAL_LINE_CODING  *p_line_coding,
                                                            void                         *p_arg);


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

void         USBD_ACM_SerialInit         (USBD_ERR                           *p_err);

CPU_INT08U   USBD_ACM_SerialAdd          (CPU_INT16U                          line_state_interval,
                                          CPU_INT16U                          call_mgmt_capabilities,
                                          USBD_ERR                           *p_err);

CPU_BOOLEAN  USBD_ACM_SerialCfgAdd       (CPU_INT08U                          subclass_nbr,
                                          CPU_INT08U                          dev_nbr,
                                          CPU_INT08U                          cfg_nbr,
                                          USBD_ERR                           *p_err);

CPU_BOOLEAN  USBD_ACM_SerialIsConn       (CPU_INT08U                          subclass_nbr);

CPU_INT32U   USBD_ACM_SerialRx           (CPU_INT08U                          subclass_nbr,
                                          CPU_INT08U                         *p_buf,
                                          CPU_INT32U                          buf_len,
                                          CPU_INT16U                          timeout,
                                          USBD_ERR                           *p_err);

CPU_INT32U   USBD_ACM_SerialTx           (CPU_INT08U                          subclass_nbr,
                                          CPU_INT08U                         *p_buf,
                                          CPU_INT32U                          buf_len,
                                          CPU_INT16U                          timeout,
                                          USBD_ERR                           *p_err);

#if 0
CPU_INT32U   USBD_ACM_SerialRxAsync      (CPU_INT08U                          subclass_nbr,
                                          CPU_INT08U                         *p_buf,
                                          CPU_INT32U                          buf_len,
                                          USBD_ACM_SERIAL_ASYNC               async,
                                          void                               *p_async_arg,
                                          USBD_ERR                           *p_err);

CPU_INT32U   USBD_ACM_SerialTxAsync      (CPU_INT08U                          subclass_nbr,
                                          CPU_INT08U                         *p_buf,
                                          CPU_INT32U                          buf_len,
                                          USBD_ACM_SERIAL_ASYNC               async,
                                          void                               *p_async_arg,
                                          USBD_ERR                           *p_err);
#endif

CPU_INT08U   USBD_ACM_SerialLineCtrlGet  (CPU_INT08U                          subclass_nbr,
                                          USBD_ERR                           *p_err);

void         USBD_ACM_SerialLineCtrlReg  (CPU_INT08U                          subclass_nbr,
                                          USBD_ACM_SERIAL_LINE_CTRL_CHNGD     line_ctrl_chngd,
                                          void                               *p_arg,
                                          USBD_ERR                           *p_err);

void         USBD_ACM_SerialLineCodingGet(CPU_INT08U                          subclass_nbr,
                                          USBD_ACM_SERIAL_LINE_CODING        *p_line_coding,
                                          USBD_ERR                           *p_err);

void         USBD_ACM_SerialLineCodingSet(CPU_INT08U                          subclass_nbr,
                                          USBD_ACM_SERIAL_LINE_CODING        *p_line_coding,
                                          USBD_ERR                           *p_err);

void         USBD_ACM_SerialLineCodingReg(CPU_INT08U                          subclass_nbr,
                                          USBD_ACM_SERIAL_LINE_CODING_CHNGD   line_coding_chngd,
                                          void                               *p_arg,
                                          USBD_ERR                           *p_err);

void         USBD_ACM_SerialLineStateSet (CPU_INT08U                          subclass_nbr,
                                          CPU_INT08U                          events,
                                          USBD_ERR                           *p_err);

void         USBD_ACM_SerialLineStateClr (CPU_INT08U                          subclass_nbr,
                                          CPU_INT08U                          events,
                                          USBD_ERR                           *p_err);


/*
*********************************************************************************************************
*                                         FUNCTION PROTOTYPES
*                                 DEFINED IN OS'S usbd_acm_serial_os.c
*********************************************************************************************************
*/



/*
*********************************************************************************************************
*                                        CONFIGURATION ERRORS
*********************************************************************************************************
*/

#ifndef  USBD_ACM_SERIAL_CFG_MAX_NBR_DEV
#error  "USBD_ACM_SERIAL_CFG_MAX_NBR_DEV not #define'd in 'usbd_cfg.h' [MUST be >= 1]"

#elif   (USBD_ACM_SERIAL_CFG_MAX_NBR_DEV < 1u)
#error  "USBD_ACM_SERIAL_CFG_MAX_NBR_DEV illegally #define'd in 'usbd_cfg.h'[MUST be >= 1]"

#elif   (USBD_ACM_SERIAL_CFG_MAX_NBR_DEV > USBD_CDC_CFG_MAX_NBR_DEV)
#error  "USBD_ACM_SERIAL_CFG_MAX_NBR_DEV illegally #define'd in 'usbd_cfg.h' [MUST be >= USBD_CDC_CFG_MAX_NBR_DEV]"
#endif


/*
*********************************************************************************************************
*                                             MODULE END
*********************************************************************************************************
*/

#endif
