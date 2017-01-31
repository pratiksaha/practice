//to find orientation of a pattern
#include<bits/stdc++.h>
using namespace std;
#define N 5

void computeLPSArray(char *pat, int M, int *lps) {
    int len = 0;
    int i = 1;
    lps[0] = 0;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i++] = len;
        } else {
            if (len != 0)
                len = lps[len-1];
            else
                lps[i++] = 0;
        }
    }
}
 
int KMPSearch(char *pat, char *txt) {
    int M = strlen(pat);
    int *lps = (int *)malloc(sizeof(int)*M);
    int j = 0;
    computeLPSArray(pat, M, lps);
    int i = 0;
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
        if (j == M) {
            return 1;
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }
    }
    free(lps);
    return 0;
}

string patternOrientation(char mat[][N], char *pat) {
    char *col = (char*) malloc(N);
    for (int i=0; i<N; i++) {
        if (KMPSearch(pat, mat[i])) {
            free(col);
            return "horizontal";
        }
        for (int j = 0; j < N; j++)
            col[j] = *(mat[j] + i);
        if (KMPSearch(pat, col)) {
            free(col);
            return "vertical";
        }
    }
    free(col);
    return "not found";
}

int main() {
    char mat[N][N] = {
        {'a', 'b', 'c', 'd', 'e'},
        {'f', 'g', 'h', 'i', 'j'},
        {'k', 'l', 'm', 'n', 'o'},
        {'p', 'q', 'r', 's', 't'},
        {'u', 'v', 'w', 'x', 'y'}
 
    };
    char pat1[] = "pqrs";
    char pat2[] = "hmrw";
    char pat3[] = "gmdn";
    cout<<"Pattern "<<pat1<<" is "<<patternOrientation(mat, pat1)<<" in the matrix\n";
    cout<<"Pattern "<<pat2<<" is "<<patternOrientation(mat, pat2)<<" in the matrix\n";
    cout<<"Pattern "<<pat3<<" is "<<patternOrientation(mat, pat3)<<" in the matrix\n";
    return 0;
}
