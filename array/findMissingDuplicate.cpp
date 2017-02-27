//to find missing element from same arrays (except one missing element)
#include<bits/stdc++.h>
using namespace std;

int findMissingDuplicateOrdered(int arr1[], int arr2[], int N) {
    if (N == 1)
        return arr1[0];
    if (arr1[0] != arr2[0])
        return arr1[0];
    int low = 0;
    int high = N - 1;
    while (low < high) {
        int mid = (low + high) / 2;
        if (arr1[mid] == arr2[mid])
            low = mid;
        else
            high = mid;
        if (low == high - 1)
            break;
    }
    return arr1[high];
}
 
int findMissingDuplicateOrdered(int arr1[], int arr2[], int M, int N) {
    if (N == M-1)
        return findMissingDuplicateOrdered(arr1, arr2, M);
    else if (M == N-1)
        return findMissingDuplicateOrdered(arr2, arr1, N);
    else
        return -1;
}

int findMissingDuplicateUnOrdered(int arr1[], int arr2[], int M, int N) {
    if (M != N-1 && N != M-1)
        return -1;
    int res = 0;
    for (int i=0; i<M; i++)
       res = res^arr1[i];
    for (int i=0; i<N; i++)
       res = res^arr2[i];
    return res;
}
 
int main() {
    int arr1[] = {1, 4, 5, 7, 9};
    int arr2[] = {4, 5, 7, 9};
    int M = sizeof(arr1) / sizeof(int);
    int N = sizeof(arr2) / sizeof(int);
    cout<<"Missing element in ordered arrays is "<<findMissingDuplicateOrdered(arr1, arr2, M, N)<<endl;
    int arr3[] = {4, 1, 5, 9, 7};
    int arr4[] = {7, 5, 9, 4};
    int X = sizeof(arr1) / sizeof(int);
    int Y = sizeof(arr2) / sizeof(int);
    cout<<"Missing element in unordered arrays is "<<findMissingDuplicateUnOrdered(arr3, arr4, X, Y)<<endl;
    return 0;
}
