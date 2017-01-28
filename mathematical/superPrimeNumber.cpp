//to print super prime nos
#include<bits/stdc++.h>
using namespace std;

bool SieveOfEratosthenes(int n, bool isPrime[]) {
    isPrime[0] = isPrime[1] = false;
    for (int i=2; i<=n; i++)
        isPrime[i] = true;
    for (int p=2; p*p<=n; p++)
        if (isPrime[p])
            for (int i=p*2; i<=n; i+=p)
                isPrime[i] = false;
}

void superPrimeNumber(int n) {
    cout<<"Super Prime Nos upto "<<n<<" are :";
    bool isPrime[n+1];
    SieveOfEratosthenes(n, isPrime);
    int primes[n+1], j = 0;
    for (int p=2; p<=n; p++)
        if (isPrime[p])
            primes[j++] = p;
    for (int k=0; k<j; k++)
        if (isPrime[k+1])
            cout<<" "<<primes[k];
    cout<<endl;
}

int main() {
    superPrimeNumber(241);
    return 0;
}
