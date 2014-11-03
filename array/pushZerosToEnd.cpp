//move all zeroes at the end of array
#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    for (int i=0; i<size; i++)
        cout<<" "<<arr[i];
    cout<<endl;
}

void pushZerosToEnd(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] != 0)
            arr[count++] = arr[i];
    while (count < n)
        arr[count++] = 0;
}

int main() {
    int arr[] = {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Input Array :\n";
    printArray(arr, n);
    pushZerosToEnd(arr, n);
    cout<<"Array after pushing all zeros to end of array :\n";
    printArray(arr, n);
    return 0;
}
