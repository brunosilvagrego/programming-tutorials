/**** System includes ****/
// #include <.h>

/**** Modules includes ****/
#include "MathLib.h"

/**** Private and public functions code ****/

/** \fn int MathLib_Power(int base, int n)
 *  \brief Computes base^n
 *  \param[in] base Base value
 *  \param[in] n Power value
 *  \return Result value
 */
int MathLib_Power(int base, int n)
{
    int i;
	int p = 1;

    for (i = 1; i <= n; i++)
    {
        p = p * base;
    }

    return p;
}