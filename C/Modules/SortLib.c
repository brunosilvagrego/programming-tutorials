/**** System includes ****/
#include <string.h>

/**** Modules includes ****/
#include "SortLib.h"

/**** Private functions ****/

/** \fn static void SortLib_SwapInt (int v[], int i, int j)
 *  \brief Swap 2 members of an array
 *  \param[in] v Numbers array
 *  \param[in] i Position of the first member to swap
 *  \param[in] j Position of the second member to swap
 */
static void SortLib_SwapInt (int v[], int i, int j);

/** \fn static void SortLib_SwapString (char *v[], int i, int j)
 *  \brief Swap 2 members of an array
 *  \param[in] v String array
 *  \param[in] i Position of the first member to swap
 *  \param[in] j Position of the second member to swap
 */
static void SortLib_SwapString (char *v[], int i, int j);

/**** Private and public functions code ****/

/** \fn void SortLib_ShellSort (int v[], int n)
 *  \brief Sort an array in ascending order
 *  \param[in] v Numbers array
 *  \param[in] n Array size
 */
void SortLib_ShellSort (int v[], int n)
{
    int gap, i, j, temp;

    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap)
            {
                temp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = temp;
            }
        }
    }
}

/** \fn void SortLib_QuickSortInt (int v[], int left, int right)
 *  \brief Sort an array in ascending order
 *  \param[in] v Numbers array
 *  \param[in] left First position of the array
 *  \param[in] right Last position of the array
 */
void SortLib_QuickSortInt (int v[], int left, int right)
{
    int i, last;

    if (left >= right)  /* Do nothing if array contains fewer than two elements */
    {
        return;
    }

    swap(v, left, (left + right) / 2);  /* Move partition element to v[0] partition */
    last = left;

    for (i = left + 1; i <= right; i++)
    {
        if (v[i] < v[left])
        {
            swap(v, ++last, i);
        }
    }

    swap(v, left, last);    /* Restore partition element */

    QuickSort(v, left, last - 1);
    QuickSort(v, last + 1, right);
}

/** \fn static void SortLib_SwapInt (int v[], int i, int j)
 *  \brief Swap 2 members of an array
 *  \param[in] v Numbers array
 *  \param[in] i Position of the first member to swap
 *  \param[in] j Position of the second member to swap
 */
static void SortLib_SwapInt (int v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/** \fn void SortLib_QuickSortString (char *v[], int left, int right)
 *  \brief Sort an array of strings
 *  \param[in] v Strings array
 *  \param[in] left First position of the array
 *  \param[in] right Last position of the array
 */
void SortLib_QuickSortString (char *v[], int left, int right)
{
    int i, last;

    if (left >= right)  /* Do nothing if array contains fewer than two elements */
    {
        return;
    }

    swap(v, left, (left + right)/2);

    last = left;

    for (i = left+1; i <= right; i++)
    {
        if (strcmp(v[i], v[left]) < 0)
        {
            swap(v, ++last, i);
        }
    }

    swap(v, left, last);

    QuickSortStr(v, left, last-1);

    QuickSortStr(v, last+1, right);
}

/** \fn static void SortLib_SwapString (char *v[], int i, int j)
 *  \brief Swap 2 members of an array
 *  \param[in] v String array
 *  \param[in] i Position of the first member to swap
 *  \param[in] j Position of the second member to swap
 */
static void SortLib_SwapString (char *v[], int i, int j)
{
    char *temp;     /* Since any individual element of v is a character pointer, temp must be also a character pointer */

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}