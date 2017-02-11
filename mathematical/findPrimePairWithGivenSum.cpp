//to find a prime number pair whose sum is equal to given number
#include<bits/stdc++.h>
using namespace std;

bool SieveOfEratosthenes(int n, bool isPrime[]) {
    isPrime[0] = isPrime[1] = false;
    for (int i=2; i<=n; i++)
        isPrime[i] = true;
    for (int p=2; p*p<=n; p++)
        if (isPrime[p] == true)
            for (int i=p*2; i<=n; i += p)
                isPrime[i] = false;
}

void findPrimePairWithGivenSum(int n) {
    bool isPrime[n+1];
    SieveOfEratosthenes(n, isPrime);
    for (int i=0; i<n; i++) {
        if (isPrime[i] && isPrime[n-i]) {
            cout<<"Prime pair with sum "<<n<<" are "<<i<<" & "<<(n-i)<<endl;
            return;
        }
    }
}
 
int main() {
    findPrimePairWithGivenSum(74);
    return 0;
}
