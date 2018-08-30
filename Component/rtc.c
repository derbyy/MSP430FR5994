/*
 * rtc.c
 */
#include "rtc.h"

Calendar m_sCalendar;

/**********************************************************************
 *  Description :   Real Time Clock module initialization function
 *  Parameters  :   Calendar*   pCalendar
 *  Return      :   void
 **********************************************************************/
void comp_RTC_Module_Initialization(Calendar* pCalendar)
{
    /* Initialize Calendar structure */
    pCalendar->Year = 0x00;
    pCalendar->Month = 0x00;
    pCalendar->DayOfMonth = 0x00;
    pCalendar->DayOfWeek = 0x00;
    pCalendar->Hours = 0x00;
    pCalendar->Minutes = 0x00;
    pCalendar->Seconds = 0x00;

    /* Initialize RTC with the specified Calendar above */
    RTC_C_initCalendar( RTC_C_BASE, pCalendar, RTC_C_FORMAT_BINARY );

    /* Start RTC Clock */
    RTC_C_startClock( RTC_C_BASE );
}
