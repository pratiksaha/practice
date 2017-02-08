//find first natural number whose factorial divides x
#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if ((a % b) == 0)
        return b;
    return gcd(b, a % b);
}

int firstFactorialDivisibleNumber(int x) {
    int i = 1;
    int new_x = x;
    for (i=1; i<x; i++) {
        new_x /= gcd(i, new_x);
        if (new_x == 1)
            break;
    }
    return i;
}
 
int main(void) {
    int x = 16;
    cout<<"First natural number whose factorial divides "<<x<<" is "<<firstFactorialDivisibleNumber(x)<<endl;
    return 0;
}
