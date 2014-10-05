//knights tour problem
#include<iostream>
#include<iomanip>
using namespace std;
#define N 8
#define width 3

bool isSafe(int x, int y, int sol[N][N]){
    if(x>=0 && x<N && y>=0 && y<N && sol[x][y] == -1)
        return true;
    return false;
}

bool solveKT(int sol[N][N], int xMove[], int yMove[], int x, int y, int move){
    int k, next_x, next_y;
    if(move == N*N)
        return true;
    for(k=0; k<8; k++){
        next_x = x + xMove[k];
        next_y = y + yMove[k];
        if(isSafe(next_x, next_y, sol)){
            sol[next_x][next_y] = move;
            if(solveKT(sol, xMove, yMove, next_x, next_y, move+1))
                return true;
            else
                sol[next_x][next_y] = -1;
        }
    }
    return false;
}

int main(){
    int sol[N][N];
    int i, j;
    
    //Initialize the solution matrix
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            sol[i][j] = -1; //-1 denotes that the cell has not been reached yet
        }
    }
    
    //Initialize the moves of a knight
    int xMove[8] = { 2, 1, -1, -2, -2, -1,  1,  2 };
    int yMove[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };
    
    sol[0][0] = 0; //Start from (0,0)
    
    if(solveKT(sol, xMove, yMove, 0, 0, 1)){
        for(i=0; i<N; i++){
            for(j=0; j<N; j++){
                cout<<setw(width)<<sol[i][j];
            }
            cout<<endl;
        }
    } else {
        cout<<"No Solution exist"<<endl;
    }
    return 0;
}
