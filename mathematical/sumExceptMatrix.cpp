//to compute sum for given array of cell indexes
#include<iostream>
using namespace std;
#define R 3
#define C 3

struct cell {
    int r, c;
};
 
void sumExceptMatrix(int mat[R][C], struct cell arr[], int n) {
    int sum = 0;
    int row[R] = {};
    int col[C] = {};
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            sum += mat[i][j];
            col[j] += mat[i][j];
            row[i] += mat[i][j];
        }
    }
    for (int k=0; k<n; k++) {
        int ro = arr[k].r;
        int co = arr[k].c;
        cout << sum - row[ro] - col[co] + mat[ro][co] << endl;
    }
}

int main() {
    int mat[R][C]= {{1, 1, 2},
                    {3, 4, 6},
                    {5, 3, 2}};
    struct cell arr[] = {{0, 0}, {1, 1}, {0, 1}};
    sumExceptMatrix(mat, arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}
