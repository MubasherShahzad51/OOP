#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <limits>
#include <fstream>
#include"Vehicle.h"
using namespace std;


class ParkingLot
{

private:
    static const int parkingsize = 49;
    char **totalSlots;
    int rows;
    int columns;
    int slotFee;
    Vehicle *vehicles[parkingsize];
    int vehicleCount;

public:
    ParkingLot(int rows, int columns, int fee);
    ~ParkingLot();
    void showAvailableSlots();
    bool isSlotAvailable(int slot);
    void reserveSlot(int slot);
    void releaseSlot(int slot);
    bool isRegistrationNumberUnique(string regNo);
    int generateUniqueKeyCode();
    void addVehicle(Vehicle *v);
    Vehicle *findVehicleByRegNo(string regNo);
    int getSlotFee() const;
    void setSlotFee(int fee);
    void showVehicleRecord();
    void printVehicleRecordToFile();
    int getTotalVehiclesParked();
    int getTotalAmountCollected();
};

#endif