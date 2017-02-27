// to rearrange array in alternating positive & negative items
#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n) {
    for (int i=0; i<n; i++)
        cout<<" "<<arr[i];
    cout<<endl;
}

void rearrangeAltPosNeg(int arr[], int n) {
    int i = -1, j = n;
    while (i < j) {
        while (arr[++i] > 0);
        while (arr[--j] < 0);
        if (i < j)
            swap(arr[i], arr[j]);
    }
    if (i == 0 || i == n)
        return;
    int k = 0;
    while (k < n && i < n) {
        swap(arr[k], arr[i]);
        i = i + 1;
        k = k + 2;
    }
}

int main() {
    int arr[] = {2, 3, -4, -1, 6, -9};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Given array is :";
    printArray(arr, n);
    rearrangeAltPosNeg(arr, n);
    cout<<"Rearranged array is :";
    printArray(arr, n);
    return 0;
}
