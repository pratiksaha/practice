//to find sum of all subsquares of size k
#include<iostream>
using namespace std;
#define N 5

void sumSquareK(int mat[N][N], int k) {
    if (k > N)
        return; 
    int stripSum[N][N]; //sums of all strips of size k x 1
    for (int j=0; j<N; j++) {
        int sum = 0;
        for (int i=0; i<k; i++)
            sum += mat[i][j];
        stripSum[0][j] = sum;
        for (int i=1; i<N-k+1; i++) {
            sum += (mat[i+k-1][j] - mat[i-1][j]);
            stripSum[i][j] = sum;
        }
    }
    for (int i=0; i<N-k+1; i++) {
        int sum = 0;
        for (int j = 0; j<k; j++)
            sum += stripSum[i][j];
        cout<<" "<<sum;
        for (int j=1; j<N-k+1; j++) {
            sum += (stripSum[i][j+k-1] - stripSum[i][j-1]);
            cout<<" "<<sum;
        }
        cout<<endl;
    }
}

int main() {
    int mat[N][N] = {{1, 1, 1, 1, 1},
                     {2, 2, 2, 2, 2},
                     {3, 3, 3, 3, 3},
                     {4, 4, 4, 4, 4},
                     {5, 5, 5, 5, 5},
                    };
    int k = 3;
    sumSquareK(mat, k);
    return 0;
}
