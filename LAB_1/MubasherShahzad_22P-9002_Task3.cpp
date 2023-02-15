#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
int main()
{
    // declaring variables for burger and addon
    char burger, add_on;
    int price_of_burger = 500, price_of_fries = 200, totalBill = 0;
    cout << "Do You want a burger? Y/N" << endl;
    cin >> burger;
    // using nested if statements fro choice
    if (burger == 'Y' || burger == 'y')
    {
        cout << "Burger Added" << endl;
        cout << "Do You want a fries and drink as addon. Just for 200 RS ? Y/N" << endl;
        cin >> add_on;

        if (add_on == 'Y' || add_on == 'y')
        {
            cout << "Thank You! " << endl;
            totalBill += price_of_fries;
        }
        else
        {
            cout << "Your Choice Thankyou." << endl;
        }
        totalBill += price_of_burger;
        cout << "Your Total Bill is: " << totalBill << endl;
    }

    else if (burger == 'N' || burger == 'n')
    {
        cout << "No Problem. See you Next time" << endl;
    }
    else
    {
        cout << "Invalid Choice" << endl;
    }

    return 0;
}