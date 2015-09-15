//to find the element that appears only once
#include<iostream>
using namespace std;

int searchSingle(int *arr, int low, int high) {
    if (low > high)
       return -1;
    if (low==high)
        return arr[low];
    int mid = (low+high)/2;
    if (mid%2 == 0) { //if mid is even
        if (arr[mid] == arr[mid+1]) //element lies on right side if element next to mid is same as mid
            return searchSingle(arr, mid+2, high);
        else //element lies on left side otherwise
            return searchSingle(arr, low, mid);
    } else { //if mid is odd
        if (arr[mid] == arr[mid-1]) //element lies on right side if element previous to mid is same as mid
            return searchSingle(arr, mid+1, high);
        else //element lies on left side otherwise
            return searchSingle(arr, low, mid-1);
    }
}

int main() {
    int arr[] = {1, 1, 2, 4, 4, 5, 5, 6, 6};
    int len = sizeof(arr)/sizeof(arr[0]);
    cout<<"Element with single occurence is "<<searchSingle(arr, 0, len-1)<<endl;
    return 0;
}
