#include "Component/clock.h"
#include "Component/gpio.h"
#include "Component/rtc.h"
#include "Component/uart.h"
#include "Component/adc.h"
#include "Component/timer.h"
#include <stdio.h>
#include <string.h>

volatile unsigned int adc_in = 0;
volatile bool bNeedMeasure = false;
volatile bool readFlag = false;

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

	/* Initialize Timer_A1 module */
	comp_TimerA_Initialization(TIMER_A1_BASE);

	for(;;)
	{
	    if(readFlag == true)
	    {

	    }
	    if(bNeedMeasure == true)
	    {
	        /* Enable/Start sampling and conversion */
	        ADC12_B_startConversion(ADC12_B_BASE, ADC12_B_MEMORY_0, ADC12_B_SINGLECHANNEL);
	        bNeedMeasure = false;

	        /* Wait for conversion is done */
	        __bis_SR_register(LPM3_bits | GIE);
	        __bic_SR_register(GIE);
	    }
	}
}

#pragma vector=TIMER0_A1_VECTOR
__interrupt void TIMER0_A1_ISR(void)
{
    readFlag = true;
}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void TIMER0_A0_ISR(void)
{
    bNeedMeasure = true;
}

#pragma vector=ADC12_B_VECTOR
__interrupt void ADC12ISR(void)
{
    adc_in = comp_ADC_getResult(ADC12_B_BASE, ADC12_B_MEMORY_0);
}
