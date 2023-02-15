#include <iostream>
using namespace std;
void display(int &x)
{
    x++;
    cout << "Value in Function:" << x << endl;
    cout << "Address of x:" << &x << endl;
}
int main()
{
    int a = 5;
    cout << "Value in main Function:" << a << endl;
    display(a);
    cout << "Value in main after Function call:" << a << endl;
    cout << "Address of a in main:" << &a << endl;

    return 0;
}