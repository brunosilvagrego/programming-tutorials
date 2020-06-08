/** \file StringLib.h */

/* 
 * File:   MathLib.h
 * Author: Bruno Grego
 * Date:   2017/01/24
 */

#ifndef _STRINGLIB_H
#define	_STRINGLIB_H

/**** System includes ****/
// #include <.h>

/** \fn int StringLib_GetCharsNum (char str[])
 *  \brief Counts the number of characters of the string passed to the function
 *  \param[in] str Character array
 *  \return Number of characters
 */
int StringLib_GetCharactersNumber (char str[]);

/** \fn int StringLib_GetSpacesNumber (char str[])
 *  \brief Counts the number of spaces of the string passed to the function
 *  \param[in] str Character array
 *  \return Number of spaces
 */
int StringLib_GetSpacesNumber (char str[]);

/** \fn int StringLib_GetWordsNumber (char str[])
 *  \brief Counts the number of words of the string passed to the function
 *  \param[in] str Character array
 *  \return Number of words
 */
int StringLib_GetWordsNumber (char str[]);

/** \fn void StringLib_StringCopy (char to[], char from[])
 *  \brief Copies the string from one array to another
 *  \param[in] to Character array to copy to
 *  \param[in] from Character array to copy from
 */
void StringLib_StringCopy (char to[], char from[]);

#endif	/* _STRINGLIB_H */