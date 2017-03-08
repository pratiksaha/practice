//to find minimum sum subsequence of an array such that one of every four consecutive elements is picked
#include<bits/stdc++.h>
using namespace std;

int minSumSubsequenceOneEveryFour(int arr[], int n) {
    int dp[n];
    if (n==1)
        return arr[0];
    if (n==2)
        return min(arr[0], arr[1]);
    if (n==3)
        return min(arr[0], min(arr[1], arr[2]));
    if (n==4)
        return min(min(arr[0], arr[1]), min(arr[2], arr[3]));
    dp[0] = arr[0];
    dp[1] = arr[1];
    dp[2] = arr[2];
    dp[3] = arr[3];
    for (int i=4; i<n; i++)
        dp[i] = arr[i] + min(min(dp[i-1], dp[i-2]), min(dp[i-3], dp[i-4]));
    return min(min(dp[n-1], dp[n-2]), min(dp[n-4], dp[n-3]));
}

int main() {
    int arr[] = {1, 2, 3, 3, 4, 5, 6, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<minSumSubsequenceOneEveryFour(arr, n)<<endl;
    return 0;
}
