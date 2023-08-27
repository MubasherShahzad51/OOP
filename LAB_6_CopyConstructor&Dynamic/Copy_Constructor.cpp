#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<stdlib.h>

using namespace std;
class Circle{
    int radius;
    public:
    void setRadius(int r){
        radius = r;
    }
    int getRadius(){
        return radius;
    }
    // default constructor
    Circle(){
        radius = 0;
    }
    // pass reference of the object
    Circle(Circle &c){
        radius = c.radius;

    }
};
int main()
{
    Circle c;
    c.setRadius(5);
    Circle c2(c);
    cout<<"C1 Radius "<<c.getRadius()<<endl;
    c.setRadius(6);
    cout<<"C2 Radius "<<c2.getRadius()<<endl;

    return 0;
}