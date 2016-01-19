//set partition; Stirling & Bell Nos
#include<bits/stdc++.h>
using namespace std;

int countPartitionStirling(int n, int k) { // count of partitions of n elements in k subsets
    int dp[n+1][k+1];
    for (int i=0; i<=n; i++)
        dp[i][0] = 0;
    for (int i=0; i<=k; i++)
        dp[0][k] = 0;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=i; j++)
            if (j == 1 || i == j)
                dp[i][j] = 1;
            else
                dp[i][j] = j*dp[i-1][j] + dp[i-1][j-1];
  return dp[n][k];
}

int countPartitionBell(int n) { // count of ways of partitioning a set of n elements
    int dp[n+1][n+1];
    dp[0][0] = 1;
    for (int i=1; i<=n; i++) {
        dp[i][0] = dp[i-1][i-1];
        for (int j=1; j<=i; j++)
            dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
   }
   return dp[n][0];
}

int main() {
    int i, n, k;
    n = 5;
    k = 2;
    cout<<"Count of partitions of "<<n<<" elements in "<<k<<" subsets = "<<countPartitionStirling(n,k)<<endl;
    for (i=0; i<=n; i++)
        cout<<"Count of ways of partitioning a set of "<<i<<" elements = "<<countPartitionBell(i)<<endl;
    return 0;
}
