//to check minimum number operations is less than or equal to k or not to convert str1 to str2
#include<bits/stdc++.h>
using namespace std;

int min(int x, int y, int z) {
    return min(min(x, y), z);
}

int editDistDP(string str1, string str2, int m, int n) {
    int dp[m+1][n+1];
    for (int i=0; i<=m; i++) {
        for (int j = 0; j<=n; j++) {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
        }
    }
    return dp[m][n];
}

bool checkKDistance(string str1, string str2, int k) {
    int m = str1.length();
    int n = str2.length();
    if (abs(m-n) > k)
        return false;
    return (editDistDP(str1, str2, m, n) <= k);
}

int main() {
    string str1 = "geek";
    string str2 = "gks";
    int k = 3;
    cout<<str1<<" & "<<str2<<(checkKDistance(str1, str2, k) ? " are ": "are not ")<<k<<" distance apart\n";
    return 0;
}
