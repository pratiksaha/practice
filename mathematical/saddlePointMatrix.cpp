//saddle point
#include<bits/stdc++.h>
using namespace std;
#define MAX 100

void saddlePointMatrix(int mat[MAX][MAX], int n) {
    cout<<"Value of Saddle Point :";
    for (int i = 0; i < n; i++) {
        int min_row = mat[i][0], col_ind = 0;
        for (int j = 1; j < n; j++) {
            if (min_row > mat[i][j]) {
                min_row = mat[i][j];
                col_ind = j;
            }
        }
        int k;
        for (k = 0; k < n; k++)
            if (min_row < mat[k][col_ind])
                break;
        if (k == n)
           cout<<" "<<min_row;
    }
    cout<<endl;
}

int main() {
    int mat[MAX][MAX] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}};
    int n = 3;
    saddlePointMatrix(mat, n);
    return 0;
}
