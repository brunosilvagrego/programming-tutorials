/**** System includes ****/
// #include <.h>

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
