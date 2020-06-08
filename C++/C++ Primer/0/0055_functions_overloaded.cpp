#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <cstddef>

using namespace std;


void print(const char *cp);
void print(const int *beg, const int *end);
void print(const int ia[], size_t size);


Record lookup(const Account&);  // find by Account
Record lookup(const Phone&);    // find by Phone
Record lookup(const Name&);     // find by Name

// NOTE: It is an error for two functions to differ only in terms of their return types.
Record lookup(const Account&);
bool lookup(const Account&);    // error: only the return type is different

// NOTE: The first declaration names its parameter. Parameter names are only a documentation aid. They do not change the parameter list.
Record lookup(const Account &acct);
Record lookup(const Account&);  // error:  parameter names are ignored

// NOTE: Telno is not a new type; it is a synonym for Phone. A type alias provides an alternative
//       name for an existing type; it does not create a new type.
typedef Phone Telno;
Record lookup(const Phone&);
Record lookup(const Telno&);    // error: Telno and Phone are the same type

// NOTE: A parameter that has a top-level const is indistinguishable from one without a top-level const.
Record lookup(Phone);
Record lookup(const Phone);     // error: redeclares Record lookup(Phone)
Record lookup(Phone*);
Record lookup(Phone* const);    // error: redeclares Record lookup(Phone*)

// NOTE: we can overload based on whether the parameter is a reference (or pointer) to the const
//       or nonconst version of a given type; such consts are low-level.
Record lookup(Account&);        // function that takes a reference to Account
Record lookup(const Account&);  // ok: new function that takes a const reference
Record lookup(Account*);        // ok: new function, takes a pointer to Account
Record lookup(const Account*);  // ok: new function, takes a pointer to const

// NOTE: Names do not overload across scopes.
string read();

void print(const string &);
void print(double);     // overloads the print function

void fooBar(int ival)
{
    bool read = false;  // new scope: hides the outer declaration of read
    string s = read();  // error: read is a bool variable, not a function
   
    // bad practice: usually it's a bad idea to declare functions at local scope
    void print(int);    // new scope: hides previous instances of print

    print("Value: ");   // error: print(const string &) is hidden
    print(ival);        // ok: print(int) is visible
    print(3.14);        // ok: calls print(int); print(double) is hidden
}


// NOTE: The main function may not be overloaded

int main()
{
    /** print() **/
	int j[2] = {0,1};

    print("Hello World");           // calls print(const char*)
    print(j, end(j) - begin(j));    // calls print(const int*, size_t)
    print(begin(j), end(j));        // calls print(const int*, const int*)


    /** lookup() **/
    Account acct;
    Phone phone;

    Record r1 = lookup(acct);       // call version that takes an Account
    Record r2 = lookup(phone);      // call version that takes a Phone

	return 0;
}
