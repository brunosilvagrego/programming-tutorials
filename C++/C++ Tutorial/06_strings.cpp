#include <iostream>
#include <cstring>
#include <string>

using namespace std;


int main ()
{
    /* C Strings */
    char c_str1[10] = "Hello";
    char c_str2[10] = "World";
    char c_str3[10];
    int len;

    // Copies c_str1 into c_str3
    strcpy(c_str3, c_str1);
    cout << "strcpy(c_str3, c_str1) = " << c_str3 << endl;

    // Concatenates c_str1 and c_str2
    strcat(c_str1, c_str2);
    cout << "strcat(c_str1, c_str2) = " << c_str1 << endl;

    // Total lenghth of str1 after concatenation
    len = strlen(c_str1);
    cout << "strlen(c_str1) = " << len << "\n" << endl;

    /* C++ Strings */
    string cpp_str1 = "Hello";
    string cpp_str2 = "World";
    string cpp_str3;

    // Copies cpp_str1 into cpp_str3
    cpp_str3 = cpp_str1;
    cout << "cpp_str3 = " << cpp_str3 << endl;

    // Concatenates cpp_str1 and cpp_str2
    cpp_str3 = cpp_str1 + cpp_str2;
    cout << "cpp_str1 + cpp_str2 = " << cpp_str3 << endl;

    // Total length of cpp_str3 after concatenation
    len = cpp_str3.size();
    cout << "cpp_str3.size() :  " << len << endl;

    return 0;
}

