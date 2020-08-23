/*
 * MThHeardbeat.h
 *
 *  Created on: 20 авг. 2020 г.
 *      Author: Violetta
 */

#ifndef MTHHEARDBEAT_H_
#define MTHHEARDBEAT_H_

#include "drvLeds.h"
#include "ulSysTime.h"

void MThHeartbeat (leds_t LedColor, uint32_t DutyCycle, uint32_t period);
//void MyDelay(int time);

#endif /* MTHHEARDBEAT_H_ */
