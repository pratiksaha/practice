//to count number of distinct pairs hat can be formed from all possible contiguous sub-arrays containing distinct numbers
#include <bits/stdc++.h>
using namespace std;
 
int countPairsContiguousSubarrayWithDistinctElements(int arr[], int n) {
    int count = 0;
    int right = 0, left = 0;
    vector<bool> visited(n, false);
    while (right < n) {
        while (right < n && !visited[arr[right]]) {
            count += (right - left);
            visited[arr[right]] = true;
            right++;
        }
        while (left < right && (right != n && visited[arr[right]])) {
            visited[arr[left]] = false;
            left++;
        }
    }
    return count;
}
 
int main() {
    int arr[] = {1, 4, 2, 4, 3, 2};
    int n = sizeof arr / sizeof arr[0];
    cout<<countPairsContiguousSubarrayWithDistinctElements(arr, n)<<endl;
    return 0;
}
