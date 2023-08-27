#include <iostream>
#include <string>

using namespace std;

// Animal abstract class
class Animal
{
protected:
    string name;
    string color;

public:
    Animal(string name, string color) : name(name), color(color) {}
    virtual ~Animal() {}
    virtual void display() = 0;
};

// Deer class derived from Animal
class Deer : public Animal
{
private:
    bool hasAntlers;

public:
    Deer(string name, string color, bool hasAntlers)
        : Animal(name, color), hasAntlers(hasAntlers) {}
    void display()
    {
        cout << "Deer Name: " << name << endl;
        cout << "Color: " << color << endl;
        cout << "Has Antlers: " << (hasAntlers ? "Yes" : "No") << endl;
    }
};

// Zebra class derived from Animal
class Zebra : public Animal
{
private:
    string stripe_pattern;

public:
    Zebra(string name, string color, string stripe_pattern)
        : Animal(name, color), stripe_pattern(stripe_pattern) {}
    void display()
    {
        cout << "Zebra Name: " << name << endl;
        cout << "Color: " << color << endl;
        cout << "Stripe Pattern: " << stripe_pattern << endl;
    }
};

int main()
{
    // Create Deer object and call its display() method
    Animal *deer = new Deer("Elk", "Brown", true);
    deer->display();
    delete deer;

    // Create Zebra object and call its display() method
    Animal *zebra = new Zebra("Plains Zebra", "Black and White", "Vertical");
    zebra->display();
    delete zebra;

    return 0;
}