#include <iostream>

using namespace std;

// NOTE: Any C++ program where you implement a class with public and private members is an example of data
//       encapsulation and data abstraction.
//
//       Data encapsulation is a mechanism of bundling the data, and the functions that use them and data
//       abstraction is a mechanism of exposing only the interfaces and hiding the implementation details
//       from the user.
//
//       In C++, we use classes to define our own Abstract Data Types (ADT).

class Sum
{
    public:
        // Constructor
        Sum (int i = 0) { total = i; }

        // Interface to outside world <=> Data Encapsulation
        void addNum (int number) { total += number; }

        int getTotal () { return total; };

    private:
        // Hidden data from outside world <=> Data Abstraction
        int total;
};

// NOTE: The public members - addNum and getTotal are the interfaces to the outside world and a user needs to know
//       them to use the class. The private member total is something that the user doesn't need to know about,
//       but is needed for the class to operate properly.

int main()
{
    Sum sum;

    sum.addNum(10);
    sum.addNum(20);
    sum.addNum(30);

    cout << "Total = " << sum.getTotal() <<endl;

    return 0;
}

// NOTE: Abstraction separates code into interface and implementation. So while designing your component,
//       you must keep interface independent of the implementation, so that if you change underlying
//       implementation the interface would remain intact.
//
//       Class members are private by default to reinforce good encapsulation. Members should not be punlic
//       unless we really need to expose them. This is applied most frequently to data members, but it applies
//       equally to all members, including virtual functions.
