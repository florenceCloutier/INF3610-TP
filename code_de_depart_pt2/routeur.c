/*
*********************************************************************************************************
*                                                 uC/OS-III
*                                          The Real-Time Kernel
*                                               PORT Windows
*
*
*            		          					Guy BOIS
*                                  Polytechnique Montreal, Qc, CANADA
*                                                  08/09/2021
*
*
*********************************************************************************************************
*/


#include "interrupts.h"
#include "routeur.h"

#include  <cpu.h>
#include  <lib_mem.h>

#include <os.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>

#include <app_cfg.h>
#include <cpu.h>
#include <ucos_bsp.h>
#include <ucos_int.h>
#include <xparameters.h>
#include <KAL/kal.h>

#include <xil_printf.h>

#include  <stdio.h>
#include  <ucos_bsp.h>

#include <Source/os.h>
#include <os_cfg_app.h>

#include <xgpio.h>
#include <xintc.h>
#include <xil_exception.h>

// ? utiliser pour suivre le remplissage et le vidage des fifos
// Mettre en commentaire et utiliser la fonction vide suivante si vous ne voulez pas de trace
//	#define safeprintf(fmt, ...)															\
//{																						\
//	OSMutexPend(&mutPrint, 0, OS_OPT_PEND_BLOCKING, &ts, &perr);						\
//	xil_printf(fmt, ##__VA_ARGS__);														\
//	OSMutexPost(&mutPrint, OS_OPT_POST_NONE, &perr);									\
//}

// ? utiliser pour ne pas avoir les traces de remplissage et de vidage des fifos

/*DECLARATION DES COMPTEURS POUR STATISTIQUES*/
int nbPacketCrees = 0;								// Nb de packets total créés
int nbPacketTraites = 0;							// Nb de paquets envoyés sur une interface
int nbPacketSourceRejete = 0;						// Nb de packets rejetés pour mauvaise source
int nbPacketSourceRejeteTotal = 0;
int packet_rejete_fifo_pleine_inputQ = 0;			// Utilisation de la fifo d'entrée
int packet_rejete_output_port_plein = 0;			// Utilisation des MB
int packet_rejete_fifo_pleine_Q = 0;
int delai_pour_vider_les_fifos_sec = 1;
int delai_pour_vider_les_fifos_msec = 0;
int routerIsOn = 0;
#define safeprintf(fmt, ...)															\
{																						\
}


/*
*********************************************************************************************************
*                                                  MAIN
*********************************************************************************************************
*/

int main (void)
{

 	OS_ERR  err;

    UCOS_LowLevelInit();

    CPU_Init();
    Mem_Init();
    OSInit(&err);

    create_application();

    OSStart(&err);
    return 0;                                         // Start multitasking
}

void create_application() {
	int error;

	error = create_events();
	if (error != 0)
		xil_printf("Error %d while creating events\n", error);

	error = create_tasks();
	if (error != 0)
		xil_printf("Error %d while creating tasks\n", error);

}

int create_tasks() {

	int i;
	OS_ERR err;

    OSTaskCreate(&StartupTaskTCB,"StartUp Task", StartupTask, (void *) 0, UCOS_START_TASK_PRIO,
                 &StartupTaskStk[0u], TASK_STK_SIZE / 2, TASK_STK_SIZE, 1, 0, (void*)0, (OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR), &err);

    return 0;
}

int create_events() {
	OS_ERR err;
	int i;

	// Creation des semaphores
	// Pas de s?maphore pour la partie 1

	// Creation des mutex
	OSMutexCreate(&mutRejete, "mutRejete", &err);
	OSMutexCreate(&mutPrint, "mutPrint", &err);
	OSMutexCreate(&mutAlloc, "mutAlloc", &err);

	// Creation des files externes  - vous pourrez diminuer au besoin la longueur des files
	OSQCreate(&lowQ, "lowQ", 1024, &err);
	OSQCreate(&mediumQ, "mediumQ", 1024, &err);
	OSQCreate(&highQ, "highQ", 1024, &err);

	return 0;
}

