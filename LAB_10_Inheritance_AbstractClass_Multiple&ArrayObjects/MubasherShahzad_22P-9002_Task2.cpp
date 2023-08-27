#include <iostream>
#include <string>

using namespace std;

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

class Deer : public Animal
{
private:
    bool hasAntlers;

public:
    Deer(string name, string color, bool hasAntlers) : Animal(name, color), hasAntlers(hasAntlers) {}

    void display()
    {
        cout << "Deer Name: " << name << endl;
        cout << "Color: " << color << endl;
        cout << "Has Antlers: " << (hasAntlers ? "Yes" : "No") << endl;
    }
};

class Zebra : public Animal
{
private:
    string stripePattern;

public:
    Zebra(string name, string color, string stripePattern) : Animal(name, color), stripePattern(stripePattern) {}

    void display()
    {
        cout << "Zebra Name: " << name << endl;
        cout << "Color: " << color << endl;
        cout << "Stripe Pattern: " << stripePattern << endl;
    }
};

void displayAll(Animal **animals, int size)
{
    for (int i = 0; i < size; i++)
    {
        animals[i]->display();
    }
}

int main()
{
    const int size = 3;
    Animal *animals[size];

    animals[0] = new Deer("Elk", "Brown", true);
    animals[1] = new Zebra("Plains Zebra", "Black and White", "Vertical");
    animals[2] = new Deer("Muntjac", "Dull Grey", true);

    displayAll(animals, size);

    for (int i = 0; i < size; i++)
    {
        delete animals[i];
    }

    return 0;
}