/*
 * timer.c
 *
 *  Created on: 30. 8. 2018
 *  Author	  : Martin
 */
#include "timer.h"


/**********************************************************************
 *  Description :   Function for initialization Timer module
 *  Parameters  :   uint16_t    u16BaseAddress
 *  Return      :   void
 **********************************************************************/
void comp_TimerA_Initialization(uint16_t u16BaseAddress)
{
    /* Initialize Timer_A module */
    Timer_A_initUpModeParam param = {0};
    param.clockSource = TIMER_A_CLOCKSOURCE_ACLK;
    param.clockSourceDivider = TIMER_A_CLOCKSOURCE_DIVIDER_1;
    param.timerPeriod = 13;
    param.timerInterruptEnable_TAIE = TIMER_A_TAIE_INTERRUPT_DISABLE;
    param.captureCompareInterruptEnable_CCR0_CCIE = TIMER_A_CCIE_CCR0_INTERRUPT_ENABLE;
    param.timerClear = TIMER_A_DO_CLEAR;
    param.startTimer = true;
    Timer_A_initUpMode(u16BaseAddress, &param);

    /* Enter LPM3. Delay for Ref to settle */
    __bis_SR_register(LPM3_bits | GIE);

    /* Change timer delay to 2 seconds */
    Timer_A_setCompareValue(u16BaseAddress, TIMER_A_CAPTURECOMPARE_REGISTER_0, 0xFFFF);

    /* Enter LPM3, wait for ~2 sec timer */
    __bis_SR_register(LPM3_bits | GIE);
}


/**********************************************************************
 *  Description :   Sets the value of the capture-compare register
 *  Parameters  :   uint16_t    u16BaseAddr
 *                  uint16_t    u16CmpRegister
 *                  uint16_t    u16CmpValue
 *  Return      :   void
 **********************************************************************/
void comp_Timer_A_SetCompValue(uint16_t u16BaseAddr, uint16_t u16CmpRegister, uint16_t u16CmpValue)
{
    Timer_A_setCompareValue(u16BaseAddr, u16CmpRegister, u16CmpValue);
}
