//to find the number of digits in factorial
#include<bits/stdc++.h>
using namespace std;

int countDigitsFactorialN(int n) {
    if (n < 0)
        return 0;
    if (n <= 1)
        return 1;
    double digits = 0;
    for (int i=2; i<=n; i++)
        digits += log10(i);
    return floor(digits) + 1;
}

long long int countDigitsFactorialNKamenetsky(int n) {
    if (n < 0)
        return 0;
    if (n <= 1)
        return 1;
    double x = ((n*log10(n/M_E)+log10(2*M_PI*n)/2.0));
    return floor(x)+1;
}

int main() {
    int n;
    n = 1;
    cout<<"No of digits in "<<n<<"! is "<<countDigitsFactorialN(n)<<endl;
    n = 5;
    cout<<"No of digits in "<<n<<"! is "<<countDigitsFactorialN(n)<<endl;
    n = 10;
    cout<<"No of digits in "<<n<<"! is "<<countDigitsFactorialN(n)<<endl;
    n = 120;
    cout<<"No of digits in "<<n<<"! is "<<countDigitsFactorialN(n)<<endl;
    n = 1;
    cout<<"No of digits in "<<n<<"! is "<<countDigitsFactorialNKamenetsky(n)<<endl;
    n = 120;
    cout<<"No of digits in "<<n<<"! is "<<countDigitsFactorialNKamenetsky(n)<<endl;
    n = 50000000;
    cout<<"No of digits in "<<n<<"! is "<<countDigitsFactorialNKamenetsky(n)<<endl;
    n = 1000000000;
    cout<<"No of digits in "<<n<<"! is "<<countDigitsFactorialNKamenetsky(n)<<endl;
    return 0;
}
