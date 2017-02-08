//to count natural numbers whose factorials are divisible by x but not y
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

int countFactorialXNotY(int x, int y) {
    return (firstFactorialDivisibleNumber(y) - firstFactorialDivisibleNumber(x));
}

int main(void) {
    int x = 15, y = 25;
    cout<<"Total nos whose factorials are divisible by "<<x<<" but not "<<y<<" is "<<countFactorialXNotY(x, y)<<endl;
    return 0;
}
