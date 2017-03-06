//reverse in groups
#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n) {
    for (int i=0; i<n; i++)
        cout<<" "<<arr[i];
    cout<<endl;
}

void reverseInGroups(int arr[], int n, int k) {
    for (int i = 0; i < n; i += k) {
        int left = i;
        int right = min(i + k - 1, n - 1);
        while (left < right)
            swap(arr[left++], arr[right--]);
    }
}

void reverseInGroupsAlternate(int arr[], int n, int k) {
    for (int i = 0; i < n; i += 2*k) {
        int left = i;
        int right = min(i + k - 1, n - 1);
        while (left < right)
            swap(arr[left++], arr[right--]);
    }    
}

void reverseInGroupsDistance(int arr[], int n, int k, int m) {
    for (int i = 0; i < n; i += k + m) {
        int left = i;
        int right = min(i + k - 1, n - 1);
        while (left < right)
            swap(arr[left++], arr[right--]);
    }
}

void reverseInGroupsDoubling(int arr[], int n, int k) {
    for (int i = 0; i < n; i += k/2) {
        int left = i;
        int right = min(i + k - 1, n - 1);
        while (left < right)
            swap(arr[left++], arr[right--]);
        k = k*2;
    }
}
int main() {
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    printArray(arr1, n1);
    reverseInGroups(arr1, n1, 3);
    printArray(arr1, n1);
    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    printArray(arr2, n2);
    reverseInGroupsAlternate(arr2, n2, 3);
    printArray(arr2, n2);
    int arr3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    printArray(arr3, n3);
    reverseInGroupsDistance(arr3, n3, 3, 2);
    printArray(arr3, n3);
    int arr4[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int n4 = sizeof(arr4)/sizeof(arr4[0]);
    printArray(arr4, n4);
    reverseInGroupsDoubling(arr4, n4, 1);
    printArray(arr4, n4);
    return 0;
}
