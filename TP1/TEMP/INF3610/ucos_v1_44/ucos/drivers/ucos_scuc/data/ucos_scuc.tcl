#############################################################################
#                               uCOS XSDK BSP                               #
#                                                                           #
#        (c) Copyright 2014-2019; Silicon Laboratories Inc.,                #
#               400 W. Cesar Chavez, Austin, TX 78701                       #
#                                                                           #
#  All rights reserved. Protected by international copyright laws.          #
#                                                                           #
# Your use of this software is subject to your acceptance of the terms      #
# of a Silicon Labs Micrium software license, which can be obtained by      #
# contacting info@micrium.com. If you do not agree to the terms of this     #
# license, you may not use this software.                                   #
#                                                                           #
# Please help us continue to provide the Embedded community with the finest #
# software available. Your honesty is greatly appreciated.                  #
#                                                                           #
#   You can find our product's documentation at: doc.micrium.com            #
#                                                                           #
#         For more information visit us at: www.micrium.com                 #
#############################################################################


source ../../../bsp/data/ucos_tcl_utils.tcl
source ../../../bsp/data/xil_tcl_utils.tcl

proc generate {drv_handle} {
    ucos_log_put "TRACE" "Generating ucos_scuc."
    xdefine_zynq_include_file $drv_handle "xparameters.h" "UCOS_L2CACHEC" "NUM_INSTANCES" "DEVICE_ID" "C_S_AXI_BASEADDR" "C_S_AXI_HIGHADDR"
}

