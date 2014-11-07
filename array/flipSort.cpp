//sort in O(nLogn) time on a hypothetical machine where flip(i) always takes O(1) time
#include<iostream>
#include<cstdlib>
using namespace std;

void flip(int arr[], int i) { //for the sake of the problem assume this is O(1)
    int start = 0;
    while (start < i) {
        swap(arr[start], arr[i]);
        start++;
        i--;
    }
}

int ceilSearch(int arr[], int low, int high, int x) {
    if(x<=arr[low]) //if x is smaller than or equal to the first elem return the first elem
        return low;
    if(x>arr[high]) //if x is greater than the last element return -1
        return -1;
        
    int mid = (low + high)/2;
    if(arr[mid] == x) {
        return mid;    
    } else if(arr[mid] < x) {
        if(mid + 1 <= high && x <= arr[mid+1]) //either arr[mid + 1] is ceiling of x
            return mid + 1;
        else //or ceiling lies in arr[mid+1...high]
            return ceilSearch(arr, mid+1, high, x);
    } else {
        if (mid - 1 >= low && x > arr[mid-1]) //either arr[mid] is ceiling of x
            return mid;
        else //or ceiling lies in arr[low...mid-1]
            return ceilSearch(arr, low, mid-1, x);
    }
}

void flipSort(int arr[], int size) {
    int i, j;
    for(int i=1; i<size; i++) {
        int j = ceilSearch(arr, 0, i-1, arr[i]); //Find the smallest element in arr[0..i-1] which is also greater than or equal to arr[i]
        if (j != -1) { //if there are element(s) greater than arr[i]
            flip(arr, j-1);
            flip(arr, i-1);
            flip(arr, i);
            flip(arr, j);
        }
    }
}

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++)
        cout<<" "<<arr[i];
    cout<<endl;
}

int main() {
    int arr[] = {18, 40, 35, 12, 30, 35, 20, 6, 90, 80};
    cout<<"Input Array :";
    printArray(arr, sizeof(arr)/sizeof(arr[0]));
    flipSort(arr, sizeof(arr)/sizeof(arr[0]));
    cout<<"Sorted Array :";
    printArray(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}
