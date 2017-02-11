//to calculate minimum sum of product of two arrays
#include<bits/stdc++.h>
using namespace std;

int minSumOfProductArraysPermutation(int A[], int B[], int n) {
    sort(A, A + n);
    sort(B, B + n);
    int result = 0;
    for (int i = 0; i < n; i++)
        result += (A[i] * B[n - i - 1]);
    return result;
}
 
int main() {
    int A[] = {3, 1, 1};
    int B[] = {6, 5, 4};
    int n = sizeof(A)/sizeof(A[0]);
    cout<<minSumOfProductArraysPermutation(A, B, n)<<endl;
    return 0;
}
