//to find minimum number of flip to make binary string alternate
#include <bits/stdc++.h>
using namespace std;

char flip(char ch) {
    return (ch == '0') ? '1' : '0';
}

int getFlipWithStartingCharcter(string str, char expected) {
    int flipCount = 0;
    int n = str.length();
    for (int i = 0; i < n; i++) {
        if (str[i] != expected)
            flipCount++;
        expected = flip(expected);
    }
    return flipCount;
}

int minFlipToMakeStringAlternate(string str) {
    return min(getFlipWithStartingCharcter(str, '0'), getFlipWithStartingCharcter(str, '1'));
}

int main() {
    string str = "0001010111";
    cout<<"Min flips to make "<<str<<" alternate is "<<minFlipToMakeStringAlternate(str)<<endl;
    return 0;
}
