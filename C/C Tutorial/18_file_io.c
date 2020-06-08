#include <stdio.h>

int main ()
{
    int i;
    char buff[255];
    FILE *fp;

    /* Write to file */
    fp = fopen("C:\\Users\\bruno\\Desktop\\C_Sandbox\\test.txt", "w+");

    fprintf(fp, "fprintf() Test\n");
    fputs("fputs() Test\n", fp);

    fclose(fp);

    /* Read from file */
    fp = fopen("C:\\Users\\bruno\\Desktop\\C_Sandbox\\test.txt", "r");

    fscanf(fp, "%s", buff);
    printf("1: %s\n\n", buff);

    fgets(buff, 255, (FILE*)fp);
    printf("2: %s\n", buff);

    fgets(buff, 255, (FILE*)fp);
    printf("3: %s\n", buff );

    fclose(fp);

    /* Append to file */
    fp = fopen("C:\\Users\\bruno\\Desktop\\C_Sandbox\\test.txt", "a");

    fputs("\nAuthor:\nBruno Grego\n", fp);

    fclose(fp);

    /* Read all lines from the file */
    fp = fopen("C:\\Users\\bruno\\Desktop\\C_Sandbox\\test.txt", "r");

    i = 1;

    while (fgets(buff, 255, (FILE*)fp) != NULL)
    {
        printf("Line %i: %s\n", i, buff);
        i++;
    }

    fclose(fp);


    return 0;
}
