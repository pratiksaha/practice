//to find number of non-negative solutions for a given linear equation
#include<iostream>
#include<cstring>
using namespace std;

int solLinearEquations(int coeff[], int n, int rhs) {
    int dp[rhs+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i=0; i<n; i++)
        for (int j=coeff[i]; j<=rhs; j++)
            dp[j] += dp[j-coeff[i]];
    return dp[rhs];
}

int main() {
    int coeff[]  = {2, 2, 5};
    int rhs = 4;
    cout<<solLinearEquations(coeff, sizeof(coeff)/sizeof(coeff[0]), rhs)<<endl;
    return 0;
}
