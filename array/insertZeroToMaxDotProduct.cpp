//to find maximum dot product of two array by inserting zeroes
#include<bits/stdc++.h>
using namespace std;

int insertZeroToMaxDotProduct(int A[], int B[], int m, int n) {
    int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    for (int i=1; i<=n; i++)
        for (int j=i; j<=m; j++)
            dp[i][j] = max((dp[i-1][j-1] + (A[j-1]*B[i-1])), dp[i][j-1]);
    return dp[n][m] ;
}

int main() {
    int A[] = { 2, 3, 1, 7, 8 } ;
    int B[] = { 3, 6, 7 } ;
    int m = sizeof(A)/sizeof(A[0]);
    int n = sizeof(B)/sizeof(B[0]);
    cout<<insertZeroToMaxDotProduct(A, B, m, n)<<endl;
    return 0;
}
