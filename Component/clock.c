/*
 * clock.c
 *
 *  Created on: 26. 8. 2018
 *  Author	  : Martin
 */
#include "clock.h"

/*************************************************************
 *  Description :   CLock system initialization function
 *  Parameters  :   void
 *  Return      :   void
 *************************************************************/
void comp_Clock_Module_Initialization(void)
{
    /* Set DCO frequency to 8 MHz */
    CS_setDCOFreq( CS_DCORSEL_0, DCOFSEL_6 );
    /* Set external clock frequency to 32.768 KHz */
    CS_setExternalClockSource( CLOCK_SOURCE_EXTERNAL_HIGH, CLOCK_SOURCE_EXTERNAL_LOW);
    /* Set ACLK = LFXT */
    CS_initClockSignal( CS_ACLK, CS_LFXTCLK_SELECT, CS_CLOCK_DIVIDER_1 );
    /* Set SMCLK = DCO with frequency divider of 1 */
    CS_initClockSignal( CS_SMCLK, CS_DCOCLK_SELECT, CS_CLOCK_DIVIDER_8 );
    /* Set MCLK = DCO with frequency divider of 1 */
    CS_initClockSignal( CS_MCLK, CS_DCOCLK_SELECT, CS_CLOCK_DIVIDER_8 );
    /* Start XT1 with no time out */
    CS_turnOnLFXT( CS_LFXT_DRIVE_3 );
}

