//total coverage of all zeros
#include <bits/stdc++.h>
using namespace std;
#define R 4
#define C 4

int getTotalCoverageOfZerosInMatrix(int mat[R][C]) {
    int res = 0;
    for (int i = 0; i < R; i++) {
        bool isOne = false;
        for (int j = 0; j < C; j++) {
            if (mat[i][j] == 1)
                isOne = true;
            else if (isOne)
                res++;
        }
        isOne = false;
        for (int j = C-1; j >= 0; j--) {
            if (mat[i][j] == 1)
                isOne = true;
            else if (isOne)
                res++;
        }
    }
    for (int j = 0; j < C; j++) {
        bool isOne = false;
        for (int i = 0; i < R; i++) {
            if (mat[i][j] == 1)
                isOne = true;
            else if (isOne)
                res++;
        }
        isOne = false;
        for (int i = R-1; i >= 0; i--) {
            if (mat[i][j] == 1)
                isOne = true;
            else if (isOne)
                res++;
        }
    }
    return res;
}

int main() {
    int mat[R][C] = {
        {0, 0, 0, 0},
        {1, 0, 0, 1},
        {0, 1, 1, 0},
        {0, 1, 0, 0}
    };
    cout<<"Total coverage of all zeroes in the matrix is "<<getTotalCoverageOfZerosInMatrix(mat)<<endl;
    return 0;
}
