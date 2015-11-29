//to count derangements
#include<iostream>
using namespace std;
 
int countDerangements(int n) {
    int der[n + 1];
    der[0] = 1, der[1] = 0, der[2] = 1;
    for (int i=3; i<=n; ++i)
        der[i] = (i-1)*(der[i-1] + der[i-2]);
    return der[n];
}

int main() {
    int n = 4;
    cout<<"Count of Derangements for n="<<n<<" is "<<countDerangements(n)<<endl;
    return 0;
}
