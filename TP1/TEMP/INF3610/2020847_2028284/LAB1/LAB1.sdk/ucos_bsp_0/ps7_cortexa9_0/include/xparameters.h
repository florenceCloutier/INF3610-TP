#ifndef XPARAMETERS_H   /* prevent circular inclusions */
#define XPARAMETERS_H   /* by using protection macros */

/* Definition for CPU ID */
#define XPAR_CPU_ID 0U

/* Definitions for peripheral PS7_CORTEXA9_0 */
#define XPAR_PS7_CORTEXA9_0_CPU_CLK_FREQ_HZ 666666687


/******************************************************************/

/* Canonical definitions for peripheral PS7_CORTEXA9_0 */
#define XPAR_CPU_CORTEXA9_0_CPU_CLK_FREQ_HZ 666666687


/******************************************************************/

#include "xparameters_ps.h"

#define STDOUT_BASEADDRESS 0xE0001000

/******************************************************************/

/* Platform specific definitions */
#define PLATFORM_ZYNQ
 
/* Definitions for sleep timer configuration */
#define XSLEEP_TIMER_IS_DEFAULT_TIMER
 
 
/******************************************************************/

/* Definitions for peripheral PS7_DDR_0 */
#define XPAR_PS7_DDR_0_S_AXI_BASEADDR 0x00100000
#define XPAR_PS7_DDR_0_S_AXI_HIGHADDR 0x1FFFFFFF


/******************************************************************/

/* Definitions for driver DEVCFG */
#define XPAR_XDCFG_NUM_INSTANCES 1U

/* Definitions for peripheral PS7_DEV_CFG_0 */
#define XPAR_PS7_DEV_CFG_0_DEVICE_ID 0U
#define XPAR_PS7_DEV_CFG_0_BASEADDR 0xF8007000U
#define XPAR_PS7_DEV_CFG_0_HIGHADDR 0xF80070FFU


/******************************************************************/

/* Canonical definitions for peripheral PS7_DEV_CFG_0 */
#define XPAR_XDCFG_0_DEVICE_ID XPAR_PS7_DEV_CFG_0_DEVICE_ID
#define XPAR_XDCFG_0_BASEADDR 0xF8007000U
#define XPAR_XDCFG_0_HIGHADDR 0xF80070FFU


/******************************************************************/

/* Definitions for driver DMAPS */
#define XPAR_XDMAPS_NUM_INSTANCES 2

/* Definitions for peripheral PS7_DMA_NS */
#define XPAR_PS7_DMA_NS_DEVICE_ID 0
#define XPAR_PS7_DMA_NS_BASEADDR 0xF8004000
#define XPAR_PS7_DMA_NS_HIGHADDR 0xF8004FFF


/* Definitions for peripheral PS7_DMA_S */
#define XPAR_PS7_DMA_S_DEVICE_ID 1
#define XPAR_PS7_DMA_S_BASEADDR 0xF8003000
#define XPAR_PS7_DMA_S_HIGHADDR 0xF8003FFF


/******************************************************************/

/* Canonical definitions for peripheral PS7_DMA_NS */
#define XPAR_XDMAPS_0_DEVICE_ID XPAR_PS7_DMA_NS_DEVICE_ID
#define XPAR_XDMAPS_0_BASEADDR 0xF8004000
#define XPAR_XDMAPS_0_HIGHADDR 0xF8004FFF

/* Canonical definitions for peripheral PS7_DMA_S */
#define XPAR_XDMAPS_1_DEVICE_ID XPAR_PS7_DMA_S_DEVICE_ID
#define XPAR_XDMAPS_1_BASEADDR 0xF8003000
#define XPAR_XDMAPS_1_HIGHADDR 0xF8003FFF


/******************************************************************/


/* Definitions for peripheral PS7_AFI_0 */
#define XPAR_PS7_AFI_0_S_AXI_BASEADDR 0xF8008000
#define XPAR_PS7_AFI_0_S_AXI_HIGHADDR 0xF8008FFF


