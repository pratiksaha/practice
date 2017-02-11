//to find sum of product of x and y such that floor(n/x) = y
#include<bits/stdc++.h>
using namespace std;
 
int sumOfRange(int a, int b) {
    int i = (a * (a+1)) >> 1;
    int j = (b * (b+1)) >> 1;
    return (i - j);
}
 
int sumOfProductxyFloornxy(int n) {
    int sum = 0;
    int root = sqrt(n);
    for (int i=1; i<=root; i++) {
        int up = n/i;
        int low = max(n/(i+1), root);
        sum += (i * sumOfRange(up, low));
        sum += (i * (n/i));
    }
    return sum;
}
 
int main() {
    int n = 10;
    cout<<sumOfProductxyFloornxy(n)<<endl;
    return 0;
}
