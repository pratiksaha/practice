//to find a fixed point in a sorted array i.e arr[i] == i
#include<iostream>
using namespace std;

int fixedPoint(int arr[], int low, int high) {
    if (low<=high) {
        int mid = (low+high)/2;
        if (arr[mid] == mid)
            return mid;
        if (arr[mid] > mid)
            return fixedPoint(arr, low, mid-1);
        else
            return fixedPoint(arr, mid+1, high);
    }
    return -1; //no fixed point
}

int main() {
    int arr[] = {-10, -1, 0, 3, 10, 11, 30, 50, 100};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Fixed Point is "<<fixedPoint(arr, 0, n-1)<<endl;
    return 0;
}
