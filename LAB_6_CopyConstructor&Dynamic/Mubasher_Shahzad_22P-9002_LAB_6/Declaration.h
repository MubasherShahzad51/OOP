#include <iostream>
#include <cstring>

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
    void Menu();
};