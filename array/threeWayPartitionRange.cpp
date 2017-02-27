//to implement three way partitioning around a given range
#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n) {
    for (int i=0; i<n; i++)
        cout<<" "<<arr[i];
    cout<<endl;
}

// Partitions arr[0..n-1] around [lowVal..highVal]
void threeWayPartitionRange(int arr[], int n, int lowVal, int highVal) {
    int start = 0, end = n-1;
    for (int i=0; i<=end;) {
        if (arr[i] < lowVal)
            swap(arr[i++], arr[start++]);
        else if (arr[i] > highVal)
            swap(arr[i], arr[end--]);
        else
            i++;
    }
}

int main() {
    int arr[] = {1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32};
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);
    threeWayPartitionRange(arr, n, 10, 20);
    printArray(arr, n);
    return 0;
}
