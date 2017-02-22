//to count pair in range having GCD equal to given number
#include <bits/stdc++.h>
using namespace std;
 
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
 
int countPairsWithGCDInRange(int L, int R, int g) {
    L = (L + g - 1) / g;
    R = R/ g;
    int ans = 0;
    for (int i = L; i <= R; i++)
        for (int j = L; j <= R; j++)
            if (gcd(i, j) == 1)
                ans++;
    return ans;
}
 
int main() {
    int L = 1, R = 11, g = 5;
    cout<<"No of pairs in ["<<L<<","<<R<<"] with GCD = "<<g<<" is "<<countPairsWithGCDInRange(L, R, g)<<endl;
    return 0;
}