/*
*********************************************************************************************************
*                                               STARTUP TASK
*********************************************************************************************************
*/


///////////////////////////////////////////////////////////////////////////////////////
//									TASKS
///////////////////////////////////////////////////////////////////////////////////////

/*
 *********************************************************************************************************
 *											  TaskReset
 *  -TODO
 *********************************************************************************************************
 */
void TaskReset(void *data) {
	CPU_TS ts;
	OS_ERR err;
	int i;
	while (true) {
		// RDV unilat?ral via la s?maphore SemReset
		// ? completer
		// xil_printf("------------------- Task Reset --------------------\n");
		routerIsOn = 1; // Le syst?me (re)d?marre

		// Allumez les LEDS (0x03, 0x04, etc.) pour montrer qu?on est en mode
		// fonctionnement
		// ? compl?ter
		// R?d?marrerztoutes les t?ches (suspendues pr?c?demment dans TaskStartUp ou TaskStop)
		// ? compl?ter
	}
}

/*
 *********************************************************************************************************
 *											  TaskStop
 *  -TODO
 *********************************************************************************************************
 */
void TaskStop(void *data) {
	CPU_TS ts;
	OS_ERR err;
	while (true) {
		// RDV unilateral avec la s?maphore SemStop
		// ? compl?ter
		if (!routerIsOn) {
			continue ;
		}
		// xil_printf("--------------- Task stop check ---------------\n");
		// Test sur nbPacketSourceRejete
		// ? compl?ter
		routerIsOn = 0;
		// Afficher les statistiques et ?teindre les LEDS (0x03, 0x04, etc.)
		// pour montrer qu?on s?arr?te
		// ? compl?ter
		// Suspendre tous les taches
		safeprintf("------------ Task stop suspend all tasks ----------\n");
		// ? compl?ter
	}
}

void fit_timer_20s_isr(void *p_int_arg, CPU_INT32U source_cpu){
	OS_ERR perr;
	safeprintf("------------------ FIT TIMER 0 -------------------\n");
	// Traitement sur SemStop
	// ? compl?ter
}

void gpio_isr(void *p_int_arg, CPU_INT32U source_cpu){
	CPU_TS ts;
	OS_ERR err;
	u32 button_data;

	button_data = XGpio_DiscreteRead(&gpSwitch, 1); //get button data
	XGpio_DiscreteWrite(&gpSwitch, 2, button_data); //write switch data to the corresponding LEDs
	// On regarde quel bouton a ?t? activ? et on l?affiche
	// Selon le, cas on red?marre les t?ches du syst?me ou on red?marre
	// StartupTaskTCB qui doit s?occuper d?arr?ter le syst?me
	// ? compl?ter
	// On met ? 0 les interruptions du GPIO avec l?aide du masque
	// XGPIO_IR_MASK
	// ? compl?ter
}

/*
 *********************************************************************************************************
 *											  TaskGeneratePacket
 *  - G?n?re des paquets et les envoie dans la InputQ.
 *  - Differentes options pour debugger:
 *  1) Enlever les commentaire des xil_printf dans TaskGenerate, TaskComputing et TaskOutputPort
 *  2) Activer les safeprint (lignes 46 ? 53) et mettre en commentaire ? les lignes 56 ? 58.
 *  3) Vous pouvez aussi *temporairement* modifier la variable
 *    "shouldSlowthingsDown" ? true pour ne g?n?rer que quelques paquets par seconde, et ainsi pouvoir
 *    d?boguer le flot de vos paquets de mani?re plus saine d'esprit. Cependant, la correction sera effectu?e
 *    avec cette variable ? false.
 *
 *********************************************************************************************************
 */
