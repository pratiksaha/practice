//to find sum of maximum of all subsets of array
#include<bits/stdc++.h>
using namespace std;
 
int sumOfMaxOfSubsets(int arr[], int N) {
    sort(arr, arr + N, greater<int>());
    int sum = arr[0];
    for (int i = 1; i < N; i++)
        sum = 2 * sum + arr[i];
    return sum;
}
 
int main() {
    int arr[] = {3, 2, 5};
    int N = sizeof(arr) / sizeof(arr[0]);
    cout<<sumOfMaxOfSubsets(arr, N)<<endl;
    return 0;
}
