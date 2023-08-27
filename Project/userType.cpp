#include<iostream>
#include"userType.h"
using namespace std;

userType::userType(string name, string id, string contactNo) : name{name}, id{id}, contactNo{contactNo} {}
userType::userType(string name, string id) {
    this->name = name;
    this->id = id;
}




void userType::setName(string name)
{
    name = name;
}

void userType::setId(string id)
{
    id = id;
}

void userType::setContactNo(string No)
{
    contactNo = No;
}
string userType::getName() const
{
    return name;
}
string userType::getId() const
{
    return id;
}
string userType::getContactNo() const
{
    return contactNo;
}