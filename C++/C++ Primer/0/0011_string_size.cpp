#include <iostream>
#include <string>

using namespace std;

int main()
{
    string st("The expense of spirit\n");

    // Although we don’t know the precise type of string::size_type, we do know that it is an unsigned type
    // You can avoid problems due to conversion between unsigned and int by not using ints in expressions that use size().
    unsigned int st_size = st.size();

    cout << "The size of string: " << st << "is " << st_size << " characters, including the newline" << endl;

	return 0;
}