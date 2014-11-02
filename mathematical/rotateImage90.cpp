//Rotate an image by 90 degrees
#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;

void displayMatrix(int *M, int R, int C) {
    int i,j;
    for(i=0; i<R; i++) {
        for(j=0; j<C; j++) {
            cout<<setw(4)<<*(M+i*C+j);
        }
        cout<<endl;
    }
}

void rotate(int *S, int *D, int R, int C) {
    int i, j;
    for(i=0; i<R; i++)
        for(j=0; j<C; j++)
            *(D+j*R+R-i-1) = *(S+i*C+j);
}
 
int main() {
    int image[4][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    int *Source;
    int *Destination;
    int m = 3;
    int n = 4;
    Source = (int *)image;
    Destination = (int *)malloc(sizeof(int)*m*n);
    cout<<"Input Image :\n";
    displayMatrix(Source, m, n);
    rotate(Source, Destination, m, n);
    cout<<"Output Image :\n";
    displayMatrix(Destination, n, m);
    free(Destination);
    return 0;
}
