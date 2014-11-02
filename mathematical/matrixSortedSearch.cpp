//Search in a row-wise and column-wise sorted matrix
#include<iostream>
using namespace std;
#define R 4
#define C 5


void search(int mat[R][C], int key) {
    int i = 0;
    int j = C-1;
    while ( i<R && j>=0 ) {
        if (mat[i][j] == key) {
            cout<<key<<" Found at index ("<<i<<","<<j<<")\n";
            return ;
        } 
        
        if (mat[i][j]>key)
            j--;
        else
            i++;
   }
   cout<<key<<" not found\n";
}

int main() {
    int M[R][C] = { {10, 20, 30, 40, 42},
                    {15, 25, 35, 45, 47},
                    {27, 29, 37, 48, 59},
                    {32, 33, 39, 50, 60},
                  };    
    search(M, 29);
    search(M, 15);
    search(M, 59);
    search(M, 38);
    return 0;
}
