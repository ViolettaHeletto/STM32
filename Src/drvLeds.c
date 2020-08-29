/*
 * drvLeds.c
 *
 *  Created on: 18 авг. 2020 г.
 *      Author: Violetta
 */
#include "drvLeds.h"


void LEDs_Turn_ON (leds_t LedColor){

	HAL_GPIO_WritePin(GPIOD, LedColor, GPIO_PIN_SET);
};

void LEDs_Turn_OFF(leds_t LedColor){

	HAL_GPIO_WritePin(GPIOD, LedColor, GPIO_PIN_RESET);
}
