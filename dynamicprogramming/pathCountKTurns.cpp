//to count paths with exactly k turns
#include<iostream>
#include<cstring>
using namespace std;
#define MAX 100

int dp[MAX][MAX][MAX][2];

int pathCountKTurns(int i, int j, int k, int d) {
    if (i<0 || j<0)
        return 0;
    if (i == 0 && j == 0)
        return 1;
    if (k == 0) { //0 turns left
        if (d==0 && i==0)
            return 1;
        if (d==1 && j==0)
            return 1;
        return 0;
    }
    if (dp[i][j][k][d] != -1)
        return dp[i][j][k][d];
    if (d == 0) //direction is row
        return dp[i][j][k][d] = pathCountKTurns(i, j-1, k, d) + pathCountKTurns(i-1, j, k-1, !d);
    else //direction is column
        return dp[i][j][k][d] =  pathCountKTurns(i-1, j, k, d) + pathCountKTurns(i, j-1, k-1, !d);
}

int pathCountKTurns(int i, int j, int k) {
    if (i==0 && j==0)
        return 1;
    memset(dp, -1, sizeof(dp));
    return pathCountKTurns(i-1, j, k, 1) + pathCountKTurns(i, j-1, k, 0);
}

int main() {
    int m = 3, n = 3, k = 2;
    cout<<"No of paths with "<<k<<" turns = "<<pathCountKTurns(m-1, n-1, k)<<endl;
    return 0;
}
