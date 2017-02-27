//to check if given string is palindrome or not after every query
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<bits/stdc++.h>
using namespace std;
 
void addRemoveUnequal(string &str, int index, int n, unordered_set<int> &S) {
    if (str[index] == str[n-1-index]) {
        auto it = S.find(index);
        if (it != S.end())
            S.erase(it) ;
    } else {
        S.insert(index);
    }
}

void checkPalindromeAfterEveryQuery(string &str, int Q) {
    int n = str.length();
    unordered_set<int> S;
    for (int i=0; i<n/2; i++)
        if (str[i] != str[n-1-i])
            S.insert(i);
    for (int q=1; q<=Q; q++) {
        int i1, i2;
        char ch;
        cin >> i1 >> i2 >> ch;
        str[i1] = str [i2] = ch;
        if (i1 > n/2)
            i1 = n- 1 -i1;
        if (i2 > n/2)
            i2 = n -1 - i2;
        addRemoveUnequal(str, i1 , n, S );
        addRemoveUnequal(str, i2 , n, S );
        cout<<(S.empty()? "YES" : "NO")<<endl;
    }
}

int main() {
    string str = "geeks";
    int Q = 2 ;
    checkPalindromeAfterEveryQuery(str, Q);
    return 0;
}
