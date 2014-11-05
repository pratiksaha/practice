//given arr[0..n-1], construct prod[] such that prod[i] is equal to the prod of all the elem except arr[i] without using division operator and in O(n).
#include<iostream>
using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i<size; i++)
        cout<<" "<<arr[i];
    cout<<endl;
}

int* productArray(int arr[], int n) {
    int i, temp;
    int *prod = new int[n];
    for(i=0; i<n; i++)
        prod[i] = 1;
    
    temp = 1;
    for(i=0; i<n; i++) {
        prod[i] = temp;
        temp *= arr[i];
    }
 
    temp = 1;
    for(i= n-1; i>=0; i--) {
        prod[i] *= temp;
        temp *= arr[i];
    }

    return prod;
}

int main() {
    int arr[] = {10, 3, 5, 6, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"The input array is :";
    printArray(arr, n);
    int *res = productArray(arr, n);
    cout<<"The product array is :";
    printArray(res, n);
    return 0;
}
