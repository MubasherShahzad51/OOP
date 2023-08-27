#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <limits>
#include <fstream>
#include"Vehicle.h"
#include"ParkingLot.h"
#include"userType.h"
#include"Owner.h"
#include"Truck.h"
#include"Bike.h"
#include"Bus.h"
#include"Car.h"



using namespace std;


Vehicle *Owner ::InputData(ParkingLot &parking)
{
    int type;
    string input;
    int slot;
    cout << "Enter Owner name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter Owner ID (e.g 1234): ";
    getline(cin, id);

    cout << "Enter Owner Contact Number (e.g 923106080378): ";
    getline(cin, contactNo);

    cout << "1. Car" << endl
         << "2. Truck" << endl
         << "3. Bike" << endl
         << "4. Bus " << endl
         << "Enter owner Vehicle type.";
    cin >> type;

    while (cin.fail() || cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "ERROR::::::::::::Invalid Vehicle type. \nEnter owner Vehicle type: ";
        cin >> type;
    }

    Vehicle *v = nullptr;
    switch (type)
    {
    case 1:
        v = new Car;
        v->setVehicleType("Car");
        break;
    case 2:
        v = new Truck();
        v->setVehicleType("Truck");
        break;
    case 3:
        v = new Bike();
        v->setVehicleType("Vike");
        break;
    case 4:
        v = new Bus();
        v->setVehicleType("Bus");
        break;
    default:
        cout << "Invalid Vehicle Type." << endl;
        break;
    }

    if (v != nullptr)
    {
        cout << "Enter Vehicle Model (e.g LX230) ";
        cin.ignore();
        getline(cin, input);
        v->setVehicleModel(input);

        while (true)
        {
            cout << "Enter Owner Car Registration Number (e.g XYZ0012): ";
            cin >> input;
            if (parking.isRegistrationNumberUnique(input))
            {
                v->setRegistrationNumber(input);
                break;
            }
            else
            {
                cout << "Registration number already exists. Please enter a unique registration number." << endl;
            }
        }

        while (true)
        {
            cout << "Enter the slot number you want to reserve (1-49): ";
            cin >> slot;

            while (cin.fail() || cin.peek() != '\n' || slot < 0 || slot > 49)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "ERROR::::::::::::Invalid Vehicle type. \nEnter the slot number you want to reserve (1-49): ";
                cin >> slot;
            }
            if (parking.isSlotAvailable(slot))
            {
                parking.reserveSlot(slot);
                v->setSlotNumber(slot);
                break;
            }
            else
            {
                cout << "Slot is not available. Please enter another slot number." << endl;
            }
        }

        int keyCode = parking.generateUniqueKeyCode();
        v->setKeyCode(keyCode);
        v->setIsParked(true);
        v->setOwnerID(id); // Set the owner ID attribute
        parking.addVehicle(v);

        cout << "Your unique key code is: " << keyCode << ". Remember this code." << endl;
        cout << "Your slot number is: " << slot << "." << endl;
    }
    

    return v;
}

Vehicle *Owner::Exit(ParkingLot &parking)
{
    string ownerID, regNo;
    int keyCode;

    cout << "Enter Owner ID: ";
    cin >> ownerID;

    cout << "Enter Owner Car Registration Number: ";
    cin >> regNo;

    Vehicle *v = parking.findVehicleByRegNo(regNo);
    if (v == nullptr)
    {
        cout << "Invalid registration number. Please enter the registration number you provided at the time of arrival." << endl;
        return nullptr;
    }

    if (!v->getIsParked())
    {
        cout << "This vehicle is not parked in the parking lot." << endl;
        return nullptr;
    }

    while (true)
    {
        cout << "Enter the unique key provided at the time of arrival: ";
        cin >> keyCode;
        if (v->getKeyCode() == keyCode && v->getOwnerID() == ownerID)
        {
            break;
        }
        else
        {
            cout << "Invalid key code or owner ID. Please enter valid information." << endl;
        }
    }

    parking.releaseSlot(v->getSlotNumber());
    v->setIsParked(false);
    cout << "Vehicle successfully exited by paying charges of $" << parking.getSlotFee() << "." << endl;

    return v;
}