//to replace all 'O's with 'X''s if surrounded by 'X'
#include<iostream>
using namespace std;
#define M 6
#define N 6

void floodFillUtil(char mat[M][N], int x, int y, char prevC, char newC) {
    if (x<0 || x>=M || y<0 || y>=N) //out of bounds
        return;
    if (mat[x][y] != prevC) //not in the region or already replaced
        return;
    mat[x][y] = newC; //replace color at (x, y)
    floodFillUtil(mat, x+1, y, prevC, newC); //recur east
    floodFillUtil(mat, x-1, y, prevC, newC); //recur west
    floodFillUtil(mat, x, y+1, prevC, newC); //recur north
    floodFillUtil(mat, x, y-1, prevC, newC); //recur south
}
 
void replaceOXsurrounded(char mat[M][N]) {
    int i, j;
    for (i=0; i<M; i++)
        for (j=0; j<N; j++)
            if (mat[i][j] == 'O')
                mat[i][j] = '-'; //replace all 'O'  with '-'
    for (i=0; i<M; i++)   //Call floodFillUtil for all '-' lying on left edge
        if (mat[i][0] == '-')
            floodFillUtil(mat, i, 0, '-', 'O');
    for (i=0; i<M; i++)  //Call floodFillUtil for all '-' lying on right edge
        if (mat[i][N-1] == '-')
            floodFillUtil(mat, i, N-1, '-', 'O');
    for (i=0; i<N; i++)   //Call floodFillUtil for all '-' lying on top edge
        if (mat[0][i] == '-')
            floodFillUtil(mat, 0, i, '-', 'O');
    for (i=0; i<N; i++)  //Call floodFillUtil for all '-' lying on bottom edge
        if (mat[M-1][i] == '-')
            floodFillUtil(mat, M-1, i, '-', 'O');
    for (i=0; i<M; i++)
        for (j=0; j<N; j++)
            if (mat[i][j] == '-')
                mat[i][j] = 'X';
}

void printMatrix(char inp[M][N]) {
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            cout<<" "<<inp[i][j];
        }
        cout<<endl;
    }
}

int main() {
    char matr[M][N] =  {{'X', 'O', 'X', 'O', 'X', 'X'},
                        {'X', 'O', 'X', 'X', 'O', 'X'},
                        {'X', 'X', 'X', 'O', 'X', 'X'},
                        {'O', 'X', 'X', 'X', 'X', 'X'},
                        {'X', 'X', 'X', 'O', 'X', 'O'},
                        {'O', 'O', 'X', 'O', 'O', 'O'},
                       };
    cout<<"Input:\n";
    printMatrix(matr);
    replaceOXsurrounded(matr);
    cout<<"Output:\n";
    printMatrix(matr);
    return 0;
}
