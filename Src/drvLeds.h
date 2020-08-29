/*
 * drvLeds.h
 *
 *  Created on: 12 авг. 2020 г.
 *      Author: Violetta
 */

#ifndef DRVLEDS_H_
#define DRVLEDS_H_
#include "main.h"

typedef enum {
	LED_GREEN = GPIO_PIN_12,
	LED_RED = GPIO_PIN_14,
	LED_Blue = GPIO_PIN_15,
	LED_Orange = GPIO_PIN_13
}leds_t;


void LEDs_Turn_ON (leds_t LedColor);
void LEDs_Turn_OFF(leds_t LedColor);

#endif /* DRVLEDS_H_ */
