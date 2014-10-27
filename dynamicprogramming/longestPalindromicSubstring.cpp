//Longest Palindromic Substring
#include<iostream>
#include<cstring>
using namespace std;

int longestPalSubstrDP(char *str) {
    int n = strlen(str);
    int i, j, k;
    int table[n][n];
    memset(table, 0, sizeof(table));
    
    int result = 1;
    int start = 0;
    for (i=0; i<n; i++ )//all length 1 substrings are palindromes
        table[i][i] = 1;
    
    for( k=2; k<=n; k++ ) { //k is length of substring
        for( i=0; i<n-k+1; i++ ) {//i is starting index
            j = i+k-1;//j is ending index
            if( (k==2 && str[i] ==str[j]) || (table[i+1][j-1] && str[i] == str[j]) ) {
                table[i][j] = 1;
                if( k>result ) {
                    start = i;
                    result = k;
                }
            }
        }
    }
    cout<<"Length of Longest Palindromic Substring is "<<result<<endl;
    
    char *lps = new char[result+1];
    lps[result] = '\0';  
    for (i=start, j=0; i<=start+result-1; i++, j++ )
        lps[j]=str[i];
    cout<<"Longest Palindromic Substring is "<<lps<<endl;
    delete[] lps; 
}

int main() {
    char str[] = "thistesttsetfor";
    longestPalSubstrDP(str) ;
    return 0;
}
