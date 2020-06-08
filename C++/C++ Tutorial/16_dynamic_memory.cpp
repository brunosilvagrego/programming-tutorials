#include <iostream>
#include <cstring>

using namespace std;


class Box
{
    public:
        Box() { cout << "Constructor called!\n" << endl; }

        ~Box() { cout << "Destructor called!\n" <<endl; }
};


// NOTE - Memory in your C++ program is divided into two parts:
//
//      The stack - All variables declared inside the function will take up memory from the stack.
//
//      The heap - This is unused memory of the program and can be used to allocate the memory
//                 dynamically when program runs.
//
//      You can allocate memory at run time within the heap for the variable of a given type using
//      the 'new' operator, and you can use 'delete' operator to de-allocate memory that was previously allocated.

// NOTE: The malloc() function from C still exists in C++, but it is recommended to avoid using this function.
//       The main advantage of 'new' over malloc() is that it doesn't just allocate memory, it constructs objects,
//       which is the main purpose of C++.


int main()
{
    /* Variable */
    double* pd  = NULL;     // Pointer initialized with null
    pd  = new double;       // Allocate memory for the variable

    *pd = 29494.99;         // Store a value at allocated address
    cout << "pd = " << *pd << "\n" << endl;
    delete pd;              // Free up the memory


    /* Char array */
    char* pc  = NULL;       // Pointer initialized with null
    pc = new char[20];      // Request memory for the variable

    strcpy(pc, "Hello World");
    cout << "pc = " << pc << "\n" << endl;
    delete [] pc;       // Delete array pointed to by pvalue


    /* Object array */
    Box* boxArray;
    boxArray = new Box[4];  // Allocate memory
    delete [] boxArray;     // Free up the memory

    return 0;
}
