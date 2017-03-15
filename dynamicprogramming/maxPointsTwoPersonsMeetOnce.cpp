//to find max points that can be collected by two persons and allowed to meet once
#include<bits/stdc++.h>
#define M 3
#define N 3
using namespace std;

int maxPointsTwoPersonsMeetOnce(int A[M][N]) {
    int P1S[M+1][N+1], P1E[M+1][N+1];
    memset(P1S, 0, sizeof(P1S));
    memset(P1E, 0, sizeof(P1E));
    int P2S[M+1][N+1], P2E[M+1][N+1];
    memset(P2S, 0, sizeof(P2S));
    memset(P2E, 0, sizeof(P2E));
    for (int i=1; i<=M; i++)
        for (int j=1; j<=N; j++)
            P1S[i][j] = max(P1S[i-1][j],
                  P1S[i][j-1]) + A[i-1][j-1];
    for (int i=M; i>=1; i--)
        for (int j=N; j>=1; j--)
            P1E[i][j] = max(P1E[i+1][j],
                  P1E[i][j+1]) + A[i-1][j-1];
    for (int i=M; i>=1; i--)
        for(int j=1; j<=N; j++)
            P2S[i][j] = max(P2S[i+1][j],
                  P2S[i][j-1]) + A[i-1][j-1];
    for (int i=1; i<=M; i++)
        for (int j=N; j>=1; j--)
            P2E[i][j] = max(P2E[i-1][j],
                  P2E[i][j+1]) + A[i-1][j-1];
    int ans = 0;
    for (int i=2; i<M; i++) {
        for (int j=2; j<M; j++) {
            int op1 = P1S[i][j-1] + P1E[i][j+1] + P2S[i+1][j] + P2E[i-1][j];
            int op2 = P1S[i-1][j] + P1E[i+1][j] + P2S[i][j-1] + P2E[i][j+1];
            ans = max(ans, max(op1, op2));
        }
    }
    return ans;
}

int main() {
    int A[M][N] = {{100, 100, 100},
                  {100, 1, 100},
                  {100, 100, 100}};
    cout<<maxPointsTwoPersonsMeetOnce(A)<<endl;
    return 0;
}
