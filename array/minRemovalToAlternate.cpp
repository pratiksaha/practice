//to find min chars to be removed to make a binary string alternate
#include<bits/stdc++.h>
using namespace std;

int minRemovalToAlternate(string s) {
    int result = 0;
    for (int i=0; i<(s.length()-1); i++)
        if (s[i] == s[i+1])
            result++;
    return result;
}

int main() {
    cout<<minRemovalToAlternate("000111")<<endl;
    cout<<minRemovalToAlternate("11111")<<endl;
    cout<<minRemovalToAlternate("01010101")<<endl;
    return 0;
}
