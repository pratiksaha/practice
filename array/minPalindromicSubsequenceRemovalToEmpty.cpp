//to count minimum palindromic subsequences to be removed to make an string empty
#include<bits/stdc++.h>
using namespace std;
 
bool isPalindrome(const char *str) {
    int l = 0;
    int h = strlen(str) - 1;
    while (h > l)
        if (str[l++] != str[h--])
            return false;
    return true;
}

int minPalindromicSubsequenceRemovalToEmpty(const char *str) {
    if (str[0] == '\0')
        return 0;
    if (isPalindrome(str))
        return 1;
    return 2;
}

int main() {
   cout<<minPalindromicSubsequenceRemovalToEmpty("010010")<<endl;
   cout<<minPalindromicSubsequenceRemovalToEmpty("0100101")<<endl;
   return 0;
}
