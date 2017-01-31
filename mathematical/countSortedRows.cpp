//to find number of sorted rows
#include<bits/stdc++.h>
#define MAX 100
using namespace std;
 
int countSortedRows(int mat[][MAX], int r, int c) {
    int result = 0;
    for (int i=0; i<r; i++) {
        int j;
        for (j=0; j<c-1; j++)
            if (mat[i][j+1] <= mat[i][j])
                break;
        if (j == c-1)
            result++;
    }
    for (int i=0; i<r; i++) {
        int j;
        for (j=c-1; j>0; j--)
            if (mat[i][j-1] <= mat[i][j])
                break;
        if (c > 1 && j == 0)
            result++;
    }
    return result;
}

int main() {
    int m = 4, n = 5;
    int mat[][MAX] = {{1, 2, 3, 4, 5},
                      {4, 3, 1, 2, 6},
                      {8, 7, 6, 5, 4},
                      {5, 7, 8, 9, 10}};
    cout<<"No of sorted rows in matrix is "<<countSortedRows(mat, m, n)<<endl;
    return 0;
}
