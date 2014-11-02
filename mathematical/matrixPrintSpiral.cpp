//Print a matrix spirally 
#include <iostream>
#include<iomanip>
using namespace std;
#define R 3
#define C 6
#define W 5

void printMatrix(int M[R][C]) {
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cout<<setw(W)<<M[i][j];
        }
        cout<<endl;
    }
}
 
void spiralOrder(int M[R][C]) {
    int i;
    int k = 0; //beg row index
    int l = 0; //beg col index
    int m = R; //end row index
    int n = C; //end col index
 
    while (k<m && l<n) {     
        for (i=l; i<n; i++) //print the first row from the rem rows
            cout<<setw(W)<<M[k][i];
        k++;
        for (i=k; i<m; i++) //print the last col from the rem cols 
            cout<<setw(W)<<M[i][n-1];
        n--;
        if (k<m) {
            for (i=n-1; i>=l; i--) //print the last row from the rem rows
                cout<<setw(W)<<M[m-1][i];
            m--;
        } 
        if (l<n) {
            for (i=m-1; i>=k; i--) //print the first col from the rem cols
                cout<<setw(W)<<M[i][l];
            l++;    
        }        
    }
    cout<<endl;
}

int main() {
    int M[R][C] = { {1,  2,  3,  4,  5,  6},
                    {7,  8,  9,  10, 11, 12},
                    {13, 14, 15, 16, 17, 18}
                  };
 
    cout<<"Input matrix is :\n";
    printMatrix(M);
    cout<<"Spiral printing of matrix is :\n";
    spiralOrder(M);
    return 0;
}

