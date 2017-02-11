//print all permutations of a given string
#include<bits/stdc++.h>
using namespace std;

int fact(int n) {
    return (n==1)? 1 : n*fact(n-1);
}

void allPermutationsIterative(string s) {
    int n = s.length();
    int fc = fact(n);
    int j = 1;
    int m = 0;
    for (int perm_c = 0; perm_c < fc; ) {
        string perm = s;
        int k = 0;
        while (k != fc/n) {
            while (j != n-1) {
                cout<<perm<<endl;
                swap(perm[j], perm[j+1]);
                k++;
                perm_c++;
                j++;
            }
            j = 1;
        }
        m++;
        if (m == n)
            break;
        swap(s[0], s[m]);
    }
}

int main() {
    string s = "ABC";
    allPermutationsIterative(s);
    return 0;
}
