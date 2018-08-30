#include "Component/clock.h"
#include "Component/gpio.h"
#include "Component/rtc.h"
#include "Component/uart.h"
#include "Component/adc.h"
#include <stdio.h>
#include <string.h>

volatile unsigned int adc_in = 0;

/***************************************************************************
 * The main procedure of MSP430FR5994 Firmware for MPPT regulator.
 ***************************************************************************/
int main(void)
{
    /* Stop Watchdog timer */
    WDT_A_hold( WDT_A_BASE );

    /* Initialize GPIO system */
    comp_GPIO_Module_Initialization();
	
	/* Initialization of clock system */
	comp_Clock_Module_Initialization();

	/* Initialize UART_A3 module */
	comp_UART_Module_Initialization(EUSCI_A3_BASE);

	/* Initialize UART_A0 module */
	comp_UART_Module_Initialization(EUSCI_A0_BASE);

	/* Initialize Real Time clock system */
	comp_RTC_Module_Initialization(&m_sCalendar);

	for(;;)
	{
//	    ADC12_B_startConversion(ADC12_B_BASE, ADC12_B_MEMORY_0, ADC12_B_SEQOFCHANNELS);
//	    _delay_cycles(2000000);
	}
}

#pragma vector=ADC12_B_VECTOR
__interrupt void ADC12ISR(void)
{
    adc_in = ADC12MEM0;
}
