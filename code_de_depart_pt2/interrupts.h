
/* ************************************************
 *                INTERRUPTIONS
 **************************************************/

#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include "routeur.h"


#define GIC_DEVICE_ID	        XPAR_PS7_SCUGIC_0_DEVICE_ID
#define PL_INTC_IRQ_ID          XPS_IRQ_INT_ID
#define FIT_20S_IRQ_ID          XPAR_AXI_INTC_0_FIT_TIMER_0_INTERRUPT_INTR
#define GPIO_SW_IRQ_ID			XPAR_AXI_INTC_0_AXI_GPIO_0_IP2INTC_IRPT_INTR
#define GPIO_SW_DEVICE_ID		XPAR_AXI_GPIO_0_DEVICE_ID

#define XGPIO_IR_MASK		0x3 /**< Mask of all bits */

#define GPIO_BUTTONS_CHANNEL 1
#define GPIO_LEDS_CHANNEL 2

#define COLOR_DOUBLE_BLUE 		0b100100
#define COLOR_DOUBLE_RED 		0b001001
#define COLOR_DOUBLE_GREEN 		0b010010
#define COLOR_DOUBLE_PURPLE		0b101101
#define COLOR_DOUBLE_YELLOW		0b011011

XIntc axi_intc;
XGpio gpSwitch;


/* ************************************************
 *              INTERRUPTION PROTOTYPES
 **************************************************/

void fit_timer_20s_isr(void *p_int_arg, CPU_INT32U source_cpu);
void gpio_isr(void *p_int_arg, CPU_INT32U source_cpu);
void initialize_gpio();
int initialize_axi_intc();
int connect_fit_timer_20s_irq();
int connect_gpio_irq();
void connect_axi();
void cleanup();
void disconnect_intc_irq();
void disconnect_fit_timer_20s_irq();

#define TurnOnLED(color) XGpio_DiscreteWrite(&gpSwitch, GPIO_LEDS_CHANNEL, color)

#endif /* INTERRUPTS_H */
