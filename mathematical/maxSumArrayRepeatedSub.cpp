//find the max possible sum of array after repeated subtraction operation
#include<bits/stdc++.h>
using namespace std;
 
int GCD(int a, int b) {
    if (b == 0)
        return a;
    return GCD(b, a % b);
}
 
int maxSumArrayRepeatedSubUtil(int arr[], int n) {
    int finalGCD = arr[0];
    for (int i = 1; i < n; i++)
        finalGCD = GCD(arr[i], finalGCD);
 
    return finalGCD;
}
 
int maxSumArrayRepeatedSub(int arr[], int n) {
    int maxElement = maxSumArrayRepeatedSubUtil(arr, n);
    return (maxElement * n);
}
 
int main() {
    int arr[] = {8, 20, 12, 36};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxSumArrayRepeatedSub(arr, n)<<endl;
    return 0;
}
