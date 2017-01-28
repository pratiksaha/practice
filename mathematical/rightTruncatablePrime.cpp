//to check whether a given number is a right-truncatable prime
#include<bits/stdc++.h>
using namespace std;

bool sieveOfEratosthenes(int n, bool isPrime[]) {
    isPrime[0] = isPrime[1] = false;
    for (int i=2; i<=n; i++)
        isPrime[i] = true;
    for (int p=2; p*p<=n; p++)
        if (isPrime[p] == true)
            for (int i=p*2; i<=n; i += p)
                isPrime[i] = false;
}

bool rightTruncatablePrime(int n) {
    bool isPrime[n+1];
    sieveOfEratosthenes(n, isPrime);
    while (n) {
        if (isPrime[n])
            n = n/10;
        else
            return false;
    }
    return true;
}

int main() {
    int n = 59399;
    cout<<n<<" is"<<(rightTruncatablePrime(n)? " " : " not ")<<"a right truncatable prime no\n";
    return 0;
}
