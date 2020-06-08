#include <iostream>

using namespace std;

int main()
{
    int i = 42, *p = &i, &r = i;
    decltype(r + 0) j; // ok: addition yields an int; j is an (uninitialized) int
    decltype(*p) k; // error: k is int& and must be initialized

    int a = 0;
	decltype(a) c = a;   // c is an int
	decltype((a)) d = a; // d is a reference to a

	cout << "a: " << a << " c: " << c << " d: " << d << endl;

	cout << "++c;" << endl;
	++c;                 // increments c; a (and d) unchanged
	cout << "a: " << a << " c: " << c << " d: " << d << endl;

	cout << "++d;" << endl;
	++d;                 // increments a through the reference d
	cout << "a: " << a << " c: " << c << " d: " << d << endl;

	int A = 0, B = 0;
	decltype((A)) C = A;   // C is a reference to A
	decltype(A = B) D = A; // D is also a reference to A

	cout << endl;
	cout << "A: " << A << " C: " << C << " D: " << D << endl;

	cout << "++C;" << endl;
	++C;
	cout << "A: " << A << " C: " << C << " D: " << D << endl;

	cout << "++D;" << endl;
	++D;
	cout << "A: " << A << " C: " << C << " D: " << D << endl;

    return 0;
}
