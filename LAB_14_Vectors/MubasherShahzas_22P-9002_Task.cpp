#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Item
{
public:
    string name;
    double price;

    Item(string name, double price) : name(name), price(price) {}
};

void displayMenu()
{
    cout << "Menu:\n";
    cout << "1. Add items\n";
    cout << "2. Remove items\n";
    cout << "3. Clear cart\n";
    cout << "4. Exchange product\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

void displayProducts(const vector<Item> &products)
{
    cout << "Available products:\n";
    for (int i = 0; i < products.size(); ++i)
    {
        cout << i + 1 << ". " << products[i].name << "  $" << products[i].price << "\n";
    }
}

void displayCart(const vector<Item> &cart)
{
    if (cart.empty())
    {
        cout << "Your cart is empty.\n";
    }
    else
    {
        cout << "Your cart:\n";
        for (int i = 0; i < cart.size(); ++i)
        {
            cout << i + 1 << ". " << cart[i].name << "  $" << cart[i].price << "\n";
        }
    }
}

int main()
{
    vector<Item> products = {
        Item("Shirt", 10.05),
        Item("Jeans", 15.15),
        Item("Shoes", 5.5),
        Item("Glasses", 3.33)};

    vector<Item> cart;
    int choice;

    do
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            displayProducts(products);
            int productIndex;
            cout << "Enter the product number to add to the cart: ";
            cin >> productIndex;
            cart.push_back(products[productIndex - 1]);
            cout << "Product added to the cart.\n";
            break;
        }
        case 2:
        {
            displayCart(cart);
            if (!cart.empty())
            {
                int itemIndex;
                cout << "Enter the item number to remove from the cart: ";
                cin >> itemIndex;
                cart.erase(cart.begin() + itemIndex - 1);
                cout << "Item removed from the cart.\n";
            }
            break;
        }
        case 3:
        {
            cart.clear();
            cout << "Cart cleared.\n";
            break;
        }
        case 4:
        {
            displayCart(cart);
            if (!cart.empty())
            {
                int itemIndex;
                cout << "Enter the item number to exchange: ";
                cin >> itemIndex;
                displayProducts(products);
                int productIndex;
                cout << "Enter the product number to replace with: ";
                cin >> productIndex;
                cart[itemIndex - 1] = products[productIndex - 1];
                cout << "Product exchanged.\n";
            }
            break;
        }
        case 5:
        {
            cout << "Exit\n";
            break;
        }
        default:
        {
            cout << "Invalid choice. Please try again.\n";
            break;
        }
        }
    } while (choice != 5);

    return 0;
}