//to find the element which is greater than all left elements and smaller than all right elements.
#include<iostream>
#include<climits>
using namespace std;
 
int findElementGreaterLeftSmallerRight(int arr[], int n) {
    int leftMax[n];
    leftMax[0] = INT_MIN;
    for (int i = 1; i < n; i++)
        leftMax[i] = max(leftMax[i-1], arr[i-1]);
    int rightMin = INT_MAX;
    for (int i=n-1; i>=0; i--) {
        if (leftMax[i] < arr[i] && rightMin > arr[i])
             return i;
        rightMin = min(rightMin, arr[i]);
    }
    return -1;
}

int main() {
    int arr[] = {5, 1, 4, 3, 6, 8, 10, 7, 9};
    cout<<"Index of the element is "<<findElementGreaterLeftSmallerRight(arr, sizeof(arr)/sizeof(arr[0]))<<endl;
    return 0;
}