/* Definitions for peripheral PS7_AFI_1 */
#define XPAR_PS7_AFI_1_S_AXI_BASEADDR 0xF8009000
#define XPAR_PS7_AFI_1_S_AXI_HIGHADDR 0xF8009FFF


/* Definitions for peripheral PS7_AFI_2 */
#define XPAR_PS7_AFI_2_S_AXI_BASEADDR 0xF800A000
#define XPAR_PS7_AFI_2_S_AXI_HIGHADDR 0xF800AFFF


/* Definitions for peripheral PS7_AFI_3 */
#define XPAR_PS7_AFI_3_S_AXI_BASEADDR 0xF800B000
#define XPAR_PS7_AFI_3_S_AXI_HIGHADDR 0xF800BFFF


/* Definitions for peripheral PS7_DDRC_0 */
#define XPAR_PS7_DDRC_0_S_AXI_BASEADDR 0xF8006000
#define XPAR_PS7_DDRC_0_S_AXI_HIGHADDR 0xF8006FFF


/* Definitions for peripheral PS7_GLOBALTIMER_0 */
#define XPAR_PS7_GLOBALTIMER_0_S_AXI_BASEADDR 0xF8F00200
#define XPAR_PS7_GLOBALTIMER_0_S_AXI_HIGHADDR 0xF8F002FF


/* Definitions for peripheral PS7_GPV_0 */
#define XPAR_PS7_GPV_0_S_AXI_BASEADDR 0xF8900000
#define XPAR_PS7_GPV_0_S_AXI_HIGHADDR 0xF89FFFFF


/* Definitions for peripheral PS7_INTC_DIST_0 */
#define XPAR_PS7_INTC_DIST_0_S_AXI_BASEADDR 0xF8F01000
#define XPAR_PS7_INTC_DIST_0_S_AXI_HIGHADDR 0xF8F01FFF


/* Definitions for peripheral PS7_IOP_BUS_CONFIG_0 */
#define XPAR_PS7_IOP_BUS_CONFIG_0_S_AXI_BASEADDR 0xE0200000
#define XPAR_PS7_IOP_BUS_CONFIG_0_S_AXI_HIGHADDR 0xE0200FFF


/* Definitions for peripheral PS7_OCMC_0 */
#define XPAR_PS7_OCMC_0_S_AXI_BASEADDR 0xF800C000
#define XPAR_PS7_OCMC_0_S_AXI_HIGHADDR 0xF800CFFF


/* Definitions for peripheral PS7_PL310_0 */
#define XPAR_PS7_PL310_0_S_AXI_BASEADDR 0xF8F02000
#define XPAR_PS7_PL310_0_S_AXI_HIGHADDR 0xF8F02FFF


/* Definitions for peripheral PS7_PMU_0 */
#define XPAR_PS7_PMU_0_S_AXI_BASEADDR 0xF8891000
#define XPAR_PS7_PMU_0_S_AXI_HIGHADDR 0xF8891FFF
#define XPAR_PS7_PMU_0_PMU1_S_AXI_BASEADDR 0xF8893000
#define XPAR_PS7_PMU_0_PMU1_S_AXI_HIGHADDR 0xF8893FFF


/* Definitions for peripheral PS7_QSPI_LINEAR_0 */
#define XPAR_PS7_QSPI_LINEAR_0_S_AXI_BASEADDR 0xFC000000
#define XPAR_PS7_QSPI_LINEAR_0_S_AXI_HIGHADDR 0xFCFFFFFF


/* Definitions for peripheral PS7_RAM_0 */
#define XPAR_PS7_RAM_0_S_AXI_BASEADDR 0x00000000
#define XPAR_PS7_RAM_0_S_AXI_HIGHADDR 0x0003FFFF


/* Definitions for peripheral PS7_RAM_1 */
#define XPAR_PS7_RAM_1_S_AXI_BASEADDR 0xFFFC0000
#define XPAR_PS7_RAM_1_S_AXI_HIGHADDR 0xFFFFFFFF


