//to find min and max in a sorted and rotated array with distinct elems
#include<iostream>
using namespace std;
 
int findMin(int arr[], int low, int high, int size) {
    if (high<low) //not rotated at all
        return arr[0];
    if (high==low)
        return arr[low];
    int mid = (low+high)/2;
    if (mid<high && arr[mid+1]<arr[mid])
        return arr[mid+1];
    if (mid>low && arr[mid]<arr[mid-1])
        return arr[mid];
    if (arr[high]>arr[mid])
        return findMin(arr, low, mid-1, size);
    else
        return findMin(arr, mid+1, high, size);
}

int findMax(int arr[], int low, int high, int size) {
    if (high<low) //not rotated at all
        return arr[size-1];
    if (high==low)
        return arr[low];
    int mid = (low+high)/2;
    if (mid>low && arr[mid-1]>arr[mid])
        return arr[mid-1];
    if (mid<high && arr[mid]>arr[mid+1])
        return arr[mid];
    if (arr[low]<arr[mid])
        return findMax(arr, mid+1, high, size);
    else
        return findMax(arr, low, mid-1, size);
}

int main() {
    int arr1[] = {5, 6, 1, 2, 3, 4};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    cout<<"Min = "<<findMin(arr1, 0, n1-1, n1)<<" Max = "<<findMax(arr1, 0, n1-1, n1)<<endl;
    
    int arr2[] =  {1, 2, 3, 4};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    cout<<"Min = "<<findMin(arr2, 0, n2-1, n2)<<" Max = "<<findMax(arr2, 0, n2-1, n2)<<endl;
 
    int arr3[] =  {1};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    cout<<"Min = "<<findMin(arr3, 0, n3-1, n3)<<" Max = "<<findMax(arr3, 0, n3-1, n3)<<endl;
 
    int arr4[] =  {1, 2};
    int n4 = sizeof(arr4)/sizeof(arr4[0]);
    cout<<"Min = "<<findMin(arr4, 0, n4-1, n4)<<" Max = "<<findMax(arr4, 0, n4-1, n4)<<endl;
 
    int arr5[] =  {2, 1};
    int n5 = sizeof(arr5)/sizeof(arr5[0]);
    cout<<"Min = "<<findMin(arr5, 0, n5-1, n5)<<" Max = "<<findMax(arr5, 0, n5-1, n5)<<endl;
 
    int arr6[] =  {5, 6, 7, 1, 2, 3, 4};
    int n6 = sizeof(arr6)/sizeof(arr6[0]);
    cout<<"Min = "<<findMin(arr6, 0, n6-1, n6)<<" Max = "<<findMax(arr6, 0, n6-1, n6)<<endl;
 
    int arr7[] =  {1, 2, 3, 4, 5, 6, 7};
    int n7 = sizeof(arr7)/sizeof(arr7[0]);
    cout<<"Min = "<<findMin(arr7, 0, n7-1, n7)<<" Max = "<<findMax(arr7, 0, n7-1, n7)<<endl;
 
    int arr8[] =  {2, 3, 4, 5, 6, 7, 8, 1};
    int n8 = sizeof(arr8)/sizeof(arr8[0]);
    cout<<"Min = "<<findMin(arr8, 0, n8-1, n8)<<" Max = "<<findMax(arr8, 0, n8-1, n8)<<endl;
    
    int arr9[] =  {3, 4, 5, 1, 2};
    int n9 = sizeof(arr9)/sizeof(arr9[0]);
    cout<<"Min = "<<findMin(arr9, 0, n9-1, n9)<<" Max = "<<findMax(arr9, 0, n9-1, n9)<<endl;;
 
    return 0;
}
