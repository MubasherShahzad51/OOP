#include <iostream>
using namespace std;

class Animal
{
public:
    string name;
    int age;
    // virtual keyword use for method or function overriding in derived class
    virtual void speak() {}
};

class Bird : private Animal
{
private:
    int wingLength;

public:
    Bird(string name, int age, int wingLength)
    {
        this->name = name;
        this->age = age;
        this->wingLength = wingLength;
    }
    void speak()
    {
        cout << "I am a bird."<<endl<<"My name is: "<< name <<endl<< "I am " << age << " years old." << endl;
        cout << "I have a wingspan of " << wingLength << " cm and I can sing." << endl;
    }
};

class Reptile : private Animal
{
private:
    string habitat;

public:
    Reptile(string name, int age, string habitat)
    {
        this->name = name;
        this->age = age;
        this->habitat = habitat;
    }
    void speak()
    {
        cout << "I am a reptile named " << name <<endl<< "I am " << age << " years old." << endl;
        cout << "I live in " << habitat << " and I can creep." << endl;
    }
};

int main()
{
    Bird b("Cuckoo", 5, 12);
    Reptile r("Snake", 10, "Jungle");
    b.speak();
    r.speak();
    return 0;
}