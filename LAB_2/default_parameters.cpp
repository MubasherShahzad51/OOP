#include<iostream>

using namespace std;
void fun(int x = 5){
    cout<<"X = "<<x<<endl;
}
int main()
{
    // default value will show
    fun();
    // it will override the default value by passing our own value
    fun(6);
    fun(8);
    return 0;
}