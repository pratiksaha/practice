// C++ program to count number of factors of n
#include<bits/stdc++.h>
using namespace std;

void sieve(int n, bool prime[]) {
    for (int i=1; i<=n; i++)
        prime[i] = 1;
    prime[1] = 0;
    for (int i=2; i*i<=n; i++)
        if (prime[i])
            for (int j=i*i; j<=n; j += i)
                prime[j] = 0;
}

int expFactor(int n, int p) {
    int x = p;
    int exponent = 0;
    while ((n/x) > 0) {
        exponent += n/x;
        x *= p;
    }
    return exponent;
}

long long int countFactorsOfNFactorial(int n) {
    long long int ans = 1;
    bool prime[n+1];
    sieve(n, prime);
    for (int p=1; p<=n; p++)
        if (prime[p]==1)
            ans *= (expFactor(n, p) + 1);
    return ans;
}

int main() {
    int n = 16;
    cout<<"Count of factors of ("<<n<<")! is "<<countFactorsOfNFactorial(n)<<endl;
    return 0;
}
