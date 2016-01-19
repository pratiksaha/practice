//primes
#include<bits/stdc++.h>
using namespace std;

int powerModP(int a, unsigned int n, int p) {
    int res = 1;
    a = a % p;
    while (n > 0) {
        if (n & 1)
            res = (res*a) % p;
        n = n>>1;
        a = (a*a) % p;
    }
    return res;
}

bool primeNaive(int n) {
    if (n<=1)
        return false;
    for (int i=2; i<n; i++)
        if (n%i == 0)
            return false;
    return true;
}

bool primeFermat(unsigned int n, int k) {
    if (n <= 1 || n == 4)
    return false;
    if (n <= 3)
        return true;
    while (k>0) {
        int a = 2 + rand()%(n-4);
        if (powerModP(a, n-1, n) != 1) // Fermat's little theorem
            return false;
        k--;
    }
    return true;
}

void simpleSieve(int limit, vector<int> &prime) {
    bool mark[limit+1];
    memset(mark, true, sizeof(mark));
    for (int p=2; p*p<limit; p++)
        if (mark[p] == true)
            for (int i=p*2; i<limit; i+=p)
                mark[i] = false;
    for (int p=2; p<limit; p++) {
        if (mark[p] == true) {
            prime.push_back(p);
            cout<<" "<<p;
        }
    }
}

void segmentedSieve(int n) {
    int limit = floor(sqrt(n))+1;
    vector<int> prime;  
    simpleSieve(limit, prime); 
    int low  = limit;
    int high = 2*limit;
    while (low < n) {
        bool mark[limit+1];
        memset(mark, true, sizeof(mark));
        for (int i=0; i<prime.size(); i++) {
            int loLim = floor(low/prime[i]) * prime[i];
            if (loLim<low)
                loLim += prime[i];
            for (int j=loLim; j<high; j+=prime[i])
                mark[j-low] = false;
        }
        for (int i=low; i<high; i++)
            if (mark[i-low] == true)
                cout<<" "<<i;
        low += limit;
        high += limit;
        if (high>=n)
            high = n;
    }
    cout<<endl;
}

int sundaramSieve(int n) {
    int nNew = (n-2)/2;
    bool marked[nNew + 1];
    memset(marked, false, sizeof(marked));
    for (int i=1; i<=nNew; i++)
        for (int j=i; (i+j+2*i*j)<=nNew; j++)
            marked[i+j+2*i*j] = true;
    if (n > 2)
        cout<<" "<<2;
    for (int i=1; i<=nNew; i++)
        if (marked[i] == false)
            cout<<" "<<2*i+1;
    cout<<endl;
}

bool testMillerRabin(int d, int n) {
    int a = 2+rand()%(n-4);
    int x = powerModP(a, d, n);
    if (x == 1 || x == n-1)
        return true;
    while (d != n-1) {
        x = (x*x)%n;
        d *= 2;
        if (x == 1)
            return false;
        if (x == n-1)
            return true;
    }
    return false;
}

bool primeMillerRabin(int n, int k) {
    if (n <= 1 || n == 4)
        return false;
    if (n <= 3)
        return true;
    int d = n-1;
    while (d%2 == 0)
        d /= 2;
    for (int i=0; i<k; i++)
        if (testMillerRabin(d, n) == false)
            return false;
    return true;
}

int main() {
    int n, k;
    k = 3;
    n = 11;
    cout<<n<<(primeNaive(n)?" is ":" is not ")<<"prime\n";
    cout<<n<<(primeFermat(n, k)?" is ":" is not ")<<"prime\n";
    n = 15;
    cout<<n<<(primeNaive(n)?" is ":" is not ")<<"prime\n";
    cout<<n<<(primeFermat(n, k)?" is ":" is not ")<<"prime\n";
    n = 100;
    cout<<"Primes Smaller than "<<n<<" :";
    segmentedSieve(n);
    cout<<"Primes Smaller than "<<n<<" :";
    sundaramSieve(n);
    k = 4;
    cout<<"All primes smaller than "<<n<<" :";
    for (int i=1; i<n; i++)
        if (primeMillerRabin(i, k))
            cout<<" "<<i;
    cout<<endl;
    return 0;
}
