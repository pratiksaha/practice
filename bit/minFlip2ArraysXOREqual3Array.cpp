//to find minimum flips required to make XOR of two arrays equal to another array with constraints on number of flip on each array
#include<bits/stdc++.h>
using namespace std;

int minFlip2ArraysXOREqual3Array(int arr1[], int arr2[], int arr3[], int p, int q, int n) {
    int flip = 0;
    for (int i = 0; i < n; i++)
        if (arr1[i] ^ arr2[i] != arr3[i])
            flip++;
    return (flip <= p + q)? flip : -1;
}
 
int main() {
    int arr1[] = { 1, 0, 1, 1, 1, 1, 1 };
    int arr2[] = { 0, 1, 1, 1, 1, 0, 0 };
    int arr3[] = { 1, 1, 1, 1, 0, 0, 1 };
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int p = 2, q = 4;
    cout<<"Minimum flips required = "<<minFlip2ArraysXOREqual3Array(arr1, arr2, arr3, p, q, n)<<endl;
    return 0;
}
