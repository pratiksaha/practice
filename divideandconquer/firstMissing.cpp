//to find the first missing no in a sorted array
#include<iostream>
using namespace std;

int firstMissing(int arr[], int low, int high) {
    if (low > high)
        return high+1;
    if (low != arr[low])
        return low;
    int mid = (low+high)/2;;
    if (arr[mid] > mid)
        return firstMissing(arr, low, mid-1);
    else
        return firstMissing(arr, mid+1, high);
}

int main() {
    int arr[] = {0, 1, 2, 3, 4, 5, 8, 9, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"First missing no is "<<firstMissing(arr, 0, n-1)<<endl;
    return 0;
}
