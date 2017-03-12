//to find the kth smallest element after removing some integer from first n natural number
#include<bits/stdc++.h>
using namespace std;

int kSmallestRemovingInteger(int arr[], int n, int k) {
    sort(arr, arr+n);
    if (k < arr[0])
        return k;
    if (k == arr[0])
        return arr[0] + 1;
    if (k > arr[n-1])
        return k + n;
    if (arr[0] == 1)
        k--;
    else
        k -= (arr[0] - 1);
    for (int i=1; i<n; i++) {
        int c = arr[i] - arr[i-1] - 1;
        if (k <= c)
            return arr[i-1] + k;
        else
            k -= c;
    }
    return arr[n-1] + k;
}

int main() {
    int k = 1;
    int arr[] = { 1 };
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<kSmallestRemovingInteger(arr, n, k)<<endl;
    return 0;
}
