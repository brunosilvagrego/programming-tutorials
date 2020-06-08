#include <iostream>

using namespace std;


// NOTE: Names introduced in a using directive obey normal scope rules. The name is visible from the
//       point of the using directive to the end of the scope in which the directive is found.
//       Entities with the same name defined in an outer scope are hidden.
//
//       A namespace can be defined in several parts and so a namespace is made up of the sum of its
//       separately defined parts. The separate parts of a namespace can be spread over multiple files.


// First name space
namespace first_space
{
    void func()
    {
        cout << "Inside first_space.\n" << endl;
    }
}

// Second name space
namespace second_space
{
    void func()
    {
        cout << "Inside second_space.\n" << endl;
    }
}

using namespace first_space;

int main ()
{
    // Calls function from the first name space
    func();

    // Calls function from the second name space
    second_space::func();

    return 0;
}
