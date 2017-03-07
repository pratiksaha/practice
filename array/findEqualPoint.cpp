//to find Equal(Middle) point in a sorted array with duplicates
#include<bits/stdc++.h>
using namespace std;

int findEqualPoint(int arr[], int n) {
     int distArr[n];
     int i = 0, di = 0;
     while (i < n) {
        distArr[di++] = i++;
        while (i<n && arr[i] == arr[i-1])
            i++;
     }
     return (di & 1)? distArr[di>>1] : -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 4, 5, 6, 6, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int index = findEqualPoint(arr, n);
    if (index != -1)
        cout<<"Equal Point is "<<arr[index]<<endl;
    else
        cout<<"Equal Point does not exists\n";
    return 0;
}
