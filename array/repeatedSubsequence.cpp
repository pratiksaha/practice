//to check if any repeated subsequence exists in the string
#include<bits/stdc++.h>
#define MAX_CHAR 256
using namespace std;

bool isPalindrome(char str[], int l, int h) {
    while (h > l)
        if (str[l++] != str[h--])
            return false;
    return true;
}
 
bool repeatedSubsequence(char str[]) {
    int n = strlen(str);
    int freq[MAX_CHAR] = { 0 };
    for (int i = 0; i < n; i++) {
        freq[str[i]]++;
        if (freq[str[i]] > 3)
            return true;
    }
    int k = 0;
    for (int i = 0; i < n; i++)
        if (freq[str[i]] > 1)
            str[k++] = str[i];
    str[k] = '\0';
    if (isPalindrome(str, 0, k-1)) {
        if (k & 1)
            return str[k/2] == str[k/2 - 1];
        return false;
    }
    return true;
}
 
int main() {
    char str[] = "ABCABD";
    if (repeatedSubsequence(str))
        cout<<"Repeated Subsequence Exists\n";
    else
        cout<<"Repeated Subsequence Does Not Exists\n";
    return 0;
}
