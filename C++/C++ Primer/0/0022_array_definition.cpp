#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    unsigned cnt = 42;				// not a constant expression
	constexpr unsigned sz = 42;		// constant expression
	int arr[10];					// array of ten ints
	int *parr[sz];					// array of 42 pointers to int
	string bad[cnt];				// error: cnt is not a constant expression
	string strs[get_size()];		// ok if get_size is constexpr, error otherwise

    // WARNING: As with variables of built-in type, a default-initialized array of built-in type
    //          that is defined inside a function will have undefined values.

    const unsigned sz = 3;
    int ia1[sz] = {0,1,2};          // array of three ints with values 0, 1, 2
    int a2[] = {0, 1, 2};           // an array of dimension 3
    int a3[5] = {0, 1, 2};          // equivalent to a3[] = {0, 1, 2, 0, 0}
    string a4[3] = {"hi", "bye"};   // same as a4[] = {"hi", "bye", ""}
    int a5[2] = {0,1,2};            // error: too many initializers

    char a1[] = {'C', '+', '+'};        // list initialization, no null
    char a2[] = {'C', '+', '+', '\0'};  // list initialization, explicit null
    char a3[] = "C++";                  // null terminator added automatically
    const char a4[6] = "Daniel";        // error: no space for the null terminator

    int a[] = {0, 1, 2};            // array of three ints
    int a2[] = a;                   // error: cannot initialize one array with another
    a2 = a;                         // error: cannot assign one array to another

    // WARNING: Some compilers allow array assignment as a compiler extension. It is
    //          usually a good idea to avoid using nonstandard features. Programs that use
    //          such features will not work with a different compiler.

    int *ptrs[10];                  // ptrs is an array of ten pointers to int
    int &refs[10] = /* ? */;        // error: not possible to define an arrays of references (a reference is not an object)
    int (*Parray)[10] = &arr;       // Parray points to an array of ten ints
    int (&arrRef)[10] = arr;        // arrRef refers to an array of ten ints
    int *(&arry)[10] = ptrs;        // arry is a reference to an array of ten pointers

    // TIP: It can be easier to understand array declarations by starting with the array’s
    //      name and reading them from the inside out.

    string nums[] = {"one", "two", "three"};    // array of strings
    string *p = &nums[0];                       // p points to the first element in nums
    string *p2 = nums;                          // equivalent to p2 = &nums[0]

    // NOTE: In most expressions, when we use an object of array type, we are really
    //       using a pointer to the first element in that array.

    int ia[] = {0,1,2,3,4,5,6,7,8,9};           // ia is an array of ten ints
    auto ia2(ia);                               // ia2 is an int* that points to the first element in ia
    ia2 = 42;                                   // error: ia2 is a pointer, and we can't assign an int to a pointer
    auto ia2(&ia[0]);                           // now it's clear that ia2 has type int*
    decltype(ia) ia3 = {0,1,2,3,4,5,6,7,8,9};   // ia3 is an array of ten ints
    ia3 = ia2;                                  // error: can't assign an int* to an array
    ia3[4] = i;                                 // ok: assigns the value of i to an element in ia3

	return 0;
}