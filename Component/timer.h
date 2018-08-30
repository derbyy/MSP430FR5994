/*
 * timer.h
 *
 *  Created on: 30. 8. 2018
 *  Author	  : Martin
 */

#ifndef COMPONENT_TIMER_H_
#define COMPONENT_TIMER_H_

#include "driverlib/MSP430FR5xx_6xx/driverlib.h"

/* Function for initialization Timer module */
extern void comp_TimerA_Initialization(void);

/* Sets the value of the capture-compare register */
extern void comp_TimerA_SetCompValue(uint16_t u16BaseAddr, uint16_t u16CmpRegister, uint16_t u16CmpValue);

#endif /* COMPONENT_TIMER_H_ */
