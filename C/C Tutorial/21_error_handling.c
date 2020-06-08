#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

extern int errno;


int main ()
{
    FILE * pf;
    int errnum;
    pf = fopen ("unexist.txt", "rb");

    if (pf == NULL)
    {
        errnum = errno;
        fprintf(stderr, "Value of errno: %d\n", errno);

        /* perror() */
        perror("Error printed by perror");

        /* strerror() */
        fprintf(stderr, "Error opening file: %s\n", strerror(errnum));
    }
    else
    {
        fclose (pf);
    }

    /* Division by 0 */
    int dividend = 20;
    int divisor = 0;
    int quotient;

    if( divisor == 0)
    {
        fprintf(stderr, "\nDivision by zero! Exiting...\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        quotient = dividend / divisor;
        fprintf(stderr, "Value of quotient : %d\n", quotient );

        exit(EXIT_SUCCESS);
    }


    return 0;
}
