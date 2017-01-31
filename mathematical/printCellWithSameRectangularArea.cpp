//to print cells with same rectangular sum diagonally
#include<bits/stdc++.h>
using namespace std;
#define R 4
#define C 4
 
void printCellWithSameRectangularArea(int mat[R][C], int m, int n) {
    int sum[m][n], sumr[m][n];
    cout<<"cells with same rectangular sums in the matrix :";
    int totalSum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sumr[i][j] = sum[i][j] = mat[i][j];
            totalSum += mat[i][j];
        }
    }
    for (int i = 1; i < m; i++) {
        sum[i][0] += sum[i-1][0];
        sumr[m-i-1][n-1] += sumr[m-i][n-1];
    }
    for (int j = 1; j < n; j++) {
        sum[0][j] += sum[0][j-1];
        sumr[m-1][n-j-1] += sumr[m-1][n-j];
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
            sumr[m-i-1][n-j-1] += sumr[m-i][n-j-1] + sumr[m-i-1][n-j] - sumr[m-i][n-j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int mainDiagRectangleSum = sum[i][j] + sumr[i][j] - mat[i][j];
            if (totalSum == 2 * mainDiagRectangleSum)
                cout<<" ("<<i<<","<<j<<")";
        }
    }
    cout<<endl;
}

int main() {
    int mat[R][C] = {
        1, 2, 3, 5,
        4, 1, 0, 2,
        0, 1, 2, 0,
        7, 1, 1, 0
    };
    printCellWithSameRectangularArea(mat, R, C);
    return 0;
}
