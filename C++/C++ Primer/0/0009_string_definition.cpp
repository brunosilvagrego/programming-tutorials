#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1;          // default initialization; s1 is the empty string
    string s2 = s1;     // s2 is a copy of s1
    string s3 = "hiya"; // s3 is a copy of the string literal
    string s4("hiya");  // direct initialization
    string s5(10, 'c'); // s4 is cccccccccc

    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl;
    cout << "s4: " << s4 << endl;
    cout << "s5: " << s5 << endl;

	return 0;
}