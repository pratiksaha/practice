//to implement Pancake Sorting
#include<iostream>
using namespace std;

void flip(int arr[], int end) {
    int beg = 0;
    while (beg < end) {
        int temp = arr[beg];
        arr[beg] = arr[end];
        arr[end] = temp;
        beg++;
        end--;
    }
}

int findMax(int arr[], int n) {
    int mi = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] > arr[mi])
            mi = i;
    return mi;
}

int pancakeSort(int arr[], int n) {
    for (int i=n; i>1; i--) {
        int mi = findMax(arr, i);
        if (mi != i-1) {
            flip(arr, mi);
            flip(arr, i-1);
        }
    }
}

void printArray(int arr[], int n) {
    for (int i=0; i<n; i++)
        cout<<" "<<arr[i];
    cout<<endl;
}

int main() {
    int arr[] = {23, 10, 20, 11, 12, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Input Array :";
    printArray(arr, n);
    pancakeSort(arr, n);
    cout<<"Sorted Array :";
    printArray(arr, n);
    return 0;
}
