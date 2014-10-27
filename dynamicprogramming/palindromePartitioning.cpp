//Palindrome Partitioning Problem
#include<iostream>
#include<cstring>
#include<climits>
#include<algorithm>
using namespace std;

int palPartitonDP(char *str) {
    int n = strlen(str);
    int C[n][n]; //C[i][j] = min no of cuts needed for palindrome partitioning of substring str[i..j]
    bool P[n][n]; //P[i][j] is true if substring str[i..j] is palindrome, 
 
    int i, j, k, L;
    for (i=0; i<n; i++) { //all length 1 substrings are palindromes
        P[i][i] = true;
        C[i][i] = 0;
    }
 
    for (L=2; L<=n; L++) { //L is length of substring
        for (i=0; i<n-L+1; i++) { //i is starting index
            j = i+L-1; //j is ending index
            if ( (L==2 && str[i]==str[j]) || (str[i] == str[j] && P[i+1][j-1]) ) {
                P[i][j] == true;
                C[i][j] = 0;
            } else {
                P[i][j] = false;
                C[i][j] = INT_MAX;
                for (k=i; k<=j-1; k++) //make a cut at every possible location starting from i to j and get the minimum cost cut
                    C[i][j] = min (C[i][j], C[i][k]+C[k+1][j]+1);
            }
        }
    }
    return C[0][n-1];
}

int main() {
    char str[] = "ababbbabbababa";
    cout<<"Min cuts needed for Palindrome Partitioning is "<<palPartitonDP(str)<<endl;
    return 0;
}
