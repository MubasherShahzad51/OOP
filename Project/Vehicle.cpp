#include<iostream>
#include"Vehicle.h"

using namespace std;


void Vehicle::setVehicleType(string type)
{
    vehicleType = type;
}
void Vehicle::setVehicleModel(string model)
{
    vehicleModel = model;
}
void Vehicle::setRegistrationNumber(string regNo)
{
    registrationNumber = regNo;
}
void Vehicle::setSlotNumber(int slot)
{
    slotNumber = slot;
}
void Vehicle::setKeyCode(int code)
{
    keyCode = code;
}
void Vehicle::setIsParked(bool parked)
{
    isParked = parked;
}
void Vehicle::setOwnerID(string id)
{
    ownerID = id;
}
string Vehicle::getVehicleType()
{
    return vehicleType;
}
string Vehicle::getVehicleModel()
{
    return vehicleModel;
}
string Vehicle::getRegistrationNumber()
{
    return registrationNumber;
}
int Vehicle::getSlotNumber()
{
    return slotNumber;
}
int Vehicle::getKeyCode()
{
    return keyCode;
}
bool Vehicle::getIsParked()
{
    return isParked;
}
string Vehicle::getOwnerID()
{
    return ownerID;
}