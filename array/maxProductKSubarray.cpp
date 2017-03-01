//to find the maximum product of a subarray of size k
#include <bits/stdc++.h>
using namespace std;

int maxProductKSubarray(int arr[], int n, int k) {
    int maxproduct = 1;
    for (int i=0; i<k; i++)
        maxproduct *= arr[i];
    int prev_product = maxproduct;
    for (int i=1; i<=n-k; i++) {
        int curr_product = (prev_product/arr[i-1]) * arr[i+k-1];
        maxproduct = max(maxproduct, curr_product);
        maxproduct = curr_product;
    }
    return maxproduct;
}

int main() {
    int arr1[] = {1, 5, 9, 8, 2, 4, 1, 8, 1, 2};
    int k = 6;
    int n = sizeof(arr1)/sizeof(arr1[0]);
    cout<<maxProductKSubarray(arr1, n, k)<<endl;
    k = 4;
    cout<<maxProductKSubarray(arr1, n, k)<<endl;
    int arr2[] = {2, 5, 8, 1, 1, 3};
    k = 3;
    n = sizeof(arr2)/sizeof(arr2[0]);
    cout<<maxProductKSubarray(arr2, n, k)<<endl;
    return 0;
}
