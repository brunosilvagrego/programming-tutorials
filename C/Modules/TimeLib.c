/**** System includes ****/
//#include <stdio.h>

/**** Modules includes ****/
#include "ConversionLib.h"

/**** Private and public functions code ****/

/** \fn char TimeLib_YearIsLeap (int year)
 *  \brief Checks if the year passed as argument is a leap year or not
 *  \param[in] year Year to check
 *  \return 0 if it is a leap year, 1 otherwise
 */
char TimeLib_YearIsLeap (int year)
{
    char ret;

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        ret = 0;    /* Is leap year */
    }
    else
    {
        ret = 1;    /* Is not */
    }

    return ret;
}

/** \fn int TimeLib_DayOfYear (int year, int month, int day)
 *  \brief Computes the day of year of a given date
 *  \param[in] year Date year
 *  \param[in] month Date month
 *  \param[in] day Date day
 *  \return Day of year
 */
int TimeLib_DayOfYear (int year, int month, int day)
{
    int i, leap;

    leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);

    for (i = 1; i < month; i++)
    {
        day += daytab[leap][i];
    }

    return day;
}

/** \fn void TimeLib_MonthDay (int year, int yearday, int *pmonth, int *pday)
 *  \brief Computes month and day from day of the year
 *  \param[in] year Date year
 *  \param[in] yearDay Date year day
 *  \param[in] pmonth Pointer to store month value
 *  \param[in] pday Pointer to store day value
 */
void TimeLib_MonthDay (int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);

    for (i = 1; yearday > daytab[leap][i]; i++)
    {
        yearday -= daytab[leap][i];
    }

    *pmonth = i;
    *pday = yearday;
}

/** \fn char *TimeLib_MonthName (int n)
 *  \brief Computes month name from its number
 *  \param[in] n Month number
 *  \return Pointer to the month name
 */
char *TimeLib_MonthName (int n)
{
    static char *name[] = {"Illegal month", "January", "February", "March", "April", "May", "June", "July", "August", "September",
                           "October", "November", "December"};

    return ((n < 1 || n > 12) ? name[0] : name[n]);
}