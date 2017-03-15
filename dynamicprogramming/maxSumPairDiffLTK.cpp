//to find maximum pair sum whose difference is less than K
#include <bits/stdc++.h>
using namespace std;

int maxSumPairDiffLTK(int arr[], int N, int k) {
    int maxSum = 0;
    sort(arr, arr+N);
    for (int i=N-1; i>0; i--) {
        if (arr[i]-arr[i-1] < k) {
            maxSum += arr[i];
            maxSum += arr[i-1];
            i--;
        }
    }
    return maxSum;
}

int main() {
    int arr[] = {3, 5, 10, 15, 17, 12, 9};
    int N = sizeof(arr)/sizeof(int);
    int K = 4;
    cout<<maxSumPairDiffLTK(arr, N, K)<<endl;
    return 0;
}
