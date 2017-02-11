//to calculate (a*b)%c
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
long long int calcAmulBmodC(long long int a, long long int  b, long long int  c) {
    if (b==0)
        return 0;
    long long int s = calcAmulBmodC(a, b/2, c);
    if (b%2==1)
        return (a%c+2*(s%c)) % c;
    else
        return (2*(s%c)) % c;
}
 
int main() {
    long long int  a = 1000000000007;
    long long int  b = 10000000000005;
    long long int  c = 1000000000000003;
    cout<<"("<<a<<"*"<<b<<")%"<<c<<" = "<<calcAmulBmodC(a, b, c)<<endl;
    return 0;
}
