//to find numbers with exactly n distinct prime factor numbers from a to b
#include<bits/stdc++.h>
using namespace std;
 
vector <int> primes;
 
void segmentedSieve() {
    int n = 10000;
    int nNew = (n-2)/2;
    bool marked[nNew + 1];
    memset(marked, false, sizeof(marked));
    for (int i=1; i<=nNew; i++)
        for (int j=i; (i + j + 2*i*j) <= nNew; j++)
            marked[i + j + 2*i*j] = true;
    primes.push_back(2);
    for (int i=1; i<=nNew; i++)
        if (marked[i] == false)
            primes.push_back(2*i+1);
}
 
int countNDistinctPrimeFactorsAB(int a, int b, int n) {
    segmentedSieve();
    int result = 0;
    for (int i=a; i<=b; i++) {
        int tmp = sqrt(i), copy = i;
        int count = 0;
        for (int j=0; primes[j]<=tmp; j++) {
            if (copy%primes[j]==0) {
                count++;
                while (copy%primes[j]==0)
                    copy = copy/primes[j];
            }
        }
        if (copy != 1)
            count++;
        if (count==n)
            result++;
    }
    return result;
}
 
int main() {
    int a = 1, b = 100, n = 3;
    cout<<"Total numbers with exactly "<<n<<" distinct prime factor numbers from "<<a<<" to "<<b<<" is "<<countNDistinctPrimeFactorsAB(a, b, n)<<endl;
    return 0;
}
