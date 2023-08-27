#include<iostream>
#include<cstring>
#include "Employee_Salary.h"
using namespace std;

Employee::Employee() // Default constructor
{

    employee_ID = 0;
    employee_Name = "None";
    employee_JobTitle = "Null";
    hours_per_week = 0;
}
// parameterized constructor
Employee::Employee(int employee_ID, string employee_Name, string employee_JobTitle, int hours_per_week)
{

    this->employee_ID = employee_ID;
    this->employee_Name = employee_Name;
    this->employee_JobTitle = employee_JobTitle;
    this->hours_per_week = hours_per_week;
}
void Employee::set_id(int id)
{
    employee_ID = id;
}
void Employee::set_name(string name)
{
    employee_Name = name;
}
void Employee::set_jobTitle(string title)
{
    employee_JobTitle = title;
}
void Employee::set_hours(int hrs)
{
    hours_per_week = hrs;
}
int Employee::get_id()
{
    return employee_ID;
}
string Employee::get_name()
{
    return employee_Name;
}
string Employee::get_jobTitle()
{
    return employee_JobTitle;
}
int Employee::get_hours()
{
    return hours_per_week;
}
void Employee::Calc_Sallery()
{
    const int hour_rate = 1000;

    cout << "Employee Name  " << employee_Name << endl;
    int base_salary, extra_salary;
    if (hours_per_week <= 40)
    {
        base_salary = hours_per_week * 1000;
        cout << "Total salary is: " << base_salary << endl;
    }
    else if (hours_per_week > 40)
    {
        base_salary = 40 * 1000;
        cout << "Extra hours are: " << hours_per_week - 40 << endl;
        cout << "Extra Amount without base salary is: " << (hours_per_week - 40) * 2000 << endl;
        cout << "Base  salary is: " << base_salary << endl;
        extra_salary = base_salary + ((hours_per_week - 40) * 2000);
        cout << "Total Salary is : " << extra_salary << endl;
    }
}