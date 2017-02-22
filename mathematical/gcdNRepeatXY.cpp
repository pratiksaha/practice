//to print GCD of number formed by N repeating x times and y times
#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

void gcdNRepeatXY(int n, int x, int y) {
    cout<<"GCD of 2 nos formed by repeating "<<n<<" "<<x<<" & "<<y<<" times is ";
    int g = gcd(x,y);
    for (int i = 0; i < g; i++)
        cout<<n;
    cout<<endl;
}
 
int main() {
    int n = 123, x = 5, y = 2;
    gcdNRepeatXY(n, x, y);
    return 0;
}
