//to print union and intersection of two unsorted arrays
#include<iostream>
#include<algorithm>
using namespace std;

int binarySearch(int arr[], int l, int r, int x) {
    if (l<=r) {
        int mid = (l+r)/2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid-1, x);
        else
            return binarySearch(arr, mid+1, r, x);
    }
    return -1;
}

void UnionIntersection(int arr1[], int arr2[], int m, int n) {
    int i;
    sort(arr1, arr1 + m);
    cout<<"Union :";
    for (i=0; i<m; i++)
        cout<<" "<<arr1[i];
    for (i=0; i<n; i++)
        if (binarySearch(arr1, 0, m-1, arr2[i]) == -1)
            cout<<" "<<arr2[i];
    cout<<endl;
    cout<<"Intersection :";
    for (i=0; i<n; i++)
        if (binarySearch(arr1, 0, m-1, arr2[i]) != -1)
            cout<<" "<<arr2[i];
    cout<<endl;
}

int main() {
    int arr1[] = {3, 8, 6, 20, 7};
    int arr2[] = {7, 1, 5, 2, 3, 6};
    UnionIntersection(arr1, arr2, sizeof(arr1)/sizeof(arr1[0]), sizeof(arr2)/sizeof(arr2[0]));
    return 0;
}
