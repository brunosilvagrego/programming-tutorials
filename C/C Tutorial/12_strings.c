#include <stdio.h>
#include <string.h>

int main ()
{
    char str1[12] = "Hello ";
    char str2[12] = "World";
    char str3[12];
    int len;

    /* Copy str1 into str3 */
    strcpy(str3, str1);
    printf("strcpy(str3, str1): %s\n\n", str3);

    /* Concatenates str1 and str2 */
    strcat(str1, str2);
    printf("strcat(str1, str2): %s\n\n", str1);

    /* Total length of str1 after concatenation */
    len = strlen(str1);
    printf("strlen(str1): %d\n\n", len);

    /* Compare two strings */
    char comp1[] = "abc";
    char comp2[] = "abd";
    char comp3[] = "abe";

    printf("strcmp(%s,%s) = %d\n", comp2, comp1, strcmp(comp2, comp1));
    printf("strcmp(%s,%s) = %d\n", comp2, comp3, strcmp(comp2, comp3));
    printf("strcmp(%s,%s) = %d\n", comp2, comp2, strcmp(comp2, comp2));

    /* Finds the occurrence of a specified character in the given string */
    const char ch = 'r';
    char *p;
    p = strchr(str2, ch);
    printf("\nString starting from '%c' is: %s\n", ch, p);

    /* Finds the occurrence of a specified string in the given string */
    const char str4[] = "orl";
    char *ret;

    ret = strstr(str2, str4);

    printf("\nThe substring is: %s\n\n", ret);

    /* Breaks the string into a series of tokens using the given delimiter */
    char str5[] = "This is a Test String";
    const char delim[2] = " ";
    char *token;

    // Get the first token
    token = strtok(str5, delim);

    // Walk through other tokens
    while(token != NULL)
    {
        printf( "%s\n", token);

        token = strtok(NULL, delim);
    }

    return 0;
}
