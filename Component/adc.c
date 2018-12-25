/*
 * adc.c
 *
 *  Created on: 26. 8. 2018
 *  Author	  : Martin
 */
#include "adc.h"
#include "timer.h"

/**********************************************************************
 *  Description :   Analog/Digital converter module initialization
 *  Parameters  :   uint16_t    u16AdcChannel
 *                  uint16_t    u16AdcMemBuffer
 *  Return      :   void
 **********************************************************************/
void comp_ADC_Module_Initialization(uint16_t u16AdcChannel, uint16_t u16AdcMemBuffer)
{
    /* Initialize the ADC12B Module */
    /*
     * Base address of ADC12B Module
     * Use internal ADC12B bit as sample/hold signal to start conversion
     * USE ADC120SC as clock source
     * Use default clock divider/pre-divider of 1
     * Use Temperature Sensor and Battery Monitor internal channels
     */
    ADC12_B_initParam adc_initParam = {0};
    adc_initParam.sampleHoldSignalSourceSelect |= ADC12_B_SAMPLEHOLDSOURCE_SC;
    adc_initParam.clockSourceSelect |= ADC12_B_CLOCKSOURCE_ADC12OSC;
    adc_initParam.clockSourceDivider |= ADC12_B_CLOCKDIVIDER_1;
    adc_initParam.clockSourcePredivider |= ADC12_B_CLOCKPREDIVIDER__1;
    ADC12_B_init(ADC12_B_BASE, &adc_initParam);

    /* Enable the ADC12B module */
    ADC12_B_enable(ADC12_B_BASE);

    /* Sets up the sampling timer pulse mode */
    ADC12_B_setupSamplingTimer(ADC12_B_BASE,
                               ADC12_B_CYCLEHOLD_16_CYCLES,
                               ADC12_B_CYCLEHOLD_16_CYCLES,
                               ADC12_B_MULTIPLESAMPLESDISABLE);

    /* Maps ADC input channel to Memory 0 and select voltage references */
    /*
     * Base address of the ADC12B Module
     * Configure memory buffer 0
     * Map ADC input to memory buffer 0
     * Vref+ = IntBuffer
     * Vref- = AVss
     * Memory buffer 0 is not the end of a sequence
     */
    ADC12_B_configureMemoryParam adc_confMemoryParam = {0};
    adc_confMemoryParam.memoryBufferControlIndex = u16AdcMemBuffer;
    adc_confMemoryParam.inputSourceSelect |= u16AdcChannel;
    adc_confMemoryParam.refVoltageSourceSelect |= ADC12_B_VREFPOS_INTBUF_VREFNEG_VSS;
    adc_confMemoryParam.endOfSequence |= ADC12_B_NOTENDOFSEQUENCE;
    adc_confMemoryParam.windowComparatorSelect |= ADC12_B_WINDOW_COMPARATOR_DISABLE;
    adc_confMemoryParam.differentialModeSelect |= ADC12_B_DIFFERENTIAL_MODE_DISABLE;
    ADC12_B_configureMemory(ADC12_B_BASE, &adc_confMemoryParam);

    /* Configure internal reference to 2.5V */
    while(Ref_A_isRefGenBusy(REF_A_BASE));
    Ref_A_enableTempSensor(REF_A_BASE);
    Ref_A_setReferenceVoltage(REF_A_BASE, REF_A_VREF2_5V);
    Ref_A_enableReferenceVoltage(REF_A_BASE);

    /* Clear memory buffer 0 interrupt */
    ADC12_B_clearInterrupt(ADC12_B_BASE, 0, ADC12_B_IFG0);

    /* Enable memory buffer 0 interrupt */
    ADC12_B_enableInterrupt(ADC12_B_BASE, ADC12_B_IE0, 0, 0);
}

/**********************************************************************
 *  Description :   Function for read ADC value from specific channel
 *  Parameters  :   uint16_t    u16AdcChannel
 *                  uint8_t     u8MemoryBufferIndex
 *  Return      :   void
 **********************************************************************/
void comp_ADC_ReadChannel(uint16_t u16AdcChannel, uint8_t u8MemoryBufferIndex)
{
    /* Initialize ADC12_B Module */
    comp_ADC_Module_Initialization(u16AdcChannel, u8MemoryBufferIndex);

    /* Enable/Start sampling and conversion */
    ADC12_B_startConversion(ADC12_B_BASE, u8MemoryBufferIndex, ADC12_B_SINGLECHANNEL);

    /* Wait for conversion is done */
    __bis_SR_register(LPM3_bits | GIE);
    __bic_SR_register(GIE);

    /* Set breakpoint here */
    __no_operation();

   /* Disable ADC12 Module and Timer_A0 module */
    ADC12_B_disable(ADC12_B_BASE);
}


/**********************************************************************
 *  Description :   Returns the raw contents of the specified memory
 *                  buffer
 *  Parameters  :   uint16_t    u16BaseAddress
 *                  uint16_t    u8MemoryBufferIndex
 *  Return      :   uint16_t
 **********************************************************************/
uint16_t comp_ADC_getResult(uint16_t u16BaseAddress, uint8_t u8MemoryBufferIndex)
{
    return ADC12_B_getResults(u16BaseAddress, u8MemoryBufferIndex);
}
