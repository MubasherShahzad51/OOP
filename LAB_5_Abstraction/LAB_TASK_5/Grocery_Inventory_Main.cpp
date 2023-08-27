#include <iostream>
#include <cstring>
#include <cmath>
#include "Grocery_Inventory.h"

using namespace std;
void update_item(GroceryInventory *item);
void search_item_by_id(GroceryInventory items[], int total_items, int id);
int main()
{
    int total_items;
    cout << "Enter the total number of items to store: ";
    cin >> total_items;
    // Arrays of Objects/instances
    GroceryInventory items[total_items];

    for (int i = 0; i < total_items; i++)
    {
        int item_ID;
        string item_Name;
        float item_Price;
        int item_Quantity;
        cout << "Enter item " << i + 1 << " details: " << endl;
        cout << "ID: ";
        cin >> item_ID;
        cout << "Name: ";
        cin.ignore();
        getline(cin, item_Name, '\n');
        cout << "Price: ";
        cin >> item_Price;
        cout << "Quantity: ";
        cin >> item_Quantity;

        items[i].set_id(item_ID);
        items[i].set_name(item_Name);
        items[i].set_price(item_Price);
        items[i].set_quantity(item_Quantity);
    }
    int choice;
    int id_no;
    while (1) // infinite Loop
    {
        cout << endl
             << "Menu:" << endl;
        cout << "1. Display Items" << endl;
        cout << "2. Update item details" << endl;
        cout << "3. Search for items by ID" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1)
        {

            for (int i = 0; i < total_items; i++)
            {
                items[i].display_details();
            }
        }
        else if (choice == 2)
        {
            update_item(items);
        }
        else if (choice == 3)
        {
            search_item_by_id(items, total_items, id_no);
        }
        else
            exit(0);
    }

    return 0;
}