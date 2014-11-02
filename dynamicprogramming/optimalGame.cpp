//Find max value obtianable from a given sequence of coins
#include<iostream>
#include<climits>
using namespace std;

void optimalStrategyOfGame(int arr[], int n) {
    int table[n][n], gap, i, j, x, y, z;
 
    for (gap=0; gap<n; gap++) {
        for (i=0, j=gap; j<n; i++, j++) {
            x = ((i+2)<=j)?table[i+2][j]:0;
            y = ((i+1)<=(j-1))?table[i+1][j-1]:0;
            z = (i<=(j-2))?table[i][j-2]:0;
            table[i][j] = max(arr[i] + min(x, y), arr[j] + min(y, z));
        }
    }
 
    cout<<table[0][n-1]<<endl;
}
 
int main() {
    int a[] = {8, 15, 3, 7};
    optimalStrategyOfGame(a, sizeof(a)/sizeof(a[0]));
    int b[] = {2, 2, 2, 2};
    optimalStrategyOfGame(b, sizeof(b)/sizeof(b[0]));
    int c[] = {20, 30, 2, 2, 2, 10};
    optimalStrategyOfGame(c, sizeof(c)/sizeof(c[0])); 
    return 0;
}
