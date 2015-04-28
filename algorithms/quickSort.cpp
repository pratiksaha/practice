//Quick Sort
#include<iostream>
#include<cstdlib>
using namespace std;

int partition(int arr[], int l, int r) { //CLRS partition
    int x = arr[r]; //pivot
    int i = l-1;
    for (int j=l; j<=r-1; j++) {
        if (arr[j] < x) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[r]);
    return i+1;
}

void quickSort(int arr[], int l, int r) { //CLRS quick sort
    if (l<r) {
        int p = partition(arr, l, r);
        quickSort(arr, l, p-1);
        quickSort(arr, p+1, r);
    }
}

void printArray(int arr[], int size) {
    for (int i=0; i<size; i++)
        cout<<" "<<arr[i];
    cout<<endl;
}

int main() {
    int a1[] = {10, 7, 8, 9, 1, 5};
    int n1 = sizeof(a1)/sizeof(a1[0]);
    cout<<"Input Array :";
    printArray(a1, n1);
    quickSort(a1, 0, n1-1);
    cout<<"Sorted Array :";
    printArray(a1, n1);
    return 0;
}
