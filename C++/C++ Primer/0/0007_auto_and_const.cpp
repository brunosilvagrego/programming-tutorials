#include <iostream>

using namespace std;

int main()
{
    const int i = 42;
    auto j = i;                     // j is int
    const auto &k = i;              // k is const int& (reference to const int)
    auto *p = &i;                   // p is int* (pointer to int)
    const auto j2 = i, &k2 = i;     // j2 is const int; k2 is const int&

    cout << "i = " << i << endl;
    cout << "j = " << j << endl;
    cout << "k = " << k << endl;
    cout << "p = " << p << endl;
    cout << "j2 = " << j2 << endl;
    cout << "k2 = " << k2 << endl;

    return 0;
}