//to calculate Nth root of a number
#include<bits/stdc++.h>
using namespace std;

double nthRoot(int A, int N) {
    double xPre = rand() % 10;
    double eps = 1e-3;
    double delX = INT_MAX;
    double xK;
    while (delX > eps) {
        xK = ((N - 1.0) * xPre + (double)A/pow(xPre, N-1)) / (double)N;
        delX = abs(xK - xPre);
        xPre = xK;
    }
    return xK;
}

int main() {
    int N = 4;
    int A = 81;
    cout<<N<<"th root of "<<A<<" is "<<nthRoot(A, N)<<endl;
    return 0;
}
