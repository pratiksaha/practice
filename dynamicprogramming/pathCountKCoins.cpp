//to count paths with exactly k coins
#include<iostream>
#include<cstring>
using namespace std;
#define N 3
#define MAX_K 1000
 
int dp[N][N][MAX_K];

int pathCountKCoins(int mat[N][N], int m, int n, int k) {
    if (m<0 || n<0)
        return 0;
    if (m==0 && n==0)
        return (k == mat[m][n]);
    if (dp[m][n][k] != -1)
        return dp[m][n][k];
    dp[m][n][k] = pathCountKCoins(mat, m-1, n, k-mat[m][n]) + pathCountKCoins(mat, m, n-1, k-mat[m][n]);
    return dp[m][n][k];
}

int pathCountKCoins(int mat[N][N], int k) {
    memset(dp, -1, sizeof(dp));
    return pathCountKCoins(mat, N-1, N-1, k);
}

int main() {
    int k = 12;
    int mat[N][N] = {{1, 2, 3},
                     {4, 6, 5},
                    {3, 2, 1}};
    cout<<"No of paths with "<<k<<" coins = "<<pathCountKCoins(mat, k)<<endl;
    return 0;
}
