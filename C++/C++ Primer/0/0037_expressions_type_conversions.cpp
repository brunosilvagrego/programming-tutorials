#include <iostream>
#include <string>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
    bool flag = false;
    char cval = 'b';
    short sval = -10;
    unsigned short usval = 10;
    int ival = -20;
    unsigned int uival = -20;
    long lval = -30;
    unsigned long ulval = 30;
    float fval = -3.14;
    double dval = 3.1415;

    cout << "(3.14159L + 'a') = " << (3.14159L + 'a') << endl;  // 'a' promoted to int, then that int converted to long double
    cout << "dval + ival = " << (dval + ival) << endl;          // ival converted to double
    cout << "dval + fval = " << (dval + fval) << endl;          // fval converted to double
    cout << "ival = dval = " << (ival = dval) << endl;          // dval converted (by truncation) to int
    cout << "flag = dval = " << (flag = dval) << endl;          // if dval is 0, then flag is false, otherwise true
    cout << "cval + fval = " << (cval + fval) << endl;          // cval promoted to int, then that int converted to float
    cout << "sval + cval = " << (sval + cval) << endl;          // sval and cval promoted to int
    cout << "cval + lval = " << (cval + lval) << endl;          // cval converted to long
    cout << "ival + ulval = " << (ival + ulval) << endl;        // ival converted to unsigned long
    cout << "usval + ival = " << (usval + ival) << endl;        // promotion depends on the size of unsigned short and int
    cout << "uival + lval = " << (uival + lval) << endl;        // conversion depends on the size of unsigned int and long
    cout << endl;


    // WARNING: Although necessary at times, casts are inherently dangerous constructs.

    int i = 1;
    int j = 3;

    double slope;

    slope = i/j;
    cout << slope << endl;  // prints 0

    slope = static_cast<double>(i) / j; // cast used to force floating-point division
    cout << slope << endl;  // prints 0.333333

    slope = static_cast<double>(i / j);
    cout << slope << endl;  // prints 0

    slope = (double) i / j; // C-language-style cast notation
    cout << slope << endl;  // prints 0.333333
    
    // WARNING: A reinterpret_cast is inherently machine dependent. Safely using
    //          reinterpret_cast requires completely understanding the types involved
    //          as well as the details of how the compiler implements the cast.

    // ADVICE: Avoid Casts
    //         Casts interfere with normal type checking. As a result, we
    //         strongly recommend that programmers avoid casts. This advice is particularly
    //         applicable to reinterpret_casts. Such casts are always hazardous. A
    //         const_cast can be useful in the context of overloaded functions.
    //         Other uses of const_cast often indicate a design flaw.
    //         The other casts, static_cast and dynamic_cast, should be
    //         needed infrequently. Every time you write a cast, you should think hard
    //         about whether you can achieve the same result in a different way. If the cast
    //         is unavoidable, errors can be mitigated by limiting the scope in which the
    //         cast value is used and by documenting all assumptions about the types involved.

    // WARNING: Old-style casts are less visible than are named casts. Because they are easily
    //          overlooked, it is more difficult to track down a rogue cast.

	return 0;
}
