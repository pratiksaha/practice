// to find the element that appears odd number of time
#include<iostream>
using namespace std;

int searchOdd(int *arr, int low, int high) {
    if (low > high)
       return -1;
    if (low==high)
        return arr[low];
    int mid = (low+high)/2;
    if (mid%2 == 0) { //if mid is even
        if (arr[mid] == arr[mid+1]) //element lies on right side if element next to mid is same as mid
            return searchOdd(arr, mid+2, high);
        else //element lies on left side otherwise
            return searchOdd(arr, low, mid);
    } else { //if mid is odd
        if (arr[mid] == arr[mid-1]) //element lies on right side if element previous to mid is same as mid
            return searchOdd(arr, mid+1, high);
        else //element lies on left side otherwise
            return searchOdd(arr, low, mid-1);
    }
}

int main() {
    int arr[] = {1, 1, 2, 2, 1, 1, 2, 2, 13, 1, 1, 40, 40};
    int len = sizeof(arr)/sizeof(arr[0]);
    cout<<"Element with odd occurence is "<<searchOdd(arr, 0, len-1)<<endl;
    return 0;
}
