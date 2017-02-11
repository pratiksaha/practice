//to calculate minimum number of powers of x to make sum equal to n.
#include <bits/stdc++.h>
using namespace std;
 
int minPowerTerms(int n, int x) {
    if (x==1)
        return n;
    int ans = 0;
    while (n > 0) {
        ans += (n%x);
        n /= x;
    }
    return ans;
}
 
int main() {
    int n = 5, x = 3;
    cout<<minPowerTerms(n, x)<<endl;
    return 0;
}
