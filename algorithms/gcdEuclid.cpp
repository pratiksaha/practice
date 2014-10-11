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
    return 0;
}
