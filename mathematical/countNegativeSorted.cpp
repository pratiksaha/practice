//to count negative numbers in a rowwise and columnwise sorted matrix
#include<bits/stdc++.h>
using namespace std;
#define R 3
#define C 4

int countNegativeSorted(int M[R][C]) {
    int count = 0, i = 0, j = C-1;
    while (j>=0 && i<R) {
        if (M[i][j]<0) {
            count += j+1;
            i++;
        } else {
            j--;
        }
    }    
}

int main() {
    int M[R][C] = { {-3, -2, -1,  1},
                    {-2,  2,  3,  4},
                    {4,   5,  7,  8}
                  };
    cout<<"No of negative nos in the given matrix is "<<countNegativeSorted(M)<<endl;
    return 0;
}
