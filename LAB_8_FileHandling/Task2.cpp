#include <iostream>
#include <string>

using namespace std;

class Employee
{
    string name;
    double salary;

public:
    Employee(string name, double salary)
    {
        this->name = name;
        this->salary = salary;
    }
    string getName()
    {
        return name;
    }
    double calcSalary()
    {
        return salary;
    }
};

class HourlyEmployee : public Employee
{
    double hourlyRate;
    int hoursWorked;

public:
    HourlyEmployee(string name, double hourlyRate, int hoursWorked)
        : Employee(name, 0), hourlyRate(hourlyRate), hoursWorked(hoursWorked) {}
    double calcSalary()
    {
        return hourlyRate * hoursWorked;
    }
};

class SalariedEmployee : public Employee
{
    double annualSalary;

public:
    SalariedEmployee(string name, double annualSalary)
        : Employee(name, 0), annualSalary(annualSalary) {}
    double calcSalary()
    {
        return annualSalary / 12;
    }
};

int main()
{
    string name;
    double hourlyRate, annualSalary;
    int hoursWorked;

    cout << "Enter hourly employee name: ";
    getline(cin, name);
    cout << "Enter hourly rate: $";
    cin >> hourlyRate;
    cout << "Enter hours worked: ";
    cin >> hoursWorked;

    HourlyEmployee hourlyEmployee(name, hourlyRate, hoursWorked);
    cout << "Hourly Employee Details:\n"
         << "Name: " << hourlyEmployee.getName() << endl
         << "Hourly Rate: $" << hourlyRate << endl
         << "Hours Worked: " << hoursWorked << endl
         << "Hourly Employee Salary: $" << hourlyEmployee.calcSalary() << endl;

    // ignore the newline character
    cin.ignore();  
    cout << "\nEnter salaried employee name: ";
    getline(cin, name);
    cout << "Enter annual salary: $";
    cin >> annualSalary;

    SalariedEmployee salariedEmployee(name, annualSalary);
    cout << "Salaried Employee Details:\n"
         << "Name: " << salariedEmployee.getName() << endl
         << "Annual Salary: $" << annualSalary << endl
         << "Salaried Employee Salary: $" << salariedEmployee.calcSalary() << endl;

    return 0;
}