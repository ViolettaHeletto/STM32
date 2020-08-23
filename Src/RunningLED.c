/*
 * RunningLED.c
 *
 *  Created on: 23 авг. 2020 г.
 *      Author: Violetta
 */

#include "RunningLED.h"

leds_t ColourLED[4] = { LED_RED, LED_Blue, LED_GREEN, LED_Orange};

typedef enum{
  STATE_TURN_LED_ON,
  STATE_WAIT_DUTYCYCLE,
  STATE_TURN_LED_OFF,
  STATE_WAIT_PERIOD,
  STATE_NEXT_STEP
} RunningLEDs_t;


static int ColourLEDSize = sizeof(ColourLED)/sizeof(uint16_t);
static RunningLEDs_t RLcurrentState = STATE_TURN_LED_ON;
static uint32_t Step = 0;
static uint32_t RLStateTurn(uint8_t choise, leds_t ColourLED);
  static uint32_t RLstartTime = 0;


void RunningLEDs(uint16_t PERIOD, uint16_t DUTY_CYCLE) {
  RunningLEDs_t RLnextState = RLcurrentState;
  uint8_t RLisItTime = 0;
  uint8_t menu = 1;


  switch(RLcurrentState){
  case STATE_TURN_LED_ON:
	  RLstartTime = RLStateTurn(menu, ColourLED[Step]);
	  RLnextState = STATE_WAIT_DUTYCYCLE;
    break;
  case STATE_WAIT_DUTYCYCLE:
    RLisItTime = SysTime_isItTime(RLstartTime, DUTY_CYCLE);
    if (RLisItTime){
      RLnextState = STATE_TURN_LED_OFF;
    }
    break;
  case STATE_TURN_LED_OFF:
	RLstartTime = RLStateTurn(!menu, ColourLED[Step]);
    RLnextState = STATE_WAIT_PERIOD;
   break;
  case STATE_WAIT_PERIOD:
    RLisItTime = SysTime_isItTime(RLstartTime, PERIOD - DUTY_CYCLE);
    if (RLisItTime){
     RLnextState = STATE_NEXT_STEP;
    }
  break;
  case STATE_NEXT_STEP:
    if (Step < ColourLEDSize){
      Step++;
    }else{
    Step = 0;
    }
   RLnextState = STATE_TURN_LED_ON;
  break;
  default:
   RLnextState = STATE_TURN_LED_ON;
  }
  RLcurrentState = RLnextState;
}

uint32_t RLStateTurn(uint8_t choise, leds_t ColourLED)
{
	uint32_t TimeStart = 0;
	if (choise == 1)
	{
		LEDs_Turn_ON(ColourLED);
		TimeStart = GetCurrentTime();
	}
	 else
	 {
		 LEDs_Turn_OFF(ColourLED);
		TimeStart = GetCurrentTime();
	 }
	return TimeStart;
}
