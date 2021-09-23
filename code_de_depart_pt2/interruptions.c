/*
 *********************************************************************************************************
 *											  Interrupts
 *											  3 Interrupts
 *											  * Pushbutton
 *											  * 3s Timer
 * 											  * 10s Timer
 *								
 *********************************************************************************************************
 */
#include "interrupts.h"

#include "routeur.h"

void initialize_gpio()
{
	if (XST_DEVICE_NOT_FOUND == XGpio_Initialize(&gpSwitch, GPIO_SW_DEVICE_ID))
		UCOS_Print("Erreur init gpio\n");
	XGpio_SetDataDirection(&gpSwitch, GPIO_LEDS_CHANNEL, 0x00);      // On indique que le LED est output
	XGpio_SetDataDirection(&gpSwitch, GPIO_BUTTONS_CHANNEL, 0x01); // On indique que le BUTTONS  est intput
	XGpio_InterruptGlobalEnable(&gpSwitch);
	XGpio_InterruptEnable(&gpSwitch, XGPIO_IR_MASK);
}

int initialize_axi_intc() {
	int status;

	status = XIntc_Initialize(&axi_intc, XPAR_AXI_INTC_0_DEVICE_ID);
	if (status != XST_SUCCESS)
		return XST_FAILURE;

	return XST_SUCCESS;
}

int connect_fit_timer_20s_irq() {
	int status;

	status = XIntc_Connect(&axi_intc, FIT_20S_IRQ_ID, fit_timer_20s_isr, NULL);
		if (status != XST_SUCCESS)
			return status;

	XIntc_Enable(&axi_intc, FIT_20S_IRQ_ID);

	return XST_SUCCESS;
}

int connect_gpio_irq()
{
	int status = XIntc_Connect(&axi_intc, GPIO_SW_IRQ_ID, gpio_isr, &gpSwitch);
	if (status == XST_SUCCESS)
		XIntc_Enable(&axi_intc, GPIO_SW_IRQ_ID);
	return status;
}

void connect_axi() {

	// La connexion est sur IRQ ID#31
	CPU_BOOLEAN succes = UCOS_IntVectSet (PL_INTC_IRQ_ID,
			                             1,
			                             0,
										 (UCOS_INT_FNCT_PTR)XIntc_DeviceInterruptHandler,
										 (void*)(uint32_t)axi_intc.CfgPtr->DeviceId);
	if (succes != DEF_OK)
		UCOS_Print ("connect axi : FAIL \n");
	succes = UCOS_IntSrcEn(PL_INTC_IRQ_ID);
	if (succes != DEF_OK)
		UCOS_Print ("enable axi : FAIL \n");

	connect_gpio_irq();
	connect_fit_timer_20s_irq();
	XIntc_Start(&axi_intc, XIN_REAL_MODE);


}

void cleanup() {
	/*
	 * Disconnect and disable the interrupt
	 */

	disconnect_intc_irq();
	disconnect_fit_timer_20s_irq();
}

void disconnect_intc_irq() {
	UCOS_IntSrcDis(PL_INTC_IRQ_ID);
}

void disconnect_fit_timer_20s_irq() {
	/*
	 * Disconnect and disable the interrupt
	 */
	XIntc_Disable(&axi_intc, FIT_20S_IRQ_ID);
	XIntc_Disconnect(&axi_intc, FIT_20S_IRQ_ID);

}


