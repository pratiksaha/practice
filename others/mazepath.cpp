//Find a path in a maze moving only downwards or to the right
#include<iostream>
using namespace std;
#define N 4

bool isSafe(int maze[N][N], int x, int y){
    if(x>=0 && x<N && y>=0 && y<N && maze[x][y]==1)
        return true;
    return false;    
}

//return true if path exists, false otherwise
bool solveMaze(int maze[N][N], int sol[N][N], int x, int y){ 
    if (x == N-1 && y == N-1){
        sol[x][y] = 1;
        return true;
    }
    if( isSafe(maze, x, y) ){
        sol[x][y] = 1;
        if(solveMaze(maze, sol, x+1, y))
            return true;
        if(solveMaze(maze, sol, x, y+1))
            return true;
        sol[x][y] = 0;
        return false;
    }
    return false;
}

int main(){
    int maze[N][N]  =  {{1, 0, 0, 0},
                        {1, 1, 0, 1},
                        {0, 1, 0, 0},
                        {1, 1, 1, 1}}; //input maze 1 indicates a valid cell, 0 means dead end
    int sol[N][N] = {   {0,0,0,0},
                        {0,0,0,0},
                        {0,0,0,0},
                        {0,0,0,0}}; //Solution matrix Cell with 1 will indicate a path in the maze
    if(solveMaze(maze, sol, 0, 0)) { //start from cell (0,0)
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout<<" "<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
    } else { 
        cout<<"Solution path doesnot exist"<<endl;
    }
    return 0;
}
