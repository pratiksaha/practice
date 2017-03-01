//to count number of subarrays with even sum
#include<bits/stdc++.h>
using namespace std;

int countSubarraysWithEvenSum(int arr[], int n) {
    int temp[2] = {1, 0};
    int result = 0, sum = 0;
    for (int i=0; i<=n-1; i++) {
        sum = ( (sum + arr[i]) % 2 + 2) % 2;
        temp[sum]++;
    }
    result = result + (temp[0]*(temp[0]-1)/2);
    result = result + (temp[1]*(temp[1]-1)/2);
    return (result);
}

int main() {
    int arr[] = {1, 2, 2, 3, 4, 1};
    int n = sizeof (arr) / sizeof (arr[0]);
    cout<<"The Number of Subarrays with even sum is "<<countSubarraysWithEvenSum(arr, n)<<endl;
    return (0);
}
