//to break given array into maximum number of subarrays with equal average
#include<bits/stdc++.h>
using namespace std;

void breakToMaxSubarraysWithEqualAverage(int arr[], int n) {
    vector<int> result;
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    int curr_sum = 0;
    int prev_index = -1;
    for (int i=0; i<n ; i++) {
        curr_sum += arr[i];
        if (sum *(i - prev_index) == curr_sum*n) {
            curr_sum = 0;
            prev_index = i;
            result.push_back(i);
        }
    }
    if (prev_index != n-1) {
        cout<"Not Possible\n";
        return;
    }
    cout<<"(0, "<<result[0]<<")\n";
    for (int i=1; i<result.size(); i++)
        cout<<"("<<result[i-1]+1<<", "<<result[i]<<")\n";
}

int main() {
    int arr[] = {4, 6, 2, 4, 8, 0, 6, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    breakToMaxSubarraysWithEqualAverage(arr, n);
    return 0;
}
