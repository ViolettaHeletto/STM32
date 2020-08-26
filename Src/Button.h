/*
 * Button.h
 *
 *  Created on: 24 авг. 2020 г.
 *      Author: Violetta
 */

#ifndef BUTTON_H_
#define BUTTON_H_

typedef enum {
	BUTT_LEFT,
	BUTT_UP,
	BUTT_RIGHT,
	BUTT_DOWN,
	BUTT_CENTER,
	BUTTON_NUMBER
}buttons_t;

typedef enum{
	BUTTON_RELEASED,
	BUTTON_PRESSED,

}ButtonState_t;


ButtonState_t Button_GetKeyState(buttons_t KeyName);
void Button_run();

#endif /* BUTTON_H_ */
