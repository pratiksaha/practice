//to print all possible sentences from a list of word list
#include <iostream>
#include <string>
using namespace std;
#define R 3
#define C 3

void printSentences(string arr[R][C], int m, int n, string output[R]) {
    output[m] = arr[m][n];
    if (m==R-1) {
        for (int i=0; i<R; i++)
            cout<<output[i]<<" ";
        cout<<endl;
        return;
    }
    for (int i=0; i<C; i++)
        if (arr[m+1][i] != "")
            printSentences(arr, m+1, i, output);
}

void printSentences(string arr[R][C]) {
    string output[R];
    for (int i=0; i<C; i++)
        if (arr[0][i] != "")
            printSentences(arr, 0, i, output);
}

int main() {
    string arr[R][C] = {{"you", "we"},
                        {"have", "are"},
                        {"sleep", "eat", "drink"}};
    printSentences(arr);
    return 0;
}
