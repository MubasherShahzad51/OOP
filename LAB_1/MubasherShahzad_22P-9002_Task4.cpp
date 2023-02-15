#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;
int main()
{
    int Rows;
    // taking no rows as input from user
    cout << "Enter Number Of Rows: ";
    cin >> Rows;
    // using nested for loops to print hal diamond pattern
    for (int i = 1; i < Rows; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = 1; i <= Rows; i++)
    {
        for (int j = i; j <= Rows; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}