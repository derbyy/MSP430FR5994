/*
 * timer.c
 *
 *  Created on: 30. 8. 2018
 *  Author	  : Martin
 */
#include "timer.h"

/**********************************************************************
 *  Description :   Function for initialization Timer A module to Up mode
 *  Parameters  :   uint16_t    u16BaseAddress
 *  Return      :   void
 **********************************************************************/
void comp_TimerA_vUpModeInitialization(uint16_t u16BaseAddress)
{
    Timer_A_initUpModeParam param = {0};
    param.clockSource |= TIMER_A_CLOCKSOURCE_ACLK;
    param.clockSourceDivider |= TIMER_A_CLOCKSOURCE_DIVIDER_1;
    param.timerPeriod |= 13;
    param.timerInterruptEnable_TAIE |= TIMER_A_TAIE_INTERRUPT_DISABLE;
    param.captureCompareInterruptEnable_CCR0_CCIE |= TIMER_A_CCIE_CCR0_INTERRUPT_ENABLE;
    param.timerClear |= TIMER_A_DO_CLEAR;
    param.startTimer |= true;
    Timer_A_initUpMode(u16BaseAddress, &param);
}

/**********************************************************************
 *  Description :   Function for set up Timer A module
 *  Parameters  :   uint16_t    u16BaseAddress
 *                  uint16_t    u16compRegister
 *                  uint16_t    u16CompValue
 *  Return      :   void
 **********************************************************************/
void comp_TimerA_vSetUpTimer(uint16_t u16BaseAddress, uint16_t u16compRegister, uint16_t u16CompValue)
{
    /* Initialize Timer_A module into Up mode */
    comp_TimerA_vUpModeInitialization(u16BaseAddress);

    /* Enter LPM3. Delay for Ref to settle */
    __bis_SR_register(LPM3_bits | GIE);

    /* Change timer delay to 2 seconds */
    comp_Timer_A_vSetCompValue(u16BaseAddress, u16compRegister, u16CompValue);

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
void comp_Timer_A_vSetCompValue(uint16_t u16BaseAddr, uint16_t u16CmpRegister, uint16_t u16CmpValue)
{
    Timer_A_setCompareValue(u16BaseAddr, u16CmpRegister, u16CmpValue);
}
