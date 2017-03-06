//to find maximum value (arr[i]-i) - (arr[j]-j) in an array
#include<bits/stdc++.h>
using namespace std;

int maxDiffElemIndexDiffPair(int arr[], int n) {
    if (n < 2) {
        return INT_MIN;
    } else {
        int min_val = INT_MAX, max_val = INT_MIN;
        for (int i=0; i<n; i++) {
            if ((arr[i]-i) > max_val)
                max_val = arr[i] - i;
            if ((arr[i]-i) < min_val)
                min_val = arr[i]-i;
        }
        return (max_val - min_val);
    }
}

int main() {
    int arr[] = {9, 15, 4, 12, 13};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxDiffElemIndexDiffPair(arr, n)<<endl;
    return 0;
}
