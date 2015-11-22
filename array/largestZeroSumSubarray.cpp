//to find the length of largest subarray with 0 sum
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<iostream>
#include<unordered_map>
using namespace std;

int largestZeroSumSubarray(int arr[], int n) {
    unordered_map<int, int> presum;
    int sum = 0;
    int max_len = 0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
        if (arr[i]==0 && max_len==0)
            max_len = 1;
        if (sum == 0)
            max_len = i+1;
        if (presum.find(sum) != presum.end())
            max_len = max(max_len, i-presum[sum]);
        else
            presum[sum] = i;
    }
    return max_len;
}
 
// Driver Program to test above function
int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    cout<<"Length of the longest 0 sum subarray is "<<largestZeroSumSubarray(arr, sizeof(arr)/sizeof(arr[0]))<<endl;
    return 0;
}
