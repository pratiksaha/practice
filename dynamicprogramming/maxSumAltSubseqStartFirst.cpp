//to find sum of maximum sum alternating sequence starting with first element
#include<bits/stdc++.h>
using namespace std;

int maxSumAltSubseqStartFirst(int arr[], int n) {
    if (n == 1)
        return arr[0];
    int dec[n];
    memset(dec, 0, sizeof(dec));
    int inc[n];
    memset(inc, 0, sizeof(inc));
    dec[0] = inc[0] = arr[0];
    int flag = 0 ;
    for (int i=1; i<n; i++) {
        for (int j=0; j<i; j++) {
            if (arr[j] > arr[i]) {
                dec[i] = max(dec[i], inc[j]+arr[i]);
                flag = 1;
            } else if (arr[j] < arr[i] && flag == 1) {
                inc[i] = max(inc[i], dec[j]+arr[i]);
            }
        }
    }
    int result = INT_MIN;
    for (int i=0; i<n; i++) {
        if (result < inc[i])
            result = inc[i];
        if (result < dec[i])
            result = dec[i];
    }
    return result;
}

int main() {
    int arr[]= {8, 2, 3, 5, 7, 9, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxSumAltSubseqStartFirst(arr, n)<<endl;
    return 0;
}
