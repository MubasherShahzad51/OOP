#include <iostream>
using namespace std;

class Boat
{
protected:
    int boatLength;

public:
    Boat(int length) : boatLength(length) {}
    void swim()
    {
        cout << "I am swimming" << endl;
    }
};

class Plane
{
protected:
    int maxAltitude;

public:
    Plane(int altitude) : maxAltitude(altitude) {}
    void fly()
    {
        cout << "I am flying" << endl;
    }
};

class Skimmer : protected Boat, protected Plane
{
private:
    string name;
    int numPassengers;

public:
    Skimmer(int length, int altitude, string n, int num) : Boat(length), Plane(altitude), name(n), numPassengers(num) {}
    void swimAndFly()
    {
        swim();
        fly();
    }
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Number of Passengers: " << numPassengers << endl;
        cout << "Boat Length: " << boatLength << endl;
        cout << "Maximum Altitude: " << maxAltitude << endl;
    }
};

int main()
{
    Skimmer s(50, 10000, "Skimmer Flying Boat", 6);
    s.display();
    s.swimAndFly();
    return 0;
}