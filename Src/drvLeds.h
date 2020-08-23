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
	LED_GREEN =  LD4_Pin,
	LED_RED =  LD5_Pin,
	LED_Blue = LD6_Pin,
	LED_Orange =  LD3_Pin
}leds_t;

void LEDs_Turn_ON (leds_t LedColor);
void LEDs_Turn_OFF(leds_t LedColor);

#endif /* DRVLEDS_H_ */
