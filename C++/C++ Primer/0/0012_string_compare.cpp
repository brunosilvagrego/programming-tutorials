#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1 = "Hello";
    string str2 = "Hello World";
    string str3  = "Hiya";

    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;
    cout << "str3: " << str3 << endl;
    cout << endl;
    
    // 1. If two strings have different lengths and if every character in the shorter
    // string is equal to the corresponding character of the longer string, then the
    // shorter string is less than the longer one.
    
    // 2. If any characters at corresponding positions in the two strings differ, then
    // the result of the string comparison is the result of comparing the first
    // character at which the strings differ.

    if (str1 < str2)
    {
        cout << "str1 is smaller than str2" << endl;
    }
    
    if (str3 > str1)
    {
        cout << "str3 is greater than str1" << endl;
    }
    
    if (str3 > str2)
    {
        cout << "str3 is greater than str1" << endl;
    }

	return 0;
}