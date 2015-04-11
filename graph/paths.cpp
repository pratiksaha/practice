//count and print paths in a graph
#include<iostream>
using namespace std;

void pathUtil(int *mat, int i, int j, int m, int n, int *path, int pi) {
    if (i == m-1) { //reached bottom of matrix
        for (int k=j; k<n; k++)
            path[pi+k-j] = *((mat+i*n)+k);
        for (int l=0; l<pi+n-j; l++)
            cout<<path[l]<<" ";
        cout<<endl;
    } else if (j == n-1) { //reached right corner of matrix
        for (int k=i; k<m; k++)
            path[pi+k-i] = *((mat+k*n)+j);
        for (int l=0; l<pi+m-i; l++)
            cout<<path[l]<<" ";
        cout<<endl;
    } else {
        path[pi] = *((mat+i*n)+j); //include current cell
        pathUtil(mat, i+1, j, m, n, path, pi + 1); //move down
        pathUtil(mat, i, j+1, m, n, path, pi + 1); //move right
        pathUtil(mat, i+1, j+1, m, n, path, pi + 1); //move diagonal
    }
}

void paths(int *mat, int m, int n) {
    int *path = new int[m+n];
    pathUtil(mat, 0, 0, m, n, path, 0);
}

int pathCount(int *mat, int m, int n) {
    int count[m][n];
    for (int i=0; i<m; i++)
        count[i][0] = 1;
    for (int j=0; j<n; j++)
        count[0][j] = 1;
    for (int i=1; i<m; i++)
        for (int j=1; j<n; j++)
            count[i][j] = count[i-1][j] + count[i][j-1] + count[i-1][j-1];
    return count[m-1][n-1];
}

int main() {
    int mat[2][3] = { {1, 2, 3}, {4, 5, 6} };
    cout<<"No of paths = "<<pathCount(*mat, 2, 3)<<endl;
    paths(*mat, 2, 3);
    return 0;
}
