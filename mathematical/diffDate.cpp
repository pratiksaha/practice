//to find number of days between two given dates
#include<iostream>
using namespace std;

struct Date {
    int d, m, y;
};

const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int countLeapYears(Date d) {
    int years = d.y;
    if (d.m <= 2) // Check if the current year needs to be considered for the count of leap years or not
        years--;
    return years/4 - years/100 + years/400; //An year is a leap year if it is a multiple of 4 and multiple of 400 and not a multiple of 100
}

int diffDate(Date dt1, Date dt2) {
    long int n1 = dt1.y*365 + dt1.d;
    for (int i=0; i<dt1.m-1; i++)
        n1 += monthDays[i];
    n1 += countLeapYears(dt1);
    long int n2 = dt2.y*365 + dt2.d;
    for (int i=0; i<dt2.m-1; i++)
        n2 += monthDays[i];
    n2 += countLeapYears(dt2);
    return (n2 - n1);
}

int main() {
    Date dt1 = {1, 2, 2000};
    Date dt2 = {1, 2, 2004};
    cout<<"Difference between two dates is "<<diffDate(dt1, dt2)<<endl;
    return 0;
}
