/*
*********************************************************************************************************
*                                                uC/FS
*                                      The Embedded File System
*
*                         (c) Copyright 2008-2019; Silicon Laboratories Inc.,
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
*                                      UNICODE STRING MANAGEMENT
*
* Filename : fs_unicode.h
* Version  : v4.07.06
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                               MODULE
*********************************************************************************************************
*/

#ifndef  FS_UNICODE_H
#define  FS_UNICODE_H


/*
*********************************************************************************************************
*                                            INCLUDE FILES
*********************************************************************************************************
*/

#include  <cpu.h>
#include  "fs_cfg_fs.h"


/*
*********************************************************************************************************
*                                               EXTERNS
*********************************************************************************************************
*/

#ifdef   FS_UNICODE_MODULE
#define  FS_UNICODE_EXT
#else
#define  FS_UNICODE_EXT  extern
#endif


/*
*********************************************************************************************************
*                                        DEFAULT CONFIGURATION
*********************************************************************************************************
*/

#ifndef  FS_UNICODE_CFG_WCHAR_SIZE
#define  FS_UNICODE_CFG_WCHAR_SIZE                        16
#endif


/*
*********************************************************************************************************
*                                               DEFINES
*********************************************************************************************************
*/

#define  MB_MAX_LEN                                        4u


/*
*********************************************************************************************************
*                                             DATA TYPES
*********************************************************************************************************
*/

#if   (FS_UNICODE_CFG_WCHAR_SIZE == 16)
typedef  CPU_INT16U  CPU_WCHAR;
#elif (FS_UNICODE_CFG_WCHAR_SIZE == 32)
typedef  CPU_INT32U  CPU_WCHAR;
#else
#error  "FS_UNICODE_CFG_WCHAR_SIZE  illegally #define'd in 'app_cfg.h'"
#error  "                           [MUST be  16]                     "
#error  "                           [     ||  32]                     "
#endif


/*
*********************************************************************************************************
*                                          GLOBAL VARIABLES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                              MACRO'S
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                         FUNCTION PROTOTYPES
*********************************************************************************************************
*/

CPU_SIZE_T    WC_StrLen            (CPU_WCHAR    *pstr);

CPU_SIZE_T    WC_StrLen_N          (CPU_WCHAR     *pstr,
                                    CPU_SIZE_T     len_max);


                                                                        /* -------------- STR COPY FNCTS -------------- */
CPU_WCHAR    *WC_StrCopy           (CPU_WCHAR    *pdest,
                                    CPU_WCHAR    *psrc);

CPU_WCHAR    *WC_StrCopy_N         (CPU_WCHAR    *pdest,
                                    CPU_WCHAR    *psrc,
                                    CPU_SIZE_T    len_max);


CPU_WCHAR    *WC_StrCat            (CPU_WCHAR    *pdest,
                                    CPU_WCHAR    *pstr_cat);

CPU_WCHAR    *WC_StrCat_N          (CPU_WCHAR    *pdest,
                                    CPU_WCHAR    *pstr_cat,
                                    CPU_SIZE_T    len_max);


                                                                        /* -------------- STR CMP  FNCTS -------------- */
CPU_INT32S    WC_StrCmp            (CPU_WCHAR    *p1_str,
                                    CPU_WCHAR    *p2_str);

CPU_INT32S    WC_StrCmp_N          (CPU_WCHAR    *p1_str,
                                    CPU_WCHAR    *p2_str,
                                    CPU_SIZE_T    len_max);

CPU_INT32S    WC_StrCmpIgnoreCase  (CPU_WCHAR    *p1_str,
                                    CPU_WCHAR    *p2_str);

CPU_INT32S    WC_StrCmpIgnoreCase_N(CPU_WCHAR    *p1_str,
                                    CPU_WCHAR    *p2_str,
                                    CPU_SIZE_T    len_max);


                                                                        /* -------------- STR SRCH FNCTS -------------- */
