/*
 * HSERVO_Prog.c
 *
 *  Created on: Dec 21, 2023
 *      Author: Hardware
 */

#include"../../MCAL/MRCC/MRCC_Int.h"

#include"../../MCAL/MGPIO/MGPIO_Int.h"

#include"../../MCAL/MTIMER/MTIMER_Int.h"

#include"HSERVO_Config.h"
#include"HSERVO_Int.h"


void HSERVO_vServoInit(Enum_TIMER_NUM Copy_u8TimerNum,u8 Copy_u8ChannelNum){

	switch(Copy_u8TimerNum){
	case TIMER1:
		MGPIO_vSetPinMode(PORTA, Copy_u8ChannelNum + 7 , ALTFUNC);
		MGPIO_vSetAlternativeFunction(PORTA, Copy_u8ChannelNum + 7 , MGPIO_ALTFUNC_TIM12);
		break;
	case TIMER2:
		if(Copy_u8ChannelNum == 1){
			MGPIO_vSetPinMode(PORTA, Copy_u8ChannelNum + 14 , ALTFUNC);
			MGPIO_vSetAlternativeFunction(PORTA, Copy_u8ChannelNum + 14 , MGPIO_ALTFUNC_TIM12);}
		else if(Copy_u8ChannelNum == 2){
			MGPIO_vSetPinMode(PORTB, Copy_u8ChannelNum + 1 , ALTFUNC);
			MGPIO_vSetAlternativeFunction(PORTB, Copy_u8ChannelNum + 1 , MGPIO_ALTFUNC_TIM12);
		}
		else{
			MGPIO_vSetPinMode(PORTA, Copy_u8ChannelNum - 1 , ALTFUNC);
			MGPIO_vSetAlternativeFunction(PORTA, Copy_u8ChannelNum - 1 , MGPIO_ALTFUNC_TIM12);
		}
		break;
	case TIMER3:
		if(Copy_u8ChannelNum<CH3){
			MGPIO_vSetPinMode(PORTA, Copy_u8ChannelNum + 5 , ALTFUNC);
			MGPIO_vSetAlternativeFunction(PORTA, Copy_u8ChannelNum + 5 , MGPIO_ALTFUNC_TIM35);}
		else{
			MGPIO_vSetPinMode(PORTB, Copy_u8ChannelNum  - CH3 , ALTFUNC);
			MGPIO_vSetAlternativeFunction(PORTB, Copy_u8ChannelNum - CH3 , MGPIO_ALTFUNC_TIM35);
		}
		break;
	case TIMER4:
		MGPIO_vSetPinMode(PORTB, Copy_u8ChannelNum + 5 , ALTFUNC);
		MGPIO_vSetAlternativeFunction(PORTB, Copy_u8ChannelNum + 5 , MGPIO_ALTFUNC_TIM35);
		break;
	case TIMER5:
		MGPIO_vSetPinMode(PORTA, Copy_u8ChannelNum - 1  , ALTFUNC);
		MGPIO_vSetAlternativeFunction(PORTA, Copy_u8ChannelNum - 1 , MGPIO_ALTFUNC_TIM35);
		break;
	case TIMER9:
		MGPIO_vSetPinMode(PORTA, Copy_u8ChannelNum + 1 , ALTFUNC);
		MGPIO_vSetAlternativeFunction(PORTA, Copy_u8ChannelNum + 1 , MGPIO_ALTFUNC_TIM911);
		break;
	case TIMER10:
		MGPIO_vSetPinMode(PORTB, Copy_u8ChannelNum + 7 , ALTFUNC);
		MGPIO_vSetAlternativeFunction(PORTB, Copy_u8ChannelNum + 7 , MGPIO_ALTFUNC_TIM911);
		break;
	case TIMER11:
		MGPIO_vSetPinMode(PORTB, Copy_u8ChannelNum + 8 , ALTFUNC);
		MGPIO_vSetAlternativeFunction(PORTB, Copy_u8ChannelNum + 8 , MGPIO_ALTFUNC_TIM911);
		break;
	}
}

void HSERVO_vServoDeg(u8 Copy_u8TimerNum,u8 Copy_u8ChannelNum,u32 Copy_u8Deg){
	if(Copy_u8Deg >180){
		Copy_u8Deg = 180;
	}
	u16 Positive_Duty = ( (Copy_u8Deg * 2000)/180 + 500 );
	MTIMER_vPWM(Copy_u8TimerNum,Copy_u8ChannelNum, SERVO_FullPeriod, Positive_Duty);
}






