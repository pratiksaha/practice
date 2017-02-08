//to find count of divisors in n!
#include<bits/stdc++.h>
using namespace std;

vector<unsigned long long int> allPrimes;
 
void sieve(int n) {
    vector<bool> prime(n+1, true);
    for (int p=2; p*p<=n; p++) {
        if (prime[p] == true) {
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
    for (int p=2; p<=n; p++)
        if (prime[p])
            allPrimes.push_back(p);
}
 
unsigned long long int countFactorialDivisors(unsigned long long int n) {
    sieve(n);
    unsigned long long int result = 1;
    for (int i=0; i < allPrimes.size(); i++) {
        unsigned long long int p = allPrimes[i];
        unsigned long long int exp = 0;
        while (p <= n) {
            exp = exp + (n/p);
            p = p*allPrimes[i];
        }
        result = result*(exp+1);
    }
    return result;
}
 
int main(){
    int n = 6;
    cout<<"No of divisors of "<<n<<"! is "<<countFactorialDivisors(6)<<endl;
    return 0;
}
