#include <iostream>
#include <cstring>
#include "Grocery_Inventory.h"

using namespace std;
// Defining default Constructor
GroceryInventory::GroceryInventory()
{
    item_ID = 0;
    item_Name = "None";
    item_Price = 0;
    item_Quantity = 0;
}
// Defining Parameterized Constructor
GroceryInventory::GroceryInventory(int item_ID, string item_Name, float item_Price, int item_Quantity)
{
    this->item_ID = item_ID;
    this->item_Name = item_Name;
    this->item_Price = item_Price;
    this->item_Quantity = item_Quantity;
}

// Defining Getter and Setter methods
int GroceryInventory::get_id()
{
    return item_ID;
}
string GroceryInventory::get_name()
{
    return item_Name;
}

float GroceryInventory::get_price()
{
    return item_Price;
}
int GroceryInventory::get_quantity()
{
    return item_Quantity;
}

void GroceryInventory::set_id(int item_ID)
{
    this->item_ID = item_ID;
}

void GroceryInventory::set_name(string item_Name)
{
    this->item_Name = item_Name;
}

void GroceryInventory::set_price(float item_Price)
{
    this->item_Price = item_Price;
}

void GroceryInventory::set_quantity(int item_Quantity)
{
    this->item_Quantity = item_Quantity;
}
void GroceryInventory::display_details()
{
    cout << "ID: " << item_ID << ", Name: " << item_Name << ", Price: " << item_Price << ", Quantity: " << item_Quantity << endl;
}
GroceryInventory::~GroceryInventory()
{
    cout << "Object destroyed" << endl;
}
// Declaring two void functions which update the items quantity and price and the pther pne search item by id
void update_item(GroceryInventory *item);
void search_item_by_id(GroceryInventory items[], int total_items, int id);

// Defining two void functions which update the items quantity and price and the pther pne search item by id
void update_item(GroceryInventory *item)
{
    int choice, option;
    cout << "For which item do you want to update Values: ";
    cin >> option;
    cout << "Enter 1 to update item_Price or 2 to update item_Quantity: ";
    cin >> choice;

    if (choice == 1)
    {
        float new_price;
        cout << "Enter new item_Price: ";
        cin >> new_price;
        item[option - 1].set_price(new_price);
    }
    else if (choice == 2)
    {
        int new_quantity;
        cout << "Enter new item_Quantity: ";
        cin >> new_quantity;
        item[option - 1].set_quantity(new_quantity);
    }
    else
    {
        cout << "Invalid choice." << endl;
    }
}

void search_item_by_id(GroceryInventory *items, int total_items, int id)
{
    bool found = false;
    // Search GroceryInventory By ID
    cout << "Enter ID: ";
    cin >> id;
    for (int i = 0; i < total_items; i++)
    {
        if (items[i].get_id() == id)
        {
            items[i].display_details();
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "GroceryInventory not found" << endl;
    }
}
