//to find maximum value of mat[c][d] - ma[a][b] such that c > a and d > b
#include<bits/stdc++.h>
using namespace std;
#define N 5

int maxCD_AB(int mat[][N]) {
    int maxValue = INT_MIN;
    int maxArr[N][N];
    maxArr[N-1][N-1] = mat[N-1][N-1];
    int maxv = mat[N-1][N-1];
    for (int j = N-2; j >= 0; j--) {
        if (mat[N-1][j] > maxv)
            maxv = mat[N-1][j];
        maxArr[N-1][j] = maxv;
    }
    maxv = mat[N - 1][N - 1];
    for (int i = N-2; i >= 0; i--) {
        if (mat[i][N-1] > maxv)
            maxv = mat[i][N-1];
        maxArr[i][N-1] = maxv;
    }
    for (int i = N-2; i >= 0; i--) {
        for (int j = N-2; j >= 0; j--) {
            if (maxArr[i+1][j+1] - mat[i][j] > maxValue)
                maxValue = maxArr[i + 1][j + 1] - mat[i][j];
            maxArr[i][j] = max(mat[i][j],max(maxArr[i][j + 1],maxArr[i + 1][j]));
        }
    }
    return maxValue;
}
 
int main() {
    int mat[N][N] = {
                      { 1, 2, -1, -4, -20 },
                      { -8, -3, 4, 2, 1 },
                      { 3, 8, 6, 1, 3 },
                      { -4, -1, 1, 7, -6 },
                      { 0, -4, 10, -5, 1 }
                    };
    cout<<"Maximum Value is "<<maxCD_AB(mat)<<endl;
    return 0;
}
