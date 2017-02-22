//to find GCD of Fib(M) and Fib(N)
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

int f[MAX] = {0};

int fib(int n) {
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return (f[n] = 1);
    if (f[n])
        return f[n];
    int k = (n & 1)? (n+1)/2 : n/2;
    f[n] = (n & 1)? (fib(k)*fib(k) + fib(k-1)*fib(k-1)) : (2*fib(k-1) + fib(k))*fib(k);
    return f[n];
}
 
int gcd(int M, int N) {
    return (M ? gcd(N%M, M) : N);
}
 
int gcdFibMFibN(int M,  int N) {
    return fib(gcd(M, N));
}

int main() {
   int M = 3, N = 12;
   cout<<"GCD(Fib("<<M<<"),Fib("<<N<<")) = "<<gcdFibMFibN(M, N)<<endl;
   return 0;
}
