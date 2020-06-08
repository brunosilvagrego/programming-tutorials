/**** System includes ****/
// #include <.h>

/**** Modules includes ****/
#include "SearchLib.h"

/**** Private and public functions code ****/

/** \fn int SearchLib_BinarySearch (int x, int v[], int n)
 *  \brief Search for a number in a sorted array
 *  \param[in] x Number to search
 *  \param[in] v Numbers array
 *  \param[in] n Array size
 *  \return Position (offset) of the number in the array, or -1 if not found
 */
int SearchLib_BinarySearch (int x, int v[], int n)
{
    int low, high, mid, i, pos;

    low = 0;
    high = n - 1;
    mid = 0;
    i = 0;
    pos = -1;

    while (low <= high && i < n)
    {
        mid = (low + high) / 2;

        if (x == v[mid])
        {
            pos = mid;
            i = n;
        }
        else if (x < v[mid])
        {
            high = mid + 1;
        }
        else if (x > v[mid])
        {
            low = mid + 1;
        }

        i++;
    }

    return pos;
}