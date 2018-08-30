/*
 * timer.c
 *
 *  Created on: 30. 8. 2018
 *  Author	  : Martin
 */
#include "timer.h"


/**********************************************************************
 *  Description :   Function for initialization Timer module
 *  Parameters  :   void
 *  Return      :   void
 **********************************************************************/
void comp_TimerInitialization(void)
{
    /* Initialize Timer_A module */
    Timer_A_initUpModeParam timerParam = {0};
    timerParam.clockSource |= TIMER_A_CLOCKSOURCE_ACLK;
    timerParam.clockSourceDivider |= TIMER_A_CLOCKSOURCE_DIVIDER_1;
    timerParam.timerPeriod = 0xFF;
    timerParam.timerInterruptEnable_TAIE |= TIMER_A_TAIE_INTERRUPT_DISABLE;
    timerParam.captureCompareInterruptEnable_CCR0_CCIE |= TIMER_A_CCIE_CCR0_INTERRUPT_ENABLE;
    timerParam.timerClear |= TIMER_A_DO_CLEAR;
    timerParam.startTimer = true;
    Timer_A_initUpMode(TIMER_A0_BASE, &timerParam);

    /* Enter LPM3. Delay for Ref to settle */
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
