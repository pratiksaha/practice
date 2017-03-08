//to find minimum difference of maximum and minimum of K number
#include<bits/stdc++.h>
using namespace std;

int minDiffOfMaxMinOfKElem(int arr[], int n, int k) {
    int result = INT_MAX;
    sort(arr, arr + n);
    for (int i=0; i<=n-k; i++)
        result = min(result, arr[i+k-1] - arr[i]);
    return result;
}

int main() {
    int arr[] = {10, 100, 300, 200, 1000, 20, 30};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    cout<<minDiffOfMaxMinOfKElem(arr, n, k)<<endl;
    return 0;
}
