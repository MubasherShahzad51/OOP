#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <cstring>
#include <time.h>
#include <iomanip>
using namespace std;

class Dice
{
private:
    int value;

public:
    void roll()
{
    srand((unsigned)time(NULL));
    int random = 1 + (rand() % 6);
    value = random;
    cout << "Side : " << value << endl;

    switch (value)
    {
    case 6:
        cout << "Chakka!" << endl;
        break;
    default:
        cout << "Better Luck Next time" << endl;
        break;
    }
}
};
void Call();

int main()
{
    Call();
    return 0;
}

void Call()
{

    char choice;

    Dice MyDice;
    while (1)
    {
        cout << "Do you want to Roll (Y/N): ";
        cin >> choice;
        switch (choice)
        {

        case 'Y':
            MyDice.roll();
            break;
        case 'y':
            MyDice.roll();
            break;
        case 'N':
            exit(0);
        case 'n':
            exit(0);
        default:
            cout << "Enter Valid Choice." << endl;
            break;
        }
    }
}