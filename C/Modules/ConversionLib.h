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

/** \fn int ConversionsLib_AsciiToIntegerSigned (char str[])
 *  \brief Converts a string in ASCII code to integer, skips spaces and cosiders the sign
 *  \param[in] str Character array
 *  \return Integer number
 */
int ConversionsLib_AsciiToIntegerSigned (char str[]);

/** \fn double ConversionLib_AsciiToDouble (char str[])
 *  \brief Converts a string in ASCII code to float, skips spaces and cosiders the sign
 *  \param[in] str Character array
 *  \return Float number
 */
double ConversionLib_AsciiToDouble (char str[]);

/** \fn void ConversionLib_IntegerToAscii (int n, char str[])
 *  \brief Converts an integer number to ASCII code, cosidering the sign
 *  \param[in] n Number to convert
 *  \param[in] str Character array to store the conversion
 */
void ConversionLib_IntegerToAscii (int n, char str[]);

/** \fn int ConversionsLib_HexadecimalToInteger (char str[])
 *  \brief converts a string of hexadecimal digits (including an optional 0x or 0X) into its equivalent integer value.
 *  \brief The allowable digits are 0 through 9, a through f,and A through F.
 *  \param[in] str Character array
 *  \return Integer number
 */
int ConversionsLib_HexadecimalToInteger (char str[]);

#endif	/* _CONVERSIONLIB_H */