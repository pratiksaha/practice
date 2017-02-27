//to check if given string is K-Palindrome or not
#include<bits/stdc++.h>
using namespace std;
 
bool checkKPalindromeMemoized(string str1, string str2, int m, int n) {
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
             dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
 
    return dp[m][n];
}
 
bool checkKPalindromeDP(string str, int k) {
    string revStr = str;
    reverse(revStr.begin(), revStr.end());
    int len = str.length();
    return (checkKPalindromeMemoized(str, revStr, len, len) <= k*2);
}

int lcs( string X, string Y, int m, int n ) {
    int L[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    return L[m][n];
}

bool checkKPalindromeLCS(string str, int k) {
    int n = str.length();
    string revStr = str;
    reverse(revStr.begin(), revStr.end());
    int lps = lcs(str, revStr, n, n);
    return (n - lps <= k);
}

int main() {
    string str = "acdcb";
    int k = 2;
    cout<<str<<(checkKPalindromeDP(str, k) ? " is " : " is not ")<<k<<"-palindrome\n";
    cout<<str<<(checkKPalindromeLCS(str, k) ? " is " : " is not ")<<k<<"-palindrome\n";
    return 0;
}
