//to find k-th prime factor
#include<bits/stdc++.h>
using namespace std;
#define MAX 10001

int s[MAX+1];

void sieveOfEratosthenes() {
    memset(s, -1, sizeof(s));
    vector <bool> prime(MAX+1, false);
    for (int i=2; i<=MAX; i+=2)
        s[i] = 2;
    for (int i=3; i<=MAX; i+=2) {
        if (prime[i] == false) {
            s[i] = i;
            for (int j=i; j*i<=MAX; j+=2) {
                if (prime[i*j] == false) {
                    prime[i*j] = true;
                    s[i*j] = i;
                }
            }
        }
    }
}

int kPrimeFactor(int n, int k) {
    while (n > 1) {
        if (k == 1)
            return s[n];
        k--;
        n /= s[n];
    }
    return -1;
}
 
int main() {
    sieveOfEratosthenes();
    int n = 12, k = 3;
    cout<<k<<"th prime factor of "<<n<<" is "<<kPrimeFactor(n, k)<<endl;
    n = 14, k = 3;
    cout<<k<<"th prime factor of "<<n<<" is "<<kPrimeFactor(n, k)<<endl;
    return 0;
}
