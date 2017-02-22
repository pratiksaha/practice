//to find n-th element in the sorted list of multiples of two numbers
#include<bits/stdc++.h>
using namespace std;
 
int nElementSortedMultiple(int a, int b, int n) {
    int lcm = (a * b)/__gcd(a,b);
    int l = 1, r = min(a, b)*n;
    while (l <= r) {
        int mid = (l + r)/2;
        int val = mid/a + mid/b - mid/lcm;
        if (val == n)
            return max((mid/a)*a, (mid/b)*b);
        if (val < n)
            l = mid + 1;
        else
            r = mid - 1;
    }
}

int main() {
    int a = 5, b = 3, n = 5;
    cout<<n<<"th element in the sorted list of multiples of "<<a<<" & "<<b<<" is "<<nElementSortedMultiple(a, b, n)<<endl;
    return 0;
}
