#ifndef Vehicle_H
#define Vehicle_H

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <limits>
#include <fstream>

using namespace std;
class Vehicle
{
protected:
    string vehicleType;
    string vehicleModel;
    string registrationNumber;
    int slotNumber;
    int keyCode;
    bool isParked;
    string ownerID;

public:
    virtual ~Vehicle() {}
    virtual void showDetails() = 0;
    void setVehicleType(string type);
    void setVehicleModel(string model);
    void setRegistrationNumber(string regNo);
    void setSlotNumber(int slot);
    void setKeyCode(int code);
    void setIsParked(bool parked);
    void setOwnerID(string id);
    string getVehicleType();
    string getVehicleModel();
    string getRegistrationNumber();
    int getSlotNumber();
    int getKeyCode();
    bool getIsParked();
    string getOwnerID();
};
#endif