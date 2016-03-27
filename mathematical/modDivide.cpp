//modular division
#include<bits/stdc++.h>
using namespace std;

int gcdExtended(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;
}

int modInverse(int b, int m) {
    int x, y;
    int g = gcdExtended(b, m, &x, &y);
    if (g != 1)
        return -1;
    return (x%m + m) % m;
}

void modDivide(int a, int b, int m) {
    cout<<"Value of c such that ("<<b<<"*c)%"<<m<<" = "<<a<<"%"<<m<<" is ";
    a = a % m;
    int inv = modInverse(b, m);
    if (inv == -1)
       cout<<"Not Defined\n";
    else
       cout<<(inv*a)%m<<endl;
}

int main() {
    int a = 8, b = 3, m = 5;
    modDivide(a, b, m);
    return 0;
}
