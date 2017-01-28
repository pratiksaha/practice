//to print Mersenne primes
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

void mersennePrime(int n) {
    bool prime[n+1];
    sieveOfEratosthenes(n, prime);
    cout<<"Mersenne prime numbers upto "<<n<<" :";
    for (int k=2; ((1<<k)-1) <= n; k++) {
        long long num = (1<<k) - 1;
        if (prime[num])
            cout<<" "<<num;
    }
    cout<<endl;
}

int main() {
    int n = 31;
    mersennePrime(n);
    return 0;
}
