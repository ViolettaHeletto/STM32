/*
 * ulKeyboard.c
 *
 *  Created on: Aug 25, 2020
 *      Author: Violetta
 */

#include "ulKeyboard.h"
#include "Button.h"
#include "drvLeds.h"

static leds_t glue_table[4] = {
		LED_Orange,
		LED_RED,
		LED_Blue,
		LED_GREEN

};

void ulKeyboard_run(){

	for (buttons_t key = 0; key < BUTTON_NUMBER; key++)
	{
		ButtonState_t KeyState = Button_GetKeyState(key);

		if(key != BUTT_CENTER)
		{
			if(KeyState == BUTTON_RELEASED)
			{
			LEDs_Turn_ON(glue_table[key]);
			}
			else
			{
				LEDs_Turn_OFF(glue_table[key]);
			}
		}
		else if(KeyState == BUTTON_RELEASED)
		{
			LEDs_Turn_ON(LED_GREEN|LED_RED|LED_Blue|LED_Orange);
		}

	}


}
