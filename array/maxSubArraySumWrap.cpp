//find max contiguous circular sum subarray
#include<iostream>
using namespace std;

int kadane(int a[], int n) {
    int max_so_far = 0;
    int max_ending_here = 0;
    for(int i=0; i<n; i++) {
        max_ending_here = max_ending_here + a[i];
        if(max_ending_here < 0)
            max_ending_here = 0;
        if(max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }
    return max_so_far;
}

int maxSubArraySumWrap(int a[], int n) {
    int max_no_wrap = kadane(a, n);
    int max_wrap = 0;
    for(int i=0; i<n; i++) {
        max_wrap += a[i];
        a[i] = -a[i];
    }
    max_wrap = max_wrap + kadane(a, n);
    for(int i=0; i<n; i++)//regenerate array
        a[i] = -a[i];
   return (max_wrap > max_no_wrap)? max_wrap: max_no_wrap;
}

int main() {
    int a[] =  {11, 10, -20, 5, -3, -5, 8, -13, 10};
    cout<<"Maximum circular sum is "<<maxSubArraySumWrap(a, sizeof(a)/sizeof(a[0]))<<endl;
    return 0;
}
