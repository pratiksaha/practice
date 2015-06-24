//to find the smallest no  that cannot be represented as sum of subsets of a given sorted array
#include<iostream>
using namespace std;

int smallestNonSubsetSum(int arr[], int n) {
    int res = 1;
    for (int i=0; i<n && arr[i]<=res; i++)
        res += arr[i];
    return res;
}

int main() {
    int arr1[] = {1, 3, 4, 5};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    cout<<smallestNonSubsetSum(arr1, n1)<<endl;
    int arr2[] = {1, 2, 6, 10, 11, 15};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    cout<<smallestNonSubsetSum(arr2, n2)<<endl;
    int arr3[] = {1, 1, 1, 1};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    cout<<smallestNonSubsetSum(arr3, n3)<<endl;
    int arr4[] = {1, 1, 3, 4};
    int n4 = sizeof(arr4)/sizeof(arr4[0]);
    cout<<smallestNonSubsetSum(arr4, n4)<<endl;
    return 0;
}
