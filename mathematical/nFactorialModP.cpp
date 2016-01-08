//to comput n! % p
#include<bits/stdc++.h>
using namespace std;

int largestPower(int n, int p) {
    int x = 0; 
    while (n) {
        n /= p;
        x += n;
    }
    return x; //x = n/p + n/(p^2) + n/(p^3) + ....
} 

int modexp(int x, unsigned int y, int p) {
    int res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

int modInverse(int a, int p) { //p is prime
   return modexp(a, p-2, p);
}

int nFactorialModPSieve(int n, int p) { ////n! % p using Sieve of Eratosthenes
    if (n >= p)
        return 0;
    int res = 1;
    bool isPrime[n+1];
    memset(isPrime, 1, sizeof(isPrime));
    for (int i=2; i*i<=n; i++) {
        if (isPrime[i]) {
            for (int j=2*i; j<=n; j+=i)
                isPrime[j] = 0;
        }
    }
    for (int i=2; i<=n; i++) {
        if (isPrime[i]) {
            int k = largestPower(n, i);
            res = (res*modexp(i, k, p)) % p;
        }
    }
    return res;
}

int nFactorialModPWilson(int n, int p) { //n! % p using Wilson's Theorem
    if (p <= n)
        return 0;
    int res = (p-1);
    for (int i=n+1; i<p; i++)
       res  = (res*modInverse(i, p)) % p;
    return res;
}

int main() {
    int n = 25, p = 29;
    cout<<n<<"! % "<<p<<" = "<<nFactorialModPSieve(n, p)<<endl;
    cout<<n<<"! % "<<p<<" = "<<nFactorialModPWilson(n, p)<<endl;
    return 0;
}
