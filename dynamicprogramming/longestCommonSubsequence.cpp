//Longest Common Subsequence
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

void lcs( char *X, char *Y) {
    int m = strlen(X);
    int n = strlen(Y);
    int i, j, L[m+1][n+1];
 
   /* Following steps build L[m+1][n+1] in bottom up fashion. Note
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
    for (i=0; i<=m; i++) {
        for (j=0; j<=n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i-1] == Y[j-1])
                 L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }
 
    int k = L[m][n];
    char lcs[k+1];
    lcs[k] = '\0';
 
    i = m;
    j = n;
    while (k>0) {//Start from the right-most-bottom-most corner and one by one store characters in lcs
        if (X[i-1] == Y[j-1]) {//if current character in X and Y are same, then current character is part of LCS
            lcs[k-1] = X[i-1];
            i--;
            j--;
            k--;
        } else {//if not same, then find the larger of two and go in the direction of larger value
            if (L[i-1][j] > L[i][j-1])
                i--;
            else
                j--;
        }
    }
    cout<<"LCS of "<<X<<" & "<<Y<<" is "<<lcs<<endl;
    cout<<"diff of "<<X<<" & "<<Y<<" is\n";
    i = 0;
    j = 0;
    k = 0;
    for (k=0; k<L[m][n]; k++) {
        if(lcs[k] == X[i] && lcs[k] == Y[j]) {//if char in lcs do not print anything
            i++;
            j++;
        } else {
            while(lcs[k] != X[i]) {//print chars from X until next common char
                cout<<"> "<<X[i]<<endl;
                i++;
            }
            i++;
            while(lcs[k] != Y[j]) {//print chars from Y until next common char
                cout<<"< "<<Y[j]<<endl;
                j++;
            }
            j++;
        }
    }
    while(i<m) {//any remainning chars in X 
       cout<<"> "<<X[i]<<endl;
       i++;
    }
    while(j<n) {//any remainning chars in Y
        cout<<"< "<<Y[j]<<endl;
        j++;
    }
    
}

int main() {
    char X[] = "AGGTABCPV";
    char Y[] = "UGXTXAYBQWEPJKL";
    lcs(X, Y);
    return 0;
}
