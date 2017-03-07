//to find minimum number of deletes required to make all elements same
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<bits/stdc++.h>
using namespace std;

int minDeleteToSameElements(int arr[],int n) {
    unordered_map<int, int> freq;
    for (int i=0; i<n; i++)
        freq[arr[i]]++;
    int max_freq = INT_MIN;
    for (auto itr = freq.begin(); itr != freq.end(); itr++)
        max_freq = max(max_freq, itr->second);
    return n - max_freq;
}

int main() {
    int arr[] = {4, 3, 4, 4, 2, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<minDeleteToSameElements(arr, n)<<endl;
    return 0;
}
