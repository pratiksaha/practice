//josephus problem
#include<bits/stdc++.h>
using namespace std;

int josephus(int n, int k) {
    if (n == 1)
        return 1;
    else
        return (josephus(n - 1, k) + k-1) % n + 1;
}

int main() {
    int n=14, k=2;
    cout<<"Solution to Josephus Problem for n="<<n<<" & k="<<k<<" is "<<josephus(n, k)<<endl;
    return 0;
}
