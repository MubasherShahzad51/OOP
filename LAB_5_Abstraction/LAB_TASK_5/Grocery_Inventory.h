#include <iostream>
using namespace std;
class GroceryInventory // class is a template
{
private:
    int item_ID;
    string item_Name;
    float item_Price;
    int item_Quantity;

public:
    // Declaring Default Constructor
    GroceryInventory();
    // Declaring Paramterized Constructor
    GroceryInventory(int item_ID, string item_Name, float item_Price, int item_Quantity);
    // Declaring Getter and Setter methods
    int get_id();
    string get_name();
    float get_price();
    int get_quantity();
    void set_id(int item_ID);
    void set_name(string item_Name);
    void set_price(float item_Price);
    void set_quantity(int item_Quantity);
    // Declaring Destructor
    ~GroceryInventory();
    void display_details();
};
