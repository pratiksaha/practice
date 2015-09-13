//to rotate a matrix
#include<iostream>
#include<iomanip>
using namespace std;
#define N 4

void rotateMatrix(int mat[N][N]) {
    int row = 0, col = 0, m = N, n = N;
    int prev, curr;
    while (row<m && col<n) {
        if (row+1 == m || col+1 == n)
            break;
        prev = mat[row+1][col]; //first element of next row will replace first element of current row
        for (int i=col; i<n; i++) { //move elements of first row from the remaining rows
            curr = mat[row][i];
            mat[row][i] = prev;
            prev = curr;
        }
        row++;
        for (int i=row; i<m; i++) { //move elements of last column from the remaining columns
            curr = mat[i][n-1];
            mat[i][n-1] = prev;
            prev = curr;
        }
        n--;
        if (row<m) { //move elements of last row from the remaining rows
            for (int i=n-1; i>=col; i--) {
                curr = mat[m-1][i];
                mat[m-1][i] = prev;
                prev = curr;
            }
        }
        m--;
        if (col<n) { //move elements of first column from the remaining rows
            for (int i=m-1; i>=row; i--) {
                curr = mat[i][col];
                mat[i][col] = prev;
                prev = curr;
            }
        }
        col++;
    }
}

void printMatrix(int mat[N][N]) {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++)
            cout<<setw(3)<<mat[i][j];
        cout<<endl;
    }
    cout<<endl;
}

int main() {
    int a[N][N] = { {1,  2,  3,  4},
                    {5,  6,  7,  8},
                    {9,  10, 11, 12},
                    {13, 14, 15, 16}};
    printMatrix(a);
    rotateMatrix(a);
    printMatrix(a);
    return 0;
}
