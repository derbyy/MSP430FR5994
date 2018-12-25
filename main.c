#include "Component/clock.h"
#include "Component/gpio.h"
#include "Component/rtc.h"
#include "Component/uart.h"
#include "Component/adc.h"
#include "Component/timer.h"
#include <stdio.h>
#include <string.h>

volatile unsigned int adc_in = 0;
/***************************************************************************
 * The _system_pre_init procedure of MSP430FR5994 Firmware for MPPT regulator.
 ***************************************************************************/
uint8_t _system_pre_init(void)
{
    // Stop Watchdog timer
    WDT_A_hold(__MSP430_BASEADDRESS_WDT_A__);     // Stop WDT

    GPIO_setOutputHighOnPin(GPIO_PORT_P4, GPIO_PIN0);
    GPIO_setAsOutputPin(GPIO_PORT_P4, GPIO_PIN0);

    /*==================================*/
    /* Choose if segment initialization */
    /* should be done or not. */
    /* Return: 0 to omit initialization */
    /* 1 to run initialization */
    /*==================================*/
    return 0x01;
}

/***************************************************************************
 * The main procedure of MSP430FR5994 Firmware for MPPT regulator.
 ***************************************************************************/
int main(void)
{
    /* Initialize GPIO system */
    comp_GPIO_Module_Initialization();

    /* Initialization of clock system */
    comp_Clock_Module_Initialization();
	
	/* Initialize UART_A3 module */
	//comp_UART_Module_Initialization(EUSCI_A3_BASE);

	/* Initialize UART_A0 module */
	//comp_UART_Module_Initialization(EUSCI_A0_BASE);

	/* Initialize Real Time clock system */
	//comp_RTC_Module_Initialization(&m_sCalendar);

	/* Initialize Timer_A0 module */
	comp_TimerA_Initialization(TIMER_A0_BASE);

	while(1)
	{
	    /* Enter into LPM3 power save mode and wait for interrupts */
        __bis_SR_register(LPM3_bits | GIE);
        __no_operation();
        comp_ADC_ReadChannel(ADC12INCH_12, ADC12_B_MEMORY_0);
	}
}


#pragma vector=TIMER0_A0_VECTOR
__interrupt void TIMER0_A0_ISR(void)
{
    /* Exit active CPU */
    __bic_SR_register_on_exit(LPM3_bits);
}

#pragma vector=ADC12_B_VECTOR
__interrupt void ADC12ISR(void)
{
    adc_in = ADC12MEM0;
    ADC12IFGR0 &= ~ADC12IFG0;             // Clear interrupt flag
    __bic_SR_register_on_exit(LPM3_bits); // Exit active CPU
}
