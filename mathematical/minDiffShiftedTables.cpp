//to find the minimum difference between any two terms of two tables
#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int minDiffShiftedTables(int a, int b, int x, int y) {
    int g  = gcd(a,b);
    int diff = abs(x-y) % g;
    return min(diff, g - diff);
}

int main() {
    int a = 20, b = 52, x = 5, y = 7;
    cout<<minDiffShiftedTables(a, b, x, y)<<endl;
    return 0;
}
