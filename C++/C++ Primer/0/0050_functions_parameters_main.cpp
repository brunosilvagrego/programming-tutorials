#include <iostream>
#include <string>
#include <iterator>
#include <vector>

#include <cstring>
#include <cstddef>

using namespace std;

// WARNING: When you use the arguments in argv, remember that the optional
//          arguments begin in argv[1]; argv[0] contains the program’s name, not
//          user input.

// int main(int argc, char **argv) { ... }  // equivalent definition indicating that argv points to a char*.

int main(int argc, char *argv[])
{
    int op = 0;

    if (op == 1)
    {
        string s1(argv[1]);
        string s2(argv[2]);
        string cat = s1 + " " + s2;

        cout << "String concatenation: " << cat << endl;
    }
    else
    {
        int total = 0, value;

        for (int i = 1; i < argc-1; i++)
        {
            value = atoi(argv[i]);
            total += value;
        }

        cout << "Sum = " << total << endl;
    }

    return 0;
}