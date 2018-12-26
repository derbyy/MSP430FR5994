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
    /* 1. Cut off load from solar panel */
    //comp_GPIO_setOutputLowOnPin(GPIO_PORT_P3, GPIO_PIN4);

    /* 2. Wait for ~30ms to stabilize voltage */
    //comp_TimerA_Initialization(TIMER_A1_BASE, 0x0400);

    /* 3. Read voltage from solar panel */
    comp_ADC_ReadChannel(ADC12INCH_13, ADC12_B_MEMORY_0);

    /* 4. Store readed value */
    mppt_u16ADCSolarVoltageValue = comp_ADC_getResult(ADC12_B_BASE, ADC12_B_MEMORY_0);

    /* 5. Connect load to solar panel */
    //comp_GPIO_setOutputHighOnPin(GPIO_PORT_P3, GPIO_PIN4);

    /* 6. Read voltage on Supercapacitor bank 1 */
    comp_ADC_ReadChannel(ADC12INCH_12, ADC12_B_MEMORY_0);

    /* 7. Store readed value */
    mppt_u16ADCSupercapVoltageValue_1 = comp_ADC_getResult(ADC12_B_BASE, ADC12_B_MEMORY_0);

    /* 6. Read voltage on Supercapacitor bank 2 */
    comp_ADC_ReadChannel(ADC12INCH_14, ADC12_B_MEMORY_0);

    /* 8. Store readed value */
    mppt_u16ADCSupercapVoltageValue_2 = comp_ADC_getResult(ADC12_B_BASE, ADC12_B_MEMORY_0);
}

