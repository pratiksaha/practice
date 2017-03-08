//to find maximum subarray size such that all subarrays of that size have sum less than K
#include<bits/stdc++.h>
using namespace std;

int search(int prefixsum[], int n, int k) {
    int ans = -1; 
    int left = 1, right = n;
    while (left <= right) {
        int mid = (left + right)/2;
        int i;
        for (i = mid; i <= n; i++)
            if (prefixsum[i] - prefixsum[i - mid] > k)
                break;
        if (i == n+1) {
            left = mid + 1;
            ans = mid;
        } else {
            right = mid -1;
        }
    }
    return ans;
}

int maxSubarraySizeSumLTK(int arr[], int n, int k) {
    int prefixsum[n+1];
    memset(prefixsum, 0, sizeof(prefixsum));
    for (int i = 0; i < n; i++)
        prefixsum[i+1] = prefixsum[i] + arr[i];
 
    return search(prefixsum, n, k);
}

int main() {
    int arr[] = {1, 2, 10, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 14;
    cout<<maxSubarraySizeSumLTK(arr, n, k)<<endl;
    return 0;
}
