//to check if all rows of a matrix are rotations of each other
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000;

bool rotatedPermutationMatrix( int mat[MAX][MAX], int n) {
    string str_cat = "";
    for (int i = 0 ; i < n ; i++)
        str_cat = str_cat + "-" + to_string(mat[0][i]);
    str_cat = str_cat + str_cat;
    for (int i=1; i<n; i++) {
        string curr_str = "";
        for (int j=0 ; j<n ; j++)
            curr_str = curr_str + "-" + to_string(mat[i][j]);
        if (str_cat.find(curr_str) == string::npos)
            return false;
    }
    return true;
}

int main() {
    int n = 4 ;
    int mat[MAX][MAX] = {
        {1, 2, 3, 4},
        {4, 1, 2, 3},
        {3, 4, 1, 2},
        {2, 3, 4, 1}
    };
    cout<<"Given matrix is"<<(rotatedPermutationMatrix(mat, n)? " " : " not ")<<"a rotated permuation matrix\n";
    return 0;
}
