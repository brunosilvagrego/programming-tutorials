/** \file StringLib.h */

/* 
 * File:   StringLib.h
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

/** \fn void StringLib_StringScan (char str[], int maxLength)
 *  \brief Scans a string from the console, resumes when the user press enter ('\n')
 *  \param[in] str Character array to store the string
 *  \param[in] maxLength String maximum admissible length
 */
void StringLib_StringScan (char str[], int maxLength);

/** \fn void StringLib_StringSqueeze (char str[], char c)
 *  \brief Removes any occurrence of character c from the string str
 *  \param[in] str Character array
 *  \param[in] c Character to be removed
 */
void StringLib_StringSqueezeCharacter (char str[], char c);

/** \fn void StringLib_StringSqueezeString (char str1[], char str2[])
 *  \brief Removes any occurrence of string str2 characters from the string str1
 *  \param[in] str1 Character array to remove charactes from
 *  \param[in] str2 Character array that contais the characters to be removed
 */
void StringLib_StringSqueezeString (char str1[], char str2[]);

/** \fn void StringLib_StringConcatenate (char dest[], char str1[], char str2[])
 *  \brief Concatenates strings str1 and str2
 *  \param[in] dest Character array to store the result
 *  \param[in] str1 First string concatenated
 *  \param[in] str2 Second string concatenated
 */
void StringLib_StringConcatenate (char dest[], char str1[], char str2[]);

/** \fn int StringLib_StringLength (char str[])
 *  \brief Computes the length of the string passed as argument
 *  \param[in] str Character array
 *  \return String length
 */
int StringLib_StringLength (char str[]);

/** \fn void StringLib_StringStatistics (char str[], int stats[])
 *  \brief Checks the string statistics (spaces, digits, letters)
 *  \param[in] str Character array
 *  \param[in] stats Array to store the statistics
 */
void StringLib_StringStatistics (char str[], int stats[]);

/** \fn void StringLib_StringReverse (char str[])
 *  \brief Reverses the order of the string characters
 *  \param[in] str Character array
 */
void StringLib_StringReverse (char str[]);

#endif	/* _STRINGLIB_H */