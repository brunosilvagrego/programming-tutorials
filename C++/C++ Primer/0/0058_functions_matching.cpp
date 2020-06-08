#include <iostream>
#include <string>
#include <iterator>
#include <vector>

using namespace std;


void f()
{
    cout << "f()" << endl;
}

void f(int)
{
    cout << "f(int)" << endl;
}

void f(int, int)
{
    cout << "f(int, int)" << endl;
}

void f(double, double = 3.14)
{
    cout << "f(double, double = 3.14)" << endl;
}

void manip(long)
{
    cout << "manip(long)" << endl;
}

void manip(float)
{
    cout << "manip(float)" << endl;
}

Record lookup(Account&);        // function that takes a reference to Account
Record lookup(const Account&);  // new function that takes a const reference

// BEST PRACTICES: Casts should not be needed to call an overloaded function. The need for a
//                 cast suggests that the parameter sets are designed poorly.

int main()
{
    f();            // calls void f()
    f(5);           // calls void f(int)
    f(2, 4);        // calls void f(int, int)
    f(5.6);         // calls void f(double, double)

    f(42, 2.56);    // error: call of overloaded 'f(int, double)' is ambiguous

    manip(3);       // error: ambiguous call
    manip(3.14);    // error: ambiguous call

    const Account a;
    Account b;
    lookup(a);      // calls lookup(const Account&)
    lookup(b);      // calls lookup(Account&)

	return 0;
}
