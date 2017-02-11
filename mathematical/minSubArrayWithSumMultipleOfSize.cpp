//to find min subarray whose sum is multiple of size
#include<bits/stdc++.h>
using namespace std;

void minSubArrayWithSumMultipleOfSize(int arr[], int N) {
    int modIdx[N]; 
    for (int i = 0; i < N; i++)
        modIdx[i] = -1;
    int minLen = N + 1;
    int curLen = N + 1;
    int sum = 0;
    int l, r;
    for (int i = 0; i < N; i++) {
        sum += arr[i];
        sum %= N;
        if (modIdx[sum] == -1 && sum == 0)
            curLen = i + 1;
        if (modIdx[sum] != -1)
            curLen = i - modIdx[sum];
        if (curLen < minLen) {
            minLen = curLen;
            l = modIdx[sum] + 1;
            r = i;
        }
        modIdx[sum] = i;
    }
    for (int i = l; i <= r; i++)
        cout<<" "<<arr[i];
    cout<<endl;
}

int main() {
    int arr[] = {1, 1, 2, 2, 4, 2};
    int N = sizeof(arr) / sizeof(int);
    minSubArrayWithSumMultipleOfSize(arr, N);
    return 0;
}
