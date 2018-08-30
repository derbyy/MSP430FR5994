/*
 * gpio.h
 *
 *  Created on: 26. 8. 2018
 *  Author	  : Martin
 */

#ifndef COMPONENT_GPIO_H_
#define COMPONENT_GPIO_H_

#include "driverlib/MSP430FR5xx_6xx/driverlib.h"

/* GPIO module initialization function */
extern void comp_GPIO_Module_Initialization(void);

/* This function selected pins on a selected port as output pins */
extern void comp_GPIO_setAsOutputPin(uint8_t u8SelectedPort, uint16_t u16SelectedPins);

/* This function selected pins on a selected port as input pins */
extern void comp_GPIO_setAsInputPin(uint8_t u8SelectedPort, uint16_t u16SelectedPins);

/* This function configures the peripheral module function in the output
 * direction for the selected pin for either primary, secondary or ternary
 * module function modes
 */
extern void comp_GPIO_setModeOnOutputPin(uint8_t u8SelectedPort, uint16_t u16SelectedPins, uint8_t u8Mode);

/* This function configures the peripheral module function in the input
 * direction for the selected pin for either primary, secondary or ternary
 * module function modes
 */
extern void comp_GPIO_setModeOnInputPin(uint8_t u8SelectedPort, uint16_t u16SelectedPins, uint8_t u8Mode);

/* This function sets output HIGH on the selected port's pin */
extern void comp_GPIO_setOutputHighOnPin(uint8_t u8SelectedPort, uint16_t u16SelectedPins);

/* This function sets output LOW on the selected port's pin */
extern void comp_GPIO_setOutputLowOnPin(uint8_t u8SelectedPort, uint16_t u16SelectedPins);

/* This function toggles the output on the selected port's pin */
extern void comp_GPIO_toggleOutputOnPin(uint8_t u8SelectedPort, uint16_t u16SelectedPins);

/* This function sets the selected Pin in input Mode with Pull Down resistor */
extern void comp_GPIO_setAsInputPinPullDown(uint8_t u8SelectedPort, uint16_t u16SelectedPins);

/* This function sets the selected Pin in input Mode with Pull Up resistor */
extern void comp_GPIO_setAsInputPinPullUp(uint8_t u8SelectedPort, uint16_t u16SelectedPins);

/* This function gets the input value on the selected pin */
extern void comp_GPIO_getInputPinValue(uint8_t u8SelectedPort, uint16_t u16SelectedPins);

/* This function enables the port interrupt on the selected pin */
extern void comp_GPIO_enableInterrupt(uint8_t u8SelectedPort, uint16_t u16SelectedPins);

/* This function disables the port interrupt on the selected pin */
extern void comp_GPIO_disableInterrupt(uint8_t u8SelectedPort, uint16_t u16SelectedPins);

/* This function gets the interrupt status of the selected pin */
extern void comp_GPIO_getInterruptStatus(uint8_t u8SelectedPort, uint16_t u16SelectedPins);

/* This function clears the interrupt flag on the selected pin */
extern void comp_GPIO_clearInterrupt(uint8_t u8SelectedPort, uint16_t u16SelectedPins);

/* This function selects on what edge the port interrupt flag should be set
 * for a transition. Values for edgeSelect should be
 * GPIO_LOW_TO_HIGH_TRANSITION or GPIO_HIGH_TO_LOW_TRANSITION
 */
extern void comp_GPIO_selectInterruptEdge(uint8_t u8SelectedPort, uint16_t u16SelectedPins, uint8_t u8EdgeSelect);

#endif /* COMPONENT_GPIO_H_ */
