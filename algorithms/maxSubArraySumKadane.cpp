//to find the max sum contiguous subarray using kadane's algorithm
#include<iostream>
#include<cstdlib>
using namespace std;

int kadane(int a[], int n) {
    int max_so_far = a[0];
    int curr_max = a[0];
    for (int i=1; i<n; i++) {
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
    }
    return max_so_far;
}

int main() {
    int a1[] = {2, 3, 4, 1, 2, 1, 5, 3};
    int a2[] = {-2, -3, -4, -1, -2, -1, -5, -3};
    int a3[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout<<"Maximum contiguous sum is "<<kadane(a1, sizeof(a1)/sizeof(a1[0]))<<endl;
    cout<<"Maximum contiguous sum is "<<kadane(a2, sizeof(a2)/sizeof(a2[0]))<<endl;
    cout<<"Maximum contiguous sum is "<<kadane(a3, sizeof(a3)/sizeof(a3[0]))<<endl;
    return 0;
}