void TaskGenerate(void *data) {
	srand(42);
	OS_ERR err, perr;
	CPU_TS ts;
	bool isGenPhase = false; 		//Indique si on est dans la phase de generation ou non
	const bool shouldSlowThingsDown = false;		//Variable ? modifier
	int packGenQty = (rand() % 255);
	while(true) {
		if (isGenPhase) {
			OSMutexPend(&mutAlloc, 0, OS_OPT_PEND_BLOCKING, &ts, &err);
				Packet *packet = malloc(sizeof(Packet));
			OSMutexPost(&mutAlloc, OS_OPT_POST_NONE, &err);

			packet->src = rand() * (UINT32_MAX/RAND_MAX);
			packet->dst = rand() * (UINT32_MAX/RAND_MAX);
			packet->type = rand() % NB_PACKET_TYPE;

			for (int i = 0; i < ARRAY_SIZE(packet->data); ++i)
				packet->data[i] = (unsigned int)rand();
			packet->data[0] = ++nbPacketCrees;

//			if (shouldSlowThingsDown) {
//			OSMutexPend(&mutPrint, 0, OS_OPT_PEND_BLOCKING, &ts, &err);
//				xil_printf("GENERATE : ********Generation du Paquet # %d ******** \n", nbPacketCrees);
//				xil_printf("ADD %x \n", packet);
//				xil_printf("	** id : %d \n", packet->data[0]);
//				xil_printf("	** src : %x \n", packet->src);
//				xil_printf("	** dst : %x \n", packet->dst);
//				xil_printf("	** type : %d \n", packet->type);
//			OSMutexPost(&mutPrint, OS_OPT_POST_NONE, &err);

			//}

			OSTaskQPost(&TaskComputingTCB, packet, sizeof(packet), OS_OPT_POST_FIFO + OS_OPT_POST_NO_SCHED, &err);

			safeprintf("Nb de paquets dans inputQ - apres production de TaskGenenerate: %d \n", TaskComputingTCB.MsgQ.NbrEntries);

			if (err == OS_ERR_Q_MAX || err == OS_ERR_MSG_POOL_EMPTY) {

				OSMutexPend(&mutAlloc, 0, OS_OPT_PEND_BLOCKING, &ts, &err);
				safeprintf("GENERATE: Paquet rejete a l'entree car la FIFO est pleine !\n");
					free(packet);
				OSMutexPost(&mutAlloc, OS_OPT_POST_NONE, &err);
				packet_rejete_fifo_pleine_inputQ++;
			}

			if (shouldSlowThingsDown) {
				OSTimeDlyHMSM(0,0,0, 200 + rand() % 600, OS_OPT_TIME_HMSM_STRICT, &err);
			} else {
				OSTimeDlyHMSM(0, 0, 0, 1, OS_OPT_TIME_HMSM_STRICT, &err);

				if ((nbPacketCrees % packGenQty) == 0) //On gen?re au maximum 255 paquets par phase de g?neration
				{
					isGenPhase = false;
				}
			}
		}
		else
		{
			OSTimeDlyHMSM(0, 0, delai_pour_vider_les_fifos_sec, delai_pour_vider_les_fifos_msec, OS_OPT_TIME_HMSM_STRICT, &err);
			isGenPhase = true;
			do { packGenQty = (rand() %255); } while (packGenQty == 0);

		safeprintf("GENERATE: Generation de %d paquets durant les %d prochaines millisecondes\n", packGenQty, packGenQty*2);
//			xil_printf("GENERATE: Generation de %d paquets durant les %d prochaines millisecondes\n", packGenQty, packGenQty*2);
		}
	}
}

/*
 *********************************************************************************************************
 *											  TaskComputing
 *  -V?rifie si les paquets sont conformes (CRC,Adresse Source)
 *  -Dispatche les paquets dans des files (HIGH,MEDIUM,LOW)
 *
 *********************************************************************************************************
 */
