//to find  the largest subsquaresurrounded by 'X' in a given matrix of 'O' and 'X'
#include<iostream>
#include<cstdlib>
using namespace std;
#define M 7
#define N 6
 
void largestSubSquareX(char mat[M][N]) {
    int i, j;
    int hor[M][N]; //hor[i][j] = no of horizontal continuous ‘X’ characters till mat[i][j] in mat[][]
    int ver[M][N]; //ver[i][j] = no of vertical continuous ‘X’ characters till mat[i][j] in mat[][]
    hor[0][0] = ver[0][0] = (mat[0][0] == 'X');
    for (i=0; i<M; i++) {
        for (j=0; j<N; j++) {
            if (mat[i][j] == 'O') {
                ver[i][j] = hor[i][j] = 0;
            } else {
                hor[i][j] = (j==0)?1:hor[i][j-1]+1;
                ver[i][j] = (i==0)?1:ver[i-1][j]+1;
            }
        }
    }
    int maxSq=1, indX=M-1, indY=N-1;
    for (i=M-1; i>=1; i--) { //start from the rightmost-bottommost and move towards leftmost-topmost
        for (j=N-1; j>=1; j--) {
            int temp = min(hor[i][j], ver[i][j]); //there is a right vertical line and bottom horizontal line of length at least temp
            while (temp >= maxSq) {
                if (ver[i][j-temp+1] >= temp && hor[i-temp+1][j] >= temp) {
                    maxSq = temp;
                    indX = j-temp+1;
                    indY = i-temp+1;
                }
                temp--;
            }
        }
    }
    cout<<"Largest sub square surrounded by X of size "<<maxSq<<" starts at ("<<indX<<","<<indY<<")\n";
}

void printMatrix(char inp[M][N]) {
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            cout<<" "<<inp[i][j];
        }
        cout<<endl;
    }
}

int main() {
    char mat[M][N] =  { {'X', 'O', 'X', 'X', 'X', 'X'},
                        {'X', 'O', 'X', 'X', 'O', 'X'},
                        {'X', 'X', 'X', 'O', 'O', 'X'},
                        {'O', 'X', 'X', 'X', 'X', 'X'},
                        {'X', 'X', 'X', 'X', 'O', 'O'},
                        {'O', 'O', 'X', 'O', 'O', 'O'},
                        {'O', 'O', 'X', 'O', 'O', 'O'},
                    };
    cout<<"Input\n";
    printMatrix(mat);
    largestSubSquareX(mat);
    return 0;
}
