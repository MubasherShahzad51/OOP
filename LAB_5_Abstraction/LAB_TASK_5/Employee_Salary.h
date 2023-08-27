#include<iostream>
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