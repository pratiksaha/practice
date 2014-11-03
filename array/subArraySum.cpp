//Given an unsorted array of nonnegative integers, find a continous subarray which adds to a given number
#include<iostream>
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

int main() {
    int arr[] = {15, 2, 4, 8, 9, 5, 10, 23};
    int sum = 23;
    subArraySum(arr, sizeof(arr)/sizeof(arr[0]), sum);
    return 0;
}
