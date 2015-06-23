//to check if a string is a rotation of a palindrome
//TODO: do in O(n) time using manacher's algorithm
#include<iostream>
#include<string>
using namespace std;

bool checkPalindrome(string str) {
    int l = 0;
    int h = str.length() - 1;
    while (l<h)
        if (str[l++] != str[h--])
            return false;
    return true;
}

bool checkRotationPalindrome(string str) {
    if (checkPalindrome(str)) {
        return true;
    } else {
        int n = str.length();
        for (int i=0; i<n-1; i++) {
            string str1 = str.substr(i+1, n-i-1);
            string str2 = str.substr(0, i+1);
            if (checkPalindrome(str1.append(str2)))
                return true;
        }
        return false;
    }
}

int main() {
    checkRotationPalindrome("aab") ? cout<<"String is a rotation of a palindrome\n" : cout<<"String is not a rotation of a palindrome\n";
    checkRotationPalindrome("abcde") ? cout<<"String is a rotation of a palindrome\n" : cout<<"String is not a rotation of a palindrome\n";
    checkRotationPalindrome("aaaad") ? cout<<"String is a rotation of a palindrome\n" : cout<<"String is not a rotation of a palindrome\n";
    return 0;
}
