#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <limits>
#include <fstream>
#include"Vehicle.h"
#include"ParkingLot.h"
using namespace std;

ParkingLot::ParkingLot(int rows, int columns, int fee) : rows(rows), columns(columns), slotFee(fee), vehicleCount(0)
{
    totalSlots = new char *[rows];
    for (int i = 0; i < rows; i++)
    {
        totalSlots[i] = new char[columns];
        for (int j = 0; j < columns; j++)
        {
            totalSlots[i][j] = '#';
        }
    }
    for (int i = 0; i < parkingsize; i++)
    {
        vehicles[i] = nullptr;
    }
}

ParkingLot::~ParkingLot()
{
    for (int i = 0; i < rows; i++)
    {
        delete[] totalSlots[i];
    }
    delete[] totalSlots;
}

void ParkingLot::showAvailableSlots()
{
    bool isFull = true;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << totalSlots[i][j] << " ";
            if (totalSlots[i][j] == '#')
            {
                isFull = false;
            }
        }
        cout << endl;
    }
    if (isFull)
    {
        cout << "No Parking Available, all the slots are full." << endl;
    }
}

bool ParkingLot::isSlotAvailable(int slot)
{
    int row = (slot - 1) / columns;
    int col = (slot - 1) % columns;
    return totalSlots[row][col] == '#';
}

void ParkingLot::reserveSlot(int slot)
{
    int row = (slot - 1) / columns;
    int col = (slot - 1) % columns;
    totalSlots[row][col] = '*';
}

void ParkingLot::releaseSlot(int slot)
{
    int row = (slot - 1) / columns;
    int col = (slot - 1) % columns;
    totalSlots[row][col] = '#';
}

bool ParkingLot::isRegistrationNumberUnique(string regNo)
{
    for (int i = 0; i < vehicleCount; i++)
    {
        if (vehicles[i]->getRegistrationNumber() == regNo)
        {
            return false;
        }
    }
    return true;
}

int ParkingLot::generateUniqueKeyCode()
{
    srand(time(0));
    int code;
    bool isUnique;
    do
    {
        isUnique = true;
        code = rand() % 900 + 100;
        for (int i = 0; i < vehicleCount; i++)
        {
            if (vehicles[i]->getKeyCode() == code)
            {
                isUnique = false;
                break;
            }
        }
    } while (!isUnique);
    return code;
}

void ParkingLot::addVehicle(Vehicle *v)
{
    vehicles[vehicleCount++] = v;
}

Vehicle *ParkingLot::findVehicleByRegNo(string regNo)
{
    for (int i = 0; i < vehicleCount; i++)
    {
        if (vehicles[i]->getRegistrationNumber() == regNo)
        {
            return vehicles[i];
        }
    }
    return nullptr;
}

int ParkingLot::getSlotFee() const { return slotFee; }
void ParkingLot::setSlotFee(int fee) { slotFee = fee; }

void ParkingLot::showVehicleRecord()
{
    cout << left << setw(15) << "ID" << setw(20) << "Registration #" << setw(10) << "Key Code" << setw(10) << "Status" << setw(10) << "Total Fee" << endl;
    for (int i = 0; i < vehicleCount; i++)
    {
        cout << left << setw(15) << vehicles[i]->getOwnerID() << setw(20) << vehicles[i]->getRegistrationNumber() << setw(10) << vehicles[i]->getKeyCode() << setw(10) << (vehicles[i]->getIsParked() ? "Current" : "Gone") << setw(10) << (vehicles[i]->getIsParked() ? "------" : to_string(slotFee) + "$") << endl;
    }
}

void ParkingLot::printVehicleRecordToFile()
{
    ofstream outFile("vehicle_records.txt");
    outFile << left << setw(15) << "ID" << setw(20) << "Registration #" << setw(10) << "Key Code" << setw(10) << "Status" << setw(10) << "Total Fee" << endl;
    for (int i = 0; i < vehicleCount; i++)
    {
        outFile << left << setw(15) << vehicles[i]->getOwnerID() << setw(20) << vehicles[i]->getRegistrationNumber() << setw(10) << vehicles[i]->getKeyCode() << setw(10) << (vehicles[i]->getIsParked() ? "Current" : "Gone") << setw(10) << (vehicles[i]->getIsParked() ? "------" : to_string(slotFee) + "$") << endl;
    }
    outFile.close();
}

int ParkingLot::getTotalVehiclesParked()
{
    int count = 0;
    for (int i = 0; i < vehicleCount; i++)
    {
        if (vehicles[i]->getIsParked())
        {
            count++;
        }
    }
    return count;
}

int ParkingLot::getTotalAmountCollected()
{
    int count = 0;
    for (int i = 0; i < vehicleCount; i++)
    {
        if (!vehicles[i]->getIsParked())
        {
            count += slotFee;
        }
    }
    return count;
}