/* Definitions for peripheral PS7_SLCR_0 */
#define XPAR_PS7_SLCR_0_S_AXI_BASEADDR 0xF8000000
#define XPAR_PS7_SLCR_0_S_AXI_HIGHADDR 0xF8000FFF


/******************************************************************/

/* Definitions for driver GPIO */
#define XPAR_XGPIO_NUM_INSTANCES 1

/* Definitions for peripheral AXI_GPIO_0 */
#define XPAR_AXI_GPIO_0_BASEADDR 0x41200000
#define XPAR_AXI_GPIO_0_HIGHADDR 0x4120FFFF
#define XPAR_AXI_GPIO_0_DEVICE_ID 0
#define XPAR_AXI_GPIO_0_INTERRUPT_PRESENT 1
#define XPAR_AXI_GPIO_0_IS_DUAL 1


/******************************************************************/

/* Canonical definitions for peripheral AXI_GPIO_0 */
#define XPAR_GPIO_0_BASEADDR 0x41200000
#define XPAR_GPIO_0_HIGHADDR 0x4120FFFF
#define XPAR_GPIO_0_DEVICE_ID XPAR_AXI_GPIO_0_DEVICE_ID
#define XPAR_GPIO_0_INTERRUPT_PRESENT 1
#define XPAR_GPIO_0_IS_DUAL 1


/******************************************************************/

/* Definitions for driver GPIOPS */
#define XPAR_XGPIOPS_NUM_INSTANCES 1

/* Definitions for peripheral PS7_GPIO_0 */
#define XPAR_PS7_GPIO_0_DEVICE_ID 0
#define XPAR_PS7_GPIO_0_BASEADDR 0xE000A000
#define XPAR_PS7_GPIO_0_HIGHADDR 0xE000AFFF


/******************************************************************/

/* Canonical definitions for peripheral PS7_GPIO_0 */
#define XPAR_XGPIOPS_0_DEVICE_ID XPAR_PS7_GPIO_0_DEVICE_ID
#define XPAR_XGPIOPS_0_BASEADDR 0xE000A000
#define XPAR_XGPIOPS_0_HIGHADDR 0xE000AFFF


/******************************************************************/

#define XPAR_INTC_MAX_NUM_INTR_INPUTS 2
#define XPAR_XINTC_HAS_IPR 1
#define XPAR_XINTC_HAS_SIE 1
#define XPAR_XINTC_HAS_CIE 1
#define XPAR_XINTC_HAS_IVR 1
/* Definitions for driver INTC */
#define XPAR_XINTC_NUM_INSTANCES 1

/* Definitions for peripheral AXI_INTC_0 */
#define XPAR_AXI_INTC_0_DEVICE_ID 0
#define XPAR_AXI_INTC_0_BASEADDR 0x41800000
#define XPAR_AXI_INTC_0_HIGHADDR 0x4180FFFF
#define XPAR_AXI_INTC_0_KIND_OF_INTR 0xFFFFFFFC
#define XPAR_AXI_INTC_0_HAS_FAST 0
#define XPAR_AXI_INTC_0_IVAR_RESET_VALUE 0x0000000000000010
#define XPAR_AXI_INTC_0_NUM_INTR_INPUTS 2
#define XPAR_AXI_INTC_0_ADDR_WIDTH 32


/******************************************************************/

#define XPAR_INTC_SINGLE_BASEADDR 0x41800000
#define XPAR_INTC_SINGLE_HIGHADDR 0x4180FFFF
#define XPAR_INTC_SINGLE_DEVICE_ID XPAR_AXI_INTC_0_DEVICE_ID
#define XPAR_AXI_INTC_0_TYPE 0U
#define XPAR_FIT_TIMER_0_INTERRUPT_MASK 0X000001U
#define XPAR_AXI_INTC_0_FIT_TIMER_0_INTERRUPT_INTR 0U
#define XPAR_AXI_GPIO_0_IP2INTC_IRPT_MASK 0X000002U
#define XPAR_AXI_INTC_0_AXI_GPIO_0_IP2INTC_IRPT_INTR 1U

