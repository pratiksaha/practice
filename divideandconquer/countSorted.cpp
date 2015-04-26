//to count the no of occurences in a sorted array
#include<iostream>
using namespace std;

int first(int arr[], int low, int high, int x, int n) {
    if(high >= low) {
        int mid = (low + high)/2;
        if ((mid==0 || x>arr[mid-1]) && arr[mid]==x)
            return mid;
        else if (x>arr[mid])
            return first(arr, mid+1, high, x, n);
        else
            return first(arr, low, mid-1, x, n);
    } else {
        return -1;
    }
}

int last(int arr[], int low, int high, int x, int n) {
    if(high >= low) {
        int mid = (low + high)/2;
        if((mid==n-1 || x<arr[mid+1]) && arr[mid]==x)
            return mid;
        else if (x<arr[mid])
            return last(arr, low, mid-1, x, n);
        else
            return last(arr, mid+1, high, x, n);      
    } else {
        return -1;
    }
}

int countSorted(int arr[], int n, int x) {
    int i = first(arr, 0, n-1, x, n);
    if (i==-1) //x does not exist in array
        return i; 
    int j = last(arr, i, n-1, x, n);     
    return j-i+1;
}

int main() {
    int arr[] = {2, 3, 3, 3, 3, 3, 5, 5, 5, 6, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    for (int x=1; x<=7; x++)
        cout<<x<<" occurs "<<countSorted(arr, n, x)<<" times in the array\n";
    return 0;
}
