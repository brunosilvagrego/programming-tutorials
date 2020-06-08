#include <iostream>

using namespace std;


void swap (int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int sum (int a, int b = 20)
{
    return (a + b);
}


int main ()
{
    // Local variable declaration:
    int a = 100;
    int b = 200;
    int result;

    cout << "Before swap, value of a :" << a << endl;
    cout << "Before swap, value of b :" << b << "\n" << endl;

    /* Calling a function to swap the values using variable reference */
    swap(a, b);

    cout << "After swap, value of a :" << a << endl;
    cout << "After swap, value of b :" << b << "\n" << endl;

    /* Calling sum() with two parameters */
    result = sum(a, b);
    cout << "sum(a, b) = " << result << "\n" << endl;

    /* Calling sum() with the default parameter */
    result = sum(a);
    cout << "sum(a) = " << result << endl;

    return 0;
}
