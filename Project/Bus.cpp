#include<iostream>
#include"Bus.h"
using namespace std;
void Bus ::showDetails()
{
    cout << "Vehicle Type: " << vehicleType << endl;
    cout << "Vehicle Model: " << vehicleModel << endl;
    cout << "Registration Number: " << registrationNumber << endl;
    cout << "Slot Number: " << slotNumber << endl;
    cout << "Key Code: " << keyCode << endl;
    cout << "Owner ID: " << ownerID << endl;
}