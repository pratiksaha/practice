//to find the minimum value of m that satisfies ax + by = m and all values after m also satisfy
#include<bits/stdc++.h>
using namespace std;
 
inline int minValueForLinearEqnAndAll(int a, int b) {
    return (__gcd(a, b) == 1)? a*b-a-b+1 : -1;
}
 
int main() {
    int a = 4, b = 7;
    cout<<minValueForLinearEqnAndAll(a, b)<<endl;
    return 0;
}
