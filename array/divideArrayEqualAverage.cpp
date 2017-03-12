//to divide an array to make average equal
#include<bits/stdc++.h>
using namespace std;

void divideArrayEqualAverage(int arr[], int n) {
    int sum = 0;
    for (int i=0; i<n; i++)
        sum += arr[i];
    bool found = false;
    int lsum = 0;
    for (int i=0; i<n-1; i++) {
        lsum += arr[i];
        int rsum = sum - lsum;
        if (lsum*(n-i-1) == rsum*(i+1)) {
            cout<<"Subarrays from 0 to "<<i<<" and from "<<i+1<<" to n-1 have same average\n";
            found = true;
        }
    }
    if (found == false)
        cout<<"No Subarrays found\n";
}

int main() {
    int arr[] = {1, 5, 7, 2, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    divideArrayEqualAverage(arr, n);
    return 0;
}
