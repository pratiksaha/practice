//rearrange positive and negative numbers in a array
#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n) {
    for (int i=0; i<n; i++)
        cout<<" "<<arr[i];
    cout<<endl;
}

void reverse(int arr[], int l, int r) {
    if (l < r) {
        swap(arr[l], arr[r]);
        reverse(arr, ++l, --r);
    }
}

void merge(int arr[], int l, int m, int r) {
    int i = l;
    int j = m + 1;
    while (i <= m && arr[i] < 0)
        i++;
    while (j <= r && arr[j] < 0)
        j++;
    reverse(arr, i, m);
    reverse(arr, m + 1, j - 1);
    reverse(arr, i, j - 1);
}

void rearrangePosNeg(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        rearrangePosNeg(arr, l, m);
        rearrangePosNeg(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);
    rearrangePosNeg(arr, 0, n - 1);
    printArray(arr, n);
    return 0;
}
