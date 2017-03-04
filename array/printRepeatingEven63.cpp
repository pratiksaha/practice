//to print the even occurring elements in given array
#include<bits/stdc++.h>
using namespace std;

void printRepeatingEven63(int arr[], int n) {
    long long _xor = 0L;
    long long pos;
    for( int i = 0; i < n; i++) {
        pos = 1 << arr[i];
        _xor ^= pos;
    }
    for (int i = 0; i < n; i++) {
        pos = 1 << arr[i];
        if (!(pos & _xor)) {
            cout<<" "<<arr[i];
            _xor ^= pos;
        }
    }
    cout<<endl;
}

int main() {
    int arr[] = { 9, 12, 23, 10, 12, 12, 15, 23, 14, 12, 15 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printRepeatingEven63(arr, n);
    return 0;
}
