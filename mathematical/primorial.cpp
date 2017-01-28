//to calculate primorial
#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000000;

vector <int> primes;

void sieveSundaram() {
    bool marked[MAX/2 + 1] = {0};
    for (int i = 1; i <= (sqrt(MAX)-1)/2 ; i++)
        for (int j = (i*(i+1))<<1 ; j <= MAX/2 ; j += 2*i +1)
            marked[j] = true;
    primes.push_back(2);
    for (int i=1; i<=MAX/2; i++)
        if (marked[i] == false)
            primes.push_back(2*i + 1);
}

int primorial(int n) {
    int result = 1;
    for (int i = 0; primes[i] <= n ; i++)
        result = result * primes[i];
    return result;
}

int main() {
    int n = 15;
    sieveSundaram();
    for (int i = 1 ; i<= n; i++)
        cout<<"Primorial(P#) of "<<i<< " is "<<primorial(i)<<endl;
    return 0;
}
