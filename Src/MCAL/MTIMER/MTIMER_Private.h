/*
 * MTIMER_Private.h
 *
 *  Created on: Dec 19, 2023
 *      Author: Hardware
 */

#ifndef MCAL_MTIMER_MTIMER_PRIVATE_H_
#define MCAL_MTIMER_MTIMER_PRIVATE_H_

#include"../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#define	TIMER1_Base_Add		0x40010000
#define TIMER2_Base_Add		0x40000000
#define TIMER3_Base_Add		0x40000400
#define TIMER4_Base_Add		0x40000800
#define TIMER5_Base_Add		0x40000C00

#define TIMER9_Base_Add		0x40014000
#define TIMER10_Base_Add	0x40014400
#define TIMER11_Base_Add	0x40014800

/*CR REGISTER BITS*/
#define	CEN		0	//Control Enable
#define OPM		3	//One Pulse Mode "RUN ONE TIME ONLY"
#define DIR		4	//Direction Up or Down Count
#define CMS0	5	//Center_Aligned Mode Selector
#define CMS1	6
#define ARPE	7   //Auto Reload Preload Enable
/*DIER REGISTER BITS*/
#define	UIE		0 	//Update Interrupt Enable
#define	TIE		6 	//Trigger Interrupt Enable
#define	BIE		7	//Break Interrupt Enable
/*CCMRx REGISTER BITS 'OUTPUT'*/
#define CCxS0	0
#define CCxS1	1
#define OCxFE	2
#define OCxPE	3
#define OCxM0	4
#define OCxM1	5
#define OCxM2	6
#define	OCxCE	7
/*CCER REGISTER*/
#define CCxE	0
#define	CCxP	1
#define CCxNE	2
#define CCxNP	3

typedef struct{
	u32 CR1; //Control Reg 1
	u32 CR2; //Control Reg 2
	u32 SMCR;
	u32 DIER; //DMA/Interrupt Enable Reg
	u32 SR;  //Status Reg
	u32 EGR;
	u32 CCMR[2];
	u32 CCER;
	u32 CNT; //COUNTER
	u32 PSC; //PRESCALER
	u32 ARR; //AUTO-RELOAD
	u32 RCR;
	u32 CCR[4];
	u32 BDTR;
	u32 DCR; //DMA CONTROLLER
	u32 DMAR;
}TIM_MemMap_t;

#define TIM1		((volatile TIM_MemMap_t *) (TIMER1_Base_Add))
#define TIM2		((volatile TIM_MemMap_t *) (TIMER2_Base_Add))
#define TIM3		((volatile TIM_MemMap_t *) (TIMER3_Base_Add))
#define TIM4		((volatile TIM_MemMap_t *) (TIMER4_Base_Add))
#define TIM5		((volatile TIM_MemMap_t *) (TIMER5_Base_Add))

#define TIM9		((volatile TIM_MemMap_t *) (TIMER9_Base_Add))
#define TIM10		((volatile TIM_MemMap_t *) (TIMER10_Base_Add))
#define TIM11		((volatile TIM_MemMap_t *) (TIMER11_Base_Add))

#endif /* MCAL_MTIMER_MTIMER_PRIVATE_H_ */
