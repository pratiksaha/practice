//to find the maximum sum such that no three are consecutive
#include<bits/stdc++.h>
using namespace std;

int maxSumNo3Cons(int arr[], int n) {
    int sum[n];
    sum[0] = arr[0];
    sum[1] = arr[0] + arr[1];
    sum[2] = max(sum[1], arr[1] + arr[2]);
    for (int i=3; i<n; i++)
        sum[i] = max(max(sum[i-1], sum[i-2] + arr[i]), arr[i] + arr[i-1] + sum[i-3]);
    return sum[n-1];
}

int main() {
    int arr[] = {100, 1000, 100, 1000, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxSumNo3Cons(arr, n)<<endl;
    return 0;
}
