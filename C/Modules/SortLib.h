/** \file SortLib.h */

/* 
 * File:   SortLib.h
 * Author: Bruno Grego
 * Date:   2017/02/09
 */

#ifndef _SORTLIB_H
#define	_SORTLIB_H

/**** System includes ****/
// #include <.h>

/** \fn void SortLib_ShellSort (int v[], int n)
 *  \brief Sort an array in ascending order
 *  \param[in] v Numbers array
 *  \param[in] n Array size
 */
void SortLib_ShellSort (int v[], int n);

/** \fn void SortLib_QuickSortInt (int v[], int left, int right)
 *  \brief Sort an array in ascending order
 *  \param[in] v Numbers array
 *  \param[in] left First position of the array
 *  \param[in] right Last position of the array
 */
void SortLib_QuickSortInt (int v[], int left, int right);

/** \fn void SortLib_QuickSortString (char *v[], int left, int right)
 *  \brief Sort an array of strings
 *  \param[in] v Strings array
 *  \param[in] left First position of the array
 *  \param[in] right Last position of the array
 */
void SortLib_QuickSortString (char *v[], int left, int right);

#endif	/* _SORTLIB_H */
