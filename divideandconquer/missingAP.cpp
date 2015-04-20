//to find the missing number in an arithmetic progression
#include<iostream>
#include<climits>
using namespace std;

int missingAP(int arr[], int low, int high, int diff, int size) {
    if (high <= low)
        return INT_MAX; //there must be two elements to find the missing
    int mid = (low+high)/2;
    if (mid < size-1 && arr[mid+1]-arr[mid] != diff) //elem just after mid is missing
        return (arr[mid] + diff);
    if (mid > 0 && arr[mid] - arr[mid-1] != diff) //elem just before mid is missing
        return (arr[mid-1] + diff);
    if (arr[mid] == arr[0] + mid*diff) //recur for right half if elems till mid follow AP
        return missingAP(arr, mid+1, high, diff, size);
    else //recur for left half
        return missingAP(arr, low, mid-1, diff, size);
}

int main() {
    int arr[] = {2, 4, 8, 10, 12, 14};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"The missing element in AP is "<<missingAP(arr, 0, n-1, (arr[n-1]-arr[0])/n, n)<<endl;
    return 0;
}
