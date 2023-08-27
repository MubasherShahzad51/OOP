#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <cstring>
#include <iomanip>

using namespace std;

class Favourite_Songs
{

private:
    string *songs;
    int size;

public:
    Favourite_Songs();
    Favourite_Songs(const Favourite_Songs &playlist);
    ~Favourite_Songs();
    void addSong(string song);
    void deleteSong(string song);
    void updateSong(int index, string newSong);
    void printSongs() const;
};

Favourite_Songs ::Favourite_Songs() : size(0), songs(new string[0]) {}
Favourite_Songs ::Favourite_Songs(const Favourite_Songs &playlist) : size(playlist.size), songs(new string[playlist.size])
{

    for (int i = 0; i < size; i++)
    {
        songs[i] = playlist.songs[i];
    }
}

Favourite_Songs ::~Favourite_Songs()
{
    delete[] songs;
}

void Favourite_Songs ::addSong(string song)
{
    string *newSongs = new string[size + 1];
    for (int i = 0; i < size; i++)
    {
        newSongs[i] = songs[i];
    }
    newSongs[size] = song;
    delete[] songs;
    size = size + 1;
    songs = newSongs;
}

void Favourite_Songs ::deleteSong(string song)
{
    int index = -1;
    for (int i = 0; i < size; i++)
    {
        if (songs[i] == song)
        {
            index = i;
            break;
        }
    }
    if (index != -1)
    {
        string *newSongs = new string[size - 1];
        for (int i = 0; i < index; i++)
        {
            newSongs[i] = songs[i];
        }
        for (int i = index + 1; i < size; i++)
        {
            newSongs[i - 1] = songs[i];
        }
        delete[] songs;
        size--;
        songs = newSongs;
    }
}
void Favourite_Songs ::updateSong(int index, string newSong)
{
    for (int i = 0; i < size; i++)
    {
        if (i + 1 == index)
        {
            songs[i] = newSong;
        }
    }
}

void Favourite_Songs ::printSongs() const
{
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << "). " << songs[i] << endl;
    }
}

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
    int choise, index;
    string Song, usersong;
    Favourite_Songs playlist;
    cout << "Enter Any song: ";
    getline(cin, usersong, '\n');
    playlist.addSong(usersong);

    while (1)
    {
        Menu();
        cout << "Enter Your choise: ";
        cin >> choise;

        switch (choise)
        {
        case 1:
            cin.ignore();
            cout << "Enter Your Song:";
            getline(cin, Song, '\n');

            playlist.addSong(Song);
            break;
        case 2:
            cin.ignore();
            cout << "Enter Your Song:";
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