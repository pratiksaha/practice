//to calculate maximum number of groups of size 3 containing two type of items
#include<bits/stdc++.h>
using namespace std;
 
int maxGroupSize3Type2(int n, int m) {
    if (n >= 2*m)
        return n;
    if (m >= 2*n)
        return m;
    if ((m + n) % 3 == 0)
        return (m+n)/3;
    int ans = (m + n)/3;
    m %= 3;
    n %= 3;
    if (m && n && (m + n) >= 3)
        ans++;
    return ans;
}
 
int main() {
    int n = 4, m = 5;
    cout<<maxGroupSize3Type2(n, m)<<endl;
    return 0;
}
