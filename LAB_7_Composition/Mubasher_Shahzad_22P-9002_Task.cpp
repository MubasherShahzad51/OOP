#include <iostream>
#include <cstring>
using namespace std;

class DateOfBirth
{
private:
    int day;
    int month;
    int year;

public:
    DateOfBirth()
    {

        day = 0;
        month = 0;
        year = 0;
    }

    DateOfBirth(int d, int m, int y)
    {
        setDate(d, m, y);
    }

    void setDate(int d, int m, int y)
    {

        day = d;
        month = m;
        year = y;
    }

    void printdate() const
    {

        cout << "DOB :" << day << "/" << month << "/" << year << endl;
    }

    void setMonth(int m)
    {

        month = m;
    }

    int getMonth()
    {
        return month;
    }
};

class Contact
{

private:
    string name;
    string email;
    string contact_No;

    DateOfBirth Person;

public:
    void setMONTH(int m)
    {
        Person.setMonth(m);
    }

    int returnMonth()
    {

        return Person.getMonth();
    }

    void setName(string c_name)
    {
        name = c_name;
    }

    string getName()
    {
        return name;
    }

    Contact(string name = "0", string email = "0", string contact_No = "0", int day = 0, int month = 0, int year = 0) : Person(day, month, year)
    {
        

        setContacts(name, email, contact_No);
    }
    void setContacts(string c_name, string c_email, string c_phone)
    {

        name = c_name;
        email = c_email;
        contact_No = c_phone;
    }

    void printContact() const
    {

        cout << "Name: " << name << endl
             << "Email: " << email << endl
             << "Phone Number: " << contact_No << endl;
        Person.printdate();
    }
};

class ContactsBook
{

private:
    Contact contacts[3];

public:
    void Add()
    {
        string c_name, c_email, c_phone;
        int d, m, y;
        for (int i = 0; i < 3; i++)
        {

            cout << "Enter Person " << i + 1 << " Name :";
            getline(cin, c_name);
            cout << "Enter Person " << i + 1 << " Email :";
            getline(cin, c_email);
            cin.clear();
            cout << "Enter Person " << i + 1 << " Phone Number :";
            getline(cin, c_phone);
            cin.clear();

            cout << "Enter Person " << i + 1 << " Day of Birth :";
            cin >> d;
            cout << "Enter Person " << i + 1 << " Month of Birth :";
            cin >> m;
            cout << "Enter Person " << i + 1 << " Year of Birth :";
            cin >> y;

            contacts[i] = Contact(c_name, c_email, c_phone, d, m, y);
            cin.ignore();
            cout << endl;
        }
    }

    void print()
    {
        for (int i = 0; i < 3; i++)
        {
            contacts[i].printContact();
            cout << endl;
        }
    }

    void printSpecific()
    {
        int month;
        cout << "Enter Specific Month : ";
        cin >> month;
        for (int i = 0; i < 3; i++)

            if (contacts[i].returnMonth() == month)
            {
                cout << "Name: " << contacts[i].getName() << endl;
            }
    }
};

int main()
{

    ContactsBook person;

    person.Add();
    person.print();
    person.printSpecific();
    return 0;
}