/*
 * upgrated_heartbeat.c
 *
 *  Created on: 12 авг. 2020 г.
 *      Author: Violetta
 */

#include "upgrated_heartbeat.h"

void Heartbeat(uint32_t period, uint32_t DutyCycle, leds_t LedColor){

	HAL_GPIO_WritePin(GPIOD, LedColor, GPIO_PIN_SET);
	HAL_Delay(DutyCycle);
	HAL_GPIO_WritePin(GPIOD, LedColor, GPIO_PIN_RESET);
	HAL_Delay(period-DutyCycle);
};


