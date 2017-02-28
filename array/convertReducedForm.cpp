//to convert an array to reduced form where elements are from 0 to n-1
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n) {
    for (int i=0; i<n; i++)
        cout<<" "<<arr[i];
    cout<<endl;
}
 
void convertReducedForm(int arr[], int n) {
    int temp[n];
    memcpy(temp, arr, n*sizeof(int));
    sort(temp, temp + n);
    unordered_map<int, int> umap;
    int val = 0;
    for (int i = 0; i < n; i++)
        umap[temp[i]] = val++;
    for (int i = 0; i < n; i++)
        arr[i] = umap[arr[i]];
}

int main() {
    int arr[] = {10, 20, 15, 12, 11, 50};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Given Array is :";
    printArray(arr, n);
    convertReducedForm(arr , n);
    cout<<"Converted Array is :";
    printArray(arr, n);
    return 0;
}
