#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    float weight, height, BMI;
    // Taking Weight as input in Kg from the user
    cout << "Enter Your Weight in Kg:";
    cin >> weight;
    // Taking height as input in meters from the user
    cout << "Enter your Heights in Meters:";
    cin >> height;
    // using bultin power function
    BMI = weight / pow(height, 2);
    cout << "BMI is:" << BMI << endl;
    return 0;
}