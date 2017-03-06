//to divide the array into two subarrays with the same sum on removing exactly one integer from the array
#include<bits/stdc++.h>
using namespace std;

void printSubArray(int arr[], int start, int end) {
    cout<<" [";
    for (int i = start; i <= end; i++)
        cout<<" "<<arr[i];
    cout<<" ] ";
}

bool divideArrayEqualSum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    int sum_so_far = 0;
    for (int i = 0; i < n; i++) {
        if (2 * sum_so_far + arr[i] == sum) {
            cout<<"The array can be divided into two subarrays with equal sum\nThe two subarrays are - ";
            printSubArray(arr, 0, i - 1);
            printSubArray(arr, i + 1, n - 1);
            cout<<endl;
            return true;
        }
        sum_so_far += arr[i];
    }
    cout<<"The array cannot be divided into two subarrays with equal sum\n";
    return false;
}

int main() {
    int arr[] = {6, 2, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    divideArrayEqualSum(arr, n);
    return 0;
}
