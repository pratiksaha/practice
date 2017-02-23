//to find sum of product of all subsets
#include<bits/stdc++.h>
using namespace std;
 
int sumOfProductOfSubsets(int arr[], int n) {
    int ans = 1;
    for (int i = 0; i < n; ++i )
        ans = ans * (arr[i] + 1);
    return ans-1;
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr)/sizeof arr[0];
    cout<<sumOfProductOfSubsets(arr, n)<<endl;
    return 0;
}