void TaskComputing(void *pdata) {
	OS_ERR err, perr;
	CPU_TS ts;
	OS_MSG_SIZE msg_size;
	Packet *packet = NULL;
	OS_TICK actualticks = 0;

	TaskStatsTCB.MsgQ.NbrEntriesMax = 1024;

	while(true){

		packet = OSTaskQPend(0, OS_OPT_PEND_BLOCKING, &msg_size, &ts, &err);

		safeprintf("Nb de paquets dans inputQ - apres consommation de TaskComputing: %d \n", TaskComputingTCB.MsgQ.NbrEntries);

		err_msg("COMPUTING OSQPEND",err);

		/* On simule un temps de traitement */
		actualticks = OSTimeGet(&err);
		while (WAITFORComputing + actualticks > OSTimeGet(&err));

		//Verification de l'espace d'addressage
		if ((packet->src > REJECT_LOW1 && packet->src < REJECT_HIGH1) ||
			(packet->src > REJECT_LOW2 && packet->src < REJECT_HIGH2) ||
			(packet->src > REJECT_LOW3 && packet->src < REJECT_HIGH3) ||
			(packet->src > REJECT_LOW4 && packet->src < REJECT_HIGH4)) {
				OSMutexPend(&mutRejete, 0, OS_OPT_PEND_BLOCKING, &ts, &err);

//				OSMutexPend(&mutPrint, 0, OS_OPT_PEND_BLOCKING, &ts, &err);
//				xil_printf("\n--TaskComputing: Source invalide (Paquet rejete) (total : %d)\n", nbPacketSourceRejete);
//				xil_printf("\n--Il s agit du paquet\n");
//				xil_printf("	** id : %d \n", packet->data[0]);
//				xil_printf("	** src : %x \n", packet->src);
//				xil_printf("	** dst : %x \n", packet->dst);
//				OSMutexPost(&mutPrint, OS_OPT_POST_NONE, &err);

				OSTaskQPost(&TaskStatsTCB, packet, sizeof(packet), OS_OPT_POST_FIFO, &err);
				++nbPacketSourceRejete;

				OSMutexPost(&mutRejete, OS_OPT_POST_NONE, &err);
		} else {

			//Dispatche les paquets selon leur type
			switch (packet->type) {
			case PACKET_VIDEO:
				OSQPost(&highQ, packet, sizeof(packet),OS_OPT_POST_FIFO, &err);
				safeprintf("Nb de paquets dans highQ - apres production de TaskComputing: %d \n", highQ.MsgQ.NbrEntries);
			break;

			case PACKET_AUDIO:
				OSQPost(&mediumQ, packet, sizeof(packet),OS_OPT_POST_FIFO, &err);
				safeprintf("Nb de paquets dans mediumQ - apres production de TaskComputing: %d \n", mediumQ.MsgQ.NbrEntries);
			break;

			case PACKET_AUTRE:
				OSQPost(&lowQ, packet, sizeof(packet),OS_OPT_POST_FIFO, &err);
				safeprintf("Nb de paquets dans lowQ - apres production de TaskComputing: %d \n", lowQ.MsgQ.NbrEntries);
			break;

			default:
				break;
			}
				if (err == OS_ERR_Q_MAX || err == OS_ERR_MSG_POOL_EMPTY) {
					OSMutexPend(&mutAlloc, 0, OS_OPT_PEND_BLOCKING, &ts, &err);
					safeprintf("TaskComputing: Paquet rejete car FIFO pleine\n");
					free(packet);
					OSMutexPost(&mutAlloc, OS_OPT_POST_NONE, &err);
					packet_rejete_fifo_pleine_Q++;
				}
		}
	}
}


/*
 *********************************************************************************************************
 *											  TaskForwarding
 *  -traite la priorit? des paquets : si un paquet de haute priorit? est pr?t,
 *   on l'envoie ? l'aide de la fonction dispatch_packet, sinon on regarde les paquets de moins haute priorit?
 *********************************************************************************************************
 */
