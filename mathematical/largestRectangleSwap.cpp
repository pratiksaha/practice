//to find the largest rectangle of 1's with swapping of columns allowed
#include<iostream>
using namespace std;

#define R 3
#define C 5

int largestRectangleSwap(int mat[R][C]) {
    int hist[R+1][C+1];
    for (int i=0; i<C; i++) {
        hist[0][i] = mat[0][i];
        for (int j=1; j<R; j++)
            hist[j][i] = (mat[j][i]==0)? 0: hist[j-1][i]+1;
    }
    for (int i=0; i<R; i++) { //sort rows of hist[][] in non-increasing order
        int count[R+1] = {0};
        for (int j=0; j<C; j++)
            count[hist[i][j]]++;
        int col_no = 0;
        for (int j=R; j>=0; j--) { //traverse the count array from right side
            if (count[j] > 0) {
                for (int k=0; k<count[j]; k++) {
                    hist[i][col_no] = j;
                    col_no++;
                }
            }
        }
    }
    int curr_area, max_area = 0;
    for (int i=0; i<R; i++) { //traverse the sorted hist[][] to find maximum area
        for (int j=0; j<C; j++) {
            curr_area = (j+1)*hist[i][j]; //values are in non-increasing order
            if (curr_area > max_area)
                max_area = curr_area;
        }
    }
    return max_area;
}

int main() {
    int mat[R][C] ={{0, 1, 0, 1, 0},
                    {0, 1, 0, 1, 1},
                    {1, 1, 0, 1, 0}};
    cout<<"Area of the largest rectangle is "<<largestRectangleSwap(mat)<<endl;
    return 0;
}
