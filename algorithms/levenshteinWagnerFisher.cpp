//Wagner Fisher Algorithm for Levenshtein Distance
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int min3(int a, int b, int c) {
    return min(min(a, b), c);
}

int levenshteinWagnerFisher(string X, string Y) {
    int i, j;
    
    int m = X.size();
    int n = Y.size();
    int LD[m+1][n+1];
    for(i=0; i<=m; i++)
        for(j=0; j<=n; j++)
            LD[i][j] = 0;

    for(i=1; i<=m; i++)
        LD[i][0] = i;
    for(j=1; j<=n; j++)
        LD[0][j] = j;

    for(i=1; i<=m; i++) {
        for(j=1; j<=n; j++) {
            if(X[i] == Y[j] ){
                LD[i][j] = LD[i-1][j-1];
            } else {
                LD[i][j]= min3(LD[i-1][j]+1, LD[i][j-1]+1, LD[i-1][j-1]+1);
            }
        }
    }

    return LD[m][n];    
}

 
int main() {
    string A = "SATURDAY";
    string B = "SUNDAY";
    cout<<"Levenshtein distance between "<<A<<" & "<<B<<" is "<<levenshteinWagnerFisher(A, B)<<endl;
    return 0;
}
