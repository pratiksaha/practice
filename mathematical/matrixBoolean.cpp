//Given mat[M][N] modify it such that if mat[i][j] == true then make all the cells of ith row and jth column as true 
#include<iostream>
#include<iomanip>
using namespace std;
#define R 3
#define C 4
#define W 2

void printMatrix(bool mat[R][C]) {
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cout<<setw(W)<<mat[i][j];
        }
        cout<<endl;
    }
}

void modifyMatrix(bool mat[R][C]) { //Time Complexity: O(n^2), Auxillary Space: O(1)
    bool row = false;
    bool col = false;
    int i, j;
    
    for (i=0; i<R; i++)
        if (mat[i][0])
            row = true;
    for (j=0; j<C; j++)
        if (mat[0][j])
            col = true;
    
    for (i=1; i<R; i++) {
        for (j=1; j<C; j++) {
            if (mat[i][j]) {
                mat[i][0] = true;
                mat[0][j] = true;
            }
        }
    }
    
    for (i=1; i<R; i++) {
        for (j=1; j<C; j++) {
            if (mat[i][0] || mat[0][j])
                mat[i][j] = true;
        }
    }
    
    for(i=0; i<R; i++)
        if (row)
            mat[i][0] = true;
        else
            mat[i][0] = false;
    for(j=0; j<C; j++)
        if (col)
            mat[0][j] = true;
        else
            mat[0][j] = false;
}

int main() {
    bool mat[R][C] = {  {1,0,0,1},
                        {0,0,1,0},
                        {0,0,0,0},
    };
    cout<<"Input Matrix :\n";
    printMatrix(mat);
    modifyMatrix(mat);
    cout<<"Matrix after modification :\n";
    printMatrix(mat);
    return 0;
}
