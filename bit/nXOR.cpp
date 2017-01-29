//to find XOR from 1 to n
#include<bits/stdc++.h>
using namespace std;

int nXOR(int n) {
    if (n % 4 == 0)
        return n;
    if (n % 4 == 1)
        return 1;
    if (n % 4 == 2)
        return n + 1;
    return 0;
}

int main() {
    int n = 5;
    cout<<"XOR from 1 to "<<n<<" is "<<nXOR(n)<<endl;
    return 0;
}
