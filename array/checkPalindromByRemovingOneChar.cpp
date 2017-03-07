//to check if it is possible to make string palindrome by removing one character
#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string::iterator low, string::iterator high) {
    while (low < high) {
        if (*low != *high)
            return false;
        low++;
        high--;
    }
    return true;
}

int checkPalindromByRemovingOneChar(string str) {
    int low = 0, high = str.length() - 1;
    while (low < high) {
        if (str[low] == str[high]) {
            low++;
            high--;
        } else {
            if (isPalindrome(str.begin() + low + 1, str.begin() + high))
                return low;
            if (isPalindrome(str.begin() + low, str.begin() + high - 1))
                return high;
            return -1;
        }
    }
    return -2;
}

int main() {
    string str = "abecbea";
    int idx = checkPalindromByRemovingOneChar(str);
    if (idx == -1)
        cout<<str<<" cannot be made palindrome by removing one character\n";
    else if (idx == -2)
        cout<<str<<" is already palindrome\n";
    else
        cout<<str<<" can be made palindrome by removing character at index "<<idx<<endl;
    return 0;
}
