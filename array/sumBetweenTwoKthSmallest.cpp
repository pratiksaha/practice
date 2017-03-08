//to find sum of all element between K1'th and k2'th smallest elements in array
#include<bits/stdc++.h>
using namespace std;

int sumBetweenTwoKthSmallest(int arr[], int n, int k1, int k2) {
    sort(arr, arr+n);
    return accumulate(arr+k1, arr+k2-1, 0);
}

int main() {
    int arr[] = { 20, 8, 22, 4, 12, 10, 14 } ;
    int  k1 = 3 , k2 = 6 ;
    int n =  sizeof(arr)/sizeof(arr[0]);
    cout<<sumBetweenTwoKthSmallest(arr, n, k1, k2)<<endl;
    return 0;
}
