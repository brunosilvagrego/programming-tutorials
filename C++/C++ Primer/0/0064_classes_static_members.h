/* Declaring static Members */

// NOTE: Like any other member, static members can be public or private. The type of a static data member
//       can be const, reference, array, class type, and so forth.
//
//       The static members of a class exist outside any object. Objects do not contain data associated with
//       static data members. Thus, each Account object will contain two data members — owner and amount.
//       
//       There is only one interestRate object that will be shared by all the Account objects. Similarly, static
//       member functions are not bound to any object; they do not have a this pointer. As a result, static member
//       functions may not be declared as const, and we may not refer to this in the body of a static member. This
//       restriction applies both to explicit uses of this and to implicit uses of this by calling a nonstatic member.

class Account
{
public:
    void calculate() { amount += amount * interestRate; }
    static double rate() { return interestRate; }
    static void rate(double);

private:
    std::string owner;
    double amount;
    static double interestRate;
    static double initRate();
};


/* Using a Class static Member */
double r;
r = Account::rate();    // access a static member using the scope operator

Account ac1;
Account *ac2 = &ac1;

// equivalent ways to call the static member rate function
r = ac1.rate();         // through an Account object or reference
r = ac2->rate();        // through a pointer to an Account object


/* Defining static Members */

// NOTE: As with any class member, when we refer to a class static member outside the class body,
//       we must specify the class in which the member is defined. The static keyword, however,
//       is used only on the declaration inside the class body.

void Account::rate(double newRate)
{
    interestRate = newRate;
}

// define and initialize a static class member
double Account::interestRate = initRate();

// NOTE: This statement defines the object named interestRate that is a static member of class Account
//       and has type double. Once the class name is seen, the remainder of the definition is in the
//       scope of the class. As a result, we can use initRate without qualification as the initializer
//       for rate. Note also that even though initRate is private, we can use this function to initialize
//       interestRate. The definition of interestRate, like any other member definition, has access to the
//       private members of the class.

// TIP: The best way to ensure that the object is defined exactly once is to put the definition of static
//      data members in the same file that contains the definitions of the class noninline member functions.


/* In-Class Initialization of static Data Members */

// NOTE: We can provide in-class initializers for static members that have const integral type and must do so
//       for static members that are constexprs of literal type.

class Account
{
public:
    static double rate() { return interestRate; }
    static void rate(double);

private:
    static constexpr int period = 30;   // period is a constant expression
    double daily_tbl[period];
};

// NOTE: If an initializer is provided inside the class, the member’s definition must not specify an initial value.

// definition of a static member with no initializer
constexpr int Account::period;  // initializer provided in the class definition


/* static Members Can Be Used in Ways Ordinary Members Can’t */
class Bar
{
public:
    // ...

private:
    static Bar mem1;    // ok: static member can have incomplete type
    Bar *mem2;          // ok: pointer member can have incomplete type
    Bar mem3;           // error: data members must have complete type
};

class Screen
{
public:
    // bkground refers to the static member
    // declared later in the class definition
    Screen& clear(char = bkground);
    
private:
    static const char bkground;
};