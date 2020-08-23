/*
 * ulSysTime.h
 *
 *  Created on: 20 авг. 2020 г.
 *      Author: Violetta
 */

#ifndef ULSYSTIME_H_
#define ULSYSTIME_H_
#include "drvLeds.h"

uint32_t GetCurrentTime();
uint32_t SysTime_isItTime(uint32_t StartTime, int delay);

#endif /* ULSYSTIME_H_ */
