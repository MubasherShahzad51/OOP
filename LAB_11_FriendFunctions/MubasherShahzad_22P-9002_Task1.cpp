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
        cout << real << " + " << imag << "i"<<endl;
    }
    friend Complex addComplex(Complex c1, Complex c2);
};

Complex addComplex(Complex c1, Complex c2)
{
    int r = c1.real + c2.real;
    int i = c1.imag + c2.imag;
    return Complex(r, i);
}

int main()
{
    Complex c1(5, 12);
    Complex c2(3, 4);
    cout<<"After Addition"<<endl;
    Complex sum = addComplex(c1, c2);
    sum.display(); 
    return 0;
}