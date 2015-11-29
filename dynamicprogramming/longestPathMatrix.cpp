//to find length of longest path in a matrix
#include<iostream>
#include<cstring>
using namespace std;
#define N 3

int longestPathMatrix(int i, int j, int mat[N][N], int dp[N][N]) {
    if (i<0 || i>=N || j<0 || j>=N)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if ((mat[i][j] +1) == mat[i][j+1])
        return dp[i][j] = 1 + longestPathMatrix(i,j+1,mat,dp);
    if (mat[i][j] +1 == mat[i][j-1])
        return dp[i][j] = 1 + longestPathMatrix(i,j-1,mat,dp);
    if (mat[i][j] +1 == mat[i-1][j])
        return dp[i][j] = 1 + longestPathMatrix(i-1,j,mat,dp);
    if (mat[i][j] +1 == mat[i+1][j])
        return dp[i][j] = 1 + longestPathMatrix(i+1,j,mat,dp);
    return dp[i][j] = 1;
}

int longestPathMatrix(int mat[N][N]) {
    int result = 1;
    int dp[N][N];
    memset(dp, -1, sizeof(dp));
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (dp[i][j] == -1)
                longestPathMatrix(i, j, mat, dp);
            result = max(result, dp[i][j]);
        }
    }
    return result;
}

int main() {
    int mat[N][N] = {{1, 2, 9},
                    {5, 3, 8},
                    {4, 6, 7}};
    cout<<"Length of the longest path in the matrix is "<<longestPathMatrix(mat)<<endl;
    return 0;
}