/******************************************************************/

/* Canonical definitions for peripheral AXI_INTC_0 */
#define XPAR_INTC_0_DEVICE_ID XPAR_AXI_INTC_0_DEVICE_ID
#define XPAR_INTC_0_BASEADDR 0x41800000U
#define XPAR_INTC_0_HIGHADDR 0x4180FFFFU
#define XPAR_INTC_0_KIND_OF_INTR 0xFFFFFFFCU
#define XPAR_INTC_0_HAS_FAST 0U
#define XPAR_INTC_0_IVAR_RESET_VALUE 0x0000000000000010U
#define XPAR_INTC_0_NUM_INTR_INPUTS 2U
#define XPAR_INTC_0_ADDR_WIDTH 32U
#define XPAR_INTC_0_INTC_TYPE 0U

#define XPAR_INTC_0_GPIO_0_VEC_ID XPAR_AXI_INTC_0_AXI_GPIO_0_IP2INTC_IRPT_INTR

/******************************************************************/

/* Definitions for driver QSPIPS */
#define XPAR_XQSPIPS_NUM_INSTANCES 1

/* Definitions for peripheral PS7_QSPI_0 */
#define XPAR_PS7_QSPI_0_DEVICE_ID 0
#define XPAR_PS7_QSPI_0_BASEADDR 0xE000D000
#define XPAR_PS7_QSPI_0_HIGHADDR 0xE000DFFF
#define XPAR_PS7_QSPI_0_QSPI_CLK_FREQ_HZ 200000000
#define XPAR_PS7_QSPI_0_QSPI_MODE 0
#define XPAR_PS7_QSPI_0_QSPI_BUS_WIDTH 2


/******************************************************************/

/* Canonical definitions for peripheral PS7_QSPI_0 */
#define XPAR_XQSPIPS_0_DEVICE_ID XPAR_PS7_QSPI_0_DEVICE_ID
#define XPAR_XQSPIPS_0_BASEADDR 0xE000D000
#define XPAR_XQSPIPS_0_HIGHADDR 0xE000DFFF
#define XPAR_XQSPIPS_0_QSPI_CLK_FREQ_HZ 200000000
#define XPAR_XQSPIPS_0_QSPI_MODE 0
#define XPAR_XQSPIPS_0_QSPI_BUS_WIDTH 2


/******************************************************************/

/* Definitions for driver SCUGIC */
#define XPAR_XSCUGIC_NUM_INSTANCES 1U

/* Definitions for peripheral PS7_SCUGIC_0 */
#define XPAR_PS7_SCUGIC_0_DEVICE_ID 0U
#define XPAR_PS7_SCUGIC_0_BASEADDR 0xF8F00100U
#define XPAR_PS7_SCUGIC_0_HIGHADDR 0xF8F001FFU
#define XPAR_PS7_SCUGIC_0_DIST_BASEADDR 0xF8F01000U


/******************************************************************/

/* Canonical definitions for peripheral PS7_SCUGIC_0 */
#define XPAR_SCUGIC_0_DEVICE_ID 0U
#define XPAR_SCUGIC_0_CPU_BASEADDR 0xF8F00100U
#define XPAR_SCUGIC_0_CPU_HIGHADDR 0xF8F001FFU
#define XPAR_SCUGIC_0_DIST_BASEADDR 0xF8F01000U


/******************************************************************/

/* Definitions for driver SCUWDT */
#define XPAR_XSCUWDT_NUM_INSTANCES 1

/* Definitions for peripheral PS7_SCUWDT_0 */
#define XPAR_PS7_SCUWDT_0_DEVICE_ID 0
#define XPAR_PS7_SCUWDT_0_BASEADDR 0xF8F00620
#define XPAR_PS7_SCUWDT_0_HIGHADDR 0xF8F006FF


