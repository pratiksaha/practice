//to find pairs with given sum such the two elements of pairs are from different rows
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<bits/stdc++.h>
using namespace std;
#define MAX 100

void pairSumDiffRows(int mat[][MAX], int n, int sum) {
    unordered_map<int, pair<int, int> > hm;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            hm[mat[i][j]] = make_pair(i, j);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int remSum = sum - mat[i][j];
            unordered_map<int, pair<int, int> >::iterator it = hm.find(remSum);
            if (it != hm.end()) {
                pair<int, int> p = it->second;
                int row = p.first;
                int col = p.second;
                if (row != i && row > i)
                    cout<<" ("<<mat[i][j]<<","<<mat[row][col]<<")";
            }
        }
    }
    cout<<endl;
}

int main() {
    int n = 4, sum = 11;
    int mat[][MAX]= {{1, 3, 2, 4},
                     {5, 8, 7, 6},
                     {9, 10, 13, 11},
                     {12, 0, 14, 15}};
    pairSumDiffRows(mat, n, sum);
    return 0;
}
