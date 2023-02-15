#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <stdlib.h>

using namespace std;
struct smartphone
{
    int a;
    string b;
    float c;

};
struct smartphone2
{
    int a;
    string b;
};
struct smartphone3
{
    int a;
    string b;
};
int main()
{
    smartphone s1;
    smartphone2 s2;
    smartphone3 s3;

    cout << sizeof(s1) << endl;
    cout << sizeof(s2) << endl;
    cout << sizeof(s3) << endl;
    cout << sizeof(s1.a) << endl;
    cout << sizeof(s1.b) << endl;
     cout << sizeof(s1.c) << endl;
    cout << sizeof(s2.a) << endl;
    cout << sizeof(s2.b) << endl;

    cout << sizeof(s3.a) << endl;
      cout << sizeof(s3.b) << endl;


    return 0;
}