/******************************************************************/

/* Canonical definitions for peripheral PS7_SCUWDT_0 */
#define XPAR_SCUWDT_0_DEVICE_ID XPAR_PS7_SCUWDT_0_DEVICE_ID
#define XPAR_SCUWDT_0_BASEADDR 0xF8F00620
#define XPAR_SCUWDT_0_HIGHADDR 0xF8F006FF


/******************************************************************/

/* Definitions for driver UCOS_EMACPS */
#define XPAR_UCOS_EMACPS_NUM_INSTANCES 1

/* Definitions for peripheral PS7_ETHERNET_0 */
#define XPAR_PS7_ETHERNET_0_DEVICE_ID 0
#define XPAR_PS7_ETHERNET_0_BASEADDR 0x00000000
#define XPAR_PS7_ETHERNET_0_HIGHADDR 0x00000000
#define XPAR_PS7_ETHERNET_0_CLOCK_FREQ_HZ 0


/******************************************************************/

/* Canonical definitions for peripheral PS7_ETHERNET_0 */
#define XPAR_UCOS_EMACPS_0_NUM_INSTANCES 0
#define XPAR_UCOS_EMACPS_0_DEVICE_ID XPAR_PS7_ETHERNET_0_DEVICE_ID
#define XPAR_UCOS_EMACPS_0_BASEADDR 0x00000000
#define XPAR_UCOS_EMACPS_0_HIGHADDR 0x00000000
#define XPAR_UCOS_EMACPS_0_CLOCK_FREQ_HZ 0


/******************************************************************/

/* Definitions for driver UCOS_L2CACHEC */
#define XPAR_UCOS_L2CACHEC_NUM_INSTANCES 1

/* Definitions for peripheral PS7_L2CACHEC_0 */
#define XPAR_PS7_L2CACHEC_0_DEVICE_ID 0
#define XPAR_PS7_L2CACHEC_0_BASEADDR 0xF8F02000
#define XPAR_PS7_L2CACHEC_0_HIGHADDR 0xF8F02FFF


/******************************************************************/

/* Definitions for driver UCOS_SCUC */
#define XPAR_UCOS_L2CACHEC_NUM_INSTANCES 1

/* Definitions for peripheral PS7_SCUC_0 */
#define XPAR_PS7_SCUC_0_DEVICE_ID 0
#define XPAR_PS7_SCUC_0_BASEADDR 0xF8F00000
#define XPAR_PS7_SCUC_0_HIGHADDR 0xF8F000FC


/******************************************************************/

/* Definitions for driver UCOS_SCUTIMER */
#define XPAR_UCOS_SCUC_NUM_INSTANCES 1

/* Definitions for peripheral PS7_SCUTIMER_0 */
#define XPAR_PS7_SCUTIMER_0_DEVICE_ID 0
#define XPAR_PS7_SCUTIMER_0_BASEADDR 0xF8F00600
#define XPAR_PS7_SCUTIMER_0_HIGHADDR 0xF8F0061F


/******************************************************************/

/* Definitions for driver UCOS_SDPS */
#define XPAR_UCOS_SDPS_NUM_INSTANCES 1

/* Definitions for peripheral PS7_SD_0 */
#define XPAR_PS7_SD_0_DEVICE_ID 0
#define XPAR_PS7_SD_0_BASEADDR 0xE0100000
#define XPAR_PS7_SD_0_HIGHADDR 0xE0100FFF
#define XPAR_PS7_SD_0_SDIO_CLK_FREQ_HZ 50000000


/******************************************************************/

/* Canonical definitions for peripheral PS7_SD_0 */
#define XPAR_UCOS_SDPS_0_NUM_INSTANCES 0
#define XPAR_UCOS_SDPS_0_DEVICE_ID XPAR_PS7_SD_0_DEVICE_ID
#define XPAR_UCOS_SDPS_0_BASEADDR 0xE0100000
#define XPAR_UCOS_SDPS_0_HIGHADDR 0xE0100FFF
#define XPAR_UCOS_SDPS_0_SDIO_CLK_FREQ_HZ 50000000


