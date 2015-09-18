//to find length of the shortest supersequence TODO: print the supersequence
#include<iostream>
#include<cstring>
using namespace std;

int shortestCommonSuperSequence(char* X, char* Y, int m, int n) {
    int dp[m+1][n+1];
    for (int i=0; i<=m; i++) {
        for (int j=0; j<=n; j++) {
           if (i == 0)
               dp[i][j] = j;
           else if (j == 0)
               dp[i][j] = i;
           else if (X[i-1] == Y[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
           else
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m][n];
}

int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    cout<<"Length of the shortest common supersequence is "<<shortestCommonSuperSequence(X, Y, strlen(X), strlen(Y))<<endl;
    return 0;
}
