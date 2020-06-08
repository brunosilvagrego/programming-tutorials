#include <iostream>
#include <string>
#include <iterator>

#include <cstring>
#include <cstddef>

using namespace std;

int main()
{
    // WARNING: Although C++ supports C-style strings, they should not be used by C++
    // programs. C-style strings are a surprisingly rich source of bugs and are the
    // root cause of many security problems. They’re also harder to use!

    string s1 = "A string example";
	string s2 = "A different string";

	if (s1 < s2)    // false: s2 is less than s1
    {
        cout << s1 << endl;
    }
	else
    {
        cout << s2 << endl;
    }

	const char ca1[] = "A string example";
	const char ca2[] = "A different string";

	cout << endl;

	if (strcmp(ca1, ca2) < 0)   // same effect as string comparison s1 < s2
    {
        cout << ca1 << endl;
    }
	else
    {
        cout << ca2 << endl;
    }

    cout << endl;

	const char *cp1 = ca1, *cp2 = ca2;
	cout << strcmp(cp1, cp2) << endl;   // output is positive
	cout << strcmp(cp2, cp1) << endl;   // output is negative
	cout << strcmp(cp1, cp1) << endl;   // output is zero

    cout << endl;

	cout << strlen(cp1) << endl;        // prints 16; strlen ignores the null

	const unsigned sz = 16 + 18 + 2;
	char largeStr[sz];                  // will hold the result

	// disastrous if we miscalculated the size of largeStr
	strcpy(largeStr, ca1);              // copies ca1 into largeStr
	strcat(largeStr, " ");              // adds a space at the end of largeStr
	strcat(largeStr, ca2);              // concatenates ca2 onto largeStr

    cout << endl;

	// prints A string example A different string
	cout << largeStr << endl;

	strncpy(largeStr, ca1, sz);     // size to copy includes the null

	if (strlen(ca1) > sz)
    {
        largeStr[sz-1] = '\0';
    }

    cout << endl;

	strncat(largeStr, " ", 2);      // pedantic, but a good habit
	strncat(largeStr, ca2, sz - strlen(largeStr));

	cout << largeStr << endl;

	cout << endl;

	// initialize large_string as a concatenation of s1, a space, and s2
	string large_string = s1 + " " + s2;

	cout << large_string << endl;

    cout << endl;

    string s = "Hello";
    char *str = s;                  // error: can't initialize a char* from a string
    const char *str = s.c_str();    // ok

    cout << str << endl;

    // WARNING: If a program needs continuing access to the contents of the array returned
    //          by str(), the program must copy the array returned by c_str.
    //          The array returned by c_str is not guaranteed to be valid indefinitely. Any
    //          subsequent use of s that might change the value of s can invalidate this array.

    // ADVICE: Use Library Types Instead of Arrays
    //         Pointers and arrays are surprisingly error-prone. Part of the problem is
    //         conceptual: Pointers are used for low-level manipulations and it is easy to
    //         make bookkeeping mistakes. Other problems arise because of the syntax,
    //         particularly the declaration syntax used with pointers.
    //         Modern C++ programs should use vectors and iterators instead of built-in
    //         arrays and pointers, and use strings rather than C-style array-based
    //         character strings.

	return 0;
}