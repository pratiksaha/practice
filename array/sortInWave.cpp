//to sort an array in wave form i.e. arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= ...
#include<iostream>
#include<cstdlib>
using namespace std;

void sortInWave(int arr[], int n) {
    for (int i=0; i<n; i+=2) { //traverse all even elem
        if (i>0 && arr[i-1] > arr[i] ) //if curr even elem is smaller than prev
            swap(arr[i], arr[i-1]);
        if (i<n-1 && arr[i] < arr[i+1] ) //if curr even elem is smaller than next
            swap(arr[i], arr[i + 1]);
    }
}

int main() {
    int arr[] = {10, 90, 49, 2, 1, 5, 23};
    int i, n;
    n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Input array :";
    for (i=0; i<n; i++)
        cout<<" "<<arr[i];
    cout<<endl;
    sortInWave(arr, n);
    cout<<"Sorted array :";
    for (i=0; i<n; i++)
        cout<<" "<<arr[i];
    cout<<endl;
    return 0;
}
