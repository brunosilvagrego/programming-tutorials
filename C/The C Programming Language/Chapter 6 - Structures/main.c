/**** Chapter 6 - Structures ****/

/** Includes **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/** Structures and unions prototypes **/
struct point
{
    int x;
    int y;
};

struct rectangle
{
    struct point pt1;
    struct point pt2;
};

struct key
{
    char *word;
    int count;
};

union test
{
    int ival;
    float fval;
    char *sval;
};

/* Bit-field */
struct
{
    unsigned int is_keyword : 1;
    unsigned int is_extern  : 1;
    unsigned int is_static  : 1;
} flags;

/** New types definition **/
typedef char *String;

/** Functions prototypes **/
struct point MakePoint (int x, int y);
struct point AddPoint (struct point p1, struct point p2);
int PointInRectangle (struct point p, struct rectangle r);
void PrintPoint (struct point *pp);

int main()
{
    /**** Make point, add point and point in rectangle functions test ****/
    struct rectangle screen;

    screen.pt1 = MakePoint(1, 2);
    screen.pt2 = MakePoint(3, 4);

    printf("screen.pt1 = (%d, %d)\nscreen.pt2 = (%d, %d)\n", screen.pt1.x, screen.pt1.y, screen.pt2.x, screen.pt2.y);

    struct point sum = AddPoint(screen.pt1, screen.pt2);

    printf("\nsum = screen.pt1 + screen.pt2 = (%d, %d)\n", sum.x, sum.y);

    struct point ptin = MakePoint(3, 3);

    if (PointInRectangle(ptin, screen))
    {
        printf("\nPoint (%d, %d) is in rectangle {(%d, %d); (%d, %d)}\n", ptin.x, ptin.y, screen.pt1.x, screen.pt1.y,
                                                                          screen.pt2.x, screen.pt2.y);
    }
    else
    {
        printf("\nPoint (%d, %d) is not in rectangle {(%d, %d); (%d, %d)}\n", ptin.x, ptin.y, screen.pt1.x, screen.pt1.y,
                                                                          screen.pt2.x, screen.pt2.y);
    }

    if (PointInRectangle(sum, screen))
    {
        printf("Point (%d, %d) is in rectangle {(%d, %d); (%d, %d)}\n", sum.x, sum.y, screen.pt1.x, screen.pt1.y,
                                                                          screen.pt2.x, screen.pt2.y);
    }
    else
    {
        printf("Point (%d, %d) is not in rectangle {(%d, %d); (%d, %d)}\n", sum.x, sum.y, screen.pt1.x, screen.pt1.y,
                                                                          screen.pt2.x, screen.pt2.y);
    }

    printf("\nPrint Point function test.");
    PrintPoint(&ptin);

    /** sizeof operator test **/
    char *pc;
    int *pi;
    float *pf;
    double *pd;
    struct point *pp;
    struct rectangle *pr;
    struct key *pk;
    struct key myKey;
    struct key keyArray[5];

    printf("\nsizeof(char) = %d Byte\n", sizeof(char));
    printf("sizeof(char *) = %d Bytes\n", sizeof pc);

    printf("\nsizeof(int) = %d Bytes\n", sizeof(int));
    printf("sizeof(int *) = %d Bytes\n", sizeof pi);

    printf("\nsizeof(float) = %d Bytes\n", sizeof(float));
    printf("sizeof(float *) = %d Bytes\n", sizeof pf);

    printf("\nsizeof(double) = %d Bytes\n", sizeof(double));
    printf("sizeof(double *) = %d Bytes\n", sizeof pd);

    printf("\nsizeof(struct point) = %d Bytes\n", sizeof(struct point));
    printf("sizeof(point) = %d Bytes\n", sizeof sum);
    printf("sizeof(point *) = %d Bytes\n", sizeof pp);

    printf("\nsizeof(struct rectangle) = %d Bytes\n", sizeof(struct rectangle));
    printf("sizeof(rectangle) = %d Bytes\n", sizeof screen);
    printf("sizeof(rectangle *) = %d Bytes\n", sizeof pr);

    printf("\nsizeof(struct key) = %d Bytes\n", sizeof(struct key));
    printf("sizeof(key) = %d Bytes\n", sizeof myKey);
    printf("sizeof(key *) = %d Bytes\n", sizeof pk);
    printf("sizeof(keyArray[5]) = %d Bytes\n", sizeof keyArray);

    /** String type test **/
    String str1 = "Bruno Grego";
    char test[] = "I am a test string";

    printf("\nMy name is %s.\n", str1);

    printf("\nString \"%s\" occupies %d bytes.\n", test, sizeof test);

    /** Union test **/
    union test u;

    u.ival = 2;
    printf("\nu.ival = %d\n", u.ival);

    u.fval = 3.1415;
    printf("u.fval = %f\n", u.fval);

    u.sval = "Test";
    printf("u.sval = %s\n", u.sval);

    printf("u.ival = %d\n", u.ival);

    /** Bit-field test **/
    flags.is_extern = 1;
    printf("\nflag.is_extern = %d\n", flags.is_extern);

    return 0;
}

/* There is no conflict between the argument name and the member with the same name.
   Indeed the re-use of the names stresses the relationship */
struct point MakePoint (int x, int y)
{
    struct point temp;

    temp.x = x;
    temp.y = y;

    return temp;
}

/* Structure parameters are passed by value like any others */
struct point AddPoint (struct point p1, struct point p2)
{
    p1.x += p2.x;
    p1.y += p2.y;

    return p1;
}

int PointInRectangle (struct point p, struct rectangle r)
{
    return ((p.x >= r.pt1.x) && (p.x <= r.pt2.x) && (p.y >= r.pt1.y) && (p.y <= r.pt2.y));
}

void PrintPoint (struct point *pp)
{
    char option = 1;

    if (option == 1)
    {
        printf("\nPoint = (%d, %d)\n", (*pp).x, (*pp).y);
    }
    else
    {
        printf("\nPoint = (%d, %d)\n", pp->x, pp->y);
    }
}
