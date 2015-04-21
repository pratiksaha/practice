//to find max in an array which is first incr and then decr
//to find min in an array which is first decr and then incr
#include<iostream>
using namespace std;
 
int findMax(int arr[], int low, int high) {
    if (low==high)
        return arr[low];
    if (high==low+1 && arr[low]>=arr[high])
        return arr[low];
    if (high==low+1 && arr[low]<arr[high])
        return arr[high];
    int mid = (low+high)/2;
    if (arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1])
        return arr[mid];
    if (arr[mid]>arr[mid+1] && arr[mid]<arr[mid-1])
        return findMax(arr, low, mid-1);
    else
        return findMax(arr, mid+1, high);
}

int findMin(int arr[], int low, int high) {
    if (low==high)
        return arr[low];
    if (high==low+1 && arr[low]<=arr[high])
        return arr[low];
    if (high==low+1 && arr[low]>arr[high])
        return arr[high];
    int mid = (low+high)/2;
    if (arr[mid]<arr[mid+1] && arr[mid]<arr[mid-1])
        return arr[mid];
    if (arr[mid]<arr[mid+1] && arr[mid]>arr[mid-1])
        return findMin(arr, low, mid-1);
    else
        return findMin(arr, mid+1, high);
}

int main() {
    int arr1[] = {1, 3, 50, 10, 9, 7, 6};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int arr2[] = {50, 10, 9, 7, 6, 1, 3};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    cout<<"Max is : "<<findMax(arr1, 0, n1-1)<<endl;
    cout<<"Min is : "<<findMin(arr2, 0, n2-1)<<endl;
    return 0;
}
