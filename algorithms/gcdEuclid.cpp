//Euclids algorithm for gcd
#include<iostream>
#include<cmath>
using namespace std;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int Euclid(int m, int n) {//gcd of -ve nos is same as that of +ve nos
    if (m<0)
        m = -m;
    if (n<0)
        n = -n;
    if( m == n)
        return m;
    if (m == 0) 
        return n;
    if (n == 0)
        return m;   
    if ( m < n)
        swap(&m, &n);
    int t;
    while (n > 0) {
        t = n;
        n = m%t;
        m = t;
    }
    return m;
}

int gcdOpt(int a, int b) {
    if (b == 0 || a == b)
        return a;
    if (a == 0)
        return b;
    if ( (a & 1) == 0 && (b & 1) == 0 )
        return gcdOpt(a>>1, b>>1) << 1;
    if ( (a & 1) == 0 && (b & 1) != 0 )
        return gcdOpt(a>>1, b);
    if ( (a & 1) != 0 && (b & 1) == 0 )
        return gcdOpt(a, b>>1);
    return (a > b)? gcdOpt(a-b, b): gcdOpt(a, b-a);
}

int gcdExtended(int a, int b, int *x, int *y) { //ax + by = gcd(a, b)
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    } else {
        int x1, y1;
        int gcd = gcdExtended(b%a, a, &x1, &y1);
        *x = y1-(b/a)*x1;
        *y = x1;
        return gcd;
    }
}

int main() {
    int a=54, b=24;
    int gcd = Euclid(a, b);
    cout<<"For "<<a<<" & "<<b;
    cout<<" gcd = "<<gcd;
    cout<<" lcm = ";
    if ( (a<0&&b<0)||(a==0&&b==0) ) {//invalid when both nos are -ve or gcd is 0(both nos 0) 
        cout<<"Invalid";
    } else {
        cout<<abs(a*b)/gcd;
    }
    cout<<endl;
    cout<<"For "<<a<<" & "<<b<<" gcd by optimzation is "<<gcdOpt(a,b)<<endl;
    int x, y;
    int m = 35, n = 15;
    int g = gcdExtended(m, n, &x, &y);
    cout<<"gcd("<<m<<","<<n<<") = "<<g<<" = "<<x<<"*"<<m<<" + "<<y<<"*"<<n<<endl;
    return 0;
}
