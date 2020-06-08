#include <iostream>

using namespace std;


int main()
{
    char name[50];
    unsigned int age;

    char coutStr[] = "Hello cout!\n";
    char cerrStr[] = "Hello cerr!\n";
    char clogStr[] = "Hello clog!\n";

    /* cout */
    cout << coutStr << endl;

    /* cin */
    cout << "Please enter your name and age: ";
    cin >> name >> age;
    cout << "Your name: " << name << endl;
    cout << "Your age: " << age << "\n" << endl;

    /* cerr */
    cerr << cerrStr << endl;

    /* clog */
    clog << clogStr << endl;


    return 0;
}
