#include<bits/stdc++.h>
using namespace std;
#define N 4
#define HASH_SIZE 128
#define R 3
#define C 4

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

void displayMatrix(int *M, int r, int c) {
    int i,j;
    for(i=0; i<r; i++) {
        for(j=0; j<c; j++) {
            cout<<setw(4)<<*(M+i*c+j);
        }
        cout<<endl;
    }
}

void displayMatrix(int mat[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout<<setw(4)<<mat[i][j];
        cout<<endl;
    }
}

void rotate(int *S, int *D, int r, int c) {
    int i, j;
    for(i=0; i<r; i++)
        for(j=0; j<c; j++)
            *(D+j*r+r-i-1) = *(S+i*c+j);
}

void rotateMatrix(int mat[][N]) {
    for (int x=0; x<N/2; x++) {
        for (int y=x; y<N-x-1; y++) {
            int temp = mat[x][y];
            mat[x][y] = mat[y][N-1-x];
            mat[y][N-1-x] = mat[N-1-x][N-1-y];
            mat[N-1-x][N-1-y] = mat[N-1-y][x];
            mat[N-1-y][x] = temp;
        }
    }
}

void transformMatrix(int *A, int r, int c) {
    for (int i = 1; i < r; i = i + 2)
        for (int j1 = 0, j2 = c - 1; j1 < j2; j1++, j2--)
            swap(*(A + i*c + j1), *(A + i*c + j2));
    int size = r*c - 1;
    int t;
    int next;
    int cycleBegin;
    bitset<HASH_SIZE> b;
    b.reset();
    b[0] = b[size] = 1;
    int i = 1;
    while (i < size) {
        cycleBegin = i;
        t = A[i];
        do {
            next = (i*r)%size;
            swap(A[next], t);
            b[i] = 1;
            i = next;
        } while (i != cycleBegin);
        for (i = 1; i < size && b[i]; i++) //random location
            ;
    }
}

void replaceMatrixMaxGCDRowCol(int mat[R][C], int n, int m) {
    int rgcd[R] = { 0 }, cgcd[C] = { 0 };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            rgcd[i] = gcd(rgcd[i], mat[i][j]);
            cgcd[j] = gcd(cgcd[j], mat[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            mat[i][j] = max(rgcd[i], cgcd[j]);
}

int main() {
    int image[4][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    int *Source;
    int *Destination;
    int m = 3;
    int n = 4;
    Source = (int *)image;
    Destination = (int *)malloc(sizeof(int)*m*n);
    cout<<"Input Image :\n";
    displayMatrix(Source, m, n);
    rotate(Source, Destination, m, n);
    cout<<"Output Image :\n";
    displayMatrix(Destination, n, m);
    free(Destination);
    int A[][4] = {{1, 2, 3, 4},
                 {5, 6, 7, 8},
                 {9, 10, 11, 12}};
    int r = 3, c = 4;
    cout<<"Given Matrix:\n";
    displayMatrix((int *)A, r, c);
    transformMatrix((int *)A, r, c);
    cout<<"Transformed Matrix:\n";
    displayMatrix((int *)A, c, r);
    int mat[N][N] =
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    cout<<"Before Inplace Rotation:\n";
    displayMatrix(mat);
    rotateMatrix(mat);
    cout<<"After Inplace Rotation:\n";
    displayMatrix(mat);
    int matrix[R][C] = {
        1, 2, 3, 3,
        4, 5, 6, 6,
        7, 8, 9, 9,
    };
    replaceMatrixMaxGCDRowCol(matrix, R, C);
    cout<<"Replaced Matrix with max GCD among rows and cols :\n";
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++)
            cout<<" "<<matrix[i][j];
        cout<<endl;
    }
    return 0;
}
