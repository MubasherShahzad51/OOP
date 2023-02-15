#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <stdlib.h>
#define n 3

using namespace std;
struct studentType
{
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
    int highest_score;
};
void read_student_data(studentType Student[]);
void highest_score(studentType Student[]);
void grade(studentType Student[]);
void print_student_data(studentType Student[]);

int main()
{
    studentType S1[n];
    read_student_data(S1);
    grade(S1);
    print_student_data(S1);
    highest_score(S1);
    return 0;
}
void read_student_data(studentType Student[])
{
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Student " << i + 1 << " First Name: ";
        cin >> Student[i].studentFName;
        cout << "Enter Student " << i + 1 << " Last Name: ";
        cin >> Student[i].studentLName;
        cin.ignore();
        cout << "Enter Student " << i + 1 << " Test Score: ";
        cin >> Student[i].testScore;
    }
}
void highest_score(studentType Student[])
{
    int highestScore ;
    int i,temp=0;
        highestScore = 0;
    for (i = 0; i < n; i++)
    {    
        if (Student[i].testScore > highestScore)
        {
            highestScore = (Student[i].testScore);
            temp=i;
        
        }
    }
            cout << endl << "Student " << temp+1 << " " << Student[temp].studentFName << " " << Student[temp].studentLName << " has Highest Score:" << highestScore << endl;
}

void grade(studentType Student[])
{
    for (int i = 0; i < n; i++)
    {
        if (Student[i].testScore >= 90)
        {
            Student[i].grade = 'A';
        }
        else if (Student[i].testScore >= 80)
        {
            Student[i].grade = 'B';
        }
        else if (Student[i].testScore >= 70)
        {
            Student[i].grade = 'C';
        }
        else if (Student[i].testScore >= 60)
        {
            Student[i].grade = 'D';
        }
        else
        {
            Student[i].grade = 'F';
        }
        // cout << "Grade of student " << i + 1 << " is: " << Student[i].grade << endl;
    }
}

void print_student_data(studentType Student[])
{
    for (int i = 0; i < n; i++)
    {
        cout << "Student " << i + 1 << ": " <<setw(1)<<left<< Student[i].studentFName<<", "<<setw(1)<<right<<Student[i].studentLName<<";"<< endl;
        // cout << "Student " << i + 1 << " Last  Name is : " << Student[i].studentLName << endl;
        cout << "Student " << i + 1 << " Test Score: " << Student[i].testScore << endl;
        cout << "Student " << i + 1 << " Grade: " << Student[i].grade << endl;
    }
}