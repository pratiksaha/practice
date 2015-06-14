//to sort using one swap
#include<iostream>
#include<algorithm>
using namespace std;

void sortByOneSwap(int arr[], int n) {
    int i, j;
    for (i=0; i<n-1; i++)
        if (arr[i] > arr[i+1])
            break;
    for (j=n-1; j>0; j--)
        if (arr[j] < arr[j-1])
            break;
    if (i<j)
        swap(arr[i], arr[j]);
}

void printArray(int arr[], int n) {
    cout<<"Array :";
    for (int i=0; i<n; i++)
        cout<<" "<<arr[i];
    cout<<endl;
}

int main() {
    int arr[] = {10, 20, 60, 40, 50, 30, 70};
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);
    sortByOneSwap(arr, n);
    printArray(arr, n);
    return 0;
}
