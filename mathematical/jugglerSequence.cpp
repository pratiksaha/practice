//to implemet juggler sequence
#include<bits/stdc++.h>
using namespace std;

void jugglerSequence(int n) {
    int a = n;
    cout<<"Juggler sequence starting with "<<a<<" is : "<<a;
    while (a != 1) {
        int b = 0;
        if (a%2 == 0)
            b  = floor(sqrt(a));
        else
            b = floor(sqrt(a)*sqrt(a)*sqrt(a));
        cout<<" "<<b;
        a = b;
    }
    cout<<endl;
}

int main() {
    jugglerSequence(3);
    jugglerSequence(9);
    return 0;
}
