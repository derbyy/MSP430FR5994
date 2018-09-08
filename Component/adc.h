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
extern void comp_ADC_Module_Initialization(uint16_t u16AdcChannel, uint16_t u16AdcMemBuffer);

/* Function for read ADC value from specific channel */
extern void comp_ADC_ReadChannel(uint16_t u16AdcChannel, uint8_t u8MemoryBufferIndex);

/* Returns the raw contents of the specified memory buffer */
extern uint16_t comp_ADC_getResult(uint16_t u16BaseAddress, uint8_t u8MemoryBufferIndex);

#endif /* COMPONENT_ADC_H_ */
