#include<iostream>
using namespace std;

char* hash[7] = {  "Sunday",
                    "Monday",
                    "Tuesday",
                    "Wedenesday",
                    "thursday",
                    "Friday",
                    "Saturday"
                 };
 
int dayofweek(int date, int month, int year)
{
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    year -= month < 3;
    return ( year + year/4 - year/100 + year/400 + t[month-1] + date) % 7;
}

int main()
{
    cout<<hash[dayofweek(30, 8, 2010)]<<endl;
    return 0;
}
