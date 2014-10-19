//KMP search algorithm
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
 
void computeLPSArray(char *pat, int M, int *lps) {
    int len = 0;  // length of the previous longest prefix suffix
    int i;
 
    lps[0] = 0; // lps[0] is always 0
    i = 1;
    while(i < M) {
        if(pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if( len != 0 ) {
                len = lps[len-1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}
 
void searchKnuthMorrisPratt(char *txt, char *pat) { 
    int N = strlen(txt);
    int M = strlen(pat);
 
    
    int i = 0;  // index for txt[]
    int j  = 0;  // index for pat[]
    
    int *lps = (int *)malloc(sizeof(int)*M); //the longest prefix suffix values for pattern
    computeLPSArray(pat, M, lps); //preprocessing
 
    while(i < N) {
        if(pat[j] == txt[i]) {
            j++;
            i++;
        }
        if (j == M) {
            cout<<"Pattern found at index "<<i-j<<endl;
            j = lps[j-1];
        } else if(pat[j] != txt[i]) {//mismatch after j matches, do not match lps[0..lps[j-1]] characters, they will match anyway
            if(j != 0)
                j = lps[j-1];
            else
                i++;
        }
    }
    free(lps);
}
 


int main() {
   char txt[] = "ABABDABACDABABCABAB";
   char pat[] = "ABABCABAB";
   searchKnuthMorrisPratt(txt, pat);
   return 0;
}
