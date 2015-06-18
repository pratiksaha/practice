//print all paths in a m*n grid
#include<iostream>
using namespace std;

void printAllPath(int *mat, int i, int j, int m, int n, int *path, int pi) {
    if (i==m-1) { //reached the bottom
        for (int k=j; k<n; k++)
            path[pi+k-j] = *((mat+i*n)+k);
        for (int l=0; l<pi+n-j; l++)
            cout<<" "<<path[l];
        cout << endl;
    } else if (j==n-1) { //reached the rightmost corner
        for (int k=i; k<m; k++)
            path[pi+k-i] = *((mat+k*n)+j);
        for (int l=0; l<pi+m-i; l++)
            cout<<" "<<path[l];
        cout << endl;
    } else {
        path[pi] = *((mat + i*n) + j);
        printAllPath(mat, i+1, j, m, n, path, pi + 1); //move down
        printAllPath(mat, i, j+1, m, n, path, pi + 1); //move right
        printAllPath(mat, i+1, j+1, m, n, path, pi + 1); //move diagonal
    } 
}

void printAllPath(int *mat, int m, int n) {
    int *path = new int[m+n];
    cout<<"All paths :\n";
    printAllPath(mat, 0, 0, m, n, path, 0);
    delete[] path;
}

int main() {
    int mat[2][3] = {{1, 2, 3},
                    {4, 5, 6}};
    printAllPath(*mat, 2, 3);
    return 0;
}
