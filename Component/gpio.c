/*
 * gpio.c
 *
 *  Created on: 26. 8. 2018
 *  Author	  : Martin
 */
#include "gpio.h"

/*************************************************************************************
 *  Description :   GPIO module initialization function
 *  Parameters  :   void
 *  Return      :   void
 *************************************************************************************/
void comp_GPIO_Module_Initialization(void)
{
    /* Set all GPIO pins to output low for low power */
    comp_GPIO_setOutputLowOnPin( GPIO_PORT_P1, GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4 | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7 );
    comp_GPIO_setOutputLowOnPin( GPIO_PORT_P2, GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4 | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7 );
    comp_GPIO_setOutputLowOnPin( GPIO_PORT_P3, GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4 | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7 );
    comp_GPIO_setOutputLowOnPin( GPIO_PORT_P4, GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4 | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7 );
    comp_GPIO_setOutputLowOnPin( GPIO_PORT_P5, GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4 | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7 );
    comp_GPIO_setOutputLowOnPin( GPIO_PORT_P6, GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4 | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7 );
    comp_GPIO_setOutputLowOnPin( GPIO_PORT_P7, GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4 | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7 );
    comp_GPIO_setOutputLowOnPin( GPIO_PORT_P8, GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4 | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7 );
    comp_GPIO_setOutputLowOnPin( GPIO_PORT_PJ, GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4 | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7 |
                                 GPIO_PIN8 | GPIO_PIN9 | GPIO_PIN10 | GPIO_PIN11 | GPIO_PIN12 | GPIO_PIN13 | GPIO_PIN14 | GPIO_PIN15 );

    comp_GPIO_setAsOutputPin( GPIO_PORT_P1, GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4 | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7 );
    comp_GPIO_setAsOutputPin( GPIO_PORT_P2, GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4 | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7 );
    comp_GPIO_setAsOutputPin( GPIO_PORT_P3, GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4 | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7 );
    comp_GPIO_setAsOutputPin( GPIO_PORT_P4, GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4 | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7 );
    comp_GPIO_setAsOutputPin( GPIO_PORT_P5, GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4 | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7 );
    comp_GPIO_setAsOutputPin( GPIO_PORT_P6, GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4 | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7 );
    comp_GPIO_setAsOutputPin( GPIO_PORT_P7, GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4 | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7 );
    comp_GPIO_setAsOutputPin( GPIO_PORT_P8, GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4 | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7 );
    comp_GPIO_setAsOutputPin( GPIO_PORT_PJ, GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4 | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7 |
                              GPIO_PIN8 | GPIO_PIN9 | GPIO_PIN10 | GPIO_PIN11 | GPIO_PIN12 | GPIO_PIN13 | GPIO_PIN14 | GPIO_PIN15 );

    /* Setup P2.1 to UART_1 function */
//    GPIO_setOutputLowOnPin( GPIO_PORT_P2, GPIO_PIN0 );
//    GPIO_setAsOutputPin( GPIO_PORT_P2, GPIO_PIN0 );
//    GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P2, GPIO_PIN1, GPIO_SECONDARY_MODULE_FUNCTION );

    /* Setup P6.1 to UART_3 funtion */
//    GPIO_setOutputLowOnPin( GPIO_PORT_P6, GPIO_PIN0 );
//    GPIO_setAsOutputPin( GPIO_PORT_P6, GPIO_PIN0 );
//    GPIO_setAsPeripheralModuleFunctionInputPin( GPIO_PORT_P6, GPIO_PIN1, GPIO_PRIMARY_MODULE_FUNCTION );

    /* Sets up P3.0, P3.1, P3.2 to ADC function */
    GPIO_setAsInputPin(GPIO_PORT_P3, GPIO_PIN0);
    GPIO_setAsInputPin(GPIO_PORT_P3, GPIO_PIN1);
    GPIO_setAsInputPin(GPIO_PORT_P3, GPIO_PIN2);

    /* Sets up P1.4 and P1.5 to High */
    comp_GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN4);
    comp_GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN5);

    /* Set PJ.4 and PJ.5 as Primary Module Function Input, LFXT */
    comp_GPIO_setModeOnInputPin(GPIO_PORT_PJ, GPIO_PIN4 + GPIO_PIN5, GPIO_PRIMARY_MODULE_FUNCTION );

    /* Disable the GPIO power-on default high-impedance mode to activate previously configured port settings */
    PMM_unlockLPM5();
}

