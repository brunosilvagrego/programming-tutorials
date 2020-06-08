/**** System includes ****/
#include <stdio.h>

/**** Modules includes ****/
#include "PrintLib.h"

/**** Private and public functions code ****/

/** \fn void PrintLib_PrintVector (int v[], int vectorLength)
 *  \brief Print an integer array, in the same line, separed by commas and between brackets
 *  \param[in] v Numbers array
 *  \param[in] vectorLength Array size
 */
void PrintLib_PrintVector (int v[], int vectorLength)
{
    int i;

    for (i = 0; i < vectorLength; i++)
    {
        if (i == 0)
        {
            printf("[%d, ", v[i]);
        }
        else if (i == (vectorLength - 1))
        {
            printf("%d]", v[i]);
        }
        else
        {
            printf("%d, ", v[i]);
        }
    }
}

/** \fn void PrintLib_PrintDecimal (int n)
 *  \brief Print a decimal number
 *  \param[in] v Numbers array
 */
void PrintLib_PrintDecimal (int n)
{
    if (n < 0)
    {
        putchar('-');
        n = -n;
    }

    if (n / 10)
    {
        PrintLib_PrintDecimal(n/10);
    }

    putchar(n % 10 + '0');
}
