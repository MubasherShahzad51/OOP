#include <iostream>
using namespace std;
int main()
{
    // declaring variable names and initializing their values with zero
    int seconds = 0, minutes=0, hours=0,total_seconds_in_hour = 3600;
    // this will show output on screen
    cout<<"Enter Time in seconds"<<endl;
    // this will take input from user
    cin>>seconds;
    hours = seconds/total_seconds_in_hour;
    minutes = (seconds - (total_seconds_in_hour * hours))/60;
    seconds = (seconds - (total_seconds_in_hour * hours)- (60 * minutes));
    cout<<"Time is "<<hours<< " Hours "<<minutes<< " Minutes "<<seconds<<" Seconds "<<endl;
    return 0;
}