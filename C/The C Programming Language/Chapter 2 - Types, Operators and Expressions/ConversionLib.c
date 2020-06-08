/**** System includes ****/
#include <stdio.h>

/**** Modules includes ****/
#include "ConversionLib.h"

/**** Defines ****/
#define	TRUE	0
#define FALSE	1

/**** Private and public functions code ****/

/** \fn int ConversionsLib_AsciiToInteger (char str[])
 *  \brief Converts a string in ASCII code to integer
 *  \param[in] str Character array
 *  \return Integer number
 */
int ConversionsLib_AsciiToInteger (char str[])
{
    int i = 0;
    int n = 0;

    while (str[i] >= '0' && str[i] <= '9')
    {
        n = 10 * n + (str[i] - '0');
        i++;
    }

    return n;
}

/** \fn int ConversionsLib_HexadecimalToInteger (char str[])
 *  \brief converts a string of hexadecimal digits (including an optional 0x or 0X) into its equivalent integer value.
 *  \brief The allowable digits are 0 through 9, a through f,and A through F.
 *  \param[in] str Character array
 *  \return Integer number
 */
int ConversionsLib_HexadecimalToInteger (char str[])
{
	int i = 0;
    int n = 0;
	int hexdigit = 0;
	int hex = TRUE;
	
	if ((str[0] == '0') && (str[1] == 'x' || str[1] == 'X'))
	{
		i = 2;
	}
	
    while (hex == TRUE)
    {
        if (str[i] >= '0' && str[i] <= '9')
		{
            hexdigit = str[i] - '0';
		}
        else if (str[i] >= 'a' && str[i] <= 'f')
		{
            hexdigit = str[i] - 'a' + 10;
		}
        else if (str[i] >= 'A' && str[i] <= 'F')
		{
            hexdigit = str[i] - 'A' + 10;
		}
        else
		{
            hex = FALSE;
		}
        
        if(hex == TRUE)
		{
			n = 16 * n + hexdigit;
			i++;
		}
    }

    return n;
}