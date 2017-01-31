//to construct an n x n matrix such that every row and every column has distinct values
#include<bits/stdc++.h>
using namespace std;
#define MAX 100

int mat[MAX][MAX];

void fillRemaining(int i, int j, int n) {
    int x = 2;
    for (int k=i+1; k<n; k++)
        mat[k][j] = x++;
    for (int k=0; k<i; k++)
        mat[k][j] = x++;
}

void constUniqueMatrix(int n) {
    int right = n-1, left = 0;
    for (int i=0; i<n; i++) {
        if (i%2 == 0) {
            mat[i][right] = 1;
            fillRemaining(i, right, n);
            right--;
        } else {
            mat[i][left] = 1;
            fillRemaining(i, left, n);
            left++;
        }
    }
}
 
int main() {
    int n = 5;
    constUniqueMatrix(n);
    cout<<"Unique matrix for n = "<<n<<" is :\n";
    for (int i=0; i<n; i++) {
        for (int j=0 ; j<n; j++)
            cout<<setw(4)<<mat[i][j];
        cout<<endl;
    }
    return 0;
}
