//implement a calendar
#include<bits/stdc++.h>
using namespace std;

int dayNumber(int day, int month, int year) {
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    year -= month < 3;
    return ( year + year/4 - year/100 + year/400 + t[month-1] + day) % 7;
}

string getMonthName(int monthNumber) {
    string months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
    return (months[monthNumber]);
}

int numberOfDays (int monthNumber, int year) {
    if (monthNumber == 0)
        return (31);
    if (monthNumber == 1) {
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            return (29);
        else
            return (28);
    }
    if (monthNumber == 2)
        return (31);
    if (monthNumber == 3)
        return (30);
    if (monthNumber == 4)
        return (31);
    if (monthNumber == 5)
        return (30);
    if (monthNumber == 6)
        return (31);
    if (monthNumber == 7)
        return (31);
    if (monthNumber == 8)
        return (30);
    if (monthNumber == 9)
        return (31);
    if (monthNumber == 10)
        return (30);
    if (monthNumber == 11)
        return (31);
}

void calendar(int year) {
    cout<<"\n\n         Calendar - "<<year<<endl;
    int days;
    int current = dayNumber (1, 1, year);
    for (int i = 0; i < 12; i++) {
        days = numberOfDays (i, year);
        cout<<"\n------------"<<getMonthName(i)<<"-------------\n";
        cout<<"  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";
        int k;
        for (k = 0; k < current; k++)
            cout<<"     ";
        for (int j = 1; j <= days; j++) {
            cout<<setw(5)<<j;
            if (++k > 6) {
                k = 0;
                cout<<endl;
            }
        }
        if (k)
            cout<<endl;
        current = k;
    }
 
    return;
}

int main() {
    int year;
    year = 2016;
    calendar(year);
    year = 2017;
    calendar(year);
    return (0);
}
