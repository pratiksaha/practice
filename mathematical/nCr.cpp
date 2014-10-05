// Program to calculate C(n,r)
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

int main()
{
    int n = 8, r = 2;
    cout<<"Value of C("<<n<<","<<r<<") is "<<binomialCoeff(n,r)<<endl;
    return 0;
}