void TaskForwarding(void *pdata) {
	OS_ERR err, perr;
	CPU_TS ts;
	OS_MSG_SIZE msg_size;
	Packet *packet = NULL;

	while(1){
		/* Si paquet vid?o pr?t */
		packet = OSQPend(&highQ, 0, OS_OPT_PEND_NON_BLOCKING, &msg_size, &ts, &err);
		safeprintf("Nb de paquets dans highQ - apres consommation de TaskFowarding: %d \n", highQ.MsgQ.NbrEntries);
		if(err == OS_ERR_NONE){
			/* Envoi du paquet */
			dispatch_packet(packet);
			safeprintf("\n--TaskForwarding:  paquets %d envoyes\n\n", ++nbPacketTraites);
		}else{
			/* Si paquet audio pr?t */
			packet = OSQPend(&mediumQ, 0, OS_OPT_PEND_NON_BLOCKING, &msg_size, &ts, &err);
			safeprintf("Nb de paquets dans mediumQ - apres consommation de TaskFowarding: %d \n", mediumQ.MsgQ.NbrEntries);
			if(err == OS_ERR_NONE){
				/* Envoi du paquet */
				dispatch_packet(packet);
				safeprintf("\n--TaskForwarding: paquets %d envoyes\n\n", ++nbPacketTraites);
			}else{
				/* Si paquet autre pr?t */
				packet = OSQPend(&lowQ, 0, OS_OPT_PEND_NON_BLOCKING, &msg_size, &ts, &err);
				safeprintf("Nb de paquets dans lowQ - apres consommation de TaskFowarding: %d \n", lowQ.MsgQ.NbrEntries);
				if(err == OS_ERR_NONE){
					/* Envoi du paquet */
					dispatch_packet(packet);
					safeprintf("\n--TaskForwarding: paquets %d envoyes\n\n", ++nbPacketTraites);
				}
			}
		}
	}
}

/*
 *********************************************************************************************************
 *											  Fonction Dispatch
 *  -Envoie le paquet pass? en param?tre vers la mailbox correspondante ? son adressage destination
 *********************************************************************************************************
 */
 void dispatch_packet (Packet* packet){
	OS_ERR err, perr;
	CPU_TS ts;
	OS_MSG_SIZE msg_size;

	/* Test sur la destination du paquet */
	if(packet->dst >= INT1_LOW && packet->dst <= INT1_HIGH ){

		safeprintf("\n--Paquet dans mb1\n");
		OSTaskQPost(&TaskOutputPortTCB[0], packet, sizeof(packet),OS_OPT_POST_FIFO, &err);
	}
	else {
			if (packet->dst >= INT2_LOW && packet->dst <= INT2_HIGH ){
			safeprintf("\n--Paquet dans mb2\n");
			OSTaskQPost(&TaskOutputPortTCB[1], packet, sizeof(packet),OS_OPT_POST_FIFO, &err);
			}
			else {
				if(packet->dst >= INT3_LOW && packet->dst <= INT3_HIGH ){
					safeprintf("\n--Paquet dans mb3\n");
					OSTaskQPost(&TaskOutputPortTCB[2], packet, sizeof(packet),OS_OPT_POST_FIFO, &err);
					}
					else {
						if(packet->dst >= INT_BC_LOW && packet->dst <= INT_BC_HIGH){
						Packet* others[2];
						int i;
						for (i = 0; i < ARRAY_SIZE(others); ++i) {
							OSMutexPend(&mutAlloc, 0, OS_OPT_PEND_BLOCKING, &ts, &err);
							others[i] = malloc(sizeof(Packet));
							OSMutexPost(&mutAlloc, OS_OPT_POST_NONE, &err);
							memcpy(others[i], packet, sizeof(Packet));
							}
						safeprintf("\n--Paquet BC dans mb1, mb2 et mb3\n");
						OSTaskQPost(&TaskOutputPortTCB[0], packet, sizeof(packet), OS_OPT_POST_FIFO, &err);
						OSTaskQPost(&TaskOutputPortTCB[1], others[0], sizeof(others[0]), OS_OPT_POST_FIFO, &err);
						OSTaskQPost(&TaskOutputPortTCB[2], others[1], sizeof(others[1]), OS_OPT_POST_FIFO, &err);
						}
					}
			}
	}
		if(err == OS_ERR_Q_MAX || err == OS_ERR_MSG_POOL_EMPTY) {
			/*Destruction du paquet si la mailbox de destination est pleine*/

			OSMutexPend(&mutAlloc, 0, OS_OPT_PEND_BLOCKING, &ts, &err);
				safeprintf("\n--TaskForwarding: Erreur mailbox full\n");
				free(packet);
				packet_rejete_output_port_plein++;
			OSMutexPost(&mutAlloc, OS_OPT_POST_NONE, &err);

		}
 }

