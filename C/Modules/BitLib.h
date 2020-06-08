/** \file BitLib.h */

/* 
 * File:   BitLib.h
 * Author: Bruno Grego
 * Date:   2017/01/31
 */

#ifndef _BITLIB_H
#define	_BITLIB_H

/**** System includes ****/
// #include <.h>

/** \fn unsigned int BitLib_BitsGet (unsigned int x, int p, int n)
 *  \brief Get n bits from position p
 *  \param[in] x Number to get bits from
 *  \param[in] p Binary position to start getting bits
 *  \param[in] n Number of bits to get
 *  \return Bits from position p
 */
unsigned int BitLib_BitsGet (unsigned int x, int p, int n);

/** \fn unsigned int BitLib_BitsSet (unsigned int x, int p, int n, unsigned int y)
 *  \brief returns x with the n bits that begin at position p set to the rightmost n bits of y, leaving the other bits unchanged
 *  \param[in] x Number to set bits
 *  \param[in] p Binary position to start setting bits
 *  \param[in] n Number rightmost bits of y
 *  \param[in] y Number that contain bits to set
 *  \return x with bits set
 */
unsigned int BitLib_BitsSet (unsigned int x, int p, int n, unsigned int y);

/** \fn unsigned int BitLib_BitsSetInverted (unsigned int x, int p, int n)
 *  \brief returns x with the n bits that begin at position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged
 *  \param[in] x Number to set bits
 *  \param[in] p Binary position to start setting bits
 *  \param[in] n Number rightmost bits to set inverted
 *  \return x with bits set inverted
 */
unsigned int BitLib_BitsSetInverted (unsigned int x, int p, int n);

/** \fn int BitLib_BitsCount (unsigned int x)
 *  \brief Count occurrences of 1-bit of number x
 *  \param[in] x Number to get bits from
 *  \return 1-bit number
 */
int BitLib_BitsCount (unsigned int x);

#endif	/* _BITLIB_H */