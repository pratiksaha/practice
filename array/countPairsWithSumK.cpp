//to find count of pairs with given sum
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include <bits/stdc++.h>
using namespace std;
 
int countPairsWithSumK(int arr[], int n, int sum) {
    unordered_map<int, int> m;
    for (int i=0; i<n; i++)
        m[arr[i]]++;
    int twice_count = 0;
    for (int i=0; i<n; i++) {
        twice_count += m[sum-arr[i]];
        if (sum-arr[i] == arr[i])
            twice_count--;
    }
    return twice_count/2;
}
 
// Driver function to test the above function
int main() {
    int arr[] = {1, 5, 7, -1, 5} ;
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 6;
    cout<<"Count of pairs with sum = "<<k<<" is "<<countPairsWithSumK(arr, n, k)<<endl;
    return 0;
}
