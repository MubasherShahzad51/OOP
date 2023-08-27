#include <iostream>
#include <cstring>
#include"Declaration.h"

using namespace std;


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

void Favourite_Songs::Menu()
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