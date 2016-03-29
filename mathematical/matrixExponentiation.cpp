//matix exponentiation
#include<bits/stdc++.h>
using namespace std;

void multiply(int a[3][3], int b[3][3]) {
    int mul[3][3];
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            mul[i][j] = 0;
            for (int k=0; k<3; k++)
                mul[i][j] += a[i][k]*b[k][j];
        }
    }
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            a[i][j] = mul[i][j];
}

int power(int F[3][3], int n) {
    int M[3][3] = {{1,1,1}, {1,0,0}, {0,1,0}};
    if (n==1) {
        return F[0][0] + F[0][1];
    } else {
        power(F, n/2);
        multiply(F, F);
        if (n%2 != 0)
            multiply(F, M);
        return F[0][0] + F[0][1];
    }
}

int matrixExponentiation(int n) {
    int F[3][3] = {{1,1,1}, {1,0,0}, {0,1,0}};
    return power(F, n-2);
}

int main() {
   int n = 5;
   cout<<"F("<<n<<") is "<<matrixExponentiation(n)<<endl;
   return 0;
}
