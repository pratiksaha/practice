//min sum partition problem
#include<bits/stdc++.h>
using namespace std;

int minSumPartition(int arr[], int n) {
    int sum = 0; 
    for (int i=0; i<n; i++)
        sum += arr[i];
    bool dp[n+1][sum+1];
    for (int i=0; i<=n; i++) //0 sum is possible with all elements
        dp[i][0] = true;
    for (int i=1; i<=sum; i++) //no other sum except 0 is possible with no elements
        dp[0][i] = false;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=sum; j++) {
            dp[i][j] = dp[i-1][j]; //ith element is excluded
            if (arr[i-1] <= j) //ith element is included
                dp[i][j] |= dp[i-1][j-arr[i-1]];
        }
    } 
    int diff = INT_MAX;
    for (int j=sum/2; j>=0; j--) { 
        if (dp[n][j] == true) {
            diff = sum-2*j;
            break;
        }
    }
    return diff;
}

int main() {
    int arr[] = {3, 1, 4, 2, 2, 1};
    cout<<"Min diff between the partitions is "<<minSumPartition(arr, sizeof(arr)/sizeof(arr[0]))<<endl;
    return 0;
}
