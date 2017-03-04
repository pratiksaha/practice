//to find surpasser count of each element
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n) {
    for (int i=0; i<n; i++)
        cout<<" "<<arr[i];
    cout<<endl;
}

int merge(int arr[], int l, int m, int r, unordered_map<int, int> &hm) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0, j = 0, k = l;
    int c = 0;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            hm[L[i]] += c;
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
            c++;
        }
    }
    while (i < n1) {
        hm[L[i]] += c;
        arr[k++] = L[i++];
    }
    while (j < n2)
        arr[k++] = R[j++];
}

int mergeSort(int arr[], int l, int r, unordered_map<int, int> &hm) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, hm);
        mergeSort(arr, m + 1, r, hm);
        merge(arr, l, m, r, hm);
    }
}

void countSurpassers(int arr[], int n) {
    unordered_map<int, int> hm;
    int dup[n];
    memcpy(dup, arr, n*sizeof(arr[0]));
    mergeSort(dup, 0, n - 1, hm);
 
    cout<<"Surpasser Count of each element is :";
    for (int i = 0; i < n; i++)
        cout<<" "<<(n - 1) - i - hm[arr[i]];
    cout<<endl;
}

int main() {
    int arr[] = { 2, 7, 5, 3, 0, 8, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Given array is :";
    printArray(arr, n);
    countSurpassers(arr, n);
    return 0;
}
