//to find maximum difference of sum of elements of any two rows
#include<bits/stdc++.h>
#define MAX 100
using namespace std;

int maxDiffRowSum(int mat[][MAX], int m, int n) {
    int rowSum[m];
    for (int i=0; i<m; i++) {
        int sum = 0;
        for (int j=0; j<n; j++)
            sum += mat[i][j];
        rowSum[i] = sum;
    }
    int max_diff = rowSum[1] - rowSum[0];
    int min_element = rowSum[0];
    for (int i=1; i<m; i++) {
        if (rowSum[i] - min_element > max_diff)
            max_diff = rowSum[i] - min_element;
        if (rowSum[i] < min_element)
            min_element = rowSum[i];
    }
    return max_diff;
}

int main() {
    int m = 5, n = 4;
    int mat[][MAX] = {{-1, 2, 3, 4},
                     {5, 3, -2, 1},
                     {6, 7, 2, -3},
                     {2, 9, 1, 4},
                     {2, 1, -2, 0}};
 
    cout<<"maximum difference of sum of elements of any two rows is "<<maxDiffRowSum(mat, m, n)<<endl;
    return 0;
}
