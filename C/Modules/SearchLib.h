/** \file SearchLib.h */

/* 
 * File:   SearchLib.h
 * Author: Bruno Grego
 * Date:   2017/02/09
 */

#ifndef _SEARCHLIB_H
#define	_SEARCHLIB_H

/**** System includes ****/
// #include <.h>

/** \fn int SearchLib_BinarySearch (int x, int v[], int n)
 *  \brief Search for a number in a sorted array
 *  \param[in] x Number to search
 *  \param[in] v Numbers array
 *  \param[in] n Array size
 *  \return Position (offset) of the number in the array, or -1 if not found
 */
int SearchLib_BinarySearch (int x, int v[], int n);

#endif	/* _SEARCHLIB_H */
