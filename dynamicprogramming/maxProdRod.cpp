//A DP based sol for Max Product Problem
#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

int max3(int a, int b, int c) {
    return max(max(a,b), c);
}

int maxProdRod(int n) {
    int val[n+1];
    val[0] = val[1] = 0;
    for (int i=1; i<=n; i++) {
        int max_val = INT_MIN;
        for (int j=1; j<=i/2; j++)
            max_val = max3(max_val, (i-j)*j, j*val[i-j]);
        val[i] = max_val;
    }
    return val[n];
}

int main() {
    cout <<"Maximum Product is "<<maxProdRod(10)<<endl;
    return 0;
}
