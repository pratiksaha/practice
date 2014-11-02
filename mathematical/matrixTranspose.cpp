//Inplace matrix transpose
#include<iostream>
#include<iomanip>
#include<bitset>
#include<cstdlib>
using namespace std;
#define HASH_SIZE 128
#define N 5
#define width 4

void printSymmetricMatrix(int M[N][N]) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cout<<setw(width)<<M[i][j];
        }
        cout<<endl;   
    }
}

void printAsymmetricMatrix(int *M, int R, int C) {
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            cout<<setw(width)<<*(M+i*C+j);
        }
        cout<<endl;
    }
}

void symmetricTranspose(int M[N][N]) {
    for(int i=0; i<N; i++)
        for(int j=i+1; j<N; j++)
            swap(M[i][j], M[j][i]);
}

void asymmetricTranspose(int *M, int R, int C) {
    int size = R*C - 1;
    int t;
    int next;
    int cycleBegin;
    int i;
    bitset<HASH_SIZE> b;
 
    b.reset();
    b[0] = b[size] = 1; //M[0] and M[size-1] won't move
    i = 1; 
    while (i<size) {
        cycleBegin = i;
        t = M[i];
        do {   
            next = (i*R)%size;
            swap(M[next], t);
            b[i] = 1;
            i = next;
        } while (i != cycleBegin);
        for (i=1; i<size && b[i]; i++);
    }
}

int main() {
    int S[N][N];
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            S[i][j] = i*N+j;
            
    cout<<"Input Symmetric matrix:\n";
    printSymmetricMatrix(S);
    
    symmetricTranspose(S);
    
    cout<<"Transpose matrix:\n";
    printSymmetricMatrix(S);
    
    int R = 5;
    int C = 6;
    int size = R*C;
    int *A = new int[size];
    for(int i=0; i<size; i++)
        A[i] = i+1;
        
    cout<<"Input Asymmetric matrix:\n";
    printAsymmetricMatrix(A, R, C);
    
    asymmetricTranspose(A, R, C);
    
    cout<<"Transpose matrix:\n";
    printAsymmetricMatrix(A, C, R);
    
    delete[] A;
    return 0;
}
