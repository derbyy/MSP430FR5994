/*
 * mppt.c
 *
 *  Created on: 26. 12. 2018
 *  Author	  : Martin
 */
#include "mppt.h"

/*************************************************************************************
 * Module variables
 *************************************************************************************/

/* Variable for holding ADC value of voltage readed from Solar panel */
static uint16_t mppt_u16ADCSolarVoltageValue = 0u;

/* Variable for holding ADC value of voltage readed from Supercapacitor bank 1 */
static uint16_t mppt_u16ADCSupercapVoltageValue_1 = 0u;

/* Variable for holding ADC value of voltage readed from Supercapacitor bank 2 */
static uint16_t mppt_u16ADCSupercapVoltageValue_2 = 0u;


/*************************************************************************************
 *  Description :   This function read voltages on all components of MPPT device
 *  Parameters  :   void
 *  Return      :   void
 *************************************************************************************/
void mppt_vReadVoltage()
{
    /* Initialize Timer A1 into Up mode */
    comp_TimerA_vUpModeInitialization(TIMER_A1_BASE);

    /* Enter LPM3. Delay for Ref to settle */
    __bis_SR_register(LPM3_bits | GIE);

    /* Cut off load from solar panel */
    comp_GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN4);

    /* Set up Timet A1 compare value ~30ms */
    comp_Timer_A_vSetCompValue(TIMER_A1_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_1, 0x0400);

    /* Enter LPM3, wait for ~30ms sec to stabilize voltage */
    __bis_SR_register(LPM3_bits | GIE);

    /* Stop Timer A1 */
    Timer_A_stop(TIMER_A1_BASE);

    /* Read voltage from solar panel */
    comp_ADC_ReadChannel(ADC12INCH_13, ADC12_B_MEMORY_0);

    /* Store readed value of connected solar panel */
    mppt_u16ADCSolarVoltageValue = comp_ADC_getResult(ADC12_B_BASE, ADC12_B_MEMORY_0);

    /* Connect load to solar panel */
    comp_GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN4);

    /* Read voltage on Supercapacitor bank 1 */
    comp_ADC_ReadChannel(ADC12INCH_12, ADC12_B_MEMORY_0);

    /* Store readed value of Supercapacitor bank 1 */
    mppt_u16ADCSupercapVoltageValue_1 = comp_ADC_getResult(ADC12_B_BASE, ADC12_B_MEMORY_0);

    /* Read voltage on Supercapacitor bank 2 */
    comp_ADC_ReadChannel(ADC12INCH_14, ADC12_B_MEMORY_0);

    /* Store readed value Supercapacitor bank 2 */
    mppt_u16ADCSupercapVoltageValue_2 = comp_ADC_getResult(ADC12_B_BASE, ADC12_B_MEMORY_0);
}

/*************************************************************************************
 *  Description :   This function get ADC value of solar panel
 *  Parameters  :   void
 *  Return      :   uint16_t
 *************************************************************************************/
uint16_t mppt_u16GetADCSolarVoltageValue()
{
    return mppt_u16ADCSolarVoltageValue;
}

/*************************************************************************************
 *  Description :   This function get ADC value of supercapacitor bank 1
 *  Parameters  :   void
 *  Return      :   uint16_t
 *************************************************************************************/
uint16_t mppt_u16GetADCSupercapVoltageValue_1()
{
    return mppt_u16ADCSupercapVoltageValue_1;
}

/*************************************************************************************
 *  Description :   This function get ADC value of supercapacitor bank 2
 *  Parameters  :   void
 *  Return      :   uint16_t
 *************************************************************************************/
uint16_t mppt_u16GetADCSupercapVoltageValue_2()
{
    return mppt_u16ADCSupercapVoltageValue_2;
}