/**********************************************************************************************
 *  Description :   This function selected pins on a selected port as output pins
 *  Parameters  :   uint8_t     u8SelectedPort
 *                  uint16_t    u16SelectedPins
 *  Return      :   void
 **********************************************************************************************/
void comp_GPIO_setAsOutputPin(uint8_t u8SelectedPort, uint16_t u16SelectedPins)
{
    GPIO_setAsOutputPin(u8SelectedPort, u16SelectedPins);
}

/**********************************************************************************************
 *  Description :   This function selected pins on a selected port as input pins
 *  Parameters  :   uint8_t     u8SelectedPort
 *                  uint16_t    u16SelectedPins
 *  Return      :   void
 **********************************************************************************************/
void comp_GPIO_setAsInputPin(uint8_t u8SelectedPort, uint16_t u16SelectedPins)
{
    GPIO_setAsInputPin(u8SelectedPort, u16SelectedPins);
}

/**********************************************************************************************
 *  Description :   This function configures the peripheral module function in the output
 *                  direction for the selected pin for either primary, secondary or ternary
 *                  module function modes
 *  Parameters  :   uint8_t     u8SelectedPort
 *                  uint16_t    u16SelectedPins
 *                  uint8_t     u8Mode
 *  Return      :   void
 **********************************************************************************************/
void comp_GPIO_setModeOnOutputPin(uint8_t u8SelectedPort, uint16_t u16SelectedPins, uint8_t u8Mode)
{
    GPIO_setAsPeripheralModuleFunctionOutputPin(u8SelectedPort, u16SelectedPins, u8Mode);
}

/**********************************************************************************************
 *  Description :   This function configures the peripheral module function in the input
 *                  direction for the selected pin for either primary, secondary or ternary
 *                  module function modes
 *  Parameters  :   uint8_t     u8SelectedPort
 *                  uint16_t    u16SelectedPins
 *                  uint8_t     u8Mode
 *  Return      :   void
 **********************************************************************************************/
void comp_GPIO_setModeOnInputPin(uint8_t u8SelectedPort, uint16_t u16SelectedPins, uint8_t u8Mode)
{
    GPIO_setAsPeripheralModuleFunctionInputPin(u8SelectedPort, u16SelectedPins, u8Mode);
}

/**********************************************************************************************
 *  Description :   This function sets output HIGH on the selected port's pin
 *  Parameters  :   uint8_t     u8SelectedPort
 *                  uint16_t    u16SelectedPins
 *  Return      :   void
 **********************************************************************************************/
void comp_GPIO_setOutputHighOnPin(uint8_t u8SelectedPort, uint16_t u16SelectedPins)
{
    GPIO_setOutputHighOnPin(u8SelectedPort, u16SelectedPins);
}

/**********************************************************************************************
 *  Description :   This function sets output LOW on the selected port's pin
 *  Parameters  :   uint8_t     u8SelectedPort
 *                  uint16_t    u16SelectedPins
 *  Return      :   void
 **********************************************************************************************/
void comp_GPIO_setOutputLowOnPin(uint8_t u8SelectedPort, uint16_t u16SelectedPins)
{
    GPIO_setOutputLowOnPin(u8SelectedPort, u16SelectedPins);
}

/**********************************************************************************************
 *  Description :   This function toggles the output on the selected port's pin
 *  Parameters  :   uint8_t     u8SelectedPort
 *                  uint16_t    u16SelectedPins
 *  Return      :   void
 **********************************************************************************************/
void comp_GPIO_toggleOutputOnPin(uint8_t u8SelectedPort, uint16_t u16SelectedPins)
{
    GPIO_toggleOutputOnPin(u8SelectedPort, u16SelectedPins);
}

