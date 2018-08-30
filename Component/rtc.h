/*
 * rtc.h
 *
 *  Created on: 26. 8. 2018
 *  Author	  : Martin
 */

#ifndef COMPONENT_RTC_H_
#define COMPONENT_RTC_H_

#include "driverlib/MSP430FR5xx_6xx/driverlib.h"

/******************** Module Variables *******************************/

extern Calendar m_sCalendar;

/*********************************************************************/

/******************** Module Functions *******************************/

/* Real Time Clock module initialization function */
extern void comp_RTC_Module_Initialization(Calendar* pCalendar);

/*********************************************************************/

#endif /* COMPONENT_RTC_H_ */
