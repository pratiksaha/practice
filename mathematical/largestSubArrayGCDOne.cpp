//to find length of the largest subarray with GCD one
#include<bits/stdc++.h>
using namespace std;
 
int largestSubArrayGCDOne(int arr[], int n) {
    int gcd = arr[0];
    for (int i=1; i<n; i++)
        gcd = __gcd(gcd, arr[i]);
    return (gcd == 1)? n : -1;
}
 
int main() {
    int arr[] = {1, 3, 5, 7};
    int n = sizeof(arr)/sizeof(int);
    cout<<"Length of the largest subarray with GCD 1 is "<<largestSubArrayGCDOne(arr, n)<<endl;
    return 0;
}
