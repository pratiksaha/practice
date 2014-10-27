//Minimum Insertions needed to form a palindrome
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int lcsDP( char *X, char *Y) {
    int n = strlen(X);
    int L[n+1][n+1];
    int i, j;
    
    for (i=0; i<=n; i++) {
        for (j=0; j<=n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i-1] == Y[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
   return L[n][n];
}

int minInsertionsDP(char str[]) {
    int n = strlen(str);
    char rev[n+1];
    strcpy(rev, str);
    reverse(rev, rev+n);
    return (n - lcsDP(str, rev));// The output is length of string minus length of lcs of str and its reverse
}
 
int main() {
    char str[] = "test";
    cout<<"Minimum Insertions to form a plaindrom with "<<str<<" is "<<minInsertionsDP(str)<<endl;
    return 0;
}
