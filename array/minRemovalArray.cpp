//to find size of minimum possible array after removing elements according to given rules
#include<iostream>
#include<cstring>
using namespace std;
#define MAX 1000

int dp[MAX][MAX];
 
int minRemovalArray(int arr[], int low, int high, int k) {
    if (dp[low][high] != -1)
        return dp[low][high];
    if ((high-low + 1) < 3)
        return high-low +1;
    int res = 1 + minRemovalArray(arr, low+1, high, k);
    for (int i = low+1; i<=high-1; i++)
        for (int j = i+1; j <= high; j++ )
            if (arr[i] == (arr[low] + k) && arr[j] == (arr[low] + 2*k) && minRemovalArray(arr, low+1, i-1, k) == 0 && minRemovalArray(arr, i+1, j-1, k) == 0)
                 res = min(res, minRemovalArray(arr, j+1, high, k));
    return (dp[low][high] = res);
}

int minRemovalArray(int arr[], int n, int k) {
    memset(dp, -1, sizeof(dp));
    return minRemovalArray(arr, 0, n-1, k);
}

int main() {
    int arr[] = {2, 3, 4, 7, 6, 4};
    cout<<minRemovalArray(arr, sizeof(arr)/sizeof(arr[0]), 1)<<endl;
    return 0;
}
