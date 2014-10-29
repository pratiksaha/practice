// A DP based program to check whether a string C is an interleaving of A & B
#include<iostream>
#include<cstring>
using namespace std;

bool isInterleaved(char* A, char* B, char* C) {
    int M = strlen(A);
    int N = strlen(B);

    if ((M+N) != strlen(C)) //C can be an interleaving of A and B only of sum of lengths of A & B is equal to length of C
       return false;
 
    bool IL[M+1][N+1]; //IL[i][j] will be true if C[0..i+j-1] is an interleaving of A[0..i-1] and B[0..j-1]
    memset(IL, 0, sizeof(IL));
    
    for (int i=0; i<=M; ++i) {
        for (int j=0; j<=N; ++j) {
            
            if (i==0 && j==0) //an empty string is interleaving of 2 empty strings
                IL[i][j] = true;    
            else if (i==0 && B[j-1]==C[j-1]) //A is empty
                IL[i][j] = IL[i][j-1];     
            else if (j==0 && A[i-1]==C[i-1]) //B is empty
                IL[i][j] = IL[i-1][j];        
            else if (A[i-1]==C[i+j-1] && B[j-1]!=C[i+j-1]) //curr char of C matches with curr char of A but doesnt match with curr char of B
                IL[i][j] = IL[i-1][j];        
            else if (A[i-1]!=C[i+j-1] && B[j-1]==C[i+j-1]) //curr char of C matches with curr char of B but doesnt match with curr char of A
                IL[i][j] = IL[i][j-1];     
            else if (A[i-1]==C[i+j-1] && B[j-1]==C[i+j-1]) //curr char of C matches with curr char of both A and B
                IL[i][j]=(IL[i-1][j] || IL[i][j-1]) ;
            //else condition is already taken care when we initialize everything to false
        }
    }
 
    return IL[M][N];
}

void test(char *A, char *B, char *C) {
    if (isInterleaved(A, B, C))
        cout<<C<<" is interleaved of "<<A<<" & "<<B<<endl;
    else
        cout<<C<<" is not interleaved of "<<A<<" & "<<B<<endl;
}

int main() {
    test("XXY", "XXZ", "XXZXXXY");
    test("XY" ,"WZ" ,"WZXY");
    test("XY", "X", "XXY");
    test("YX", "X", "XXY");
    test("XXY", "XXZ", "XXXXZY");
    return 0;
}
