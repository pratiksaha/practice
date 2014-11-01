//Find the longest arithmetic progression
#include<iostream>
using namespace std;

void longestAP(int set[], int n) {
    int i, j, k;
    int res = 0; 
    if (n <= 2) {
        res = n;
    } else {
        int L[n][n];
        res = 2;
        for (i=0; i<n; i++)
            L[i][n-1] = 2;
        
        for (j=n-2; j>=1; j--) {
            i = j-1;
            k = j+1;
            while (i >= 0 && k <= n-1) {
                if (set[i] + set[k] < 2*set[j]) {
                    k++;
                } else if (set[i] + set[k] > 2*set[j]) {
                    L[i][j] = 2, i--;
                } else {
                    L[i][j] = L[j][k] + 1;
                    res = max(res, L[i][j]);
                    i--;
                    k++;
                }
            }
            while (i >= 0) {
                L[i][j] = 2;
                i--;
            }
        } 
    }
    cout<<res<<endl;
}

int main() {
    int a[] = {1, 7, 10, 13, 14, 19};
    int b[] = {1, 7, 10, 15, 27, 29};
    int c[] = {2, 4, 6, 8, 10};
    longestAP(a, sizeof(a)/sizeof(a[0]));
    longestAP(b, sizeof(b)/sizeof(b[0]));
    longestAP(c, sizeof(c)/sizeof(c[0]));
    return 0;
}
