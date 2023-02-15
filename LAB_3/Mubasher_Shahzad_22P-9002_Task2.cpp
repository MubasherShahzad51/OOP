#include <iostream>
using namespace std;

struct StudentData
{
    string name;
    int courses[3];
};

StudentData get_student_data(StudentData foo);
void Calc_Avg_Marks(StudentData foo);
void put_student_data(StudentData foo);
void Display_Menu();
void Change_Marks(StudentData *q);

int main()
{
    int option, number_of_students, num_of_courses, marks_updated;

    StudentData student1, student2, flag1, flag2;
    flag1 = get_student_data(student1);
    cin.ignore();
    flag2 = get_student_data(student2);

    while (1)
    {
        Display_Menu();
        cout << "Please enter your option:";
        cin >> option;

        if (option == 1)
        {
            put_student_data(flag1);
            cout << endl
                 << endl;
            put_student_data(flag2);
        }
        else if (option == 2)
        {
            cout << endl
                 << "Enter Student Number:  ";
            cin >> number_of_students;
            if (number_of_students == 1)
            {

                Calc_Avg_Marks(flag1);
                continue;
            }
            else if (number_of_students == 2)
            {
                Calc_Avg_Marks(flag2);
                continue;
            }
            else
            {
                cout << "Enter Correct stiudent number: ";
            }
        }
        else if (option == 3)
        {
            cout << "Enter the student Number: ";
            cin >> number_of_students;
            if (number_of_students == 1)
                Change_Marks(&flag1);
            else if (number_of_students == 2)
                Change_Marks(&flag2);
            else
                cout << "Enter Valid Student Number" << endl;
        }
        else if (option == 4)
        {

            exit(0);
        }
        else
        {
            cout << "Enter valid option." << endl;
        }
    }

    return 0;
}

StudentData get_student_data(StudentData foo)
{

    cout << "Enter Student Name : ";
    getline(cin, foo.name);
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter Marks of Subject " << i + 1 << " : ";
        cin >> foo.courses[i];
    }

    return foo;
}

void Calc_Avg_Marks(StudentData foo)
{
    double sum = 0.0, average = 0.0;
    for (int i = 0; i < 3; i++)
    {
        sum += foo.courses[i];
    }
    average = sum / 3;
    cout << "Average is: " << average << endl;
}

void put_student_data(StudentData foo)
{
    cout << "Student Name is :" << foo.name << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "Marks of Subject  " << i + 1 << " is: " << foo.courses[i] << endl;
    }
}
void Change_Marks(StudentData *q)
{
    int num_of_courses, marks_updated;

    cout << "Enter the course  Number to change Marks: ";
    cin >> num_of_courses;
    cout << "Enter Updated Marks: ";
    cin >> marks_updated;

    if (num_of_courses == 1)
        q->courses[0] = marks_updated;
    else if (num_of_courses == 2)
        q->courses[1] = marks_updated;
    else if (num_of_courses == 3)
        q->courses[2] = marks_updated;
    else
        cout << "Enter Correct subject Number: " << endl;
}

void Display_Menu()
{

    cout << endl
         << "1) Display Student Data." << endl
         << "2) Calculate Average Marks." << endl
         << "3) Change Marks Of Courses." << endl
         << "4) Exit." << endl;
}
