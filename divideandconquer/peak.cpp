//to find a peak element i.e an element which is not smaller than its neighbors
#include<iostream>
using namespace std;

int peak(int arr[], int low, int high, int n) {
    int mid = (low+high)/2;
    if ((mid==0 || arr[mid-1]<=arr[mid])&&(mid==n-1 || arr[mid+1]<=arr[mid]))
        return mid; //mid is peak
    else if (mid > 0 && arr[mid-1] > arr[mid])
        return peak(arr, low, mid-1, n);//if mid is not peak and its left neighbor is greater than it then left half must have a peak elem
 
    else
        return peak(arr, mid+1, high, n);//if mid is not peak and its right neighbor is greater than it then right half must have a peak elem
}

int main() {
    int arr[] = {1, 3, 20, 4, 1, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Index of a peak is "<<peak(arr, 0, n-1, n)<<endl;
    return 0;
}
