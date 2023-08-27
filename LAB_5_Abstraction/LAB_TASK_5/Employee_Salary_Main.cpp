#include<iostream>
#include<cstring>
#include"Employee_Salary.h"
using namespace std;

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