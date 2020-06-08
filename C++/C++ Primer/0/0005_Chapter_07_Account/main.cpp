#include <iostream>
#include <string>
#include <iterator>
#include <vector>

#include "Account.h"

using namespace std;


int main()
{
    Account a1("Bruno", 42);
	cout << "Balance = " << a1.balance() << endl;

	a1.calculate();
	cout << endl;
	cout << "Interest Rate = " << a1.rate() << endl;
	cout << "New Balance = " << a1.balance() << endl;

	a1.rate(0.05);
    a1.calculate();
    cout << endl;
	cout << "New Interest Rate = " << a1.rate() << endl;
	cout << "New Balance = " << a1.balance() << endl;

    return 0;
}
