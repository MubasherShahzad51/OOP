#include <iostream>
#include <cstring>
#include"Declaration.h"
using namespace std;
void Menu()
{

    cout << endl
         << "-------------<< MENU >>-------------" << endl;
    cout << "1). Add a Song." << endl;
    cout << "2). Delete a Song." << endl;
    cout << "3). Update a Song." << endl;
    cout << "4). Print All Songs." << endl;
    cout << "5). Backup of Songs." << endl;
    cout << "6). Exit." << endl;
}
int main()
{
    int choice, index;
    string Song, usersong;
    Favourite_Songs playlist;
    cout << "Enter Any song: ";
    getline(cin, usersong, '\n');
    playlist.addSong(usersong);

    while (1)
    {
        Menu();
        cout << "Enter Your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cin.ignore();
            cout << "Enter Your Song: ";
            getline(cin, Song, '\n');

            playlist.addSong(Song);
            break;
        case 2:
            cin.ignore();
            cout << "Enter Your Song To Delete: ";
            getline(cin, Song, '\n');
            playlist.deleteSong(Song);
            break;
        case 3:
            cin.ignore();
            cout << "In Which index do you want to update: ";
            cin >> index;
            cin.ignore();
            cout << "Enter New song: ";
            getline(cin, Song, '\n');
            playlist.updateSong(index, Song);
            break;
        case 4:
            cout << "---------------<< Songs List >>---------------" << endl;
            playlist.printSongs();
            break;

        case 5:
        {
            cout << "---------------<< Backup Songs List >>---------------" << endl;
            Favourite_Songs temp(playlist);
            temp.printSongs();

            break;
        }
        case 6:
            exit(0);
        }
    }

    return 0;
}