/******************************************************************/

/* Definitions for driver UCOS_TTCPS */
#define XPAR_UCOS_TTCPS_NUM_INSTANCES 3

/* Definitions for peripheral PS7_TTC_0 */
#define XPAR_PS7_TTC_0_DEVICE_ID 0
#define XPAR_PS7_TTC_0_BASEADDR 0XF8001000
#define XPAR_PS7_TTC_0_TTC_CLK_FREQ_HZ 111111115
#define XPAR_PS7_TTC_0_TTC_CLK_CLKSRC 0
#define XPAR_PS7_TTC_1_DEVICE_ID 1
#define XPAR_PS7_TTC_1_BASEADDR 0XF8001004
#define XPAR_PS7_TTC_1_TTC_CLK_FREQ_HZ 111111115
#define XPAR_PS7_TTC_1_TTC_CLK_CLKSRC 0
#define XPAR_PS7_TTC_2_DEVICE_ID 2
#define XPAR_PS7_TTC_2_BASEADDR 0XF8001008
#define XPAR_PS7_TTC_2_TTC_CLK_FREQ_HZ 111111115
#define XPAR_PS7_TTC_2_TTC_CLK_CLKSRC 0


/******************************************************************/

/* Definitions for driver UCOS_UARTPS */
#define XPAR_UCOS_UARTPS_NUM_INSTANCES 1

/* Definitions for peripheral PS7_UART_1 */
#define XPAR_PS7_UART_1_DEVICE_ID 0
#define XPAR_PS7_UART_1_BASEADDR 0xE0001000
#define XPAR_PS7_UART_1_HIGHADDR 0xE0001FFF
#define XPAR_PS7_UART_1_UART_CLK_FREQ_HZ 50000000
#define XPAR_PS7_UART_1_HAS_MODEM 0


/******************************************************************/

/* Canonical definitions for peripheral PS7_UART_1 */
#define XPAR_UCOS_UARTPS_0_DEVICE_ID XPAR_PS7_UART_1_DEVICE_ID
#define XPAR_UCOS_UARTPS_0_BASEADDR 0xE0001000
#define XPAR_UCOS_UARTPS_0_HIGHADDR 0xE0001FFF
#define XPAR_UCOS_UARTPS_0_UART_CLK_FREQ_HZ 50000000
#define XPAR_UCOS_UARTPS_0_HAS_MODEM 0


/******************************************************************/

/* Definitions for driver UCOS_USBPS */
#define XPAR_UCOS_USBPS_NUM_INSTANCES 1

/* Definitions for peripheral PS7_USB_0 */
#define XPAR_PS7_USB_0_DEVICE_ID 0
#define XPAR_PS7_USB_0_BASEADDR 0xE0002000
#define XPAR_PS7_USB_0_HIGHADDR 0xE0002FFF


/******************************************************************/

/* Canonical definitions for peripheral PS7_USB_0 */
#define XPAR_UCOS_USBPS_0_DEVICE_ID XPAR_PS7_USB_0_DEVICE_ID
#define XPAR_UCOS_USBPS_0_BASEADDR 0xE0002000
#define XPAR_UCOS_USBPS_0_HIGHADDR 0xE0002FFF


/******************************************************************/

/* Definitions for driver XADCPS */
#define XPAR_XADCPS_NUM_INSTANCES 1

/* Definitions for peripheral PS7_XADC_0 */
#define XPAR_PS7_XADC_0_DEVICE_ID 0
#define XPAR_PS7_XADC_0_BASEADDR 0xF8007100
#define XPAR_PS7_XADC_0_HIGHADDR 0xF8007120


/******************************************************************/

