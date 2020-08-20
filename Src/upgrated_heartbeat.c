/*
 * upgrated_heartbeat.c
 *
 *  Created on: 12 авг. 2020 г.
 *      Author: Violetta
 */

#include "upgrated_heartbeat.h"

void Heartbeat(uint32_t period, uint32_t DutyCycle, leds_t LedColor){

	LEDs_Turn_ON(LedColor);
	HAL_Delay(DutyCycle);
	LEDs_Turn_OFF(LedColor);
	HAL_Delay(period-DutyCycle);
};


