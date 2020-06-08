#include <iostream>

using namespace std;

int main()
{
    cout << "sizeof(bool) = " << sizeof(bool) << endl;                  // 1 Byte
    cout << endl;
    cout << "sizeof(char) = " << sizeof(char) << endl;                  // 1 Byte
    cout << "sizeof(wchar_t) = " << sizeof(wchar_t) << endl;            // 2 Bytes
    cout << "sizeof(char16_t) = " << sizeof(char16_t) << endl;          // 2 Bytes
    cout << "sizeof(char32_t) = " << sizeof(char32_t) << endl;          // 4 Bytes
    cout << endl;
    cout << "sizeof(short) = " << sizeof(short) << endl;                // 2 Bytes
    cout << "sizeof(int) = " << sizeof(int) << endl;                    // 4 Bytes
    cout << "sizeof(long) = " << sizeof(long) << endl;                  // 4 Bytes
    cout << "sizeof(long long) = " << sizeof(long long) << endl;        // 8 Bytes
    cout << endl;
    cout << "sizeof(float) = " << sizeof(float) << endl;                // 4 Bytes
    cout << "sizeof(double) = " << sizeof(double) << endl;              // 8 Bytes
    cout << "sizeof(long double) = " << sizeof(long double) << endl;    // 12 Bytes

    return 0;
}
