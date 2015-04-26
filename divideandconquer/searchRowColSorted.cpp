//to search for an element in a row col sorted matrix
#include<iostream>
using namespace std;
#define M 4
#define N 4

void search(int mat[M][N], int key) { //O(M+N)
    int i=0, j=N-1;
    while (i<M && j>=0) {
        if (mat[i][j]==key) {
            cout<<key<<" Found at ("<<i<<","<<j<<")\n";
            return;
        }
        if (mat[i][j]>key)
            j--;
        else
            i++;
    }
    cout<<key<<" Not found\n";
}

bool searchDC(int mat[M][N], int rbeg, int rend, int cbeg, int cend, int key) { //O(N^1.58) works only when M==N and N is of the form 2^k
    int i = (rbeg+rend)/2;
    int j = (cbeg+cend)/2;
    if (mat[i][j] == key) {
         cout<<"Found at ("<<i<<","<<j<<") ";
         return true;
    } else {
        if (i+1<=rend && j+1<=cend ) {
            bool tr = searchDC(mat, rbeg, i, j+1, cend, key); //topright
            bool bl = searchDC(mat, i+1, rend, cbeg, j, key); //bottomleft
            bool var;
            if (mat[i][j] < key)
                var = searchDC(mat, i+1, rend, j+1, cend, key); //bottomright 
            else
                var = searchDC(mat, rbeg, i, cbeg, j, key); //topleft 
            return tr || bl || var; //key is found in at least one submatrix
        } else {
            return false;
        }
    }
}

int main() {
    int mat[4][4] ={{10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                    {32, 33, 39, 50},
                   };
    search(mat, 29);
    search(mat, 31);
    cout<<"29 : "<<searchDC(mat, 0, M-1, 0, N-1, 29)<<endl;
    cout<<"31 : "<<searchDC(mat, 0, M-1, 0, N-1, 31)<<endl;
    return 0;
}
