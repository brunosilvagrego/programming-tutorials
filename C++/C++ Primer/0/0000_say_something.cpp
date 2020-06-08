#include <iostream>

using namespace std;

int main()
{
    // Say something
    string str1, str2, str3;

	std::cout << "Hi! Say something:" << std::endl;
    std::cin >> str1 >> str2 >> str3;
    str1 = str1 + " " + str2 + " " + str3;
	std::cout << "You said: \"" << str1 << "\"" << std::endl << std::endl;

	return 0;
}
