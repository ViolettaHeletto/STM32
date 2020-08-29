/*
 * ulSysTime.c
 *
 *  Created on: 20 авг. 2020 г.
 *      Author: Violetta
 */
#include "ulSysTime.h"
#include "stdlib.h"

uint32_t GetCurrentTime(){

	return HAL_GetTick();
}

uint32_t SysTime_isItTime(uint32_t StartTime, int delay){
	uint32_t currentTime = GetCurrentTime();
	uint32_t res = currentTime - StartTime;
	uint8_t returnValue = 0;
	if( abs(res) >= delay)
	{
		returnValue = 1;
	}
	return returnValue;
}



