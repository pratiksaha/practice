//Find if there is a subarray with 0 sum
//Using features of C++ Standard (2001) Compile using g++ -std=c++11
#include<iostream>
#include<climits>
#include<algorithm>
#include<unordered_map>
using namespace std;

void zeroSumSubarray(int arr[], int n) {
    unordered_map<int, int> hash;
    int sum = 0;       
    for (int i=0; i<n; i++) {  
        sum += arr[i];
        if (arr[i] == 0) {
            cout<<"("<<i<<","<<i<<")\n";
        } else if (sum == 0) {
            cout<<"(0,"<<i<<")\n";
        } else if (hash.find(sum) != hash.end()) {                          
            cout<<"("<<hash[sum]+1<<","<<i<<")\n";
        } else {
            hash.insert(make_pair(sum, i));
        }
   }
}

int main() {
    int arr[] = {4, 2, -3, 1, 6};
    zeroSumSubarray(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}
