#include <iostream>
#include <string>
#include <iterator>
#include <vector>

using namespace std;

/* ----------------------------------------------------------------------------------------------------------------------- */
// compares lengths of two strings
bool lengthCompare(const string &, const string &);

// pf points to a function returning bool that takes two const string references
bool (*pf)(const string &, const string &); //  uninitialized

// declares a function named pf that returns a bool*
bool *pf(const string &, const string &);

// NOTE: When we use the name of a function as a value, the function is automatically converted to a pointer.
pf = lengthCompare;     // pf now points to the function named lengthCompare
pf = &lengthCompare;    // equivalent assignment: address-of operator is optional

// NOTE: There is no need to dereference the pointer.
bool b1 = pf("hello", "goodbye");               // calls lengthCompare
bool b2 = (*pf)("hello", "goodbye");            // equivalent call
bool b3 = lengthCompare("hello", "goodbye");    // equivalent call

/* Errors */
string::size_type sumLength(const string&, const string&);
bool cstringCompare(const char*, const char*);

pf = 0;                 // ok: pf points to no function
pf = sumLength;         // error: return type differs
pf = cstringCompare;    // error: parameter types differ
pf = lengthCompare;     // ok: function and pointer types match exactly

/* Overloaded functions */
void ff(int*);
void ff(unsigned int);

void (*pf1)(unsigned int) = ff; // pf1 points to ff(unsigned)
void (*pf2)(int) = ff;          // error: no ff with a matching parameter list
double (*pf3)(int*) = ff;       // error: return type of ff and pf3 don't match

/* Function Pointer Parameters */
// Third parameter is a function type and is automatically treated as a pointer to function
void useBigger(const string &s1, const string &s2, bool pf(const string &, const string &));

// Equivalent declaration: explicitly define the parameter as a pointer to function
void useBigger(const string &s1, const string &s2, bool (*pf)(const string &, const string &));

// Automatically converts the function lengthCompare to a pointer to function
useBigger(s1, s2, lengthCompare);

/* Type Aliases */
// Func and Func2 have function type
typedef bool Func(const string&, const string&);

// equivalent type
typedef decltype(lengthCompare) Func2;

// FuncP and FuncP2 have pointer to function type
typedef bool(*FuncP)(const string&, const string&);

// equivalent type
typedef decltype(lengthCompare) *FuncP2;

// equivalent declarations of useBigger using type aliases
void useBigger(const string&, const string&, Func);
void useBigger(const string&, const string&, FuncP2);

/* Returning a Pointer to Function */
using F = int(int*, int);       // F is a function type, not a pointer
using PF = int(*)(int*, int);   // PF is a pointer type

PF f1(int); // ok: PF is a pointer to function; f1 returns a pointer to function
F f1(int);  // error: F is a function type; f1 can't return a function
F *f1(int); // ok: explicitly specify that the return type is a pointer to function

int (*f1(int))(int*, int);          // direct declaration
auto f1(int) -> int (*)(int*, int); // Trailing declaration
/* ----------------------------------------------------------------------------------------------------------------------- */

// returns minimum element in an vector of ints
int min_element(vector<int>::iterator beg, vector<int>::iterator end)
{
    int minVal = *beg;

    while (beg != end)
    {
        if (minVal > *beg)
        {
            minVal = *beg;
        }

        ++beg;
    }

    return minVal;
}

// pointer to function, initialized to point to min_element
int (*pf)(vector<int>::iterator, vector<int>::iterator) = min_element;


// declarations (not strictly speaking necessary in this file)
string::size_type sumLength(const string&, const string&);
string::size_type largerLength(const string&, const string&);

// definition of these functions
string::size_type sumLength(const string &s1, const string &s2)
{
	return s1.size() + s2.size();
}

string::size_type largerLength(const string &s1, const string &s2)
{
	return (s1.size() > s2.size()) ? s1.size() : s2.size();
}


// NOTE: Depending on the value of its string parameter,
//       getFcn returns a pointer to sumLength or to largerLength

// 1. Use decltype for the return type, remembering to add a * to indicate that getFcn returns a pointer
decltype(sumLength) *getFcn(const string &);

// 2. use trailing return type
auto getFcn(const string&) -> string::size_type(*)(const string&, const string&);

// 3. direct definition
string::size_type (*getFcn(const string&))(const string&, const string&);

// define getFcn
decltype(sumLength)* getFcn(const string &fetch)
{
	if (fetch == "sum")
    {
        return sumLength;
    }

	return largerLength;
}


int main()
{
    /** int min_element(vector<int>::iterator beg, vector<int>::iterator end) **/

    vector<int> ivec = {11, 7, 5, 3, 1, 2, 4, 6};

    cout << "ivec: ";

    for (int i : ivec)
    {
        cout << i << " "; // print the elements in v
    }

	cout << '\n' << endl;

	// min_element()
    cout << "Direct call: " << min_element(ivec.begin(), ivec.end()) << endl;

    // pf(), pointer to min_element()
    cout << "Indirect call: " << pf(ivec.begin(), ivec.end()) << endl;

    // (*pf)(), pointer to min_element()
	cout << "equivalent indirect call: " << (*pf)(ivec.begin(), ivec.end()) << endl;

	cout << endl;


	/** string::size_type (*getFcn(const string&))(const string&, const string&) **/

	// pointer to sumLength()
	cout << "sumLength() = " << getFcn("sum")("hello", "world!") << endl;       // prints 11

    // pointer to largerLength()
	cout << "largerLength() = " << getFcn("larger")("hello", "world!") << endl;    // prints 6

    return 0;
}
