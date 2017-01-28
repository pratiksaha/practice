//Collatz Conjecture
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<bits/stdc++.h>
using namespace std;

bool collatzConjecture(int n, unordered_set<int> &s) {
    if (n == 1)
        return true;
    if (s.find(n) != s.end())
        return false;
    return (n % 2)? collatzConjecture(3*n + 1, s) : collatzConjecture(n/2, s);
}

bool collatzConjecture(int n) {
   unordered_set<int> s;
   return collatzConjecture(n, s);
}

int main() {
    int n = 5;
    cout<<n<<((n)? " does " : " does not ")<<"satisfy collatz conjecture\n";
    return 0;
}
