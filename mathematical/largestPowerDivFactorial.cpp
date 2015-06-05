//to find largest x such that p^x divides n!
#include<iostream>
using namespace std;

int largestPowerDivFactorial(int n, int p) {
    int x = 0; //x = n/p + n/(p^2) + n/(p^3) + ....
    while (n) {
        n /= p;
        x += n;
    }
    return x;
}

int main() {
    int n = 10, p = 3;
    cout<<"Largest power of "<<p<<" that divides "<<n<<"! is "<<largestPowerDivFactorial(n, p)<<endl;
    return 0;
}
