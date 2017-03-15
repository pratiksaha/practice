//to get the distinct subset sums of a given array
#include<bits/stdc++.h>
using namespace std;

void distinctSubsetSum(int arr[], int n) {
    int sum = 0;
    for (int i=0; i<n; i++)
        sum += arr[i];
    bool dp[n+1][sum+1];
    memset(dp, 0, sizeof(dp));
    for (int i=0; i<=n; i++)
        dp[i][0] = true;
    for (int i=1; i<=n; i++) {
        dp[i][arr[i-1]] = true;
        for (int j=1; j<=sum; j++) {
            if (dp[i-1][j]) {
                dp[i][j] = true;
                dp[i][j + arr[i-1]] = true;
            }
        }
    }
    for (int j=0; j<=sum; j++)
        if (dp[n][j])
            cout<<" "<<j;
    cout<<endl;
}

int main() {
    int arr[] = {2, 3, 4, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    distinctSubsetSum(arr, n);
    return 0;
}
