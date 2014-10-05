//Soduko solver
#include<iostream>
using namespace std;
#define N 9

//Check if a number is used in a given row
bool usedInRow(int grid[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}

//Check if a number is used in a given column
bool usedInCol(int grid[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}

//Check if a number is used in a given box 
bool usedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num)
{
    for (int row = boxStartRow; row < boxStartRow+3; row++)
        for (int col = boxStartCol; col < boxStartCol+3; col++)
            if (grid[row][col] == num)
                return true;
    return false;
}

//Check if a number is safe to be inserted at the given position
bool isSafe(int grid[N][N], int row, int col, int num)
{
    return !usedInRow(grid, row, num) && !usedInCol(grid, col, num) && !usedInBox(grid, row-(row%3) , col-(col%3), num);
}

//Find next unassigned location if it exists, else return false
bool findUnassignedLocation(int grid[N][N], int *row, int *col)
{
    for (*row = 0; *row<N; (*row)++){
        for (*col = 0; *col<N; (*col)++){
            if (grid[*row][*col] == 0){
                //cout<<*row<<" "<<*col<<endl;
                return true;
            }
        }
    }        
    return false;
}

bool solveSudoku(int grid[N][N]){
    int row, col;
    if(findUnassignedLocation(grid, &row, &col)){
        for(int num=1; num<=9; num++){
            if(isSafe(grid, row, col, num)){
                grid[row][col] = num;
                if(solveSudoku(grid))
                    return true;
                grid[row][col] = 0;
            }
        }
        return false;
    } else {
        return true;
    }
}

int main(){
    int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}}; //0 means unassigned
    if(solveSudoku(grid)){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout<<" "<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
    } else {
        cout<<"No Solution exist"<<endl;
    }
    return 0;
}
