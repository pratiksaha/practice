//Matrix Chain Multiplication problem
#include<iostream>
#include<climits>
using namespace std;

int MatrixChainOrder(int p[], int n) {
    int m[n][n];// m[i,j] = Minimum number of scalar multiplications needed to compute the matrix A[i]A[i+1]...A[j] = A[i..j] where dimension of A[i] is p[i-1] x p[i]
    int i, j, k, l, q;
    
    for (i = 1; i < n; i++)
        m[i][i] = 0;//cost is zero when multiplying one matrix 
    
    for (l=2; l<n; l++) {// l is chain length 
        for (i=1; i<=n-l+1; i++) {
            j = i+l-1;
            m[i][j] = INT_MAX;
            for (k=i; k<=j-1; k++) {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
    return m[1][n-1];
    
}

int main() {
    int arr[] = {1, 2, 3, 4, 3};
    cout<<"Minimum number of multiplications is "<<MatrixChainOrder(arr, sizeof(arr)/sizeof(arr[0]))<<endl;
    return 0;
}
