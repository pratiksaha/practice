//to get lexicographically smallest palindrome string after replacement
#include<bits/stdc++.h>
using namespace std;

bool isPossiblePalindrome(string str) {
    int n = str.length();
    for (int i=0; i<n/2; i++) 
        if (str[i] != '.' && str[n-i-1] != '.' && str[i] != str[n-i-1])
            return false;
    return true;
}

string smallestPalindromeAfterReplacement(string str) {
    if (!isPossiblePalindrome(str))
        return "Not Possible";
    int n = str.length();
    for (int i = 0; i < n; i++) {
        if (str[i] == '.') {
            if (str[n - i - 1] != '.')
                str[i] = str[n - i - 1];
            else
                str[i] = str[n - i - 1] = 'a';
        }
    }
    return str;
}

int main() {
    string str = "ab..e.c.a";
    cout<<smallestPalindromeAfterReplacement(str)<<endl;
    return 0;
}
