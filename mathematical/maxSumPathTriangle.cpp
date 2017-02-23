//min sum path in a triangle
#include<bits/stdc++.h>
using namespace std;
#define N 3
 
int maxSumPathTriangle(int tri[][N], int m, int n) {
    for (int i=m-1; i>=0; i--) {
        for (int j=0; j<=i; j++) {
            if (tri[i+1][j] > tri[i+1][j+1])
                tri[i][j] += tri[i+1][j];
            else
                tri[i][j] += tri[i+1][j+1];
        }
    }
    return tri[0][0];
}
 
int main() {
   int tri[N][N] = {  {1, 0, 0},
                      {4, 8, 0},
                      {1, 5, 3} };
   cout<<maxSumPathTriangle(tri, 2, 2)<<endl;
   return 0;
}
