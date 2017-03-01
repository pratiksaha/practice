//to find minimum adjustment cost of an array such that the difference between adjacent elements in the array is less than or equal to a given target
#include<bits/stdc++.h>
using namespace std;
#define M 100

int minAdjustmentCost(int A[], int n, int target) {
    int dp[n][M + 1];
    for (int j = 0; j <= M; j++)
        dp[0][j] = abs(j - A[0]);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= M; j++) {
            dp[i][j] = INT_MAX;
            for (int k = max(j-target,0); k <= min(M,j+target); k++)
                dp[i][j] = min(dp[i][j], dp[i - 1][k] + abs(A[i] - j));
        }
    }    
    int res = INT_MAX; 
    for (int j = 0; j <= M; j++)
        res = min(res, dp[n - 1][j]);
    return res;
}

int main() {
    int arr[] = {55, 77, 52, 61, 39, 6, 25, 60, 49, 47};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 10;
    cout<<"minimum adjustment cost is "<<minAdjustmentCost(arr, n, target)<<endl;
    return 0;
}
