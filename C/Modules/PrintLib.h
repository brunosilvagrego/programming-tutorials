/** \file PrintLib.h */

/* 
 * File:   PrintLib.h
 * Author: Bruno Grego
 * Date:   2017/02/09
 */

#ifndef _PRINTLIB_H
#define	_PRINTLIB_H

/**** System includes ****/
// #include <.h>

/** \fn void PrintLib_PrintVector (int v[], int vectorLength)
 *  \brief Print an integer array, in the same line, separed by commas and between brackets
 *  \param[in] v Numbers array
 *  \param[in] vectorLength Array size
 */
void PrintLib_PrintVector (int v[], int vectorLength);

/** \fn void PrintLib_PrintDecimal (int n)
 *  \brief Print a decimal number
 *  \param[in] v Numbers array
 */
void PrintLib_PrintDecimal (int n);

#endif	/* _PRINTLIB_H */
