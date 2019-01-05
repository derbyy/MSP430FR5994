/*
 * timer.h
 *
 *  Created on: 30. 8. 2018
 *  Author	  : Martin
 */

#ifndef COMPONENT_TIMER_H_
#define COMPONENT_TIMER_H_

#include "driverlib/MSP430FR5xx_6xx/driverlib.h"

/* Compare value for ACLK timer ~2 sec */
#define TIMER0_A0_COMP_VALUE                 0xFFFF

/* Function for initialization of TimerA module into up mode */
extern void comp_TimerA_vUpModeInitialization(uint16_t u16BaseAddress);

/* Function for set up Timer module into up mode */
extern void comp_TimerA_vSetUpTimer(uint16_t u16BaseAddress, uint16_t u16compRegister, uint16_t u16CompValue);

/* Sets the value of the capture-compare register */
extern void comp_Timer_A_vSetCompValue(uint16_t u16BaseAddr, uint16_t u16CmpRegister, uint16_t u16CmpValue);

#endif /* COMPONENT_TIMER_H_ */
