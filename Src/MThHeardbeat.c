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
static uint32_t StartTime;

void MThHeartbeat (leds_t LedColor, uint32_t DutyCycle, uint32_t period){

	static uint32_t ItTime = 0;
	timeState_t NextState = curentlyState;

	switch(curentlyState){
	case LEDs_State_ON:

		LEDs_Turn_ON (LedColor);
		StartTime = GetCurrentTime();
		NextState = LEDs_WaitingOFF;
		break;
	case LEDs_WaitingOFF:
		ItTime = SysTime_isItTime(StartTime, DutyCycle);
		if(ItTime){
			NextState = LEDs_State_OFF;
		}
		break;
	case LEDs_State_OFF:
		LEDs_Turn_OFF(LedColor);
		StartTime = GetCurrentTime();
		NextState = LEDs_waitingON;
		break;
	case LEDs_waitingON:
		ItTime = SysTime_isItTime(StartTime, period - DutyCycle);
				if(ItTime){
					NextState = LEDs_State_ON;
				}
		break;
	default: curentlyState = LEDs_State_OFF;
	}
	curentlyState = NextState;
};



