//to compute submatrix query sum in constant time
#include<bits/stdc++.h>
using namespace std;
#define M 4
#define N 5

int preProcess(int mat[M][N], int aux[M][N]) {
    for (int i=0; i<N; i++)
        aux[0][i] = mat[0][i];
    for (int i=1; i<M; i++)
        for (int j=0; j<N; j++)
            aux[i][j] = mat[i][j] + aux[i-1][j];
    for (int i=0; i<M; i++)
        for (int j=1; j<N; j++)
            aux[i][j] += aux[i][j-1];
}

int sumQuery(int aux[M][N], int tli, int tlj, int rbi, int rbj) {
    int res = aux[rbi][rbj];
    if (tli > 0)
        res -= aux[tli-1][rbj];
    if (tlj > 0)
        res -= aux[rbi][tlj-1];
    if (tli > 0 && tlj > 0)
        res += aux[tli-1][tlj-1];
    return res;
}

int main() {
    int mat[M][N] ={{1, 2, 3, 4, 6},
                    {5, 3, 8, 1, 2},
                    {4, 6, 7, 5, 5},
                    {2, 4, 8, 9, 4}};
   int aux[M][N];
   preProcess(mat, aux);
   int tli = 2, tlj = 2, rbi = 3, rbj = 4;
   cout<<"Query1 : "<<sumQuery(aux, tli, tlj, rbi, rbj)<<endl;
   tli = 0, tlj = 0, rbi = 1, rbj = 1;
   cout<<"Query2 : "<<sumQuery(aux, tli, tlj, rbi, rbj)<<endl;
   tli = 1, tlj = 2, rbi = 3, rbj = 3;
   cout<<"Query3 : "<<sumQuery(aux, tli, tlj, rbi, rbj)<<endl; 
   return 0;
}