/*
 *********************************************************************************************************
 *											  TaskPrint
 *  -Affiche les infos des paquets arriv?s ? destination et libere la m?moire allou?e
 *********************************************************************************************************
 */
void TaskOutputPort(void *data) {
	OS_ERR err, perr;
	CPU_TS ts;
	OS_MSG_SIZE msg_size;
	Packet* packet = NULL;
	Info_Port info = *(Info_Port*)data;

	while(1){
		/*Attente d'un paquet*/
		packet = OSTaskQPend (0, OS_OPT_PEND_BLOCKING, &msg_size, &ts, &err);
		err_msg("PRINT : MBoxPend",err);

//		OSMutexPend(&mutPrint, 0, OS_OPT_PEND_BLOCKING, &ts, &err);
		/*impression des infos du paquets*/
//		xil_printf("\nPaquet recu en %d \n", info.id);
//		xil_printf("	** id : %d \n", packet->data[0]);
//		xil_printf("    >> src : %x \n", packet->src);
//		xil_printf("    >> dst : %x \n", packet->dst);
//		xil_printf("    >> type : %d \n", packet->type);
//		OSMutexPost(&mutPrint, OS_OPT_POST_NONE, &err);

		/*Lib?ration de la m?moire*/
		OSMutexPend(&mutAlloc, 0, OS_OPT_PEND_BLOCKING, &ts, &err);
			free(packet);
		OSMutexPost(&mutAlloc, OS_OPT_POST_NONE, &err);
	}

}

/*
 *********************************************************************************************************
 *                                              TaskStats
 *  -Est d?clench?e lorsque le gpio_isr() lib?re le s?maphore
 *  -Lorsque d?clench?e, imprime les statistiques du routeur ? cet instant
 *********************************************************************************************************
 */
 void TaskStats(void* pdata) {
	OS_ERR err, perr;
	CPU_TS ts;
	OS_MSG_SIZE msg_size;
	Packet *packet = NULL;
	OS_TICK actualticks;

	while (1) {
		OSMutexPend(&mutPrint, 0, OS_OPT_PEND_BLOCKING, &ts, &err);

		xil_printf("\n------------------ Affichage des statistiques ------------------\n\n");
		xil_printf("Delai pour vider les fifos sec: %d\n", delai_pour_vider_les_fifos_sec);
		xil_printf("Delai pour vider les fifos msec: %d\n", delai_pour_vider_les_fifos_msec);
		xil_printf("Frequence du systeme: %d\n", OS_CFG_TICK_RATE_HZ);
		xil_printf("1 - Nb de packets total crees : %d\n", nbPacketCrees);
		xil_printf("2 - Nb de packets total traites : %d\n", nbPacketTraites);
		xil_printf("3 - Nb de packets rejetes pour mauvaise source : %d\n", nbPacketSourceRejete);
		xil_printf("4 - Nb de paquets rejetes dans fifo d'entree: %d\n", packet_rejete_fifo_pleine_inputQ);
		xil_printf("5 - Nb de paquets rejetes dans 3 Q: %d\n", packet_rejete_fifo_pleine_Q);
		xil_printf("6 - Nb de paquets rejetes dans l'interface de sortie: %d\n\n", packet_rejete_output_port_plein);
		xil_printf("7 - Nb de paquets maximum dans le fifo d'entree : %d \n", TaskComputingTCB.MsgQ.NbrEntriesMax);
		xil_printf("8 - Nb de paquets maximum dans highQ : %d \n", highQ.MsgQ.NbrEntriesMax);
		xil_printf("9 - Nb de paquets maximum dans mediumQ : %d \n", mediumQ.MsgQ.NbrEntriesMax);
		xil_printf("10 - Nb de paquets maximum dans lowQ : %d \n\n", lowQ.MsgQ.NbrEntriesMax);
		xil_printf("11- Message free : %d \n", OSMsgPool.NbrFree);
		xil_printf("12- Message used : %d \n", OSMsgPool.NbrUsed);
		xil_printf("13- Message used max : %d \n", OSMsgPool.NbrUsedMax);

		xil_printf("\n--TaskStats: Source invalide (Paquet rejete) (total : %d)\n", nbPacketSourceRejete);

		nbPacketSourceRejeteTotal += nbPacketSourceRejete;
		xil_printf("\n--TaskStats: Nombres de paquets rejetes totals : %d\n", nbPacketSourceRejeteTotal);

		while(TaskStatsTCB.MsgQ.NbrEntries > 0) {
			packet = OSTaskQPend(0, OS_OPT_PEND_BLOCKING, &msg_size, &ts, &err);
			xil_printf("\n--Il s agit du paquet\n");
			xil_printf("	** id : %d \n", packet->data[0]);
			xil_printf("	** src : %x \n", packet->src);
			xil_printf("	** dst : %x \n", packet->dst);
			OSMutexPend(&mutAlloc, 0, OS_OPT_PEND_BLOCKING, &ts, &err);
			free(packet);
			OSMutexPost(&mutAlloc, OS_OPT_POST_NONE, &err);
		}

		OSMutexPost(&mutPrint, OS_OPT_POST_NONE, &err);

		OSMutexPend(&mutRejete, 0, OS_OPT_PEND_BLOCKING, &ts, &err);
		nbPacketSourceRejete = 0;
		OSMutexPost(&mutRejete, OS_OPT_POST_NONE, &err);

		OSTimeDlyHMSM(0, 0, 30, 0, OS_OPT_TIME_HMSM_STRICT, &err);
	}
}


