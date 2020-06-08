/**** System includes ****/
//#include <stdio.h>

/**** Modules includes ****/
#include "BitLib.h"

/**** Private and public functions code ****/

/** \fn unsigned int BitLib_BitsGet (unsigned int x, int p, int n)
 *  \brief Get n bits from position p
 *  \param[in] x Number to get bits from
 *  \param[in] p Binary position to start getting bits
 *  \param[in] n Number of bits to get
 *  \return Bits from position p
 */
unsigned int BitLib_BitsGet (unsigned int x, int p, int n)
{
    return (x >> (p + 1 - n)) & ~(~0 << n);
}

/** \fn unsigned int BitLib_BitsSet (unsigned int x, int p, int n, unsigned int y)
 *  \brief returns x with the n bits that begin at position p set to the rightmost n bits of y, leaving the other bits unchanged
 *  \param[in] x Number to set bits
 *  \param[in] p Binary position to start setting bits
 *  \param[in] n Number rightmost bits of y
 *  \param[in] y Number that contain bits to set
 *  \return x with bits set
 */
unsigned int BitLib_BitsSet (unsigned int x, int p, int n, unsigned int y)
{
    return x & ~(~(~0 << n) << (p + 1 - n)) | (y & ~(~0 << n)) << (p + 1 - n);
}

/** \fn unsigned int BitLib_BitsSetInverted (unsigned int x, int p, int n)
 *  \brief returns x with the n bits that begin at position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged
 *  \param[in] x Number to set bits
 *  \param[in] p Binary position to start setting bits
 *  \param[in] n Number rightmost bits to set inverted
 *  \return x with bits set inverted
 */
unsigned int BitLib_BitsSetInverted (unsigned int x, int p, int n)
{
     return   x ^ (~(~0 << n) << (p + 1 - n));
}

/** \fn int BitLib_BitsCount (unsigned int x)
 *  \brief Count occurrences of 1-bit of number x
 *  \param[in] x Number to get bits from
 *  \return 1-bit number
 */
int BitLib_BitsCount (unsigned int x)
{
    int b;

    for (b = 0; x != 0; x >>= 1)
    {
        if (x & 0x01)
        {
            b++;
        }
    }

    return b;
}