//to find the maximum sum of strictly increasing subarrays
#include<bits/stdc++.h>
using namespace std;

int maxSumStrictlyIncreasingSubarray(int arr[] , int n) {
    int max_sum = 0;
    int current_sum = arr[0] ;
    for (int i=1; i<n ; i++ ) {
        if (arr[i-1] < arr[i]) {
            current_sum = current_sum + arr[i];
        } else {
            max_sum = max(max_sum, current_sum);
            current_sum = arr[i];
        }
    }
    return max(max_sum, current_sum);
}

int main() {
    int arr[] = {1, 2, 2, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxSumStrictlyIncreasingSubarray(arr, n)<<endl;
    return 0;
}
