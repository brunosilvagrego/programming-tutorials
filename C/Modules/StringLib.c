/**** System includes ****/
#include <stdio.h>

/**** Modules includes ****/
#include "StringLib.h"

/** Defines **/
#define IN  0
#define OUT 1

/**** Private and public functions code ****/

/** \fn int StringLib_GetCharsNum (char str[])
 *  \brief Counts the number of characters of the string passed to the function
 *  \param[in] str Character array
 *  \return Number of characters
 */
int StringLib_GetCharactersNumber (char str[])
{
    int i = 0;
    int count = 0;

    while (str[i] != 0)
    {
        if (str[i] >= ' ' && str[i] <= '~')
        {
            count++;
        }
        i++;
    }

    return count;
}

/** \fn int StringLib_GetSpacesNumber (char str[])
 *  \brief Counts the number of spaces of the string passed to the function
 *  \param[in] str Character array
 *  \return Number of spaces
 */
int StringLib_GetSpacesNumber (char str[])
{
    int i = 0;
    int count = 0;

    while (str[i] != 0)
    {
        if (str[i] == ' ')
        {
            count++;
        }
        i++;
    }

    return count;
}

/** \fn int StringLib_GetWordsNumber (char str[])
 *  \brief Counts the number of words of the string passed to the function
 *  \param[in] str Character array
 *  \return Number of words
 */
int StringLib_GetWordsNumber (char str[])
{
    int i = 0;
    int count = 0;
    char state = OUT;

    while (str[i] != 0)
    {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
        {
            state = OUT;
        }
        else if (state == OUT)
        {
            state = IN;
            count++;
        }
        i++;
    }

    return count;
}

/** \fn void StringLib_StringCopy (char to[], char from[])
 *  \brief Copies the string from one array to another
 *  \param[in] to Character array to copy to
 *  \param[in] from Character array to copy from
 */
void StringLib_StringCopy (char to[], char from[])
{
    int i = 0;

    while ((to[i] = from[i]) != 0)
    {
        i++;
    }
}

/** \fn void StringLib_StringScan (char str[], int maxLength)
 *  \brief Scans a string from the console, resumes when the user press enter ('\n')
 *  \param[in] str Character array to store the string
 *  \param[in] maxLength String maximum admissible length
 */
void StringLib_StringScan (char str[], int maxLength)
{
    char cond = 1;
    char c;
    int i = 0;

    while (i < maxLength && cond)
    {
        c = getchar();

        if (c >= ' ' && c <= '~')   /* See ASCII table */
        {
            str[i] = c;
            i++;
        }

        if (c == '\n')
        {
            str[i] = 0;
            i++;
            cond = 0;
        }
    }
}

/** \fn void StringLib_StringSqueeze (char str[], char c)
 *  \brief Removes any occurrence of character c from the string str
 *  \param[in] str Character array
 *  \param[in] c Character to be removed
 */
void StringLib_StringSqueezeCharacter (char str[], char c)
{
    int i, j;

    for (i = j = 0; str[i] != 0; i++)
    {
        /* Each time a non-c occurs, it is copied into the current j position, and only then j is incremented */
        if (str[i] != c)
        {
            str[j++] = str[i];
        }
    }

    str[j] = 0;
}

/** \fn void StringLib_StringSqueezeString (char str1[], char str2[])
 *  \brief Removes any occurrence of string str2 characters from the string str1
 *  \param[in] str1 Character array to remove charactes from
 *  \param[in] str2 Character array that contais the characters to be removed
 */
void StringLib_StringSqueezeString (char str1[], char str2[])
{
	int i;
	int j;
	int k = 0;

    for (i = 0; str1[i] != '\0'; i++)
    {
        for (j = 0; (str1[i] != str2[j]) && str2[j] != '\0' ; j++);
		
        if (str2[j] == '\0')
		{
            str1[k++] = str1[i];
		}
    }
    
    str1[k] = '\0';
}

/** \fn void StringLib_StringConcatenate (char dest[], char str1[], char str2[])
 *  \brief Concatenates strings str1 and str2
 *  \param[in] dest Character array to store the result
 *  \param[in] str1 First string concatenated
 *  \param[in] str2 Second string concatenated
 */
void StringLib_StringConcatenate (char dest[], char str1[], char str2[])
{
    int i, j;

    i = j = 0;

    /* Copy str1 */
    while ((dest[i++] =  str1[j++]) != 0);

    /* Copy str2 */
    j = 0;
    while (str2[j] != 0)
    {
        dest[i] = str2[j];
        i++;
        j++;
    }
}

/** \fn int StringLib_StringLength (char str[])
 *  \brief Computes the length of the string passed as argument
 *  \param[in] str Character array
 *  \return String length
 */
int StringLib_StringLength (char str[])
{
    int i = 0;

    while (str[i] != 0)
    {
        i++;
    }

    return i;
}

/** \fn void StringLib_StringStatistics (char str[], int stats[])
 *  \brief Checks the string statistics (spaces, digits, letters)
 *  \param[in] str Character array
 *  \param[in] stats Array to store the statistics
 */
void StringLib_StringStatistics (char str[], int stats[])
{
    char c;
    int i, nSpaces, nDigits, nLetters;

    i = nSpaces = nDigits = nLetters = 0;

    while ((c = str[i]) != 0)
    {
        switch (c)
        {
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
                nDigits++;
                break;
            case ' ':
                nSpaces++;
                break;
            default:
                nLetters++;
                break;
        }
        i++;
    }

    stats[0] = nSpaces;
    stats[1] = nDigits;
    stats[2] = nLetters;
}

/** \fn void StringLib_StringReverse (char str[])
 *  \brief Reverses the order of the string characters
 *  \param[in] str Character array
 */
void StringLib_StringReverse (char str[])
{
    int c, i, j;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--)
    {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
    }
}