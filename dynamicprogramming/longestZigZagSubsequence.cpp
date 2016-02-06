//to find longest Zig Zag subsequence
#include<bits/stdc++.h>
using namespace std;

int longestZigZagSubsequence(int arr[], int n) {
    int Z[n][2];
    for (int i=0; i<n; i++)
        Z[i][0] = Z[i][1] = 1;
    int res = 1;
    for (int i=1; i<n; i++) {
        for (int j=0; j<i; j++) {
            if (arr[j]<arr[i] && Z[i][0]<Z[j][1]+1)
                Z[i][0] = Z[j][1] + 1;
            if (arr[j]>arr[i] && Z[i][1]<Z[j][0]+1)
                Z[i][1] = Z[j][0] + 1;
        }
        if (res < max(Z[i][0], Z[i][1]))
            res = max(Z[i][0], Z[i][1]);
    }
    return res;
}

int main() {
    int arr[] = {10, 22, 9, 33, 49, 50, 31, 60};
    cout<<"Length of Longest Zig-Zag subsequence is "<<longestZigZagSubsequence(arr, sizeof(arr)/sizeof(arr[0]))<<endl;
    return 0;
}
