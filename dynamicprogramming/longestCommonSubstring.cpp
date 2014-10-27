//Longest Common Substring
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

void LCSubStrDP(char *X, char *Y) {
    int m = strlen(X);
    int n = strlen(Y);
    int LCS[m+1][n+1];
    int result = 0;
    int i, j;
    
    for (i=0; i<=m; i++) {
        for(j=0; j<=n; j++) {
            if (i==0 || j==0) {
                LCS[i][j] = 0;
            } else if (X[i-1] == Y[j-1]) {
                LCS[i][j] = LCS[i-1][j-1] + 1;
                result = max(result, LCS[i][j]);
            } else {
                LCS[i][j] = 0;
            }
        }
    }
    cout<<"Length of Longest Common Substring is "<<result<<endl;
    
    char *lcs = new char[result+1];
    lcs[result] = '\0';
    int ind;
    for (i=0; i<=m; i++) {
        for (j=0; j<=n; j++) {
            //cout<<" "<<LCS[i][j];
            if (LCS[i][j] == result )//this will only pick the last max result
                ind = i;
        }
        //cout<<endl;
    }
    result--;
    ind--;
    while(result>=0) {
        lcs[result] = X[ind];
        result--;
        ind--;
    }
    cout<<"Longest common substring is "<<lcs<<endl;
    delete[] lcs;
}

int main() {
    char X[] = "OldTestNew";
    char Y[] = "NewTestOld";
    LCSubStrDP(X, Y);
    return 0;
}
