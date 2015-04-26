//to find a common element in all rows of a row wise sorted array
#include<iostream>
using namespace std;
#define M 4
#define N 5

int commonRowSorted(int mat[M][N]) {
    int col[M]; //col[i] = index of curr last col for row i
    for (int i=0; i<M; i++)
        col[i] = N-1;
    int min_row = 0;
    while (col[min_row] >= 0) { //repeat till either all elem at curr last col don’t become same or a last col index reaches 0
        for (int i=0; i<M; i++) //find min in curr last col
            if (mat[i][col[i]] < mat[min_row][col[min_row]] )
                min_row = i;
        int eq_count = 0; //count of elems equal to min in current last col
        for (int i=0; i<M; i++) {
            if (mat[i][col[i]] > mat[min_row][col[min_row]]) { //Decrease last col index of a row whose value is more than min
                if (col[i] == 0)
                    return -1;
                col[i]--;
            } else {
                eq_count++;
            }
        }
        if (eq_count == M) //return the value if eq_count becomes M
            return mat[min_row][col[min_row]];
    }
    return -1;
}

int main() {
    int mat[M][N] ={{1, 2, 3, 4, 5},
                    {2, 4, 5, 8, 10},
                    {3, 5, 7, 9, 11},
                    {1, 3, 5, 7, 9},
                    };
    cout<<"Common element = "<<commonRowSorted(mat)<<endl;
    return 0;
}
