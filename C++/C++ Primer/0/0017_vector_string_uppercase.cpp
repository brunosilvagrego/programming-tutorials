#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

int main()
{
	vector<string> vecStr;  // hold the strings read from the console
	string temp;            // hold the temporary string from cin

	// read the input strings
	while (temp != "$")
    {
        cin >> temp;
        vecStr.push_back(temp);
	}

    // print vecStr size
	cout << "vecStr.size() = " << vecStr.size() << endl;

    // convert vecStr to uppercase using range for
	for (auto &str : vecStr)
    {
        for (auto &c : str)
        {
            c = toupper(c);
        }
    }

    // print vecStr uppercase
    cout << "vecStr before: " << endl;
    for (uint32_t i = 0; i < vecStr.size(); i++)
    {
        cout << vecStr[i] << endl;
    }

    // convert vecStr to lowercase using standard for
    for (uint32_t i = 0; i < vecStr.size(); i++)
    {
        string aux = vecStr[i];

        for (uint32_t j = 0; j < aux.length(); j++)
        {
            aux[j] = tolower(aux[j]);
        }

        vecStr[i] = aux;
    }

    // print vecStr lowercase
    cout << "vecStr after: " << endl;
    for (uint32_t i = 0; i < vecStr.size(); i++)
    {
        cout << vecStr[i] << endl;
    }

	return 0;
}