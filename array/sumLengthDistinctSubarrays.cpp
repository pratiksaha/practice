//to calculate sum of lengths of subarrays of distinct elements
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<bits/stdc++.h>
using namespace std;

int sumLengthDistinctSubarrays(int arr[], int n) {
    unordered_set<int> s;
    int j = 0, ans = 0;
    for (int i=0; i<n; i++) {
        while (j < n && s.find(arr[j]) == s.end()) {
            s.insert(arr[j]);
            j++;
        }
        ans += ((j - i) * (j - i + 1))/2;
        s.erase(arr[i]);
    }
    return ans;
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<sumLengthDistinctSubarrays(arr, n)<<endl;
    return 0;
}
