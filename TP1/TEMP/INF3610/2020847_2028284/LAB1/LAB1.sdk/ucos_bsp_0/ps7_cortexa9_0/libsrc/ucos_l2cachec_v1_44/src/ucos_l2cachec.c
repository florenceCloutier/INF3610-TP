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
*                                    MICRIUM BOARD SUPPORT PACKAGE
*                                     L2C310 L2 CACHE CONTROLLER
*
* File : ucos_l2cachec.c
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                             INCLUDE FILES
*********************************************************************************************************
*/

#include  <cpu.h>
#include  <lib_def.h>

#include  <xparameters.h>
#include  <ucos_l2cachec.h>


/*
*********************************************************************************************************
*********************************************************************************************************
**                                         GLOBAL FUNCTIONS
*********************************************************************************************************
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                             L2CacheC_En()
*
* Description : Enable the L2 Cache.
*
* Argument(s) : none.
*
* Return(s)   : none.
*
* Note(s)     : none.
*
*********************************************************************************************************
*/

void L2CacheC_En (void)
{
    L2CACHEC_REG->REG1_CTRL |= L2CACHEC_BIT_CTRL_EN;
}


/*
*********************************************************************************************************
*                                          L2CacheC_AuxCtrlSet()
*
* Description : Set the content of the Auxilliary Control Register to "aux_val".
*
* Argument(s) : aux_val Value to write in the Auxilliary Control Register.
*
* Return(s)   : none.
*
* Note(s)     : none.
*
*********************************************************************************************************
*/

void L2CacheC_AuxCtrlSet (CPU_INT32U aux_val)
{
    L2CACHEC_REG->REG1_AUX_CTRL = aux_val;
}

/*
*********************************************************************************************************
*                                          L2CacheC_PrefetchCtrlSet()
*
* Description : Set the content of the Auxilliary Control Register to "aux_val".
*
* Argument(s) : aux_val Value to write in the Auxilliary Control Register.
*
* Return(s)   : none.
*
* Note(s)     : none.
*
*********************************************************************************************************
*/

void L2CacheC_PrefetchCtrlSet (CPU_INT32U prefetch_val)
{
    L2CACHEC_REG->REG15_PREFETCH_CTRL = prefetch_val;
}


/*
*********************************************************************************************************
*                                             L2CacheC_TagRamLatencySet()
*
* Description : Configure the L2 Cache tag ram access latencies.
*
* Argument(s) : setup_latency  Setup latency.
*               read_latency   Read latency.
*               write_latency  Write latency.
*
* Return(s)   : none.
*
* Note(s)     : none.
*
*********************************************************************************************************
*/

void L2CacheC_TagRamLatencySet (CPU_INT32U setup_latency, CPU_INT32U read_latency, CPU_INT32U write_latency)
{
    L2CACHEC_REG->REG1_TAG_RAM_CTRL = (setup_latency & 0x7u) | (read_latency & 0x7u) << 4 | (write_latency & 0x7u) << 8;
}


/*
*********************************************************************************************************
*                                             L2CacheC_DataRamLatencySet()
*
* Description : Configure the L2 Cache data ram access latencies.
*
* Argument(s) : setup_latency  Setup latency.
*               read_latency   Read latency.
*               write_latency  Write latency.
*
* Return(s)   : none.
*
* Note(s)     : none.
*
*********************************************************************************************************
*/

void L2CacheC_DataRamLatencySet (CPU_INT32U setup_latency, CPU_INT32U read_latency, CPU_INT32U write_latency)
{
    L2CACHEC_REG->REG1_DATA_RAM_CTRL = (setup_latency & 0x7u) | (read_latency & 0x7u) << 4 | (write_latency & 0x7u) << 8;
}
