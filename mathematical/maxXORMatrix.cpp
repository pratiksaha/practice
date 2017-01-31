//maximum XOR value in matrix
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

int maxXORMatrix(int mat[][MAX], int N) {
    int r_xor, c_xor;
    int max_xor = 0;
    for (int i=0; i<N ; i++) {
        r_xor = 0, c_xor = 0;
        for (int j=0; j< N ; j++) {
            r_xor = r_xor^mat[i][j];
            c_xor = c_xor^mat[j][i];
        }
        if (max_xor < max(r_xor,c_xor))
            max_xor =  max(r_xor,c_xor);
    }
    return max_xor;
}

int main() {
    int N = 3;
    int mat[][MAX] = {
        {1 , 5, 4},
        {3 , 7, 2},
        {5 , 9, 10},
    };
    cout<<"Max XOR value in the given matrix is "<<maxXORMatrix(mat, N)<<endl;
    return 0;
}
