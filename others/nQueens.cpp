//N Queens problem
#include<iostream>
using namespace std;
#define N 8

bool isSafe(int sol[N][N], int row, int col){
    int i, j;
    for (i = 0; i < col; i++)//Check this row on left side
        if (sol[row][i])
            return false;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)// Check upper diagonal on left side
        if (sol[i][j])
            return false; 
    for (i = row, j = col; j >= 0 && i < N; i++, j--)// Check lower diagonal on left side
        if (sol[i][j])
            return false;
    return true;//if all tests passed return true
}

bool solveNQ(int sol[N][N], int col){
    if(col >= N)
        return true;
    for(int i=0; i<N; i++){//Try for each row
        if(isSafe(sol, i, col)){
            sol[i][col] = 1;//Place a queen
            if(solveNQ(sol, col+1))
                return true;
            sol[i][col] = 0;//backtrack     
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
            sol[i][j] = 0; //0 denotes unoccupied cell, 1 denotes occupied by queen
        }
    }
    
    if(solveNQ(sol, 0)){ //start from the 0th column
        for(i=0; i<N; i++){
            for(j=0; j<N; j++){
                cout<<" "<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
    } else {
        cout<<"NO solution exist"<<endl;
    }
    return 0;
}
