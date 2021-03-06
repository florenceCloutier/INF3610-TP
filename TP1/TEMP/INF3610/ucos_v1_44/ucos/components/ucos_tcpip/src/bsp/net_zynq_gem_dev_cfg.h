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
*                                  NETWORK DEVICE CONFIGURATION FILE
*
* File : net_dev_cfg.h
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*********************************************************************************************************
*                                               MODULE
*
* Note(s) : (1) This network device configuration header file is protected from multiple pre-processor
*               inclusion through use of the network module present pre-processor macro definition.
*********************************************************************************************************
*********************************************************************************************************
*/

#ifndef  NET_DEV_CFG_MODULE_PRESENT                             /* See Note #1.                                         */
#define  NET_DEV_CFG_MODULE_PRESENT

#include   <Source/net_cfg_net.h>

#ifdef  NET_IF_ETHER_MODULE_EN
#include   <IF/net_if_ether.h>
#endif

#ifdef  NET_IF_WIFI_MODULE_EN
#include   <IF/net_if_wifi.h>
#endif


/*
*********************************************************************************************************
*********************************************************************************************************
*                                    NETWORK DEVICE CONFIGURATION
*
* Note(s) : (1) (a) Each network device maps to a unique, developer-configured device configuration that
*                   MUST be defined in application files, typically 'net_dev_cfg.c', & SHOULD be forward-
*                   declared with the exact same name & type in order to be used by the application during
*                   calls to NetIF_Add().
*
*               (b) Since these device configuration structures are referenced ONLY by application files,
*                   there is NO required naming convention for these configuration structures.  However,
*                   the following naming convention is suggested for all developer-configured network
*                   device configuration structures :
*
*                       NetDev_Cfg_<Device>[_Number]
*
*                           where
*                                   <Device>        Name of device or device driver
*                                   [Number]        Network device number for each specific instance of
*                                                       device (optional if the development board does NOT
*                                                       support multiple instances of the specific device)
*
*                       Examples :
*
*                           NET_DEV_CFG_ETHER  NetDev_Cfg_MACB;         Ethernet configuration for MACB
*
*                           NET_DEV_CFG_ETHER  NetDev_Cfg_FEC_0;        Ethernet configuration for FEC #0
*                           NET_DEV_CFG_ETHER  NetDev_Cfg_FEC_1;        Ethernet configuration for FEC #1
*
*                           NET_DEV_CFG_WIFI   NetDev_Cfg_RS9110N21_0;  Wireless configuration for RS9110-N-21
*********************************************************************************************************
*********************************************************************************************************
*/

#ifdef  NET_IF_ETHER_MODULE_EN

extern  NET_DEV_CFG_ETHER  NetDev_GEM_1;
extern  NET_PHY_CFG_ETHER  NetPhy_Cfg_Ether_1;

#endif  /* NET_IF_ETHER_MODULE_EN */


/*
*********************************************************************************************************
*********************************************************************************************************
*                                             MODULE END
*********************************************************************************************************
*********************************************************************************************************
*/

#endif  /* NET_DEV_CFG_MODULE_PRESENT */

