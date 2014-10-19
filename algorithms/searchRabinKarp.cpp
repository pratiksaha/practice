//Rabin Karp Algorithm
#include<iostream>
#include<cstring>
using namespace std;
#define MAX 256 //256 ASCII chars
#define PRIME 101 //A prime number
  

void searchRabinKarp(char *txt, char *pat) {
    int N = strlen(txt);
    int M = strlen(pat);

    int i, j;
    
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    
    int h = 1;
    for (i=0; i<M-1; i++)
        h = (h*MAX)%PRIME;
  
    // Calculate the hash value of pattern and first window of text
    for (i = 0; i < M; i++) {
        p = (MAX*p + pat[i])%PRIME;
        t = (MAX*t + txt[i])%PRIME;
    }
     
    for (i = 0; i <= N - M; i++) {// Slide the pattern over text
        if ( p == t ) {//If the hash values match then only check for characters on by one
            for (j=0; j<M; j++)
                if (txt[i+j] != pat[j])
                    break;
            if (j==M)
                cout<<"Pattern found at index "<<i<<endl;
        }    
        if ( i < N-M ) {// Calculate hash value for next window of text
            t = (MAX*(t - txt[i]*h) + txt[i+M])%PRIME;
            if(t < 0) 
              t = (t + PRIME); 
        }
    }
}

int main() {
    char txt[] = "TESTTHISISATEST";
    char pat[] = "TEST";
    searchRabinKarp(txt, pat);
    return 0;
}
