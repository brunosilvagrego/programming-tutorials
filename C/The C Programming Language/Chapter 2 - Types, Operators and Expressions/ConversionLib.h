/** \file ConversionLib.h */

/* 
 * File:   ConversionLib.h
 * Author: Bruno Grego
 * Date:   2017/01/31
 */

#ifndef _CONVERSIONLIB_H
#define	_CONVERSIONLIB_H

/**** System includes ****/
// #include <.h>

/** \fn int ConversionsLib_AsciiToInteger (char str[])
 *  \brief Converts a string in ASCII code to integer
 *  \param[in] str Character array
 *  \return Integer number
 */
int ConversionsLib_AsciiToInteger (char str[]);

/** \fn int ConversionsLib_HexadecimalToInteger (char str[])
 *  \brief converts a string of hexadecimal digits (including an optional 0x or 0X) into its equivalent integer value.
 *  \brief The allowable digits are 0 through 9, a through f,and A through F.
 *  \param[in] str Character array
 *  \return Integer number
 */
int ConversionsLib_HexadecimalToInteger (char str[]);

#endif	/* _CONVERSIONLIB_H */