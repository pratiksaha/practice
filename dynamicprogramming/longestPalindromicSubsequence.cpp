//Longest Palindromic Subsequence
#include<iostream>
#include<cstring>
using namespace std;

void lpsDP(char *str){//this is a DP based O(n^2) solution
    int n = strlen(str);
    int i, j, cl;
    int L[n][n];

    for (i = 0; i < n; i++)//every single character is a palindrome of length 1
        L[i][i] = 1;
 
    for (cl=2; cl<=n; cl++) {//consider sequences of lengths 2..n
        for (i=0; i<n-cl+1; i++) {//start index of the sequence
            j = i+cl-1;//end index of the sequence
            if (str[i] == str[j] && cl == 2)//if there are only 2 chars and both are same
                L[i][j] = 2;
            else if (str[i] == str[j])//if there are more than two characters, and start and end chars are same
                L[i][j] = L[i+1][j-1] + 2;
            else//if start and end characters are not same
                L[i][j] = max(L[i][j-1], L[i+1][j]);
        }
    }
 
    cout<<"Longest Palindromic Subsequence length = "<<L[0][n-1]<<endl;
}

int main() {
    char a[] = "TESTATHISTEST";
    lpsDP(a);
    return 0;
}
