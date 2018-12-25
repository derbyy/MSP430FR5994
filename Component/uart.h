/*
 * uart.h
 *
 *  Created on: 26. 8. 2018
 *  Author	  : Martin
 */

#ifndef COMPONENT_UART_H_
#define COMPONENT_UART_H_

#include "driverlib/MSP430FR5xx_6xx/driverlib.h"

/* Universal Asynchronous Serial Bus module initialization */
extern void comp_UART_Module_Initialization(uint16_t u16UartModule);
extern void comp_UART_SendData(int value);

#endif /* COMPONENT_UART_H_ */
