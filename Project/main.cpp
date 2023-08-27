#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <limits>
#include <fstream>
#include "Bus.h"
#include "Bike.h"
#include "Truck.h"
#include "Car.h"
#include "userType.h"
#include "Vehicle.h"
#include "ParkingLot.h"
#include "Admin.h"
#include "Owner.h"
using namespace std;
void Menu();

int main()
{
    Owner o1;
    ParkingLot parkingLot(7, 7, 100);
    Vehicle *p = nullptr;
    Admin admin("admin", "123");
    string input;
    string pass;

    int choice;
    while (true)
    {
        Menu();
        cout << "Enter your choice: ";
        cin >> choice;

        while (cin.fail() || cin.peek() != '\n')
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "ERROR::::::::::::Invalid Choise . \nEnter your choice: ";
            cin >> choice;
        }
        switch (choice)
        {

        case 1:
            parkingLot.showAvailableSlots();
            break;
        case 2:
            p = o1.InputData(parkingLot);
            break;

        case 3:
            o1.Exit(parkingLot);
            break;
        case 4:

            cout << "Enter your login ID: ";
            cin >> input;

            cout << "Enter your password: ";
            cin >> pass;

            if (admin.authenticate(input, pass))
            {
                int adminChoice;
                while (true)
                {
                    cout << "1. SHOW VEHICLES RECORD" << endl;
                    cout << "2. TOTAL VEHICLES PARKED" << endl;
                    cout << "3. TOTAL AMOUNT COLLECTED" << endl;
                    cout << "4. MODIFY FLOOR PARKING CHARGES" << endl;
                    cout << "5. PRINT RECORD ON FILE" << endl;
                    cout << "6. EXIT" << endl;
                    cout << "Enter your choice: ";
                    cin >> adminChoice;

                    if (adminChoice == 1)
                    {
                        parkingLot.showVehicleRecord();
                    }
                    else if (adminChoice == 2)
                    {
                        cout << "Total Vehicles Parked: " << parkingLot.getTotalVehiclesParked() << endl;
                    }
                    else if (adminChoice == 3)
                    {
                        cout << "Total Amount Collected: $" << parkingLot.getTotalAmountCollected() << endl;
                    }
                    else if (adminChoice == 4)
                    {
                        int newFee;
                        cout << "Enter the new slot fee: ";
                        cin >> newFee;
                        parkingLot.setSlotFee(newFee);
                    }
                    else if (adminChoice == 5)
                    {
                        parkingLot.printVehicleRecordToFile();
                        cout << "Vehicle records have been printed to the file." << endl;
                    }
                    else if (adminChoice == 6)
                    {
                        break;
                    }
                    else
                    {
                        cout << "Invalid choice. Please enter a valid option." << endl;
                    }
                }
            }
            else
            {
                cout << "Invalid login ID or password." << endl;
            }

            break;
            case 5:
            exit(0);
            break;
        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    }

delete p;
p=nullptr;
    return 0;
}

void Menu()
{

    cout << "-----------------------------------------------------" << endl;
    cout << "1). Show Available Parking Lots. " << endl;
    cout << "2). Arrival Of Vehicle. " << endl;
    cout << "3). Departure Of Vehicle. " << endl;
    cout << "4). Administration System. " << endl;
    cout << "5). Exit. " << endl;
    cout << "-----------------------------------------------------" << endl;
}