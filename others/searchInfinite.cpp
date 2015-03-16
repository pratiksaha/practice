//search an element in a stream of sorted integers
#include<iostream>
using namespace std;

int search(int *window, int low, int high, int key) { //simple binary search
    if (high>=low) {
        int mid = (low+high)/2;
        if (window[mid] == key)
            return mid;
        else if (window[mid] > key)
            return search(window, low, mid-1, key);
        else
            return search(window, mid+1, high, key);
    } else {
        return -1;
    }
}

int searchInfinite(int *stream, int size, int key) {
    int low = 0, high = 0;
    int val = stream[0];
    while (!(key<=stream[high] && key>=stream[low]) && (high+1 < size)) {
        low = high+1;
        high = 2*(high+1)-1;
        if (high > size-1)
            high = size;
    }
    return search(stream, low, high, key);
}

int main() {
    int n, ans;
    int arr[] = {3, 5, 7, 9, 10, 90, 100, 130, 140, 160, 170};
    n = sizeof(arr)/sizeof(arr[0]);
    ans = searchInfinite(arr, n, 99);
    (ans==-1)?(cout<<"99 not found\n"):(cout<<"99 found at index "<<ans<<endl);
    ans = searchInfinite(arr, n, 3);
    (ans==-1)?(cout<<"3 not found\n"):(cout<<"3 found at index "<<ans<<endl);
    ans = searchInfinite(arr, n, 170);
    (ans==-1)?(cout<<"170 not found\n"):(cout<<"170 found at index "<<ans<<endl);
    ans = searchInfinite(arr, n, 100);
    (ans==-1)?(cout<<"100 not found\n"):(cout<<"100 found at index "<<ans<<endl);
    return 0;
}
