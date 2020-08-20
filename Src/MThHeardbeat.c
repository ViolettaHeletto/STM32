/*
 * MThHeardbeat.c
 *
 *  Created on: 20 авг. 2020 г.
 *      Author: Violetta
 */

#include "MThHeardbeat.h"

typedef enum {

	LEDs_State_ON,
	LEDs_WaitingOFF,
	LEDs_State_OFF,
	LEDs_waitingON

}timeState_t;

static timeState_t curentlyState = LEDs_State_ON;
static IsItTime = 0;

void MThHeartbeat (leds_t LedColor){

	timeState_t NextState = curentlyState;
	switch(curentlyState){
	case LEDs_State_ON:
		LEDs_Turn_ON (LedColor);
		NextState = LEDs_WaitingOFF;
		break;
	case LEDs_WaitingOFF:
		MyDelay(IsItTime);
		NextState = LEDs_State_OFF;
		break;
	case LEDs_State_OFF:
		LEDs_Turn_OFF(LedColor);
		NextState = LEDs_waitingON;
		break;
	case LEDs_waitingON:
		MyDelay(IsItTime);
		NextState = LEDs_State_ON;
		break;
	default: curentlyState = LEDs_State_OFF;
	}
	curentlyState = NextState;
};

void MyDelay(int time){

	while(time){
		time--;
	}
}
