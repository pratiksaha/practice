//Print a matix diagonally
#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;
#define R 5
#define C 4
#define W 5

void printMatrix(int M[R][C]) {
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cout<<setw(W)<<M[i][j];
        }
        cout<<endl;
    }
}

void diagonalOrder(int M[R][C]) { 
    for (int line=1; line<=(R+C-1); line++) { //there will be R+C-1 lines in the output
        int c_ind =  max(0, line-R); //get col index of the first element in this line of output.
        int cnt = min(min(line, (C-c_ind)), R); //get count of elements in this line
        for (int k=0; k<cnt; k++)
            cout<<setw(W)<<M[min(R, line)-k-1][c_ind+k]; 
        cout<<endl;
    }
}

int main() {
    int M[R][C] = {{1, 2, 3, 4},
                   {5, 6, 7, 8},
                   {9, 10, 11, 12},
                   {13, 14, 15, 16},
                   {17, 18, 19, 20},
                  };
    cout<<"Input matrix is :\n";
    printMatrix(M);
    cout<<"Diagonal printing of matrix is :\n";
    diagonalOrder(M);
    return 0;
}
