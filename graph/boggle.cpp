//boggle
#include<iostream>
#include<cstring>
using namespace std;
#define M 3
#define N 3

string dictionary[] = {"TEST", "IT", "QUIZ", "TO", "KITE"};
int n = sizeof(dictionary)/sizeof(dictionary[0]);

bool isWord(string &str) {
    for (int i=0; i<n; i++)
        if (str.compare(dictionary[i]) == 0)
            return true;
    return false;
}

void boggleUtil(char mat[M][N], bool visited[M][N], int i, int j, string &str) {
    visited[i][j] = true;
    str = str + mat[i][j];
    if (isWord(str))
        cout<<str<<endl;
    for (int row=i-1; row<=i+1 && row<M; row++)
        for (int col=j-1; col<=j+1 && col<N; col++)
            if (row>=0 && col>=0 && !visited[row][col])
                boggleUtil(mat,visited, row, col, str);
    str.erase(str.length()-1);
    visited[i][j] = false;
}

void boggle(char mat[M][N]) {
    bool visited[M][N] = {{false}};
    string str = "";
    for (int i=0; i<M; i++)
        for (int j=0; j<N; j++)
            boggleUtil(mat, visited, i, j, str);
}

int main() {
    char mat[M][N] = {  {'T','I','Z'},
                        {'U','E','K'},
                        {'Q','S','T'}
                     };
    cout<<"Following words of dictionary are present\n";
    boggle(mat);
    return 0;
}
