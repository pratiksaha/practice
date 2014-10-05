//program to generate magic square
//buggy
#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;
#define width 4

void generateMagicSquare(int N){
    int soln[N][N];
    memset(soln, 0, sizeof(soln));
    int i, j;
    
    
    //Print solution
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            cout<<setw(width)<<soln[i][j];
        }
        cout<<endl;
    }    
}

int main(){
    int num;
    cin>>num;
    generateMagicSquare(num);
    return 0;
}
