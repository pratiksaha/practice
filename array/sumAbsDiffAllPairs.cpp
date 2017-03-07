//to find sum of absolute differences in all pairs in a sorted array of distinct numbers
#include<bits/stdc++.h>
using namespace std;

int sumAbsDiffAllPairs(int arr[],int n) {
    int sum = 0;
    for (int i=n-1; i>=0; i--)
        sum += i*arr[i] - (n-1-i)*arr[i];
    return sum;
}

int main() {
    int arr[] = {1, 8, 9, 15, 16};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<sumAbsDiffAllPairs(arr, n)<<endl;
    return 0;
}