void err_msg(char* entete, uint8_t err)
{
	if(err != 0)
	{
		xil_printf(entete);
		xil_printf(": Une erreur est retourn?e : code %d \n",err);
	}
}


void StartupTask (void *p_arg)
{
	int i;
	OS_ERR err;
    KAL_ERR kal_err;
    CPU_INT32U tick_rate;
#if (UCOS_START_DEBUG_TRACE == DEF_ENABLED)
    MEM_SEG_INFO seg_info;
    LIB_ERR lib_err;
#endif
#if (APP_OSIII_ENABLED == DEF_ENABLED)
#if (OS_CFG_STAT_TASK_EN == DEF_ENABLED)
    OS_ERR  os_err;
#endif
#endif


    UCOS_IntInit();
    initialize_gpio();
    initialize_axi_intc();
    connect_axi();


#if (APP_OSIII_ENABLED == DEF_ENABLED)
    tick_rate = OS_CFG_TICK_RATE_HZ;
#endif

#if (APP_OSII_ENABLED == DEF_ENABLED)
    tick_rate = OS_TICKS_PER_SEC;
#endif

    UCOS_TmrTickInit(tick_rate);                                /* Configure and enable OS tick interrupt.              */

#if (APP_OSIII_ENABLED == DEF_ENABLED)
#if (OS_CFG_STAT_TASK_EN == DEF_ENABLED)
    OSStatTaskCPUUsageInit(&os_err);
#endif
#endif

    KAL_Init(DEF_NULL, &kal_err);
    UCOS_StdInOutInit();
    UCOS_PrintfInit();


#if (UCOS_START_DEBUG_TRACE == DEF_ENABLED)
    UCOS_Print("UCOS - uC/OS Init Started.\r\n");
    UCOS_Print("UCOS - STDIN/STDOUT Device Initialized.\r\n");
#endif

#if (APP_SHELL_ENABLED == DEF_ENABLED)
    UCOS_Shell_Init();
#endif

#if ((APP_FS_ENABLED == DEF_ENABLED) && (UCOS_CFG_INIT_FS == DEF_ENABLED))
    UCOS_FS_Init();
#endif

#if ((APP_TCPIP_ENABLED == DEF_ENABLED) && (UCOS_CFG_INIT_NET == DEF_ENABLED))
    UCOS_TCPIP_Init();
#endif /* (APP_TCPIP_ENABLED == DEF_ENABLED) */

#if ((APP_USBD_ENABLED == DEF_ENABLED) && (UCOS_CFG_INIT_USBD == DEF_ENABLED) && (UCOS_USB_TYPE == UCOS_USB_TYPE_DEVICE))
    UCOS_USBD_Init();
#endif /* #if (APP_USBD_ENABLED == DEF_ENABLED) */

#if ((APP_USBH_ENABLED == DEF_ENABLED) && (UCOS_CFG_INIT_USBH == DEF_ENABLED) && (UCOS_USB_TYPE == UCOS_USB_TYPE_HOST))
    UCOS_USBH_Init();
#endif /* #if (APP_USBH_ENABLED == DEF_ENABLED) */

#if (UCOS_START_DEBUG_TRACE == DEF_ENABLED)
    Mem_SegRemSizeGet(DEF_NULL, 4, &seg_info, &lib_err);

    UCOS_Printf ("UCOS - UCOS init done\r\n");
    UCOS_Printf ("UCOS - Total configured heap size. %d\r\n", seg_info.TotalSize);
    UCOS_Printf ("UCOS - Total used size after init. %d\r\n", seg_info.UsedSize);
#endif

    UCOS_Print("Programme initialise - \r\n");


	// On cr?e les t?ches

	for(i = 0; i < NB_OUTPUT_PORTS; i++)
	{
		Port[i].id = i;
		switch(i)
		{
			case 0:
				Port[i].name = "Port 0";
				break;
			case 1:
				Port[i].name = "Port 1";
				break;
			case 2:
				Port[i].name = "Port 2";
				break;
			default:
				break;
		};
	}

	OSTaskCreate(&TaskGenerateTCB, 		"TaskGenerate", 	TaskGenerate,	(void*)0, 	TaskGeneratePRIO, 	&TaskGenerateSTK[0u], 	TASK_STK_SIZE / 2, TASK_STK_SIZE, 1, 0, (void*) 0,(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR), &err );
	OSTaskSuspend(&TaskGenerateTCB, &err);

	OSTaskCreate(&TaskComputingTCB, 	"TaskComputing", 	TaskComputing, 	(void*)0, 	TaskComputingPRIO, 	&TaskComputingSTK[0u], 	TASK_STK_SIZE / 2, TASK_STK_SIZE, 1024, 0, (void*) 0,(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR), &err );
	OSTaskSuspend(&TaskComputingTCB, &err);

	OSTaskCreate(&TaskForwardingTCB,	"TaskForwarding", 	TaskForwarding,	(void*)0, 	TaskForwardingPRIO, &TaskForwardingSTK[0u], TASK_STK_SIZE / 2, TASK_STK_SIZE, 1, 0, (void*) 0,(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR), &err );
	OSTaskSuspend(&TaskForwardingTCB, &err);

	OSTaskCreate(&TaskResetTCB,	"TaskReset", 	TaskReset,	(void*)0, 	TaskResetPRIO, &TaskResetSTK[0u], TASK_STK_SIZE / 2, TASK_STK_SIZE, 1, 0, (void*) 0,(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR), &err );

	OSTaskCreate(&TaskStopTCB,	"TaskStop", 	TaskStop,	(void*)0, 	TaskStopPRIO, &TaskStopSTK[0u], TASK_STK_SIZE / 2, TASK_STK_SIZE, 1, 0, (void*) 0,(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR), &err );

// Pour ?viter d'avoir 3 fois le m?me code on a un tableau pour lequel chaque entr?e appel TaskOutputPort avec des param?tres diff?rents
	for(i = 0; i < NB_OUTPUT_PORTS; i++){
	OSTaskCreate(&TaskOutputPortTCB[i], "OutputPort", 	TaskOutputPort, &Port[i], TaskOutputPortPRIO, &TaskOutputPortSTK[i][0u], TASK_STK_SIZE / 2, TASK_STK_SIZE, 1, 0, (void*) 0,(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR), &err );
	OSTaskSuspend(&TaskOutputPortTCB[i], &err);
	};

	OSTaskCreate(&TaskStatsTCB, "TaskStats", TaskStats, (void*)0, TaskStatsPRIO, &TaskStatsSTK[0u], TASK_STK_SIZE / 2, TASK_STK_SIZE, 1024, 0, (void*)0, (OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR), &err);

	OSTaskSuspend((OS_TCB *)0,&err);

}

