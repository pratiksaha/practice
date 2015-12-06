//to check if an array represents a heap
#include<bits/stdc++.h>
using namespace std;

bool checkHeap(int arr[], int i, int n) {
    if (i>(n-2)/2) { //leaf node
        return true;
    } else if (arr[i]>=arr[2*i+1] && arr[i]>=arr[2*i+2] && checkHeap(arr, 2*i+1, n) && checkHeap(arr, 2*i+2, n)) { //non leaf node checks true
        return true;
    } else { //none leaf node checks false
        return false;
    }
}

bool checkHeap(int arr[], int n) {
    for (int i=0; i<=(n-2)/2; i++) //check only non leaf nodes
        if (arr[2*i+1]>arr[i] || arr[2*i+2]>arr[i]) //check heap condition
            return false;
    return true;
}

int main() {
    int arr[] = {90, 15, 10, 7, 12, 2, 7, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    checkHeap(arr, 0, n)?cout<<"Yes\n":cout<<"No\n";
    checkHeap(arr, n)?cout<<"Yes\n":cout<<"No\n";
    return 0;
} 
