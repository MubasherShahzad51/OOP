#include <iostream>
using namespace std;

class Complex
{
private:
    int real;
    int imag;

public:
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}
    void display()
    {
        cout << real << " + " << imag << "i" << endl;
    }

    Complex operator++()
    {
        Complex temp;
        temp.real = ++real;
        return temp;
    }
  
    Complex operator+(const Complex &temp)
    {
        int r = real + temp.real;
        int i = imag + temp.imag;
        return Complex(r, i);
    }
};

int main()
{
    Complex c1(5, 12);
    Complex c2(3, 4);
    ++c1;
    cout<<"After Increment"<<endl;
    c1.display();
    Complex c3 = c1 + c2;
    cout<<"After Addition"<<endl;
    c3.display();

    return 0;
}