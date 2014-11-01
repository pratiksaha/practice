// A DP based solution for Word Wrap Problem
#include<iostream>
#include<climits>
using namespace std;
 
int printSolution (int p[], int n) {
    int k;
    if (p[n] == 1)
        k = 1;
    else
        k = printSolution (p, p[n]-1) + 1;
    cout<<"Line number "<<k<<": From word no "<<p[n]<<" to "<<n<<endl;
    return k;
}

void solveWordWrap (int l[], int n, int width) {
    int extras[n+1][n+1]; //extras[i][j] = no of extra spaces if words from i to j are put in a single line
    int lc[n+1][n+1]; //lc[i][j] = cost of a line which has words from i to j
    int c[n+1]; //c[i] = total cost of optimal arrangement of words from 1 to i
    int p[n+1]; //used to print the solution
 
    int i, j;
 
    for (i=1; i<=n; i++) {
        extras[i][i] = width-l[i-1];
        for (j=i+1; j <= n; j++)
            extras[i][j] = extras[i][j-1]-l[j-1]-1;
    }

    for (i=1; i<=n; i++) {
        for (j=i; j<=n; j++) {
            if (extras[i][j] < 0)
                lc[i][j] = INT_MAX;
            else if (j==n && extras[i][j]>=0)
                lc[i][j] = 0;
            else
                lc[i][j] = extras[i][j]*extras[i][j];
        }
    }

    c[0] = 0;
    for (j=1; j<=n; j++) { //calculate min cost and find min cost arrangement
        c[j] = INT_MAX;
        for (i=1; i<=j; i++) {
            if (c[i-1]!=INT_MAX && lc[i][j]!=INT_MAX && (c[i-1]+lc[i][j]<c[j]) ) {
                c[j] = c[i-1] + lc[i][j];
                p[j] = i;
            }
        }
    }
    printSolution(p, n);
}

int main() {
    int l[] = {3, 2, 2, 5};
    int width = 6;
    solveWordWrap (l, sizeof(l)/sizeof(l[0]), width);
    return 0;
}
