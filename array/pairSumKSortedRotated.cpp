//to find a pair with a given sum in a sorted and rotated array
#include<iostream>
using namespace std;

void pairSumKSortedRotated(int arr[], int n, int k) {
    int i;
    for (i=0; i<n-1; i++)
        if (arr[i] > arr[i+1])
            break;
    int r = i; //r = index of max elem
    int l = (i+1)%n; //l = index of min elem
    while (l != r) {
        if (arr[l] + arr[r] < k) {
            l = (l+1)%n;
        } else if (arr[l] + arr[r] > k) {
            r = (n+r-1)%n;
        } else {
            cout<<"Pair with sum "<<k<<" at Indices "<<l<<" & "<<r<<" Values = "<<arr[l]<<" & "<<arr[r]<<endl;
            return;
        }
    }
    cout<<"No pair with sum "<<k<<endl;
}

int main() {
    int arr[] = {11, 15, 6, 8, 9, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    pairSumKSortedRotated(arr, n, 16);
    pairSumKSortedRotated(arr, n, 22);
    return 0;
}
