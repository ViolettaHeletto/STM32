/*
 * Button.c
 *
 *  Created on: 24 авг. 2020 г.
 *      Author: Violetta
 */

#include "Button.h"
#include "stdint.h"
#include "stm32f4xx.h"

#define COUNTER_MIN_VALUE      5
#define COUNTER_MAX_VALUE      200
#define COUNTER_PRESSED_VALUE  180
#define COUNTER_RELEASED_VALUE 20

typedef struct{
	uint8_t ButtonCounter;
	ButtonState_t KeyState;
	GPIO_TypeDef * port;
	uint16_t pin;
}key_t;

static key_t keys [BUTTON_NUMBER] = {
		{COUNTER_MIN_VALUE, BUTTON_RELEASED, GPIOC,GPIO_PIN_9},
		{COUNTER_MIN_VALUE, BUTTON_RELEASED, GPIOC,GPIO_PIN_6},
		{COUNTER_MIN_VALUE, BUTTON_RELEASED, GPIOC,GPIO_PIN_11},
		{COUNTER_MIN_VALUE, BUTTON_RELEASED, GPIOC,GPIO_PIN_8},
		{COUNTER_MIN_VALUE, BUTTON_RELEASED, GPIOA,GPIO_PIN_15},
};

ButtonState_t Button_GetKeyState(buttons_t KeyName){
	Button_run();
	return keys[KeyName].KeyState;
};


void Button_run(){

	for (uint32_t key = 0; key < BUTTON_NUMBER; key++){

		uint8_t PinState = HAL_GPIO_ReadPin(keys[key].port, keys[key].pin);

		if (PinState){
		keys[key].ButtonCounter++;
		}
		else{
		keys[key].ButtonCounter--;
		}


	if (keys[key].ButtonCounter > COUNTER_MAX_VALUE){keys[key].ButtonCounter = COUNTER_MAX_VALUE;}
	if (keys[key].ButtonCounter < COUNTER_MIN_VALUE){ keys[key].ButtonCounter = COUNTER_MIN_VALUE;}

	if (keys[key].ButtonCounter == COUNTER_PRESSED_VALUE){ //&& ( keys[key].KeyState == BUTTON_RELEASED)){
		keys[key].KeyState = BUTTON_PRESSED;
	}

	if (keys[key].ButtonCounter == COUNTER_RELEASED_VALUE){ //&& ( keys[key].KeyState == BUTTON_PRESSED)){
		keys[key].KeyState = BUTTON_RELEASED;
		}
	}
}




