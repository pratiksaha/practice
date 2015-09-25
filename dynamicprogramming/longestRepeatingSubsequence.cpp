//longest repeating subsequence TODO:print
#include<iostream>
#include<string>
using namespace std;
 
void longestRepeatingSubsequence(string str) {
    int n = str.length();
    int dp[n+1][n+1];
    for (int i=0; i<=n; i++)
        for (int j=0; j<=n; j++)
            dp[i][j] = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (str[i-1] == str[j-1] && i!=j)
                dp[i][j] =  1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    cout<<"Length of the largest subsequence that repeats itself is "<<dp[n][n]<<endl;
}

int main() {
    string str = "aabb";
    longestRepeatingSubsequence(str);
    return 0;
}
