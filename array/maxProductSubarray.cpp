//to find maximum product subarray
#include<bits/stdc++.h>
using namespace std;
 
int maxProductSubarray(int arr[], int n) {
    int max_fwd = INT_MIN, max_bkd = INT_MIN;
    int max_till_now = 1;
    for (int i=0; i<n; i++) {
        max_till_now = max_till_now*arr[i];
        if (max_till_now == 0) {
            max_till_now = 1;
            continue;
        }
        if (max_fwd < max_till_now)
            max_fwd = max_till_now;
    }
    max_till_now = 1;
    for (int i=n-1; i>=0; i--) {
        max_till_now = max_till_now * arr[i];
        if (max_till_now == 0) {
            max_till_now = 1;
            continue;
        }
        if (max_bkd < max_till_now)
            max_bkd = max_till_now;
    }
    int res =  max(max_fwd, max_bkd);
    return max(res, 0);
}
 
int main() {
    int arr[] = {-1, -2, -3, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxProductSubarray(arr, n)<<endl;
    return 0;
}
