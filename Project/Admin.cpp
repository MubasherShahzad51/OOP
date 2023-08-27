
#include<iostream>
#include"Admin.h"
#include<string>
using namespace std;
Admin:: Admin(string id , string pass ) {
     userID = id;
   password = pass;
}
bool Admin ::authenticate(string id, string pass)
{
    bool temp = (userID == id && password == pass) ? true : false;
    return temp;
}
