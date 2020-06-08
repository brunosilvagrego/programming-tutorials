#include <cstddef>
using std::size_t;

#include <cassert>
// assert is a preprocessor macro and therefore not in std
// hence we need to include cassert header,
// but no using declaration for assert

#include <string>
using std::string;

#include <iostream>
using std::endl; using std::cerr; using std::cin;

#include <cstddef>
using std::size_t;


int main()
{
    string word = "foo";
    const string::size_type threshold = 5;

    if (word.size() < threshold)
    {
        cerr << "Error: " << __FILE__
             << " : in function " << __func__
             << " at line " << __LINE__ << endl
             << "       Compiled on " << __DATE__
             << " at " << __TIME__ << endl
             << "       Word read was \"" << word
             << "\":  Length too short" << endl;
    }

    word = "something longer than five chars";
    assert(word.size() > threshold);

    return 0;
}
