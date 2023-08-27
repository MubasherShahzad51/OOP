#ifndef ADMIN_H
#define ADMIN_H
#include"userType.h"
#include"ParkingLot.h"

using namespace std;

class Admin
{
private:
    string userID;
    string password;

public:
 Admin(string id = "admin", string pass = "123");
   bool authenticate(string id, string pass);
};
#endif