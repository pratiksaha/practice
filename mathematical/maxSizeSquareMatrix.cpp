#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define r 6
#define c 5
#define w 3

void maxSubMatrix(int M[r][c]) {
    int i,j;
    int S[r][c];
    for(i = 0; i < r; i++)
        S[i][0] = M[i][0];  
    for(j = 0; j < c; j++)
        S[0][j] = M[0][j];

    for(i = 1; i < r; i++) {
        for(j = 1; j < c; j++) {
            if(M[i][j] == 1)
                S[i][j] = min(S[i][j-1], min(S[i-1][j], S[i-1][j-1])) + 1;
            else
                S[i][j] = 0;
        }   
    }
    int sq = S[0][0];
    int sqi = 0;
    int sqj = 0;
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            if(sq < S[i][j]) {
                sq = S[i][j];
                sqi = i;
                sqj = j;
            } 
        }               
    }    
   
    cout<<"Maximum size of square sub-matrix is "<<sq<<" starting at index ("<<sqi-sq+1<<","<<sqj-sq+1<<"):\n";
    for(i=sqi-sq+1; i<=sqi ; i++) {
        for(j=sqj-sq+1; j<=sqj; j++) {
            cout<<setw(w)<<M[i][j];
        }
        cout<<endl;
    }
    
}

int main() {
    int M[r][c] =  {{0, 1, 1, 0, 1},
                    {1, 1, 0, 1, 0},
                    {0, 1, 1, 1, 0},
                    {1, 1, 1, 1, 0},
                    {1, 1, 1, 1, 1},
                    {0, 0, 0, 0, 0}};
    maxSubMatrix(M);
    return 0;
}
