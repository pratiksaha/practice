//swap three variables
#include<bits/stdc++.h>
using namespace std;

void swapThreeMath(int &a, int &b, int &c) {
    a = a + b + c;
    b = a - (b+c);
    c = a - (b+c);
    a = a - (b+c);
}

void swapThreeXOR(int &a, int &b, int &c) {
    a = a ^ b ^ c;
    b = a ^ b ^ c;
    c = a ^ b ^ c;
    a = a ^ b ^ c;
}

int main() {
    int a = 10, b = 20, c = 30;
    cout<<"Before swapping a = "<<a<<", b = "<<b<<", c = "<<c<<endl;
    swapThreeMath(a, b, c);
    cout<<"After swapping a = "<<a<<", b = "<<b<<", c = "<<c<<endl;
    swapThreeXOR(a, b, c);
    cout<<"After swapping again a = "<<a<<", b = "<<b<<", c = "<<c<<endl;
    return 0;
}
