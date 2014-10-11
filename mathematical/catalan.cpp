// Program to calculate the nth catalan no
#include<iostream>
using namespace std;
 
long long int binomialCoeff(int n, int r)
{
    long long int res = 1;    
    if( r>n-r )
        r = n-r;// Since C(n, r) = C(n, n-r)
    for (int i = 0; i<r; i++) {// Calculate value of [n * (n-1) *---* (n-r+1)] / [r * (r-1) *----* 1]
        res *= (n-i);
        res /= (i+1);
    } 
    return res;
}

long long int catalan(unsigned int n)
{
    return binomialCoeff(2*n, n)/(n+1);  //Catalan(n) = C(2n, n)/(n+1);
}

int main()
{
    int n = 8;
    cout<<n<<"th Catalan Number is "<<catalan(n)<<endl;
    return 0;
}
