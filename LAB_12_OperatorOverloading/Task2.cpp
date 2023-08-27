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

    friend Complex operator++(Complex &);
    friend Complex operator+(const Complex &, const Complex &);
};

Complex operator++(Complex &c)
{
    Complex temp;
    temp.real = ++c.real;
    temp.imag = c.imag;
    return temp;
}

Complex operator+(const Complex &c1, const Complex &c2)
{
    int r = c1.real + c2.real;
    int i = c1.imag + c2.imag;
    return Complex(r, i);
}

int main()
{
    Complex c1(5, 12);
    Complex c2(3, 4);
    ++c1;
    cout << "After Increment" << endl;

    c1.display();
    Complex c3 = c1 + c2;
    cout << "After Adition" << endl;
    c3.display();

    return 0;
}