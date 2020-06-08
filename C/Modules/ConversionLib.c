/**** System includes ****/
#include <stdio.h>

/**** Modules includes ****/
#include "ConversionLib.h"
#include "StringLib.h"

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

/** \fn int ConversionsLib_AsciiToIntegerSigned (char str[])
 *  \brief Converts a string in ASCII code to integer, skips spaces and cosiders the sign
 *  \param[in] str Character array
 *  \return Integer number
 */
int ConversionsLib_AsciiToIntegerSigned (char str[])
{
    int i, n, sign;

    for (i = 0; str[i] == ' '; i++);    /* Skip spaces */

    sign = (str[i] == '-') ? -1 : 1;    /* Get sign */

    if (str[i] == '-' || str[i] == '+')     /* Skip sign */
    {
        i++;
    }

    for (n = 0; str[i] >= '0' && str[i] <= '9'; i++)
    {
        n = 10 * n + (str[i] - '0');
    }

    return sign * n;
}

/** \fn double ConversionLib_AsciiToDouble (char str[])
 *  \brief Converts a string in ASCII code to float, skips spaces and cosiders the sign
 *  \param[in] str Character array
 *  \return Float number
 */
double ConversionLib_AsciiToDouble (char str[])
{
    double val, power;
    int i, sign;

    for (i = 0; str[i] == ' '; i++);    /* Skip white space */

    sign = (str[i] == '-') ? -1 : 1;

    if (str[i] == '+' || str[i] == '-')
    {
        i++;
    }

    for (val = 0.0; str[i] >= '0' && str[i] <= '9'; i++)
    {
        val = 10.0 * val + (str[i] - '0');
    }

    if (str[i] == '.')
    {
        i++;
    }

    for (power = 1.0; str[i] >= '0' && str[i] <= '9'; i++)
    {
        val = 10.0 * val + (str[i] - '0');
        power *= 10;
    }

    return (sign * val / power);
}

/** \fn void ConversionLib_IntegerToAscii (int n, char str[])
 *  \brief Converts an integer number to ASCII code, cosidering the sign
 *  \param[in] n Number to convert
 *  \param[in] str Character array to store the conversion
 */
void ConversionLib_IntegerToAscii (int n, char str[])
{
    int i, sign;

    if ((sign = n) < 0) /* Record sign */
    {
        n = -n;         /* Make n positive */
    }

    i = 0;

    do                          /* Generate digits in reverse order */
    {
        str[i++] = n % 10 + '0';  /* Get next digit */
    }
    while ((n /= 10) > 0);      /* Delete it */

    if (sign < 0)
    {
        str[i++] = '-';
    }

    str[i] = 0;

    StringLib_StringReverse(str);
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