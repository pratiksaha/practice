//to get sum of average of all subsets
#include<bits/stdc++.h>
using namespace std;

int nCr(int n, int k) {
    int C[n+1][k+1];
    int i, j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= min(i, k); j++) {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
    return C[n][k];
}
 
double sumOfAvgOfSubsets(int arr[], int N) {
    double result = 0.0;
    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += arr[i];
    for (int n = 1; n <= N; n++)
        result += (double)(sum * (nCr(N - 1, n - 1))) / n;
    return result;
}
 
int main() {
    int arr[] = {2, 3, 5, 7};
    int N = sizeof(arr) / sizeof(int);
    cout<<sumOfAvgOfSubsets(arr, N)<<endl;
    return 0;
}
