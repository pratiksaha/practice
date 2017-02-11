//to find number of permutation with K inversions
#include<bits/stdc++.h>
using namespace std;
#define M 100

int memo[M][M];
 
int countPermutationWithKInversion(int N, int K) {
    if (N == 0)
        return 0;
    if (K == 0)
        return 1;
    if (memo[N][K] != 0)
        return memo[N][K];
    int sum = 0;
    for (int i = 0; i <= K; i++)
        if (i <= N - 1)
            sum += countPermutationWithKInversion(N-1, K-i);
    memo[N][K] = sum;
    return sum;
}

int main() {
    int N = 4;
    int K = 2;
    cout<<countPermutationWithKInversion(N, K)<<endl;
    return 0;
}
