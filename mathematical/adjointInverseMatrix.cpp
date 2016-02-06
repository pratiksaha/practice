//to find adjoint and inverse of a matrix
#include<bits/stdc++.h>
using namespace std;
#define N 4

template<class T>
void printMatrix(T mat[N][N]) {
    for (int i=0; i<N; i++)
       for (int j=0; j<N; j++)         
          cout<<mat[i][j]<<" \n"[j == N-1];
}

void getCofactor(int mat[N][N], int temp[N][N], int p, int q, int n) {
    int i = 0, j = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row != p && col != q) {
                temp[i][j++] = mat[row][col];
                if (j == n-1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

int determinantOfMatrix(int mat[N][N], int n) {
    int D = 0;
    if (n == 1)
        return mat[0][0];
 
    int temp[N][N];
    int sign = 1;
    for (int f=0; f<n; f++) {
        getCofactor(mat, temp, 0, f, n);
        D += sign * mat[0][f] * determinantOfMatrix(temp, n - 1);
        sign = -sign;
    }
    return D;
}

void adjoint(int A[N][N],int adj[N][N]) {
    if (N == 1) {
        adj[0][0] = 1;
    } else {
        int sign = 1, temp[N][N];
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                getCofactor(A, temp, i, j, N);
                sign = ((i+j)%2==0)? 1: -1;
                adj[j][i] = (sign)*(determinantOfMatrix(temp, N-1));
            }
        }
    }
}

bool inverse(int A[N][N], float inverse[N][N]) {
    int det = determinantOfMatrix(A, N);
    if (det == 0) {
        cout<<"Singular matrix, can't find its inverse";
        return false;
    } else {
        int adj[N][N];
        adjoint(A, adj);
        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++)
                inverse[i][j] = adj[i][j]/float(det);
        return true;
    }
}

int main() {
    int A[N][N] = { {5, -2, 2, 7},
                    {1, 0, 0, 3},
                    {-3, 1, 5, 0},
                    {3, -1, -9, 4}};
    int adj[N][N];
    float inv[N][N];
    cout<<"Input matrix is :\n";
    printMatrix(A);
    cout<<"The Adjoint is :\n";
    adjoint(A, adj);
    printMatrix(adj);
    cout<<"The Inverse is :\n";
    if (inverse(A, inv))
        printMatrix(inv); 
    return 0;
}
