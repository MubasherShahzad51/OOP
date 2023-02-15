#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;

// declaring a function for password
int pass(string password)
{

    int result = 0;
    for (int i = 0; i < password.length(); i++)
    {
        // condition for declaring ascii values for special characters
        if (password[i] == 37 || password[i] == 33 || password[i] == 42 || password[i] == 94 || password[i] == 97 || password[i] == 38)

        {
            if (password.length() == 8)
            {
                result = 1;
                break;
            }
        }
    }
    if (result == 1)
        return 1;
    else
        return 0;
}

int main()
{
    int temporary;
    string name, password, check_Password;
    cout << "Enter Your  Name:";
    getline(cin, name);

    while (1)
    {
        cout << "Enter Your  Password: ";
        getline(cin, password);
        temporary = pass(password);
        if (temporary == 1)
        {
            break;
        }
        else
        {
            cout << "Password must be of 8 characters and have special characters as well. " << endl;
            continue;
        }
    }

    cout << "Confirm your Password: ";
    getline(cin, check_Password);
    if (password.compare(check_Password) == 0)
    {
        cout << "“You know what? You can be a great programmer. Keep Coding!" << endl;
    }
    return 0;
}