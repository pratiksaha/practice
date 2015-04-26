//to check if a given elem is a majority elem in a sorted array i.e. occurs more than n/2 times
#include<iostream>
using namespace std;

int firstOccurence(int arr[], int low, int high, int x) {
    if (high>=low) {
        int mid = (low+high)/2;
        if ((mid==0 || x>arr[mid-1]) && arr[mid]==x)
            return mid;
        else if (x > arr[mid])
            return firstOccurence(arr, mid+1, high, x);
        else
            return firstOccurence(arr, low, mid-1, x);
    } else {
        return -1;
    }
}

bool checkMajority(int arr[], int n, int x) {
    int i = firstOccurence(arr, 0, n-1, x);
    if (i == -1)
        return false; 
    else if (((i + n/2) <= (n -1)) && arr[i+n/2] == x) //if elem is present more than n/2 times
        return true;
    else
        return false;
}

int main() {
    int arr[] = {1, 2, 3, 3, 3, 3, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    cout<<k<<" is "<<(checkMajority(arr, n, k)?" a ":" not a ")<<" majority element\n";
    k = 2;
    cout<<k<<" is "<<(checkMajority(arr, n, k)?" a ":" not a ")<<" majority element\n";
    k = 4;
    cout<<k<<" is "<<(checkMajority(arr, n, k)?" a ":" not a ")<<" majority element\n";
    return 0;
}
