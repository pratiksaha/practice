//to compute sum of digits in numbers from 1 to n
#include<iostream>
#include<cmath>
using namespace std;

int sumOfDigitsFrom1ToN(int n) {
    if (n<10)
        return n*(n+1)/2;
    int d = log10(n);
    int a[d+1];
    a[0] = 0, a[1] = 45;
    for (int i=2; i<=d; i++)
        a[i] = a[i-1]*10 + 45*ceil(pow(10,i-1));
    int p = ceil(pow(10, d));
    int msd = n/p;
    return msd*a[d] + (msd*(msd-1)/2)*p + msd*(1+n%p) + sumOfDigitsFrom1ToN(n%p);
}

int main() {
    int n = 328;
    cout<<"Sum of digits in numbers from 1 to "<<n<<" is "<<sumOfDigitsFrom1ToN(n)<<endl;
    return 0;
}
