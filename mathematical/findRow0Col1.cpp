//to find i such that all entries in i'th row are 0 and all entries in i'th column are 1
#include <iostream>
using namespace std;
#define n 5
 
int findRow0Col1(bool arr[n][n]) {
    int i=0, j=n-1, res = -1;
    while (i<n && j>=0) {
        if (arr[i][j] == 0) {
            while (j >= 0 && (arr[i][j] == 0 || i == j))
                j--;
            if (j == -1) {
                res = i;
                break;
            }
            else {
                i++;
            }
        } else {
            while (i<n && (arr[i][j] == 1 || i == j))
                i++;
            if (i == n) {
                res = j;
                break;
            } else {
                j--;
            }
        }
    }
    if (res == -1)
        return res;
    for (int i=0; i<n; i++)
        if (res != i && arr[i][res] != 1)
            return -1;
    for (int j=0; j<n; j++)
        if (res != j && arr[res][j] != 0)
            return -1;
    return res;
}

int main() {
    bool mat[n][n] = {{0, 0, 1, 1, 0},
                      {0, 0, 0, 1, 0},
                      {1, 1, 1, 1, 0},
                      {0, 0, 0, 0, 0},
                      {1, 1, 1, 1, 1}};
    cout<<"Value of i where all entries in i'th row are 0 and all entries in i'th column are 1 is "<<findRow0Col1(mat)<<endl;
 
    return 0;
}
