//prime factors
#include<bits/stdc++.h>
using namespace std;

void primeFactors(int n, bool distinct=false) {
    int prev = 0;
    if (distinct)
        cout<<"Distinct Prime Factors :";
    else
        cout<<"All Prime Factors :";
    while (n%2 == 0) {
        if (distinct) {
            if (prev != 2) {
                cout<<" 2";
                prev = 2;
            }
        } else {
            cout<<" 2";
        }
        n = n/2;
    }
    for (int i=3; i<=sqrt(n); i = i+2) {
        while (n%i == 0) {
            if (distinct) {
                if (prev != i) {
                    cout<<" "<<i;
                    prev = i;
                }        
            } else {
                cout<<" "<<i;
            }
            n = n/i;
        }
    }
    if (n>2  && (!distinct || n!=prev))
        cout<<" "<<n;
    cout<<endl;
}

long long int modular_pow(long long int base, int exponent, long long int modulus) {
    long long int result = 1;
    while (exponent>0) {
        if (exponent & 1)
            result = (result*base)%modulus;
        exponent = exponent>>1;
        base = (base*base)%modulus;
    }
    return result;
}

long long int primeFactorPollardRho(long long int n) {
    srand (time(NULL));
    if (n==1)
        return n;
    if (n%2 == 0)
        return 2;
    long long int x = (rand()%(n-2))+2;
    long long int y = x;
    long long int c = (rand()%(n-1))+1;
    long long int d = 1;
    while (d==1) {
        x = (modular_pow(x, 2, n)+c+n)%n;
        y = (modular_pow(y, 2, n)+c+n)%n;
        y = (modular_pow(y, 2, n)+c+n)%n;
        d = __gcd(abs(x-y), n); //TODO
        if (d==n)
            return primeFactorPollardRho(n);
    }
    return d;
}

int main() {
    int n = 50;
    primeFactors(n);
    primeFactors(n, true);
    long long int k = 10967535067;
    cout<<"One of the divisors for "<<k<<" is "<<primeFactorPollardRho(k)<<endl;
    return 0;
}
