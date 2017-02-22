//to find LCM of First N Natural Numbers
#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;
 
vector <int> primes;
 
void sieve() {
    bool isComposite[MAX] = {false};
    for (int i=2; i*i<=MAX; i++)
        if (isComposite[i]==false)
            for (int j=2; j*i<=MAX; j++)
                isComposite[i*j] = true;
    for (int i=2; i<=MAX; i++)
        if (isComposite[i]==false)
            primes.push_back(i);
}
 
long long int lcmTillN(int n) {
    long long lcm = 1;
    for (int i=0; i<primes.size() && primes[i]<=n; i++) {
        int pp = primes[i];
        while (pp*primes[i] <= n)
            pp = pp *primes[i];
        lcm *= pp;
        lcm %= 1000000007;
    }
    return lcm;
}

int main() {
    sieve();
    int N = 7;
    cout<<"LCM of all nos till "<<N<<" is "<<lcmTillN(N)<<endl;
    return 0;
}
