//to find sum of matrix in which each element is absolute difference of its corresponding row and column number
#include<bits/stdc++.h>
using namespace std;
 
int findSumMatrixAbsDiffRowColNos(int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += i*(n-i);
    return 2*sum;
}

int findSumMatrixAbsDiffRowColNosOpt(int n) {
    n--;
    int sum = 0;
    sum += (n*(n+1))/2;
    sum += (n*(n+1)*(2*n + 1))/6;
    return sum;
}
 
int main() {
    int n = 3;
    cout<<findSumMatrixAbsDiffRowColNos(n)<<endl;
    cout<<findSumMatrixAbsDiffRowColNosOpt(n)<<endl;
    return 0;
}
