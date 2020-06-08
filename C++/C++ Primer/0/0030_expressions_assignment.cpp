#include <iostream>

using namespace std;

int main()
{
    int i; double d;

    d = i = 3.5;
    cout << i << " " << d << endl;  // prints 3 3

    i = d = 3.5;
    cout << i << " " << d << endl;  // prints 3 3.5
    
    1024 = k;   // error: literals are rvalues
    i + j = k;  // error: arithmetic expressions are rvalues
    ci = k;     // error: ci is a const (nonmodifiable) lvalue
    
    k = 0;                      // result: type int, value 0
    k = 3.14159;                // result: type int, value 3
    k = {3.14};                 // error: narrowing conversion
    vector<int> vi;             // initially empty
    vi = {0,1,2,3,4,5,6,7,8,9}; // vi now has ten elements, values 0 through 9
    
    int ival, jval;
    ival = jval = 0;    // ok: each assigned 0
    int ival, *pval;    // ival is an int; pval is a pointer to int
    ival = pval = 0;    // error: cannot assign the value of a pointer to an int

    string s1, s2;
    s1 = s2 = "OK";     // string literal "OK" converted to string

	return 0;
}