#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <bitset>

using namespace std;

int main()
{
    // WARNING: Because there are no guarantees for how the sign bit is handled, we strongly
    //          recommend using unsigned types with the bitwise operators.

    //          If the operand is signed and its value is negative, then the way that the “sign bit” is
    //          handled in a number of the bitwise operations is machine dependent. Moreover, doing
    //          a left shift that changes the value of the sign bit is undefined.

    unsigned long quiz1 = 0;    // we'll use this value as a collection of bits
    bool status;

    quiz1 |= 1UL << 27;                 // indicate student number 27 passed
    status = quiz1 & (1UL << 27);       // how did student number 27 do?

    cout << "quiz1 = " << bitset<32>(quiz1) << endl;
    cout << (status ? "pass" : "fail"); // prints pass or fail
	cout << endl;

    quiz1 &= ~(1UL << 27);              // student number 27 failed
    status = quiz1 & (1UL << 27);       // how did student number 27 do?

    cout << "quiz1 = " << bitset<32>(quiz1) << endl;
    cout << (status ? "pass" : "fail"); // prints pass or fail
	cout << endl;
	cout << endl;

    char ch = 'q';
    cout << "      ch = " << bitset<8>(ch) << endl;

    ch = ~'q';
    cout << "     ~ch = " << bitset<8>(ch) << endl;

    ch = ~'q' << 6;
    cout << "~ch << 6 = " << bitset<8>(ch) << endl;
    cout << endl;

    unsigned long ul1 = 3, ul2 = 7;

    cout << "       ul1 = " << bitset<32>(ul1) << endl;
    cout << "       ul2 = " << bitset<32>(ul2) << endl;
    cout << " ul1 & ul2 = " << bitset<32>(ul1 & ul2) << endl;
    cout << endl;

    cout << "       ul1 = " << bitset<32>(ul1) << endl;
    cout << "       ul2 = " << bitset<32>(ul2) << endl;
    cout << " ul1 | ul2 = " << bitset<32>(ul1 | ul2) << endl;
    cout << endl;

    cout << "       ul1 = " << bitset<32>(ul1) << endl;
    cout << "       ul2 = " << bitset<32>(ul2) << endl;
    cout << " ul1 ^ ul2 = " << bitset<32>(ul1 ^ ul2) << endl;
    cout << endl;

    cout << "ul1 && ul2 = " << bitset<32>(ul1 && ul2) << endl;
    cout << "ul1 || ul2 = " << bitset<32>(ul1 || ul2) << endl;

	return 0;
}