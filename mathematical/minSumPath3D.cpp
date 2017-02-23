//min sum path in 3D
#include<bits/stdc++.h>
using namespace std;
#define l 3
#define m 3
#define n 3

inline int min(int x, int y, int z) {
  return (x < y)? ((x < z)? x : z) : ((y < z)? y : z);
}
 
int minSumPath3D(int arr[][m][n]) {
    int i, j, k;
    int tSum[l][m][n];
    tSum[0][0][0] = arr[0][0][0];
    for (i = 1; i < l; i++)
        tSum[i][0][0] = tSum[i-1][0][0] + arr[i][0][0];
    for (j = 1; j < m; j++)
        tSum[0][j][0] = tSum[0][j-1][0] + arr[0][j][0];
    for (k = 1; k < n; k++)
        tSum[0][0][k] = tSum[0][0][k-1] + arr[0][0][k];
    for (i = 1; i < l; i++)
        for (j = 1; j < m; j++)
            tSum[i][j][0] = min(tSum[i-1][j][0], tSum[i][j-1][0], INT_MAX) + arr[i][j][0];
    for (i = 1; i < l; i++)
        for (k = 1; k < n; k++)
            tSum[i][0][k] = min(tSum[i-1][0][k], tSum[i][0][k-1], INT_MAX) + arr[i][0][k];
    for (k = 1; k < n; k++)
        for (j = 1; j < m; j++)
            tSum[0][j][k] = min(tSum[0][j][k-1], tSum[0][j-1][k], INT_MAX) + arr[0][j][k];
    for (i = 1; i < l; i++)
        for (j = 1; j < m; j++)
            for (k = 1; k < n; k++)
                tSum[i][j][k] = min(tSum[i-1][j][k], tSum[i][j-1][k], tSum[i][j][k-1]) + arr[i][j][k];
    return tSum[l-1][m-1][n-1];
}
 
int main() {
  int arr[l][m][n] = {  
                        { {1, 2, 4}, {3, 4, 5}, {5, 2, 1}},
                        { {4, 8, 3}, {5, 2, 1}, {3, 4, 2}},
                        { {2, 4, 1}, {3, 1, 4}, {6, 3, 8}}
  };
  cout<<"Min Sum Path is "<<minSumPath3D(arr)<<endl;
  return 0;
}
