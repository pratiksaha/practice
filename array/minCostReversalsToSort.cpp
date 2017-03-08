//to get minimum cost to sort strings by reversal operation
#include<bits/stdc++.h>
using namespace std;

int minCostReversalsToSort(string arr[], int cost[], int N) {
    int dp[N][2];
    dp[0][0] = 0;
    dp[0][1] = cost[0];
    string revStr[N];
    for (int i = 0; i < N; i++) {
        revStr[i] = arr[i];
        reverse(revStr[i].begin(), revStr[i].end());
    }
    string curStr;
    int curCost;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 2; j++) {
            dp[i][j] = INT_MAX;
            curStr = (j == 0) ? arr[i] : revStr[i];
            curCost = (j == 0) ? 0 : cost[i];
            if (curStr >= arr[i - 1])
                dp[i][j] = min(dp[i][j], dp[i-1][0] + curCost);
            if (curStr >= revStr[i - 1])
                dp[i][j] = min(dp[i][j], dp[i-1][1] + curCost);
        }
    }
    int res = min(dp[N-1][0], dp[N-1][1]);
    return (res == INT_MAX)? -1 : res;
}

int main() {
    string arr[] = {"aa", "ba", "ac"};
    int cost[] = {1, 3, 1};
    int N = sizeof(arr) / sizeof(arr[0]);
    int res = minCostReversalsToSort(arr, cost, N);
    if (res == -1)
        cout<<"Sorting not possible\n";
    else
        cout<<"Minimum cost to sort strings using reversals is "<<res<<endl;
}
