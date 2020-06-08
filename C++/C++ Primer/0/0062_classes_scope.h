#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>


// NOTE: Member function definitions are processed after the compiler processes all of the declarations in the class.
//
//       Because member function bodies are not processed until the entire class is seen, they can use any name defined
//       inside the class. If function definitions were processed at the same time as the member declarations, then we
//       would have to order the member functions so that they referred only to names already seen.
//
//       This two-step process applies only to names used in the body of a member function. Names used in declarations,
//       including names used for the return type and types in the parameter list, must be seen before they are used.

class Account
{
public:

	Account() = default;

	Account(const std::string &s, double amt): owner(s), amount(amt) { }

    void calculate()
    {
        amount += amount * interestRate;
    }

    double balance()
    {
        return amount;
    }

public:
    static double rate()
    {
        return interestRate;
    }

    static void rate(double);

private:
    std::string owner;
    double amount = 0.0;
    static double interestRate;

    static double initRate()
    {
        return .0225;
    }

    static const std::string accountType;

	static const int period = 30;   // period is a constant expression

    double daily_tbl[period];
};

#endif


/**** Account.cpp ****/
#include <string>
using std::string;

#include "Account.h"

// define static data and function members
const string Account::accountType("Savings Account");

double Account::interestRate = initRate();

void Account::rate(double newRate)
{
    interestRate = newRate;
}
/**** Account.cpp ****/


// NOTE: Name Lookup inside Member Definitions -  A name used in the body of a member function is resolved as follows:
//       - First, look for a declaration of the name inside the member function. As usual, only declarations in the
//         function body that precede the use of the name are considered.
//
//       - If the declaration is not found inside the member function, look for a declaration inside the class.
//         All the members of the class are considered.
//
//       - If a declaration for the name is not found in the class, look for a declaration that is in scope before the
//         member function definition.
//
// WARNING:  Ordinarily, it is a bad idea to use the name of another member as the name for a parameter in a member function.
//           However, it is possible.

int height;     // defines a name subsequently used inside Screen

class Screen
{
public:
    typedef std::string::size_type pos;

    // bad practice: names local to member functions shouldn't hide member names
    void dummy_fcn(pos height)
    {
        cursor = width * height;            // Which height? The function parameter.
    }

    // bad practice: names local to member functions shouldn't hide member names
    void Screen::dummy_fcn(pos height)
    {
        cursor = width * this->height;      // member height
        
        // alternative way to indicate the member
        cursor = width * Screen::height;    // member height
    }

    // bad practice: don't hide names that are needed from surrounding scopes
    void Screen::dummy_fcn(pos height)
    {
        cursor = width * ::height;          // which height? the global one
    }

    // good practice: don't use a member name for a parameter or other local variable
    void Screen::dummy_fcn(pos ht)
    {
        cursor = width * height;            // member height
    }

private:
    pos cursor = 0;
    pos height = 0, width = 0;
};


// NOTE: Names Are Resolved Where They Appear within a File. When a member is defined outside its class,
//       the third step of name lookup includes names declared in the scope of the member definition as
//       well as those that appear in the scope of the class definition.

int height;             // defines a name subsequently used inside Screen

class Screen
{
public:
    typedef std::string::size_type pos;

    void setHeight(pos);
    pos height = 0;     // hides the declaration of height in the outer scope
};

Screen::pos verify(Screen::pos);

// var: refers to the parameter
// height: refers to the class member
// verify: refers to the global function
void Screen::setHeight(pos var)
{
    height = verify(var);
}