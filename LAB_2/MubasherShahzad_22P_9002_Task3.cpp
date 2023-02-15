#include <iostream>

using namespace std;
int main()
{
    int option, floor, room_number, days;
    char array[4][5];

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
            array[i][j] = '-';
    }

    do
    {

        cout << "1) Show Available Rooms. " << endl;
        cout << "2) Book a Room. " << endl;
        cout << "3) Exit the Program. " << endl;
        cin >> option;
        int total = 0;
        if (option == 1)
        {

            cout << "- Indicates Room is Available and * indicates Room is already booked. " << endl;
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    cout << array[i][j] << " ";
                }
                cout << endl;
            }
            continue;
        }
        if (option == 2)
        {

            cout << "On which floor you want to get room (1-4): ";
            cin >> floor;
            cout << "Enter room number (1-5): ";
            cin >> room_number;
            cout << "For how many days you want to book the room: ";
            cin >> days;

            if (floor == 1 || floor == 2)
            {
                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 5; j++)

                        if (array[floor - 1][room_number - 1] != '-')
                        {
                            cout << "Sorry this Room is already Booked " << endl
                                 << endl;
                            break;
                        }

                        else
                        {
                            array[floor - 1][room_number - 1] = '*';
                            total = days * 10000;
                            cout << "Room Successfully Booked  on floor " << floor << " Room " << room_number << endl;
                            cout << "Total Cost is :" << total << " Rs" << endl
                                 << endl;
                            break;
                        }
                    break;
                }
            }

            else if (floor == 3 || floor == 4)
            {

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 5; j++)
                        if (array[floor - 1][room_number - 1] != '-')
                        {
                            cout << "Sorry this Room is already booked " << endl
                                 << endl;
                            break;
                        }

                        else
                        {
                            array[floor - 1][room_number - 1] = '*';
                            total = days * 6000;
                            cout << "Room Successfully Booked  on floor " << floor << " Room " << room_number << endl;
                            cout << endl
                                 << "Total Cost is :" << total << " Rs" << endl
                                 << endl;
                            break;
                        }
                    break;
                }
            }
            else
            {
                cout << "Please enter valid choice." << endl
                     << endl;
            }

            continue;
        }

        else if (option == 3)
        {
            break;
        }
        else
        {
            cout << "Please enter valid choice." << endl
                 << endl;
            continue;
        }

    } while (1);

    return 0;
}