/**********************************************************************************************
 *  Description :   This function sets the selected Pin in input Mode with Pull Down resistor
 *  Parameters  :   uint8_t     u8SelectedPort
 *                  uint16_t    u16SelectedPins
 *  Return      :   void
 **********************************************************************************************/
void comp_GPIO_setAsInputPinPullDown(uint8_t u8SelectedPort, uint16_t u16SelectedPins)
{
    GPIO_setAsInputPinWithPullDownResistor(u8SelectedPort, u16SelectedPins);
}

/**********************************************************************************************
 *  Description :   This function sets the selected Pin in input Mode with Pull Up resistor
 *  Parameters  :   uint8_t     u8SelectedPort
 *                  uint16_t    u16SelectedPins
 *  Return      :   void
 **********************************************************************************************/
void comp_GPIO_setAsInputPinPullUp(uint8_t u8SelectedPort, uint16_t u16SelectedPins)
{
    GPIO_setAsInputPinWithPullUpResistor(u8SelectedPort, u16SelectedPins);
}

/**********************************************************************************************
 *  Description :   This function gets the input value on the selected pin
 *  Parameters  :   uint8_t     u8SelectedPort
 *                  uint16_t    u16SelectedPins
 *  Return      :   void
 **********************************************************************************************/
void comp_GPIO_getInputPinValue(uint8_t u8SelectedPort, uint16_t u16SelectedPins)
{
    GPIO_getInputPinValue(u8SelectedPort, u16SelectedPins);
}

/**********************************************************************************************
 *  Description :   This function enables the port interrupt on the selected pin
 *  Parameters  :   uint8_t     u8SelectedPort
 *                  uint16_t    u16SelectedPins
 *  Return      :   void
 **********************************************************************************************/
void comp_GPIO_enableInterrupt(uint8_t u8SelectedPort, uint16_t u16SelectedPins)
{
    GPIO_enableInterrupt(u8SelectedPort, u16SelectedPins);
}

/**********************************************************************************************
 *  Description :   This function disables the port interrupt on the selected pin
 *  Parameters  :   uint8_t     u8SelectedPort
 *                  uint16_t    u16SelectedPins
 *  Return      :   void
 **********************************************************************************************/
void comp_GPIO_disableInterrupt(uint8_t u8SelectedPort, uint16_t u16SelectedPins)
{
    GPIO_disableInterrupt(u8SelectedPort, u16SelectedPins);
}

/**********************************************************************************************
 *  Description :   This function gets the interrupt status of the selected pin
 *  Parameters  :   uint8_t     u8SelectedPort
 *                  uint16_t    u16SelectedPins
 *  Return      :   void
 **********************************************************************************************/
void comp_GPIO_getInterruptStatus(uint8_t u8SelectedPort, uint16_t u16SelectedPins)
{
    GPIO_getInterruptStatus(u8SelectedPort, u16SelectedPins);
}

/**********************************************************************************************
 *  Description :   This function clears the interrupt flag on the selected pin
 *  Parameters  :   uint8_t     u8SelectedPort
 *                  uint16_t    u16SelectedPins
 *  Return      :   void
 **********************************************************************************************/
void comp_GPIO_clearInterrupt(uint8_t u8SelectedPort, uint16_t u16SelectedPins)
{
    GPIO_clearInterrupt(u8SelectedPort, u16SelectedPins);
}

/**********************************************************************************************
 *  Description :   This function selects on what edge the port interrupt flag should be set
 *                  for a transition. Values for edgeSelect should be
 *                  GPIO_LOW_TO_HIGH_TRANSITION or GPIO_HIGH_TO_LOW_TRANSITION
 *  Parameters  :   uint8_t     u8SelectedPort
 *                  uint16_t    u16SelectedPins
 *                  uint8_t     u8EdgeSelect
 *  Return      :   void
 **********************************************************************************************/
void comp_GPIO_selectInterruptEdge(uint8_t u8SelectedPort, uint16_t u16SelectedPins, uint8_t u8EdgeSelect)
{
    GPIO_selectInterruptEdge(u8SelectedPort, u16SelectedPins, u8EdgeSelect);
}
