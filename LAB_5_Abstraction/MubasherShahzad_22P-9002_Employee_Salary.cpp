#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
class Employee
{
private:
    int employee_ID;
    string employee_Name;
    string employee_JobTitle;
    int hours_per_week;

public:
    // Default constructor
    Employee();
    // parameterized constructor
    Employee(int employee_ID, string employee_Name, string employee_JobTitle, int hours_per_week);
    void set_id(int id);
    void set_name(string name);
    void set_jobTitle(string title);
    void set_hours(int hrs);
    int get_id();
    string get_name();
    string get_jobTitle();
    int get_hours();
    void Calc_Sallery();
};

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
int main()
{
    int no_of_employees;
    cout << "Enter No of Employees: ";
    cin >> no_of_employees;

    Employee Emp[no_of_employees]; // arrays of object Emp
    for (int i = 0; i < no_of_employees; i++)
    {
        int emp_id, week_hrs;
        string emp_name, job_title;
        cout << "Enter ID of Employee " << i + 1 << ": ";
        cin >> emp_id;
        cout << "Enter Name of Employee " << i + 1 << ": ";
        cin.ignore();
        getline(cin, emp_name, '\n');
        cout << "Enter Job Title of Employee " << i + 1 << ": ";
        getline(cin, job_title, '\n');
        cout << "Enter No of Hours per week of Employee " << i + 1 << ": ";
        cin >> week_hrs;
        Emp[i].set_id(emp_id);
        Emp[i].set_name(emp_name);
        Emp[i].set_jobTitle(job_title);
        Emp[i].set_hours(week_hrs);
    }
    for (int i = 0; i < no_of_employees; i++)
    {
        cout << endl
             << endl
             << "Employee " << i + 1 << " Record" << endl;
        Emp[i].Calc_Sallery();
    }

    return 0;
}