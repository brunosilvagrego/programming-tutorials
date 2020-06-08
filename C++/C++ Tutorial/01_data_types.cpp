#include <iostream>

using namespace std;


// Type qualifiers:
//      const    - Objects of type const cannot be changed by the program during execution.
//
//      volatile - It tells the compiler that a variable's value may be changed in ways not explicitly
//                 specified by the program.
//
//      restrict - It is initially the only means by which the object it points to can be accessed.
//                 Only C99 adds a new type qualifier called restrict.


int main()
{
    /* Basic Data Types */
    cout << "sizeof(bool)                   = " << sizeof(bool) << endl;
    cout << "sizeof(char)                   = " << sizeof(char) << endl;
    cout << "sizeof(unsigned char)          = " << sizeof(unsigned char) << endl;
    cout << "sizeof(signed char)            = " << sizeof(signed char) << endl;
    cout << "sizeof(int)                    = " << sizeof(int) << endl;
    cout << "sizeof(unsigned int)           = " << sizeof(unsigned int) << endl;
    cout << "sizeof(signed int)             = " << sizeof(signed int) << endl;
    cout << "sizeof(short int)              = " << sizeof(short int) << endl;
    cout << "sizeof(unsigned short int)     = " << sizeof(unsigned short int) << endl;
    cout << "sizeof(signed short int)       = " << sizeof(signed short int) << endl;
    cout << "sizeof(long int)               = " << sizeof(long int) << endl;
    cout << "sizeof(unsigned long int)      = " << sizeof(unsigned long int) << endl;
    cout << "sizeof(signed long int)        = " << sizeof(signed long int) << endl;
    cout << "sizeof(long long int)          = " << sizeof(long long int) << endl;
    cout << "sizeof(unsigned long long int) = " << sizeof(unsigned long long int) << endl;
    cout << "sizeof(signed long long int)   = " << sizeof(signed long long int) << endl;
    cout << "sizeof(float)                  = " << sizeof(float) << endl;
    cout << "sizeof(double)                 = " << sizeof(double) << endl;
    cout << "sizeof(long double)            = " << sizeof(long double) << endl;
    cout << "sizeof(wchar_t)                = " << sizeof(wchar_t) << "\n" << endl;

    /* Typedef */
    typedef char BYTE;
    BYTE bt;

    for (bt = 'A'; bt <= 'z'; ++bt)
    {
        cout << bt << " ";
    }

    cout << "\n" << endl;

    /* Enumeration */
    enum Color { red, green, blue };
    Color r = red;
    Color g = green;
    Color b = blue;

    cout << "r = " << r << endl;
    cout << "g = " << g << endl;
    cout << "b = " << b << endl;

    return 0;
}
