//to search in a sorted and rotated array
#include<iostream>
using namespace std;

int linearSearch(int arr[], int low, int high, int key) {
    for (int i=low; i<=high; i++)
        if (arr[i]==key)
            return i;
    return -1;
}

int searchSortedRotated(int arr[], int n, int key) {
    int low=0, high=n-1;
    while (low<=high) {
        int mid = (low+high)/2;
        if (arr[mid]==key) {
            return mid;
        } else if (arr[mid]<arr[high]) { //right half is sorted
            if (key > arr[mid] && key <= arr[high])
                low = mid+1;
            else
                high = mid-1;
        } else if (arr[mid]>arr[low]) { //left half is sorted
            if (arr[low] <= key && key < arr[mid])
                high = mid-1;
            else
                low = mid+1;
        } else {
            return linearSearch(arr, low, high, key); //TODO: maybe something more optimal can be done here
        } 
    }
    return -1;
}

int main() {
    int arr1[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int arr_size = sizeof(arr1)/sizeof(arr1[0]);
    int no = 3;
    cout<<"Index of the element "<<no<<" is "<<searchSortedRotated(arr1, arr_size, no)<<endl;
    int arr2[] = {3, 4, 5, 1, 2};
    arr_size = sizeof(arr2)/sizeof(arr2[0]);
    cout<<"Index of the element "<<no<<" is "<<searchSortedRotated(arr2, arr_size, no)<<endl;
    no = 4;
    cout<<"Index of the element "<<no<<" is "<<searchSortedRotated(arr2, arr_size, no)<<endl;
    int arr3[] = {1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1};
    no = 0;
    arr_size = sizeof(arr3)/sizeof(arr3[0]);
    cout<<"Index of the element "<<no<<" is "<<searchSortedRotated(arr3, arr_size, no)<<endl;
    int arr4[] = {2, 3, 0, 2, 2, 2, 2, 2, 2, 2};
    no = 3;
    arr_size = sizeof(arr4)/sizeof(arr4[0]);
    cout<<"Index of the element "<<no<<" is "<<searchSortedRotated(arr4, arr_size, no)<<endl;
    no = 2;
    cout<<"Index of the element "<<no<<" is "<<searchSortedRotated(arr4, arr_size, no)<<endl;
    int arr5[] = {1, 2, 3, 4};
    no = 3;
    arr_size = sizeof(arr5)/sizeof(arr5[0]);
    cout<<"Index of the element "<<no<<" is "<<searchSortedRotated(arr5, arr_size, no)<<endl;
    return 0;
}
