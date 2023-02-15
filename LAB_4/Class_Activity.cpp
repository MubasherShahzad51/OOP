#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <stdlib.h>

using namespace std;
class Rectangle
{
    int length;
    int width;

public:
    int getLength() // getter
    {
        return length;
    }
    int getWidth()
    {
        return width;
    }
    int calc_area()
    {
        return length * width;
    }
    void setLength(int l) // setter
    {
        length = l;
    }
    void setWidth(int w)
    {
        width = w;
    }
};
int main()
{
    int l, w;
    cout << "Enter length: " << endl;
    cin >> l;
    cin.ignore();
    cout << "Enter width: " << endl;
    cin >> w;
    Rectangle r;
    r.setLength(l);
    r.setWidth(w);
    cout << "Length: " << r.getLength() << endl;
    cout << "Width: " << r.getWidth() << endl;
    cout << "Area: " << r.calc_area() << endl;

    return 0;
}