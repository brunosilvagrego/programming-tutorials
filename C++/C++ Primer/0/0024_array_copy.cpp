#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    constexpr size_t array_size = 10;
    int a[array_size];
    int b[array_size];

    cout << "a: ";

    for (size_t i = 0; i < array_size; i++)
    {
        a[i] = i;
        cout << a[i] << " ";
    }

    cout << endl;
    cout << "b: ";

    for (size_t i = 0; i < array_size; i++)
    {
        b[i] = a[i];
        cout << b[i] << " ";
    }

	return 0;
}