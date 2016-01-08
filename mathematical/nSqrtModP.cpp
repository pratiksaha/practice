//programs for sqrt(n) % p
#include<bits/stdc++.h>
using namespace std;

int modexp(int x, unsigned int y, int p) {
    int res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

bool squareRootCheck(int n, int p) {
    n = n%p;
    for (int x=2; x<p; x++)
        if ((x*x)%p == n)
            return true;
    return false;
}

bool squareRootCheckEuler(int n, int p) {
    return modexp(n, (p-1)/2, p) == 1? true : false; //check for Euler's criterion i.e. [n ^ ((p-1)/2)] % p is 1 or not 
}

int squareRoot4iplus3(int n, int p) { //find sqrt when p is of the form 4*i+3
    if (p % 4 != 3)
       return -1;
    n = n % p;
    int x = modexp(n, (p+1)/4, p);
    if ((x*x)%p == n)
        return x;
    x = p - x;
    if ((x*x)%p == n)
        return x;
    return -1;
}

int main() {
   int p = 7, n = 2;
   cout<<"(x*x) % p = n % p "<<(squareRootCheck(n, p)?"Yes":"No")<<endl;
   cout<<"(x*x) % p = n % p "<<(squareRootCheckEuler(n, p)?"Yes":"No")<<endl;
   cout<<"(x*x) % p = n % p is "<<squareRoot4iplus3(n, p)<<endl;
   return 0;
}
