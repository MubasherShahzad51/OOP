#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <stdlib.h>

using namespace std;

class Movie
{
public:
    string movie_name;
    int child_ticket_price;
    int adult_ticket_price;
    double adult_tickets_sold;
    double child_tickets_sold;
    double gross_amount;
    double amount_donated;
    double percentage_of_gross_amount;
    double net_sale;

    void output()
    {
        gross_amount = adult_ticket_price * adult_tickets_sold + child_ticket_price * child_tickets_sold;
        amount_donated = gross_amount * percentage_of_gross_amount / 100;
        net_sale = gross_amount - amount_donated;
        cout << endl
             << "Movie Name is: " << movie_name << endl;
        cout << "Number of Tickets Sold: " << adult_tickets_sold + child_tickets_sold << endl;
        cout << "Percentage of Gross Amount Donated: " << percentage_of_gross_amount << "%" << endl;
        cout << "Amount Donated: " << amount_donated << endl;
        cout << "Net Sale: " << net_sale << endl;
    }

    void input_movie_name();
    void adult_ticket();
    void child_ticket();
    void adult_sold();
    void child_sold();
    void percentage_of_donation();
};
void Movie ::input_movie_name()
{
    cout << "Enter movie name: ";
    getline(cin, movie_name);
}
void Movie ::adult_ticket()
{
    cout << "Enter the price for adult ticket: ";
    cin >> adult_ticket_price;
}
void Movie ::adult_sold()
{
    cout << "How many adult tickets are sold: ";
    cin >> adult_tickets_sold;
}
void Movie ::child_ticket()
{
    cout << "Enter the price for child ticket: ";
    cin >> child_ticket_price;
}
void Movie ::child_sold()
{
    cout << "How many child tickets are sold: ";
    cin >> child_tickets_sold;
}
void Movie ::percentage_of_donation()
{
    cout << "Percentage of donation: ";
    cin >> percentage_of_gross_amount;
}

int main()
{
    Movie Name;
    Name.input_movie_name();
    Name.adult_sold();
    Name.adult_ticket();
    Name.child_sold();
    Name.child_ticket();
    Name.percentage_of_donation();
    Name.output();

    return 0;
}