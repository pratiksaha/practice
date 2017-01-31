//find Kth element in spiral form of matrix
#include<bits/stdc++.h>
#define MAX 100
using namespace std;
 
int kElementSpiralMatrix(int A[MAX][MAX], int n, int m, int k) {
    if (n < 1 || m < 1)
        return -1;
    if (k <= m)
        return A[0][k-1];
    if (k <= (m+n-1))
        return A[(k-m)][m-1];
    if (k <= (m+n-1+m-1))
        return A[n-1][m-1-(k-(m+n-1))];
    if (k <= (m+n-1+m-1+n-2))
        return A[n-1-(k-(m+n-1+m-1))][0];
    return kElementSpiralMatrix((int (*)[MAX])(&(A[1][1])), n-2, m-2, k-(2*n+2*m-4));
}
 
int main() {
    int a[MAX][MAX] = {
        {1, 2, 3, 4, 5, 6},
        {7, 8, 9, 10, 11, 12},
        {13, 14, 15, 16, 17, 18}
    };
    int k = 17;
    cout<<k<<"th element in Spiral Matrix is "<<kElementSpiralMatrix(a, 3, 6,k)<<endl;
    return 0;
}
