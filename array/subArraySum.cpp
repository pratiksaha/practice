//Given an unsorted array of nonnegative integers, find a continous subarray which adds to a given number
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<bits/stdc++.h>
using namespace std;

void subArraySum(int arr[], int n, int sum) {
    int curr_sum = arr[0], start = 0, i;
 
    for (i=1; i<=n; i++) {
        while (curr_sum>sum && start<(i-1) ) {//if curr_sum exceeds the sum, then remove the starting elements
            curr_sum = curr_sum - arr[start];
            start++;
        }
        if (curr_sum == sum) { //if curr_sum becomes equal to sum
            cout<<"Sum found between indexes "<<start<<" & "<<i-1<<endl;
            return ;
        }
        if (i < n)
          curr_sum = curr_sum + arr[i];
    }
    cout<<"No subarray found\n"; //no subarray
}

void subArraySumNeg(int arr[], int n, int sum) {
    unordered_map<int, int> map;
    int curr_sum = 0;
    for (int i = 0; i < n; i++) {
        curr_sum = curr_sum + arr[i];
        if (curr_sum == sum){
            cout<<"Sum found between indexes 0 to "<<i<<endl;
            return;
        }
        if (map.find(curr_sum - sum) != map.end()) {
            cout<<"Sum found between indexes "<<map[curr_sum - sum] + 1<<" to "<<i<<endl;
            return;
        }
        map[curr_sum] = i;
    }
    cout<<"No subarray with given sum exists\n";
}

int main() {
    int arr1[] = {15, 2, 4, 8, 9, 5, 10, 23};
    int sum1 = 23;
    subArraySum(arr1, sizeof(arr1)/sizeof(arr1[0]), sum1);
    int arr2[] = {10, 2, -2, -20, 10};
    int sum2 = -10;
    subArraySumNeg(arr2, sizeof(arr2)/sizeof(arr2[0]), sum2);
    return 0;
}
