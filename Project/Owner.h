#ifndef OWNER_H
#define OWNER_H


#include <iostream>
#include"Vehicle.h"
#include"userType.h"
#include "ParkingLot.h"
using namespace std;

class Owner : public userType
{

    int type;

public:

     Owner(): userType("admin", id, "contact") {}
    Vehicle *InputData(ParkingLot &parking);

    Vehicle *Exit(ParkingLot &parking);

};
#endif
