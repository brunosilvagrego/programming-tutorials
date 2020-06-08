#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;


int main ()
{
    // Number definition
    int    i  = -1000;
    float  f  = 230.5;
    double d  = 45.7;
    double d2 = -3.1415;

    /* Mathematical operations */
    printf("cos(%.2f) = %.2f\n", d, cos(d));
    printf("sin(%.2f) = %.2f\n", d, sin(d));
    printf("tan(%.2f) = %.2f\n", d, tan(d));
    printf("log(%.2f) = %.2f\n", d, log(d));
    printf("pow(%.2f, 2) = %.2f\n", d, pow(d, 2));
    printf("hypot(%.2f, %.2f) = %.2f\n", f, d, hypot(f, d));
    printf("sqrt(%.2f) = %.2f\n", d, sqrt(d));
    printf("abs(%d) = %d\n", i, abs(i));
    printf("fabs(%.2f) = %.2f\n", d2, fabs(d2));
    printf("floor(%.2f) = %.2f\n\n", d, floor(d));

    /* Random numbers */
    // Set the seed
    srand((unsigned)time(NULL));

    // Generate 10 random numbers
    for(int j = 0; j < 10; j++)
    {
        cout << "rand() = " << rand() << endl;
    }

    return 0;
}