CPU_WCHAR    *WC_StrChar           (CPU_WCHAR    *pstr,
                                    CPU_WCHAR     srch_char);

CPU_WCHAR    *WC_StrChar_N         (CPU_WCHAR    *pstr,
                                    CPU_SIZE_T    len_max,
                                    CPU_WCHAR     srch_char);

CPU_WCHAR    *WC_StrChar_Last      (CPU_WCHAR    *pstr,
                                    CPU_WCHAR     srch_char);

CPU_WCHAR    *WC_StrChar_Last_N    (CPU_WCHAR    *pstr,
                                    CPU_WCHAR     srch_char,
                                    CPU_SIZE_T    len_max);


CPU_WCHAR    *WC_StrStr            (CPU_WCHAR    *pstr,
                                    CPU_WCHAR    *psrch_str);

CPU_WCHAR    *WC_StrStr_N          (CPU_WCHAR    *pstr,
                                    CPU_WCHAR    *psrch_str,
                                    CPU_SIZE_T    len_max);

                                                                        /* ------ CHARACTER CLASSIFICATION FNCTS ------ */
CPU_BOOLEAN   WC_CharIsAlpha       (CPU_WCHAR     c);

CPU_BOOLEAN   WC_CharIsAlphaNum    (CPU_WCHAR     c);

CPU_BOOLEAN   WC_CharIsLower       (CPU_WCHAR     c);

CPU_BOOLEAN   WC_CharIsUpper       (CPU_WCHAR     c);

CPU_BOOLEAN   WC_CharIsDig         (CPU_WCHAR     c);

CPU_BOOLEAN   WC_CharIsDigOct      (CPU_WCHAR     c);

CPU_BOOLEAN   WC_CharIsDigHex      (CPU_WCHAR     c);

CPU_BOOLEAN   WC_CharIsSpace       (CPU_WCHAR     c);


                                                                        /* ------------ CASE MAPPING FNCTS ------------ */
CPU_WCHAR     WC_CharToLower       (CPU_WCHAR     c);

CPU_WCHAR     WC_CharToUpper       (CPU_WCHAR     c);

CPU_WCHAR     WC_CharToCasefold    (CPU_WCHAR     c);


                                                                        /* ------------- CONVERSION FNCTS ------------- */
CPU_SIZE_T    WC_CharToMB          (CPU_CHAR     *pc_dest,
                                    CPU_WCHAR     c_src);

CPU_SIZE_T    MB_CharToWC          (CPU_WCHAR    *pc_dest,
                                    CPU_CHAR     *pc_src,
                                    CPU_SIZE_T    n);

CPU_SIZE_T    MB_CharLen           (CPU_CHAR     *pc,
                                    CPU_SIZE_T    n);


CPU_SIZE_T    WC_StrToMB           (CPU_CHAR     *pdest,
                                    CPU_WCHAR   **ppsrc,
                                    CPU_SIZE_T    len_max);

CPU_SIZE_T    MB_StrToWC           (CPU_WCHAR    *pdest,
                                    CPU_CHAR    **ppsrc,
                                    CPU_SIZE_T    len_max);


/*
*********************************************************************************************************
*                                        CONFIGURATION ERRORS
*********************************************************************************************************
*/

#ifndef  FS_UNICODE_CFG_WCHAR_SIZE
#error  "FS_UNICODE_CFG_WCHAR_SIZE        not #define'd in 'app_cfg.h'"
#error  "                           [MUST be  16]                     "
#error  "                           [     ||  32]                     "

#elif  ((FS_UNICODE_CFG_WCHAR_SIZE != 16) && \
        (FS_UNICODE_CFG_WCHAR_SIZE != 32 ))
#error  "FS_UNICODE_CFG_WCHAR_SIZE  illegally #define'd in 'app_cfg.h'"
#error  "                           [MUST be  16]                     "
#error  "                           [     ||  32]                     "
#endif


/*
*********************************************************************************************************
*                                             MODULE END
*********************************************************************************************************
*/

#endif
