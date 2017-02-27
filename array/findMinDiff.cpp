//to find minimum difference between any pair in an array
#include<bits/stdc++.h>
using namespace std;
 
// Returns minimum difference between any pair
int findMinDiff(int arr[], int n) {
    sort(arr, arr+n);
    int diff = INT_MAX;
    for (int i=0; i<n-1; i++)
        if (arr[i+1] - arr[i] < diff)
            diff = arr[i+1] - arr[i];
   return diff;
}
 
int main() {
   int arr[] = {1, 5, 3, 19, 18, 25};
   int n = sizeof(arr)/sizeof(arr[0]);
   cout<<"Minimum difference is "<<findMinDiff(arr, n)<<endl;
   return 0;
}
