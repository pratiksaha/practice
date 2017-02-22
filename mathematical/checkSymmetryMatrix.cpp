//to find if a matrix is symmetric
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
 
string checkSymmetryMatrix(int arr[][MAX], int N, int M) {
    bool horizontal = true, vertical = true;
    for (int i=0, k=N-1; i<N/2; i++, k--) {
        for (int j=0; j<M; j++) {
            if (arr[i][j] != arr[k][j]) {
                horizontal = false;
                break;
            }
        }
    }
    for (int i=0, k=M-1; i<M/2; i++, k--) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] != arr[k][j]) {
                horizontal = false;
                break;
            }
        }
    }
    if (!horizontal && !vertical)
        return "NONE";
    else if (horizontal && !vertical)
        return "HORIZONTAL";
    else if (vertical && !horizontal)
        return "VERTICAL";
    else
        return "BOTH";
}

int main() {
    int mat[MAX][MAX] = { {1, 0, 1},
                          {0, 0, 0},
                          {1, 0, 1}};
    cout<<checkSymmetryMatrix(mat, 3, 3)<<endl;
    return 0;
}
