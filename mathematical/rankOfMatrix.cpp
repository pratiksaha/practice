//to find rank of a matrix
#include<bits/stdc++.h>
using namespace std;
#define R 3
#define C 3
 
void printMatrix(int mat[R][C], int row, int col) {
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++)
            cout<<setw(4)<<mat[i][j];
        cout<<endl;
    }
}
void swapRow(int mat[R][C], int row1, int row2, int col) {
    for (int i=0; i<col; i++) {
        int temp = mat[row1][i];
        mat[row1][i] = mat[row2][i];
        mat[row2][i] = temp;
    }
}

int rankOfMatrix(int mat[R][C]) {
    int rank = C;
    for (int row=0; row<rank; row++) {
        if (mat[row][row]) { //diagonal element is not zero
            for (int col=0; col<R; col++) {
                if (col != row) { 
                    double mult = (double)mat[col][row] /mat[row][row]; //make all entries of curr col as 0 except entry mat[row][row]
                    for (int i = 0; i < rank; i++)
                        mat[col][i] -= mult * mat[row][i];
                }
            }
        } else {
            bool reduce = true;
            for (int i = row + 1; i < R;  i++) {
                if (mat[i][row]) { //find the non-zero element in curr col
                    swapRow(mat, row, i, rank); //swap the row with non-zero element with this row
                    reduce = false;
                    break ;
                }
            }
            if (reduce) { //all values in this column are 0 if we did not find any row with non-zero element in curr col
                rank--; //reduce number of columns
                for (int i = 0; i < R; i ++) //copy the last column here
                    mat[i][row] = mat[i][rank];
            }
            row--; //process this row again
        }
    }
    return rank;
}

int main() {
    int mat[R][C] = {{10,20,10},
                    {-20,-30,10},
                    {30,50,0}};
    cout<<"For matrix :\n";
    printMatrix(mat, R, C);
    cout<<"Rank = "<<rankOfMatrix(mat)<<endl;   
    return 0;
}
