//to find two non-overlapping contiguous sub-arrays such that the absolute difference between the sum of two sub-array is maximum
#include<bits/stdc++.h>
using namespace std;

int maxLeftSubArraySum(int a[], int size, int sum[]) {
    int max_so_far = a[0];
    int curr_max = a[0];
    sum[0] = max_so_far;
    for (int i = 1; i < size; i++) {
        curr_max = max(a[i], curr_max + a[i]);
        max_so_far = max(max_so_far, curr_max);
        sum[i] = max_so_far;
    }
    return max_so_far;
}
 
int maxRightSubArraySum(int a[], int n, int sum[]) {
    int max_so_far = a[n];
    int curr_max = a[n];
    sum[n] = max_so_far;
    for (int i = n-1; i >= 0; i--) {
        curr_max = max(a[i], curr_max + a[i]);
        max_so_far = max(max_so_far, curr_max);
        sum[i] = max_so_far;
    }
    return max_so_far;
}
 
int maxAbsDiffOfSumOfSubarray(int arr[], int n) {
    int leftMax[n];
    maxLeftSubArraySum(arr, n, leftMax);
    int rightMax[n];
    maxRightSubArraySum(arr, n-1, rightMax);
    int invertArr[n];
    for (int i = 0; i < n; i++)
        invertArr[i] = -arr[i];
    int leftMin[n];
    maxLeftSubArraySum(invertArr, n, leftMin);
    for (int i = 0; i < n; i++)
        leftMin[i] = -leftMin[i];
    int rightMin[n];
    maxRightSubArraySum(invertArr, n - 1, rightMin);
    for (int i = 0; i < n; i++)
        rightMin[i] = -rightMin[i];
    int result = INT_MIN;
    for (int i = 0; i < n - 1; i++) {
        int absValue = max(abs(leftMax[i] - rightMin[i + 1]), abs(leftMin[i] - rightMax[i + 1]));
        if (absValue > result)
            result = absValue;
    }
    return result;
}
 
int main() {
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a) / sizeof(a[0]);
    cout<<maxAbsDiffOfSumOfSubarray(a, n)<<endl;
    return 0;
}
