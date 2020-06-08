#include <iostream>
#include <iomanip>

using namespace std;
//using std::setw;

int main ()
{
    // n is an array of 10 integers
    int n[10];
    int i;

    // Initialize elements of array n to 0
    for (i = 0; i < 10; i++)
    {
        n[i] = i + 100; // set element at location i to i + 100
    }

    // Output each array element's value
    cout << "Element" << setw( 13 ) << "Value" << endl;

    for (i = 0; i < 10; i++)
    {
        cout << setw(7) << i << setw(13) << n[i] << endl;
    }

    return 0;
}
