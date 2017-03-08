//to check if a string can be converted to a string that has repeated substrings of length k
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<bits/stdc++.h>
using namespace std;

bool checkStringRepeatedSubstringLengthK(string str, long k) {
    int n = str.length();
    if (n%k != 0)
        return false;
    unordered_map<string, int> mp;
    for (int i=0; i<n; i+=k)
        mp[str.substr(i, k)]++;
    if (mp.size() == 1)
        return true;
    if (mp.size() != 2)
        return false;
    return (mp.begin()->second == (n/k - 1) || mp.begin()->second == 1) ? true : false;
}

int main() {
    checkStringRepeatedSubstringLengthK("abababcd", 2)? cout<<"Yes\n" : cout<<"No\n";
    return 0;
}
