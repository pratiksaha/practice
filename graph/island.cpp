//count islands
#include<iostream>
#include<cstring>
using namespace std;
#define M 5
#define N 5

bool isSafe(int mat[M][N], int row, int col, bool visited[M][N]) {
    return ((row>=0)&&(row<M))&&((col>=0)&&(col<N))&&((mat[row][col])&&(!visited[row][col]));
}

void DFS(int mat[M][N], int row, int col, bool visited[M][N]) {
    static int rowNbr[] = {-1, -1, -1,  0, 0,  1, 1, 1};
    static int colNbr[] = {-1,  0,  1, -1, 1, -1, 0, 1};
    visited[row][col] = true;
    for (int k=0; k<8; k++)
        if (isSafe(mat, row+rowNbr[k], col+colNbr[k], visited))
            DFS(mat, row+rowNbr[k], col+colNbr[k], visited);
}

int countIslands(int mat[M][N]) {
    bool visited[M][N];
    memset(visited, 0, sizeof(visited));
    int count = 0;
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            if (mat[i][j] && !visited[i][j]) { //If a cell with value 1 is not visited yet then new island found 
                DFS(mat, i, j, visited); //Visit all cells in this island and increment island count
                count++;                   
            }
        }
    }
    return count;
}

int countRectangularIslands(int mat[M][N]) {
    int count = 0;
    for (int i=0; i<M; i++)
        for (int j=0; j<N; j++)
            if (mat[i][j])
                if ((i==0 || !mat[i-1][j]) && (j==0 || !mat[i][j-1]))
                    count++; //increment island count if current cell is 1 and this is the top-leftmost of a rectangle
    return count;
}

int main() {
    int mat1[M][N]={{1, 1, 0, 0, 0},
                    {0, 1, 0, 0, 1},
                    {1, 0, 0, 1, 1},
                    {0, 0, 0, 0, 0},
                    {1, 0, 1, 0, 1}};
    int mat2[M][N]={{1, 1, 0, 0, 0},
                    {1, 1, 0, 1, 1},
                    {0, 0, 0, 1, 1},
                    {0, 0, 0, 0, 0},
                    {1, 0, 1, 0, 1}};
    cout<<"No of Islands = "<<countIslands(mat1)<<endl;
    cout<<"No of Rectangular Islands = "<<countRectangularIslands(mat2)<<endl;
    return 0;
}
