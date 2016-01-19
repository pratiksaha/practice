//to compute nCr % p
#include<bits/stdc++.h>
using namespace std;

int nCrModpDP(int n, int r, int p) {
    int C[r+1];
    memset(C, 0, sizeof(C));
    C[0] = 1;
    for (int i=1; i<=n; i++)
        for (int j=min(i, r); j>0; j--)
            C[j] = (C[j] + C[j-1])%p;
    return C[r];
}

int nCrModpLucas(int n, int r, int p) {
    if (r==0)
        return 1;
    int ni = n%p, ri = r%p;
    return (nCrModpLucas(n/p, r/p, p) * nCrModpDP(ni, ri, p)) % p;
}

int main() {
    int n, r, p;
    n = 10, r = 2, p = 13;
    cout<<n<<" C "<<r<<" % "<<p<<"  --->  "<<nCrModpDP(n, r, p)<<endl;
    n = 1000, r = 900, p = 13;
    cout<<n<<" C "<<r<<" % "<<p<<"  --->  "<<nCrModpDP(n, r, p)<<endl;
    return 0;
}
