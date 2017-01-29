//to find maximum xor value of subarray of size k
#include<bits/stdc++.h>
using namespace std;

int maxXORkSubarray(int arr[] , int n , int k) {
    int current_xor = 0 ;
    for (int i=0; i<k; i++)
        current_xor  = current_xor ^ arr[i];
    int max_xor = current_xor;
    for (int i=k; i<n; i++) {
        current_xor = current_xor ^ arr[i-k];
        current_xor = current_xor ^ arr[i];
        max_xor = max(max_xor, current_xor);
    }
    return max_xor;
}

int main() {
    int arr[] = {2, 5, 8 ,1 , 1 ,3} ;
    int k = 3;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Maximum XOR value of k subarray : "<<maxXORkSubarray(arr, n, k)<<endl;
    return 0;
}
