//perrin nos
//TODO add matrix exp method
#include<bits/stdc++.h>
using namespace std;

int perrinNumber(int n) {
    int a=3, b=0, c=2, i;
    int m;
    if (n==0)
        return a;
    if (n==1)
        return b;
    if (n==2)
        return c;
    while (n > 2) {
        m = a + b;
        a = b;
        b = c;
        c = m;
        n--;
    }
    return m;
}

int perrinNumberSum(int n) {
    return perrinNumber(n+3) + perrinNumber(n+2) - 2;
}

int main(){
    int n = 9;
    cout<<n<<"th Perrin No is "<<perrinNumber(n)<<endl;
    cout<<"Sum of first "<<n<<" Perrin Nos is "<<perrinNumberSum(n)<<endl;
    return 0;
}
