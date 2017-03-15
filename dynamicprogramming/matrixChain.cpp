//Matrix Chain Multiplication problem
#include<bits/stdc++.h>
using namespace std;

void printParenthesis(int i, int j, int n, int *bracket, char &name) {
    if (i == j) {
        cout<<name++;
    } else {
        cout << "(";
        printParenthesis(i, *((bracket+i*n)+j), n, bracket, name);
        printParenthesis(*((bracket+i*n)+j) + 1, j, n, bracket, name);
        cout << ")";
    }
}

int MatrixChainOrder(int p[], int n) {
    int m[n][n];// m[i,j] = Minimum number of scalar multiplications needed to compute the matrix A[i]A[i+1]...A[j] = A[i..j] where dimension of A[i] is p[i-1] x p[i]
    int bracket[n][n];
    for (int i = 1; i < n; i++)
        m[i][i] = 0;//cost is zero when multiplying one matrix 
    for (int l=2; l<n; l++) {// l is chain length
        for (int i=1; i<=n-l+1; i++) {
            int j = i+l-1;
            m[i][j] = INT_MAX;
            for (int k=i; k<=j-1; k++) {
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    bracket[i][j] = k;
                }
            }
        }
    }
    char tmp = 'A';
    cout<<"Optimal Cost is "<<m[1][n-1]<<endl;
    cout<<"Optimal Parenthesization is ";
    printParenthesis(1, n-1, n, (int *)bracket, tmp);
    cout<<endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 3};
    MatrixChainOrder(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}
