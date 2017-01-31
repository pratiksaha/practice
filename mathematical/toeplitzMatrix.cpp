//to check whether given matrix is a Toeplitz matrix
#include<bits/stdc++.h>
using namespace std;
#define N 5
#define M 4

bool checkDiagonal(int mat[N][M], int i, int j) {
    int res = mat[i][j];
    while (++i < N && ++j < M)
        if (mat[i][j] != res)
            return false;
    return true;
}

bool toeplitzMatrix(int mat[N][M]) {
    for (int i = 0; i < M; i++)
        if (!checkDiagonal(mat, 0, i))
            return false;
    for (int i = 1; i < N; i++)
        if (!checkDiagonal(mat, i, 0))
            return false;
    return true;
}

int main() {
    int mat[N][M] = {
        { 6, 7, 8, 9 },
        { 4, 6, 7, 8 },
        { 1, 4, 6, 7 },
        { 0, 1, 4, 6 },
        { 2, 0, 1, 4 }
    };
    cout<<"Given Matrix is"<<(toeplitzMatrix(mat)? " " : " not ")<<"a Toeplitz Matrix\n";
    return 0;
}
