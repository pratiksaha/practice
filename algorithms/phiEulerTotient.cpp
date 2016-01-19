//Euler's Totient Function
#include<iostream>
using namespace std;
 
int phiEulerTotient(int n) {
    int result = n; 
    for (int p=2; p*p<=n; ++p) { //consider all prime factors of n and subtract their multiples from result
        if (n % p == 0) { //if p is a prime factor of n
            while (n%p == 0)
                n /= p;
            result -= result/p;
        }
    }
    if (n > 1) //if n has a prime factor greater than sqrt(n)
        result -= result/n;
    return result;
}

int phiEulerTotientSieve(int n) { 
    long long phi[n+1];
    for (int i=1; i<=n; i++)
        phi[i] = i;
    for (int p=2; p<=n; p++) {
        if (phi[p] == p) { //p is prime if phi[p] is not computed already
            phi[p] = p-1; //Phi of a prime number p is always equal to p-1
            for (int i = 2*p; i<=n; i += p) { //update phi values of all multiples of p
               phi[i] = (phi[i]/p) * (p-1);
            }
        }
    }
    for (int i=1; i<=n; i++)
        cout<<"Totient of "<<i<<" is "<<phi[i]<<endl;
}

int main() {
    for (int i=1; i<=20; i++)
        cout<<"phi("<<i<<") = "<<phiEulerTotient(i)<<endl;
    phiEulerTotientSieve(20);
    return 0;
}
