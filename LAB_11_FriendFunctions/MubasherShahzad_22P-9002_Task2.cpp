#include <iostream>
using namespace std;
class Complex
{
private:
    int real;
    int imag;

public:
    Complex(int r, int i) : real(r), imag(i) {}
    void display()
    {
        cout << real << " + " << imag << "i";
    }
    friend Complex addComplex(Complex c1, Complex c2);
    friend Complex subComplex(Complex c1, Complex c2);
};

class Operations
{
public:
    static Complex add(Complex c1, Complex c2)
    {
        return addComplex(c1, c2);
    }
    static Complex sub(Complex c1, Complex c2)
    {
        return subComplex(c1, c2);
    }
};

Complex addComplex(Complex c1, Complex c2)
{
    int r = c1.real + c2.real;
    int i = c1.imag + c2.imag;
    return Complex(r, i);
}

Complex subComplex(Complex c1, Complex c2)
{
    int r = c1.real - c2.real;
    int i = c1.imag - c2.imag;
    return Complex(r, i);
}

int main()
{
    Complex c1(8, 12);
    Complex c2(2, 6);

    Complex Sum = Operations::add(c1, c2);
    Complex Sub = Operations::sub(c1, c2);

    cout << "The sum of ";
    c1.display();
    cout << " and ";
    c2.display();
    cout << " is ";
    Sum.display();
    cout << endl;

    cout << "The subtraction of ";
    c1.display();
    cout << " and ";
    c2.display();
    cout << " is ";
    Sub.display();
    cout << endl;

    return 0;
}