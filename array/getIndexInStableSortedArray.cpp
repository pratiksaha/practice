//to get index of array element in stable sorted array
#include<bits/stdc++.h>
using namespace std;

int getIndexInStableSortedArray(int arr[], int n, int idx) {
    int result = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] < arr[idx])
            result++;
        if (arr[i] == arr[idx] && i <= idx)
            result++;
    }
    return result;
}

int main() {
    int arr[] = {3, 4, 3, 5, 2, 3, 4, 3, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int keyIdx = 5;
    cout<<"Index of element at "<<keyIdx<<" in stable sorted arrays is "<<getIndexInStableSortedArray(arr, n, keyIdx)<<endl;
    return 0;
}
