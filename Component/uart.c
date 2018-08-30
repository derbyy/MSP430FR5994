/*
 * uart.c
 *
 *  Created on: 26. 8. 2018
 *  Author	  : Martin
 */
#include "uart.h"

/****************************************************************************
 *  Description :   Universal Asynchronous Serial Bus module initialization
 *  Parameters  :   uint16_t    u16UartModule
 *  Return      :   void
 ****************************************************************************/
void comp_UART_Module_Initialization(uint16_t u16UartModule)
{
    /* Configure UART 9600 bit per second at 8MHz clock source */
    EUSCI_A_UART_initParam param = { 0 };
    param.selectClockSource |= EUSCI_A_UART_CLOCKSOURCE_SMCLK;
    param.clockPrescalar |= ( UCBR5 ) ^ ( UCBR4 ) ^ ( UCBR2 );
    param.firstModReg |= ( UCBRF0 );
    param.secondModReg |= ( UCBRS6 ) ^ ( UCBRS3 ) ^ ( UCBRS0 );
    param.parity |= EUSCI_A_UART_NO_PARITY;
    param.msborLsbFirst |= EUSCI_A_UART_LSB_FIRST;
    param.numberofStopBits |= EUSCI_A_UART_ONE_STOP_BIT;
    param.uartMode |= EUSCI_A_UART_MODE;
    param.overSampling |= EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION;

    /* Check for USCI initialize status */
    if( STATUS_FAIL == EUSCI_A_UART_init( u16UartModule, &param ) )
    {
        return;
    }

    /* Enable USCI module */
    EUSCI_A_UART_enable( u16UartModule );

    /* Clear USCI interrupt */
    EUSCI_A_UART_clearInterrupt( u16UartModule, EUSCI_A_UART_RECEIVE_INTERRUPT );

    /* Enable USCI RX interrupt */
    EUSCI_A_UART_enableInterrupt( u16UartModule, EUSCI_A_UART_RECEIVE_INTERRUPT );

    /* Enable global interrupt */
    __enable_interrupt();
}

