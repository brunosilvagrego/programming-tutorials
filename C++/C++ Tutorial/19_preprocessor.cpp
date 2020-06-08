#include <iostream>

using namespace std;

// Literal Macro
#define PI  3.14159

// Function Macro
#define MIN(a,b)    (((a)<(b)) ? a : b)

// Conditional Compilation
#define DEBUG

#ifndef NULL
   #define NULL 0
#endif

#if 0
   code prevented from compiling
#endif

// The # and ## Operators
#define MKSTR( x )      #x
#define CONCAT( x, y )  x ## y


int main ()
{
// Conditional Compilation
#ifdef DEBUG
   cerr << "Trace: Entering main function.\n" << endl;
#endif

    // Literal Macro
    cout << "PI = " << PI << "\n" << endl;

    // Function Macro
    int i = 100;
    int j = 30;

    cout << "MIN(" << i << ", " << j << ") = " << MIN(i, j) << "\n" << endl;

    // The # and ## Operators
    cout << MKSTR(HELLO C++) << "\n" << endl;

    int xy = 100;
    cout << CONCAT(x, y) << "\n" << endl;

    // Predefined C++ Macros
    cout << "__LINE__ = " << __LINE__ << endl;
    cout << "__FILE__ = " << __FILE__ << endl;
    cout << "__DATE__ = " << __DATE__ << endl;
    cout << "__TIME__ = " << __TIME__ << "\n" << endl;

    // Conditional Compilation
#ifdef DEBUG
   cerr << "Trace: Exiting main function.\n" << endl;
#endif

    return 0;
}
