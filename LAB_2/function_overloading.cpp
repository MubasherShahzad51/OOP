#include <iostream>
using namespace std;
void sum(int a, int b)
{
    cout << "In Function 1:" << endl;
}
void sum(int a, int b, int c)
{
    cout << "In Function 2:" << endl;
}
void sum(int a, float b)
{
    cout << "In Function 3:" << endl;
}
void sum(float a, int b)
{
    cout << "In Function 4:" << endl;
}
int main()
{
    int a = 5;
    int b = 6;
    sum(a, b);
    return 0;
}