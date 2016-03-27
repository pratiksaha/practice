//to calculate the Permutation Coefficient
#include<bits/stdc++.h>
using namespace std;
 
int permutationCoeff(int n, int k) {
    int Fn = 1, Fk;
    for (int i=1; i<=n; i++) {
        Fn *= i;
        if (i == n-k)
           Fk = Fn;
    }
    int coeff = Fn/Fk;
    return coeff;
}

int main() {
    int n=10, k=2;
    cout<<"Value of P("<<n<<","<<k<< ") is "<<permutationCoeff(n, k)<<endl;
    return 0;
}
