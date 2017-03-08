//to find minimum number of move-to-front moves to arrange items in sorted order
#include<bits/stdc++.h>
using namespace std;

int minMoveToFrontToSort(int arr[], int n) {
    int expectedItem = n;
    for (int i=n-1; i >= 0; i--)
        if (arr[i] == expectedItem)
            expectedItem--;
    return expectedItem;
}

int main() {
    int arr[] = {4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<minMoveToFrontToSort(arr, n)<<endl;
    return 0;
}
