//to find maximum sum by breaking a number into 3 parts
#include<bits/stdc++.h>
#define MAX 1000000
using namespace std;
 
int maxSumBreakThreeParts(int n) {
    int dp[n+1];
    dp[0] = 0, dp[1] = 1;
    for (int i=2; i<=n; i++)
        dp[i] = max(dp[i/2] + dp[i/3] + dp[i/4], i);
    return dp[n];
}
 
int main() {
    int n = 24;
    cout<<"maximum sum by breaking a number into 3 parts for "<<n<<" is "<<maxSumBreakThreeParts(n)<<endl;
    return 0;
}
