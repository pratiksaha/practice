//sum of diagonals of spiral matrix
#include<bits/stdc++.h>
using namespace std;

int sumDiagonalSpiralMatrix(int n) {
    if (n == 1)
        return 1;
    return (4*n*n - 6*n + 6 + sumDiagonalSpiralMatrix(n-2));
}
 
int main() {
    int n = 7;
    cout<<sumDiagonalSpiralMatrix(n)<<endl;
    return 0;
}
