//find nth lucas
#include<bits/stdc++.h>
using namespace std;

int lucasNumber(int n) {
    int a = 2, b = 1, c, i;
    if (n == 0)
        return a;
    for (i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main(){
    int n;
    n = 9;
    cout<<n<<"th Lucas no is "<<lucasNumber(n)<<endl;
    return 0;
}
