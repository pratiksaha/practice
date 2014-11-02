//Fil a matrix with alternating O's and X's
#include <iostream>
using namespace std;

void fillOX(int m, int n) {
    int i, j, k = 0, l = 0;
    int r = m, c = n;
    char a[m][n];
    
    char key = 'X';
    while (k < m && l < n) {//use the approach to print a matrix spirally
        for (i=l; i<n; i++)
            a[k][i] = key;
        k++;
        for (i=k; i<m; i++)
            a[i][n-1] = key;
        n--;
        if (k<m) {
            for (i=n-1; i>=l; i--)
                a[m-1][i] = key;
            m--;
        }
        if (l<n) {
            for (i=m-1; i>=k; i--)
                a[i][l] = key;
            l++;
        }
        key = (key=='O')?'X':'O'; //flip character for next iteration
    }
 
    for (i=0; i<r; i++) {
        for (j=0; j<c; j++) {
            cout<<" "<<a[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}

int main() {
    cout<<"Output for m = 5, n = 6 :\n";
    fillOX(5, 6);
    cout<<"Output for m = 4, n = 4 :\n";
    fillOX(4, 4);
    cout<<"Output for m = 3, n = 4 :\n";
    fillOX(3, 4);
    cout<<"Output for m = 9, n = 13 :\n";
    fillOX(6, 17);
    return 0;
}
