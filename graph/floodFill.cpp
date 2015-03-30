// to implement flood fill algorithm
#include<iostream>
using namespace std;
#define M 8
#define N 8

void floodFillUtil(int screen[M][N], int x, int y, int prevC, int newC) {
    if (x<0 || x>=M || y<0 || y>=N) //out of bounds
        return;
    if (screen[x][y] != prevC) //not in the region or already replaced
        return;
    screen[x][y] = newC; //replace color at (x, y)
    floodFillUtil(screen, x+1, y, prevC, newC); //recur east
    floodFillUtil(screen, x-1, y, prevC, newC); //recur west
    floodFillUtil(screen, x, y+1, prevC, newC); //recur north
    floodFillUtil(screen, x, y-1, prevC, newC); //recur south
}

void floodFill(int screen[M][N], int x, int y, int newC) {//In screen, replace the region surrounding (x,y) by color newC
    int prevC = screen[x][y]; //get the original color at (x,y)
    floodFillUtil(screen, x, y, prevC, newC);
}

void printMatrix(int screen[M][N]) {
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            cout<<" "<<screen[i][j];
        }
        cout<<endl;
    }
}

int main() {
    int screen[M][N] = {{1, 1, 1, 1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1, 1, 0, 0},
                        {1, 0, 0, 1, 1, 0, 1, 1},
                        {1, 2, 2, 2, 2, 0, 1, 0},
                        {1, 1, 1, 2, 2, 0, 1, 0},
                        {1, 1, 1, 2, 2, 2, 2, 0},
                        {1, 1, 1, 1, 1, 2, 1, 1},
                        {1, 1, 1, 1, 1, 2, 2, 1},
                       };
    int x=4, y=4, newC=3;
    cout<<"Before flood fill:\n";
    printMatrix(screen);
    floodFill(screen, x, y, newC);
    cout<<"After flood fill:\n";
    printMatrix(screen);
    return 0;
}
