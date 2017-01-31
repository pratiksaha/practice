//query matrix
#include<bits/stdc++.h>
using namespace std;

void preprocessMatrix(int rows[], int cols[], int m, int n) {
    for (int i=0; i<m; i++)
        rows[i] = i;
    for (int i=0; i<n; i++)
        cols[i] = i;
}

void queryMatrix(int rows[], int cols[], int m, int n, char ch, int x, int y) {
    int tmp;
    switch(ch) {
        case 'R':
            swap(rows[x-1], rows[y-1]);
            break;
        case 'C':
            swap(cols[x-1], cols[y-1]);
            break;
        case 'P':
            cout<<"value at ("<<x<<","<<y<<") is "<<rows[x-1]*n + cols[y-1]+1<<endl;
            break;
    }
    return ;
}

int main() {
    int m = 1234, n = 5678;
    int rows[m], cols[n];
    preprocessMatrix(rows, cols, m, n);
    queryMatrix(rows, cols, m, n, 'R', 1, 2);
    queryMatrix(rows, cols, m, n, 'P', 1, 1);
    queryMatrix(rows, cols, m, n, 'P', 2, 1);
    queryMatrix(rows, cols, m, n, 'C', 1, 2);
    queryMatrix(rows, cols, m, n, 'P', 1, 1);
    queryMatrix(rows, cols, m, n, 'P', 2, 1);
    return 0;
}
