//to find missing elements from an array
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<bits/stdc++.h>
using namespace std;
 
void findMissingElementsRangeSort(int arr[], int n, int low, int high) {
    sort(arr, arr+n);
    int *ptr = lower_bound(arr, arr+n, low);
    int index = ptr - arr;
    int i = index, x = low;
    while (i < n && x<=high) {
        if (arr[i] != x)
            cout<<" "<<x;
        else
            i++;
        x++;
    }
    while (x <= high)
        cout<<" "<<x++;
    cout<<endl;
}

void findMissingElementsRangeHash(int arr[], int n, int low, int high) {
    unordered_set<int> s;
    for (int i=0; i<n; i++)
        s.insert(arr[i]);
    for (int x=low; x<=high; x++)
        if (s.find(x) == s.end())
            cout<<" "<<x;
    cout<<endl;
}

int main() {
    int arr[] = {1, 3, 5, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int low = 1, high = 10;
    findMissingElementsRangeSort(arr, n, low, high);
    findMissingElementsRangeHash(arr, n, low, high);
    return 0;
}
