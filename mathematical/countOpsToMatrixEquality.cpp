// to find no of ops to make two matrix equals
#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000;
 
int countOpsToMatrixEquality(int A[][MAX], int B[][MAX], int m, int n) {
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            A[i][j] -= B[i][j];
    for (int i=1; i<n; i++)
        for (int j=1; j<m; j++)
            if (A[i][j]-A[i][0]-A[0][j]+A[0][0] != 0)
                return -1;
    int result = 0;
    for (int i=0; i<n; i++)
        result += abs(A[i][0]);
    for (int j=0; j<m; j++)
        result += abs(A[0][j] - A[0][0]);
    return result;
}

int main() {
    int A[MAX][MAX] = { {1, 1, 1},
                        {1, 1, 1},
                        {1, 1, 1}};
    int B[MAX][MAX] = { {1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}};
    cout<<"No of ops to make the matrices equal is "<<countOpsToMatrixEquality(A,B,3,3)<<endl;
    return 0;
}
