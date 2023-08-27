#include <iostream>
#include <string>

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
