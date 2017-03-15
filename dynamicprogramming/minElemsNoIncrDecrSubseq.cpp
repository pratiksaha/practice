//to find min no of elems which are not part of incr or decr subsequences
#include<bits/stdc++.h>
#define MAX 100
using namespace std;

int minElemsNoIncrDecrSubseq(int arr[], int dp[MAX][MAX][MAX], int n, int dec, int inc, int i) {
    if (dp[dec][inc][i] != -1)
        return dp[dec][inc][i];
    if (i == n)
        return 0;
    if (arr[i] < arr[dec])
        dp[dec][inc][i] = minElemsNoIncrDecrSubseq(arr, dp, n, i, inc, i + 1);
    if (arr[i] > arr[inc]) {
        if (dp[dec][inc][i] == -1)
            dp[dec][inc][i] = minElemsNoIncrDecrSubseq(arr, dp, n, dec, i, i + 1);
        else
            dp[dec][inc][i] = min(minElemsNoIncrDecrSubseq(arr, dp, n, dec, i, i + 1), dp[dec][inc][i]);
    }
    if (dp[dec][inc][i] == -1)
        dp[dec][inc][i] = 1 + minElemsNoIncrDecrSubseq(arr, dp, n, dec, inc, i + 1);
    else
        dp[dec][inc][i] = min(1 + minElemsNoIncrDecrSubseq(arr, dp, n, dec, inc, i + 1), dp[dec][inc][i]);
    return dp[dec][inc][i];
}

int minElemsNoIncrDecrSubseq(int arr[], int n) {
    arr[MAX - 2] = INT_MAX;
    arr[MAX - 1] = INT_MIN;
    int dp[MAX][MAX][MAX];
    memset(dp, -1, sizeof dp);
    return minElemsNoIncrDecrSubseq(arr, dp, n, MAX - 2, MAX - 1, 0);
}

int main() {
    int n = 12;
    int arr[MAX] = { 7, 8, 1, 2, 4, 6, 3, 5, 2, 1, 8, 7 };
    cout<<minElemsNoIncrDecrSubseq(arr, n)<<endl;
    return 0;
}
