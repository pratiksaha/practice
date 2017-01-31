//to find maximum decimal value path
#include<bits/stdc++.h>
using namespace std;
#define N 4

long long int maxDecimalValuePath(int mat[][N], int n) {
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    if (mat[0][0] == 1)
        dp[0][0] = 1 ;
    for (int i=1; i<n; i++) {
        if (mat[0][i] == 1)
            dp[0][i] = dp[0][i-1] + pow(2, i);
        else
            dp[0][i] = dp[0][i-1];
    }
    for (int i=1; i<n; i++) {
        if (mat[i][0] == 1)
            dp[i][0] = dp[i-1][0] + pow(2, i);
        else
            dp[i][0] = dp[i-1][0];
    }
    for (int i=1; i<n; i++) {
        for (int j=1 ; j<n; j++) {
            if (mat[i][j] == 1)
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]) + pow(2, i+j);
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[n-1][n-1];
}

int main() {
    int mat[][4] = {
        { 1 ,1 ,0 ,1 },
        { 0 ,1 ,1 ,0 },
        { 1 ,0 ,0 ,1 },
        { 1 ,0 ,1 ,1 },
    };
    cout<<"value of maximum decimal value path is "<<maxDecimalValuePath(mat, 4)<<endl;
    return 0;
}
