//find all permutations of a given row
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<bits/stdc++.h>
#define MAX 100
using namespace std;

void findPermutedRows(int mat[][MAX], int m, int n, int r) {
    unordered_set<int> s;
    for (int j=0; j<n; j++)
        s.insert(mat[r][j]);
    cout<<"Permuted rows of "<<r<<"th row in the matrix are :";
    for (int i=0; i<m; i++) {
        if (i==r)
            continue;
        int j;
        for (j=0; j<n; j++)
            if (s.find(mat[i][j]) == s.end())
                break;
        if (j != n)
           continue;
        cout<<" "<<i;
    }
    cout<<endl;
}

int main() {
    int m = 4, n = 4,r = 3;
    int mat[][MAX] = {{3, 1, 4, 2},
                      {1, 6, 9, 3},
                      {1, 2, 3, 4},
                      {4, 3, 2, 1}};
    findPermutedRows(mat, m, n, r);
    return 0;
}
