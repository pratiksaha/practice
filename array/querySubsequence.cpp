//to answer subsequence queries for given string
#include<bits/stdc++.h>
using namespace std;
#define MAX 10000
#define CHAR_SIZE 26

void precompute(int mat[MAX][CHAR_SIZE], char str[], int len) {
    for (int i = 0; i < CHAR_SIZE; i++)
        mat[len][i] = len;
    for (int i = len-1; i >= 0; i--) {
        for (int j = 0; j < CHAR_SIZE; j++)
            mat[i][j] = mat[i+1][j];
        mat[i][str[i]-'a'] = i;
    }
}

bool querySubsequence(int mat[MAX][CHAR_SIZE], const char str[], int len) {
    int pos = 0;
    for (int i = 0; i < strlen(str); ++i)
        if (mat[pos][str[i] - 'a'] >= len)
            return false;
        else
            pos = mat[pos][str[i] - 'a'] + 1;
    return true;
}

int main() {
    char S[]= "geeksforgeeks";
    int len = strlen(S);
    int mat[MAX][CHAR_SIZE];
    precompute(mat, S, len);
    querySubsequence(mat, "gg", len) ? cout<<"Yes\n" : cout<<"No\n";
    querySubsequence(mat, "gro", len) ? cout<<"Yes\n" : cout<<"No\n";
    querySubsequence(mat, "gfg", len) ? cout<<"Yes\n" : cout<<"No\n";
    querySubsequence(mat, "orf", len) ? cout<<"Yes\n" : cout<<"No\n";
    return 0;
}
