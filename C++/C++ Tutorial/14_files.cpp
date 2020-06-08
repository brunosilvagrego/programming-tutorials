#include <fstream>
#include <iostream>

using namespace std;


int main ()
{
    char data[100];
    const char* filename = "C:\\Users\\bruno\\Desktop\\CPP_SandBox\\test.txt";

    // Open the file in write mode
    ofstream outfile;
    outfile.open(filename);

    // Enter your data
    cout << "Writing to the file:" << endl;
    cout << "Enter your name: ";
    cin.getline(data, 100);

    // Write inputted data into the file
    outfile << data << endl;

    // Enter more data
    cout << "Enter your age: ";
    cin >> data;
    cin.ignore();

    // Write more inputted data into the file
    outfile << data << endl;


    // NOTE: When a C++ program terminates it automatically flushes all the streams, release all the allocated memory and close
    //       all the opened files. But it is always a good practice to close all the opened files before program termination.

    // Close the opened file
    outfile.close();

    // Open the file in read mode
    ifstream infile;
    infile.open(filename);

    // Write the read data in the screen
    cout << "\nReading from the file:" << endl;
    infile >> data;
    cout << data << endl;

    // Read another line from the file and display it.
    infile >> data;
    cout << data << endl;

    // close the opened file.
    infile.close();

    // Read the whole file at once
    infile.open(filename);

    cout << "\nReading the whole file:" << endl;

    while (infile >> data)
    {
        cout << data << " ";
    }

    cout << endl;

    // close the opened file.
    infile.close();


    return 0;
}
