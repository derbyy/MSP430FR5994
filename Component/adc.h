/*
 * adc.h
 *
 *  Created on: 26. 8. 2018
 *  Author	  : Martin
 */

#ifndef COMPONENT_ADC_H_
#define COMPONENT_ADC_H_

#include "driverlib/MSP430FR5xx_6xx/driverlib.h"

/* Analog/Digital converter module initialization */
extern void comp_ADC_Module_Initialization(uint16_t u16AdcCntrlReg, uint16_t u16AdcChannel, uint16_t u16AdcMemBuffer);

#endif /* COMPONENT_ADC_H_ */
