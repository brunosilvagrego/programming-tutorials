/** \file TimeLib.h */

/* 
 * File:   TimeLib.h
 * Author: Bruno Grego
 * Date:   2017/01/31
 */

#ifndef _TIMELIB_H
#define	_TIMELIB_H

/**** System includes ****/
// #include <.h>

/** \fn char TimeLib_YearIsLeap (int year)
 *  \brief Checks if the year passed as argument is a leap year or not
 *  \param[in] year Year to check
 *  \return 0 if it is a leap year, 1 otherwise
 */
char TimeLib_YearIsLeap (int year);

/** \fn int TimeLib_DayOfYear (int year, int month, int day)
 *  \brief Computes the day of year of a given date
 *  \param[in] year Date year
 *  \param[in] month Date month
 *  \param[in] day Date day
 *  \return Day of year
 */
int TimeLib_DayOfYear (int year, int month, int day);

/** \fn void TimeLib_MonthDay (int year, int yearday, int *pmonth, int *pday)
 *  \brief Computes month and day from day of the year
 *  \param[in] year Date year
 *  \param[in] yearDay Date year day
 *  \param[in] pmonth Pointer to store month value
 *  \param[in] pday Pointer to store day value
 */
void TimeLib_MonthDay (int year, int yearday, int *pmonth, int *pday);

/** \fn char *TimeLib_MonthName (int n)
 *  \brief Computes month name from its number
 *  \param[in] n Month number
 *  \return Pointer to the month name
 */
char *TimeLib_MonthName (int n);

#endif	/* _TIMELIB_H */