//to find the pair from two sorted arays such that the sum is closest to k
#include<iostream>
#include<climits>
#include<cstdlib>
using namespace std;

void closestSumK(int *a1, int m, int *a2, int n, int k) {
    int diff = INT_MAX;
    int il, ir;
    int l = 0, r = n-1;
    while (l<m && r>=0) {
       if (abs(a1[l] + a2[r] - k) < diff) {
           il = l;
           ir = r;
           diff = abs(a1[l] + a2[r] - k);
       }
       if (a1[l] + a2[r] > k)
           r--;
       else
           l++;
    }
    cout<<"Pair with sum closest to "<<k<<" is ["<<a1[il]<<", "<<a2[ir] << "]\n";
}

int main() {
    int arr1[] = {1, 4, 5, 7};
    int arr2[] = {10, 20, 30, 40};
    int m = sizeof(arr1)/sizeof(arr1[0]);
    int n = sizeof(arr2)/sizeof(arr2[0]);
    int k = 38;
    closestSumK(arr1, m, arr2, n, k);
    return 0;
}
