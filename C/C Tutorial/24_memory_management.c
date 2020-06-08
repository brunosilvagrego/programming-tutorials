#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char name[100];
    char *description;

    strcpy(name, "Bruno Grego");

    /* Allocate memory dynamically */
    description = malloc(30 * sizeof(char));
    // description = calloc(30, sizeof(char)); => Equivalent alocation using calloc()

    if(description == NULL)
    {
        fprintf(stderr, "Error - unable to allocate the required memory\n");
    }
    else
    {
        strcpy(description, "Embedded Software Engineer");
    }

    printf("Name:  %s\n", name);
    printf("Title: %s\n\n", description);

    /* Reallocate memory dynamically */
    description = realloc(description, 100*sizeof(char));

    if (description == NULL)
    {
        fprintf(stderr, "Error - unable to allocate the required memory\n");
    }
    else
    {
        strcat(description, " | C/C++ Developer");
    }

    printf("Name:  %s\n", name);
    printf("Title: %s\n", description);

    /* Release memory using free() function */
    free(description);


    return 0;
}
