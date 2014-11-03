//find smallest subarray with sum greater than x
#include <iostream>
using namespace std;

int subArraySumSmallest(int arr[], int n, int x) {
    int curr_sum = 0, min_len = n+1;
    int start = 0, end = 0;
    while (end < n) {
        while (curr_sum <= x && end < n)
            curr_sum += arr[end++];
        while (curr_sum > x && start < n) {
            if (end - start < min_len)
                min_len = end - start;
            curr_sum -= arr[start++];
        }
    }
    return min_len;
}

int main() {
    int x;
    
    int arr1[] = {1, 4, 45, 6, 10, 19};
    x = 51;
    cout<<subArraySumSmallest(arr1, sizeof(arr1)/sizeof(arr1[0]), x)<<endl;
 
    int arr2[] = {1, 10, 5, 2, 7};
    x  = 9;
    cout<<subArraySumSmallest(arr2, sizeof(arr2)/sizeof(arr2[0]), x)<<endl;
 
    int arr3[] = {1, 11, 100, 1, 0, 200, 3, 2, 1, 250};
    x  = 280;
    cout<<subArraySumSmallest(arr3, sizeof(arr3)/sizeof(arr3[0]), x)<<endl;
 
    return 0;
}
