//Z Algorithm to search pattern
#include<bits/stdc++.h>
using namespace std;

void createZarray(string str, int Z[]) {
    int n = str.length();
    int L, R, k;
    L = R = 0; //[L,R] make a window which matches with prefix of s
    Z[0] = 0;
    for (int i=1; i<n; i++) {
        if (i > R) { //calculate using naive way if i>R nothing matches
            L = R = i;
            while (R<n && str[R-L] == str[R]) //checking from 0'th index since R-L = 0 in starting
                R++;
            Z[i] = R-L;
            R--;
        } else {
            k = i-L; //k corresponds to number which matches in [L,R] interval
            if (Z[k] < R-i+1) { //Z[i] == Z[k] if Z[k] is less than remaining interval
                 Z[i] = Z[k];
            } else {
                L = i;
                while (R<n && str[R-L] == str[R]) //else start from R  and check manually
                    R++;
                Z[i] = R-L;
                R--;
            }
        }
    }
}

void searchZAlgorithm(string text, string pattern) {
    cout<<"TEXT : "<<text<<" PATTERN : "<<pattern<<endl;
    string concat = pattern + "$" + text;
    int N = concat.length();
    int P = pattern.length();
    int Z[N];
    createZarray(concat, Z);
    for (int i=0; i<N; i++)
        if (Z[i]==P)
            cout<<"Pattern found at index "<<i-pattern.length()-1<<endl;
}

int main() {
    string text = "pratiksaha";
    string pattern = "tiks";
    searchZAlgorithm(text, pattern);
    return 0;
}
