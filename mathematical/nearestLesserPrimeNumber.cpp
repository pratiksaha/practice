//to find the nearest prime less than n
#include<bits/stdc++.h>
#define MAX 1000000
using namespace std;
 
vector<int> primes;
 
void sieve() {
    int n = MAX;
    int nNew = sqrt(n);
    int marked[n/2+500] = {0};
    for (int i=1; i<=(nNew-1)/2; i++)
        for (int j=(i*(i+1))<<1; j<=n/2; j=j+2*i+1)
            marked[j] = 1;
    primes.push_back(2);
    for (int i=1; i<=n/2; i++)
        if (marked[i] == 0)
            primes.push_back(2*i + 1);
}
 
int nearestLesserPrimeNumber(int left,int right,int n) {
    if (left<=right) {
        int mid = (left + right)/2;
        if (mid == 0 || mid == primes.size()-1)
            return primes[mid];
        if (primes[mid] == n)
            return primes[mid-1];
        if (primes[mid] < n && primes[mid+1] > n)
            return primes[mid];
        if (n < primes[mid])
            return nearestLesserPrimeNumber(left, mid-1, n);
        else
            return nearestLesserPrimeNumber(mid+1, right, n);
    }
    return 0;
}
 
int main() {
    sieve();
    int n = 17;
    cout<<"Nearest Prime Number less than "<<n<<" is "<<nearestLesserPrimeNumber(0, primes.size()-1, n)<<endl;
    return 0;
}
