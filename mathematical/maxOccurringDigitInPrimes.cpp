//to find the highest occurring digit in prime numbers in a range
#include<bits/stdc++.h>
using namespace std;
 
void sieve(bool prime[], int n) {
    for (int p = 2; p * p  <= n; p++)
        if (prime[p] == false)
            for (int i = p*2; i <= n; i+=p)
                prime[i] = true;
}
 
int maxOccurringDigitInPrimes(int L, int R) {
    bool prime[R+1];
    memset(prime, 0, sizeof(prime));
    sieve(prime, R);
    int freq[10] = { 0 };
    int val;
    for (int i = L; i <= R; i++) {
        if (!prime[i]) {
            int p = i;
            while (p) {
                freq[p%10]++;
                p /= 10;
            }
        }
    }
    int max = freq[0], ans = 0;
    for (int j = 1; j < 10; j++) {
        if (max <= freq[j]) {
            max = freq[j];
            ans = j;
        }
    }
    return ans;
}
 
int main() {
    int L = 1, R = 20;
    cout<<"Max occurring digit in all primes within ["<<L<<","<<R<<"] is "<<maxOccurringDigitInPrimes(L, R)<<endl;
    return 0;
}
