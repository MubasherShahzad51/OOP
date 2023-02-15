#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <stdlib.h>

using namespace std;
struct MovieData
{
    string Title;
    string Director;
    int YearReleased;
};
MovieData createMovieData(MovieData m)
{    
    cout << "Enter Movie Title: ";
    getline(cin, m.Title);
    cout << "Enter The Name Of Movie Director: ";
    getline(cin, m.Director);
    cout << "Enter Movie Year Of Released: ";
    cin>>m.YearReleased;

    return m;
}
void displayMovieData(MovieData m)
{
    cout<<"Movie Title: "<<m.Title<<endl;
    cout<<"Movie Director: "<<m.Director<<endl;
    cout<<"Movie Year Of Release: "<<m.YearReleased<<endl;

}
int main()
{
    MovieData Movie, temp;
    temp = createMovieData(Movie);
    Movie = temp;
    displayMovieData(Movie);    

    return 0;
}