/* Canonical definitions for peripheral PS7_XADC_0 */
#define XPAR_XADCPS_0_DEVICE_ID XPAR_PS7_XADC_0_DEVICE_ID
#define XPAR_XADCPS_0_BASEADDR 0xF8007100
#define XPAR_XADCPS_0_HIGHADDR 0xF8007120


/******************************************************************/

#endif  /* end of protection macro */
#define XPAR_PS7_ETHERNET_0_INT_SOURCE 54

#define UCOS_USB_DRIVER UCOS_USB_NONE
#define UCOS_USB_DEVICE_ID 0
#define UCOS_USB_TYPE UCOS_USB_TYPE_DEVICE
#define XPAR_PS7_USB_0_INT_SOURCE 53

#define UCOS_START_TASK_PRIO 5
#define UCOS_START_TASK_STACK_SIZE 784
#define UCOS_START_DEBUG_TRACE DEF_ENABLED
#define UCOS_AMP_MASTER DEF_ENABLED
#define UCOS_CFG_INIT_CAN DEF_ENABLED
#define UCOS_CFG_INIT_NET DEF_ENABLED
#define UCOS_CFG_INIT_FS DEF_ENABLED
#define UCOS_CFG_INIT_OPENAMP DEF_ENABLED
#define UCOS_CFG_INIT_USBD DEF_ENABLED
#define UCOS_CFG_INIT_USBH DEF_ENABLED
#define UCOS_ETHERNET_ADDRESS "10.10.110.2"
#define UCOS_ETHERNET_GATEWAY "10.10.110.1"
#define UCOS_ETHERNET_SUBMASK "255.255.255.0"
#define UCOS_ETHERNET_DHCP DEF_ENABLED
#define UCOS_IF_RX_BUF_NBR 12
#define UCOS_IF_TX_LARGE_BUF_NBR 8
#define UCOS_IF_TX_SMALL_BUF_NBR 8
#define UCOS_IF_RX_DESC_NBR 0
#define UCOS_IF_TX_DESC_NBR 0
#define UCOS_IF_DEDIC_MEM_ADDR 0
#define UCOS_IF_DEDIC_MEM_SIZE 0
#define UCOS_IF_HW_ADDR "02:00:00:00:00:00"
#define UCOS_PHY_BUS_ADDR 255
#define UCOS_PHY_BUS_MODE UCOS_NET_PHY_BUS_MODE_MII
#define UCOS_PHY_TYPE UCOS_NET_PHY_TYPE_INT
#define UCOS_PHY_SPEED UCOS_NET_PHY_SPD_AUTO
#define UCOS_PHY_DUPLEX UCOS_NET_PHY_DUPLEX_AUTO
#define XPAR_PS7_SD_0_INT_SOURCE 56

#define UCOS_CPU_TYPE UCOS_CPU_TYPE_PS7
#define XPAR_PS7_UART_1_INT_SOURCE 82

#define UCOS_SDCARD_EN DEF_DISABLED
#define UCOS_RAMDISK_EN DEF_DISABLED
#define UCOS_RAMDISK_SIZE 128
#define UCOS_RAMDISK_SECTOR_SIZE 512
#define UCOS_RAMDISK_BASE_ADDRESS 0
#define UCOS_ZYNQ_CONFIG_MMU DEF_ENABLED
#define UCOS_ZYNQ_ENABLE_MMU DEF_ENABLED
#define UCOS_ZYNQ_CONFIG_CACHES DEF_ENABLED
#define UCOS_ZYNQ_ENABLE_CACHES DEF_ENABLED
#define UCOS_ZYNQ_ENABLE_OPTIMS DEF_DISABLED
#define ZYNQ_ENABLE_EARLY_L1_I_EN DEF_DISABLED
#define ZYNQ_ENABLE_EARLY_L1_D_EN DEF_DISABLED
#define UCOS_STDOUT_DRIVER UCOS_UART_PS7_UART
#define UCOS_STDOUT_DEVICE_ID 0
