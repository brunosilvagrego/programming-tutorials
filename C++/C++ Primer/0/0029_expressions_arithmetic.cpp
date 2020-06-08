#include <iostream>

using namespace std;

int main()
{
    /* Precedence */
    cout << -30 * 3 + 21 / 5 << endl;   // prints -86

	cout << -30 + 3 * 21 / 5 << endl;   // prints -18

	cout << 30 / 3 * 21 % 5 << endl;    // prints 0

	cout << 30 / 3 * 21 % 4 << endl;    // prints 2

	cout << -30 / 3 * 21 % 4 << endl;   // prints -2

	cout << 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2 << endl;   // prints 91

	cout << endl;
	cout << 6 + 3 * 4 / 2 + 2 << endl;                  // prints 14

	// parentheses in this expression match default precedence and associativity
	cout << ((6 + ((3 * 4) / 2)) + 2) << endl;          // prints 14

	int temp = 3 * 4;           // 12
	int temp2 = temp / 2;       // 6
	int temp3 = temp2 + 6;      // 12
	int result = temp3 + 2;     // 14
	cout << result << endl;     // prints 14

	// parentheses result in alternative groupings
	cout << endl;
	cout << (6 + 3) * (4 / 2 + 2) << endl;      // prints 36
	cout << ((6 + 3) * 4) / 2 + 2 << endl;      // prints 20
	cout << 6 + 3 * 4 / (2 + 2) << endl;        // prints 9

	// NOTE: (-m)/n and m/(-n) are always equal to -(m/n), m%(-n) is equal to m%n, and (-m)%n is equal to -(m%n)
	cout << endl;
	cout <<  21 %  6 << endl;   // prints  3
	cout <<  21 /  6 << endl;   // prints  3
	cout <<  21 %  7 << endl;   // prints  0
	cout <<  21 /  7 << endl;   // prints  3
    cout << -21 % -8 << endl;   // prints -5
    cout << -21 / -8 << endl;   // prints  2
    cout <<  21 % -5 << endl;   // prints  1
    cout <<  21 / -5 << endl;   // prints -4
    cout << -15 /  4 << endl;   // prints -3
    cout <<  15 / -4 << endl;   // prints -3
    cout <<  15 % -4 << endl;   // prints  3
    cout << -15 /  4 << endl;   // prints -3

	/* Negative */
	int i = 1024;
	int k = -i; // i is -1024

	cout << endl;
	cout << i << " " << k << " " << endl;

	bool b = true;
	bool b2 = -b; // b2 is true!

	cout << endl;
	cout << b << " " << b2 << " " << endl;

    /* Precision */
	// the compiler might warn about loss of precision
	int ival = 3.541 + 3;

	cout << endl;
	cout << ival << endl;  // prints 6

	// ival1 is 3; result is truncated; remainder is discarded
	int ival1 = 21/6;

	// ival2 is 3; no remainder; result is an integral value
	int ival2 = 21/7;

    cout << endl;
	cout << ival1 << " " << ival2 << endl;

	short short_value = 32767; // max value if shorts are 16 bits

	short_value += 1; // this calculation overflows

	cout << endl;
	cout << "short_value: " << short_value << endl;

	return 0;
}