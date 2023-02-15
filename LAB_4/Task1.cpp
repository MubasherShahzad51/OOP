#include <iostream>
#include <string>
using namespace std;

class Account
{
private:
    string name;
    double balance;

public:
    Account()
    {
        name = "";
        balance = 0.0;
    }
    void depositAmount(double amount)
    {
        balance += amount;
    }
    void withdrawAmount(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
        }
        else
        {
            cout << "Youd Don't Have Enough balance!" << endl;
        }
    }
    string getName()
    {
        return name;
    }
    void setName(string &name)
    {
        this->name = name;
    }
    double getBalance()
    {
        return balance;
    }
    void setBalance(double &balance)
    {
        this->balance = balance;
    }
};

Account createAccount()
{
    Account account;
    string name;
    double balance;
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter your initial balance: ";
    cin >> balance;
    cin.ignore();
    account.setName(name);
    account.setBalance(balance);
    return account;
}

int main()
{
    Account account; 
    account = createAccount();
    int choice;
    double amount;

    while (true)
    {
        cout << "1. Display Balance" << endl;
        cout << "2. Deposit Amount" << endl;
        cout << "3. Withdraw Amount" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Balance: " << account.getBalance() << endl;
            break;
        case 2:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            account.depositAmount(amount);
            break;
        case 3:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            account.withdrawAmount(amount);
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid choice" << endl;
        }
    }
}
