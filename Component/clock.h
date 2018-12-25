/*
 * clock.h
 *
 *  Created on: 26. 8. 2018
 *  Author	  : Martin
 */

#ifndef COMPONENT_CLOCK_H_
#define COMPONENT_CLOCK_H_

#include "driverlib/MSP430FR5xx_6xx/driverlib.h"

#define CLOCK_SOURCE_EXTERNAL_HIGH           32768
#define CLOCK_SOURCE_EXTERNAL_LOW                0

/* CLock system initialization function */
extern void comp_Clock_Module_Initialization(void);


#endif /* COMPONENT_CLOCK_H_ */
