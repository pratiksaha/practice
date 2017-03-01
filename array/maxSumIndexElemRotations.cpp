//to compute maximum sum of i*arr[i] among rotations
#include<bits/stdc++.h>
using namespace std;

int maxSumIndexElemRotations(int arr[], int n) {
    int cum_sum = 0;
    for (int i=0; i<n; i++)
        cum_sum += arr[i];
    int curr_val = 0;
    for (int i=0; i<n; i++)
        curr_val += i*arr[i];
    int res = curr_val;
    for (int i=1; i<n; i++) {
        int next_val = curr_val - (cum_sum - arr[i-1]) + arr[i-1] * (n-1);
        curr_val = next_val;
        res = max(res, next_val);
    }
    return res;
}

int main() {
    int arr[] = {8, 3, 1, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxSumIndexElemRotations(arr, n)<<endl;
    return 0;
}
