//to count no of sols for x^2  = 1 mod p where x lies in range [1, n]
#include<bits/stdc++.h>
using namespace std;

long long int countSolutionXSquareEqualsOneModPRange(int n, int p) {
    long long int ans = 0;
    for (long long int x=1; x<p; x++) {
        if ((x*x)%p == 1) {
            long long int last = x + p * (n/p);
            if (last > n)
                last -= p;
            ans += ((last-x)/p + 1);
        }
    }
    return ans;
}

int main() {
    int n = 10, p = 5;
    cout<<"No of sols for x^ = 1 mod p where x in [1,"<<n<<"] and p = "<<p<<" is "<<countSolutionXSquareEqualsOneModPRange(n, p)<<endl;
    return 0;
}
