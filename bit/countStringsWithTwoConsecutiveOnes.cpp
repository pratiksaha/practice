//count all distinct binary strings with two consecutive 1's
//TODO: optimize to O(logn) using S(n) = 2^n - fib(n+2)
#include<bits/stdc++.h>
using namespace std;

int countStringsWithTwoConsecutiveOnes(int n) {
    int a[n], b[n];
    a[0] = b[0] = 1;
    for (int i=1; i<n; i++) {
        a[i] = a[i-1] + b[i-1];
        b[i] = a[i-1];
    }
    return (1<<n) - a[n-1] - b[n-1];
}
int main() {
    int n = 5;
    cout<<"No of distinct binary strings with two consecutive 1's of length "<<n<<" is "<<countStringsWithTwoConsecutiveOnes(5)<<endl;
    return 0;
}
