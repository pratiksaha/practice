//to find longest contiguous subsequence TODO: print
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<iostream>
#include<unordered_set>
using namespace std;

int longestContiguousSubSequence(int arr[], int n) {
    unordered_set<int> S;
    int ans = 0;
    for (int i=0; i<n; i++)
        S.insert(arr[i]);
    for (int i=0; i<n; i++) {
        if (S.find(arr[i]-1) == S.end()) {
            int j = arr[i];
            while (S.find(j) != S.end())
                j++;
            ans = max(ans, j - arr[i]);
        }
    }
    return ans;
}

int main() {
    int arr[] =  {1, 9, 3, 10, 4, 20, 2};
    cout<<"Length of the Longest contiguous subsequence is "<<longestContiguousSubSequence(arr, sizeof(arr)/sizeof(arr[0]))<<endl;
    return 0;
}
