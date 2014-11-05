//find the product of the maximum product subarray
#include<iostream>
#include<algorithm>
using namespace std;

int maxSubarrayProduct(int arr[], int n) {
    int max_ending_here = 1;
    int min_ending_here = 1;
    int max_so_far = 1; 
    for (int i=0; i<n; i++) { 
        if (arr[i] == 0) { //if curr is 0, then the maximum product cannot end here
            max_ending_here = 1;
            min_ending_here = 1;
        } else if (arr[i] > 0) { //if curr is +ve, update max_ending_here
            max_ending_here = max_ending_here*arr[i];
            min_ending_here = min(min_ending_here*arr[i], 1);
        } else {//if curr is -ve, max_ending_here can either be 1 or +ve, min_ending_here can either be 1 or -ve
            int temp = max_ending_here;
            max_ending_here = max(min_ending_here*arr[i], 1);
            min_ending_here = temp*arr[i];
        }
        if (max_so_far< max_ending_here)
            max_so_far = max_ending_here;
    }
    return max_so_far;
}

int main() {
    int arr[] = {1, -2, -3, 0, 7, -8, -2};
    cout<<"Maximum Sub Array Product is "<<maxSubarrayProduct(arr, sizeof(arr)/sizeof(arr[0]))<<endl;;
    return 0;
}
