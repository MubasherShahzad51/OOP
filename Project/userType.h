#ifndef USERTYPE_H
#define USERTYPE_H
#include<iostream>
#include<string>
using namespace std;
class userType
{
protected:
string name;
string id;
string contactNo;

public:

userType(){};
userType(string name = "", string id = "", string contactNo = "");
userType(string name = "", string id = "");
void setName(string);
void setId(string);
void setContactNo(string);
string getName() const;
string getId()const;
string getContactNo() const;
};
#endif