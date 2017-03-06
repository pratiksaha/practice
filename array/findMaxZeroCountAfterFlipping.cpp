//to maximize number of zeroes by flipping a subarray
#include<bits/stdc++.h>
using namespace std;

int findMaxZeroCountAfterFlipping(bool arr[], int n) {
    int orig_zero_count = 0;
    int max_diff = 0;
    int curr_max = 0;
    for (int i=0; i<n; i++) {
        if (arr[i] == 0)
           orig_zero_count++;
        int val = (arr[i] == 1)? 1 : -1;
        curr_max = max(val, curr_max + val);
        max_diff = max(max_diff, curr_max);
    }
    max_diff = max(0, max_diff);
    return orig_zero_count + max_diff;
}

int main() {
    bool arr[] = {0, 1, 0, 0, 1, 1, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Max number of zeroes after fliiping a subbarray is "<<findMaxZeroCountAfterFlipping(arr, n)<<endl;
    return 0;
}
