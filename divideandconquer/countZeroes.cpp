//to find count of zeroes in an array where all 1s are present before all 0s
#include<iostream>
using namespace std;

int firstZero(int arr[], int low, int high) {
    if (high >= low) {
        int mid = (high + low)/2;
        if ((mid==0 || arr[mid-1]==1) && arr[mid]==0)
            return mid;
        if (arr[mid] == 1)
            return firstZero(arr, mid+1, high);
        else
            return firstZero(arr, low, mid-1);
    }
    return -1;
}

int countZeroes(int arr[], int n) {
    int first = firstZero(arr, 0, n-1);
    if (first == -1)
        return 0;
    else
        return (n - first);
}

int main() {
    int arr[] = {1, 1, 1, 0, 0, 0, 0, 0};
    cout<<"No of zeroes = "<<countZeroes(arr, sizeof(arr)/sizeof(arr[0]))<<endl;
    return 0;
}
