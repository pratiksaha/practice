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

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int order(int p, int b) { //returns k such that b^k = 1 (mod p)
    if (gcd(p, b) != 1)
        return -1;
    int k = 3;
    while (1) {
        if (modexp(b, k, p) == 1)
            return k;
        k++;
    }
}

int convertx2e(int x, int& e) { //return  p - 1 (= x argument) as  x * 2^e
    e = 0;
    while (x % 2 == 0) {
        x /= 2;
        e++;
    }
    return x;
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

int squareRootTonelliShank(int n, int p) {
    if (gcd(n, p) != 1)
        return -1;
    if (modexp(n, (p - 1) / 2, p) == (p - 1))
        return -1;
    int s, e;
    s = convertx2e(p - 1, e);
    int q;
    for (q = 2 ; 1 ; q++) {
        if (modexp(q, (p - 1) / 2, p) == (p - 1))
            break;
        if (q == 3)
            break;
    }
    int x = modexp(n, (s + 1) / 2, p);
    int b = modexp(n, s, p);
    int g = modexp(q, s, p);
    int r = e;
    while (1) {
        int m;
        for (m=0; m<r; m++) {
            if (order(p, b) == -1)
                return -1;
            if (order(p, b) == pow(2, m))
                break;
        }
        if (m == 0)
            return x;
        x = (x * modexp(g, pow(2, r - m - 1), p)) % p;
        g = modexp(g, pow(2, r - m), p);
        b = (b * g) % p;
        if (b == 1)
            return x;
        r = m;
    }
}

int main() {
    int p = 7, n = 2;
    int x;
    cout<<"(x*x) % p = n % p "<<(squareRootCheck(n, p)?"Yes":"No")<<endl;
    cout<<"(x*x) % p = n % p "<<(squareRootCheckEuler(n, p)?"Yes":"No")<<endl;
    cout<<"(x*x) % p = n % p is "<<squareRoot4iplus3(n, p)<<endl;
    cout<<"For n = "<<n<<" p = "<<p<<" : ";
    x = squareRootTonelliShank(n, p);
    if ( x == -1 )
        cout<<"Modular Squareroot is Not possible\n";
    else
        cout<<"Modular Square root is "<<x<<endl;
    p = 113;
    cout<<"For n = "<<n<<" p = "<<p<<" : ";
    x = squareRootTonelliShank(n, p);
    if ( x == -1 )
        cout<<"Modular Squareroot is Not possible\n";
    else
        cout<<"Modular Square root is "<<x<<endl;
    return 0;
}
