#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <stdexcept>

using namespace std;


// factorial of val is val * (val - 1) * (val - 2) . . . * ((val - (val - 1)) * 1)
int fact(int val)
{
    int ret = 1;        // local variable to hold the result as we calculate it

    while (val > 1)
    {
        ret *= val--;   // assign ret * val to ret and decrement val
    }
    
    return ret;         // return the result
}

int main()
{
    int j = fact(5);    // j equals 120, i.e., the result of fact(5)
    cout << "5! is " << j << endl;

    fact("hello");      // error: wrong argument type
    fact();             // error: too few arguments
    fact(42, 10, 0);    // error: too many arguments
    fact(3.14);         // ok: argument is converted to int

    void f1(){ /* ... */ }      // implicit void parameter list
    void f2(void){ /* ... */ }  // explicit void parameter list

    int f3(int v1, v2) { /* ... */ }        // error: even when the types of two parameters are the same, the type must be repeated
    int f4(int v1, int v2) { /* ... */ }    // ok

	return 0;
}