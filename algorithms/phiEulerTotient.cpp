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

int main() {
    for (int i=1; i<=20; i++)
        cout<<"phi("<<i<<") = "<<phiEulerTotient(i)<<endl;
    return 0;
}
