//to sort an array of dates
#include<iostream>
using namespace std;

struct date {
    int d, m, y;
};

typedef date Date;

void sortDay(Date arr[], int n) {
    Date output[n];
    int i, count[31] = {0};
    for (i=0; i<n; i++)
        count[arr[i].d - 1]++;
    for (i=1; i<31; i++)
        count[i] += count[i-1];
    for (i=n-1; i>=0; i--) {
        output[count[arr[i].d - 1] - 1] = arr[i];
        count[arr[i].d - 1]--;
    }
    for (i=0; i<n; i++)
        arr[i] = output[i];
}

void sortMonth(Date arr[], int n) {
    Date output[n];
    int i, count[12] = {0};
    for (i=0; i<n; i++)
        count[arr[i].m - 1]++;
    for (i=1; i<12; i++)
        count[i] += count[i - 1];
    for (i=n-1; i>=0; i--) {
        output[count[arr[i].m - 1] - 1] = arr[i];
        count[arr[i].m - 1]--;
    }
    for (i=0; i<n; i++)
        arr[i] = output[i];
}

void sortYear(Date arr[], int n) {
    Date output[n];
    int i, count[1000] = {0};
    for (i=0; i<n; i++)
        count[arr[i].y - 2000]++;
    for (i=1; i<1000; i++)
        count[i] += count[i - 1];
    for (i=n-1; i>=0; i--) {
        output[count[arr[i].y - 2000] - 1] = arr[i];
        count[arr[i].y - 2000]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void sortDates(Date arr[], int n) {
    sortDay(arr, n);
    sortMonth(arr, n);
    sortYear(arr, n);
}

void print(Date arr[], int n) {
    for (int i=0; i<n; i++)
        cout<<" {"<<arr[i].d<<"/"<<arr[i].m<<"/"<<arr[i].y<<"}";
}

int main() {
    Date arr[] = {{20, 1, 2014}, {25, 3, 2010},
                  {3, 12, 2000}, {18, 11, 2001},
                  {19, 4, 2015}, {9, 7, 2005}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Input Dates :", print(arr, n), cout<<endl;
    sortDates(arr, n);
    cout<<"Sorted Dates :", print(arr, n), cout<<endl;
    return 0;
}
