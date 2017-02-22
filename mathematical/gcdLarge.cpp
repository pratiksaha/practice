//to find GCD of two numbers such that the second number can be very large
#include<bits/stdc++.h>
using namespace std;
 
long long int gcd(long long int a, long long int b) {
    if (!a)
        return b;
    return gcd(b%a,a);
}

long long int reduceB(long long int a, char b[]) {
    long long int mod = 0;
    for (int i=0; i<strlen(b); i++)
        mod = (mod*10 + b[i] - '0')%a;
    return mod;
}

long long int gcdLarge(long long int a, char b[]) {
    long long int num = reduceB(a, b);
    return gcd(a, num);
}
 
int main() {
    long long int a = 1221;
    char b[] = "1234567891011121314151617181920212223242526272829";
    cout<<gcdLarge(a, b)<<endl;
    return 0;
}
