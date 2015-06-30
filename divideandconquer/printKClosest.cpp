#include<iostream>
#include<cassert>
using namespace std;

int findCrossOver(int arr[], int low, int high, int x) {
    if (arr[high] <= x) // x is greater than all
        return high;
    if (arr[low] > x) // x is smaller than all
        return low;
    int mid = (low + high)/2;
    if (arr[mid]<=x && arr[mid+1]>x)
        return mid;
    if(arr[mid]<x)
        return findCrossOver(arr, mid+1, high, x);
    else
        return findCrossOver(arr, low, mid-1, x);
}

void printKclosest(int arr[], int x, int k, int n) {
    assert(k<=n);
    cout<<"For";
    for (int i=0; i<n; i++)
        cout<<" "<<arr[i];
    cout<<" "<<k<<" elements closest to "<<x<<" are :";
    int l = findCrossOver(arr, 0, n-1, x);
    int r = l+1;
    int count = 0;
    if (arr[l] == x)
        l--;
    while (l>=0 && r<n && count<k) { //compare left and right of crossover to find closest elements
        if (x-arr[l] < arr[r]-x)
            cout<<" "<<arr[l--];
        else
            cout<<" "<<arr[r++];
        count++;
    }
    while (count<k && l>=0) //no more elements on right side
        cout<<" "<<arr[l--], count++;
    while (count<k && r<n) //no more elements on left side
        cout<<" "<<arr[r++], count++;
    cout<<endl;
}

int main() {
    int arr[] ={12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 35, k = 4;
    printKclosest(arr, x, k, n);
    return 0;
}
