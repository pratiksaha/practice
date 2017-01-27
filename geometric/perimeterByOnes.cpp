//to find perimeter of area covered by 1s in a binary matrix
#include<bits/stdc++.h>
using namespace std;
#define R 3
#define C 5

int countNeighbours(int mat[R][C], int i, int j) {
    int count = 0;
    if (i>0 && mat[i-1][j])
        count++;
    if (j>0 && mat[i][j-1])
        count++;
    if (i<R-1 && mat[i+1][j])
        count++;
    if (j<C-1 && mat[i][j+1])
        count++;
    return count;
}

int perimeterByOnes(int mat[R][C]) {
    int perimeter = 0;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (mat[i][j])
                perimeter += (4 - countNeighbours(mat, i ,j));
    return perimeter;
}

int main() {
    int mat[R][C] = {
        0, 1, 0, 0, 0,
        1, 1, 1, 0, 0,
        1, 0, 0, 0, 0,
    };
    cout<<perimeterByOnes(mat)<<endl;
    return 0;
}
