#include<iostream>
#include<cassert>
using namespace std;

//A recursive binary search function. It returns location of x in given array arr[l..r] is present, otherwise -1
int BinarySearch_rec(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = (l+r)/2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] > x)
            return BinarySearch_rec(arr, l, mid-1, x);
        else
            return BinarySearch_rec(arr, mid+1, r, x);
    }
    return -1;
}

//An iterative binary search function. It returns location of x in given array arr[l..r] if present, otherwise -1
int BinarySearch_itr(int arr[], int l, int r, int x) {
    int mid;
    while (l <= r) {
        mid = (l+r)/2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            l = mid + 1; 
        else
            r = mid - 1;
    }
    return -1;
}

//deffered binary search algorithm
//always returns the smallest index of the key
int BinarySearch(int arr[], int low, int high, int key) {
    int mid;
    while (low<high) {
        mid = ((unsigned int)low + (unsigned int)high)>>1; //avoid integer overflow
        assert(mid < high);
        if (arr[mid] < key)
            low = mid + 1; 
        else
            high = mid - 1;
    }
    if (low == high && arr[low] == key)
        return low;
    else
        return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40, 40, 40};
    int key, pos, n;
    n = sizeof(arr)/sizeof(arr[0]);
    key = 4;
    pos = BinarySearch_rec(arr, 0, n-1, key);
    (pos == -1)?(cout<<key<<" is not present in array"<<endl):(cout<<key<<" is present at index "<<pos<<endl);
    key = 8;
    pos = BinarySearch_rec(arr, 0, n-1, key);
    (pos == -1)?(cout<<key<<" is not present in array"<<endl):(cout<<key<<" is present at index "<<pos<<endl);
    key = 4;
    pos = BinarySearch_itr(arr, 0, n-1, key);
    (pos == -1)?(cout<<key<<" is not present in array"<<endl):(cout<<key<<" is present at index "<<pos<<endl);
    key = 8;
    pos = BinarySearch_itr(arr, 0, n-1, key);
    (pos == -1)?(cout<<key<<" is not present in array"<<endl):(cout<<key<<" is present at index "<<pos<<endl);
    key = 4;
    pos = BinarySearch(arr, 0, n-1, key);
    (pos == -1)?(cout<<key<<" is not present in array"<<endl):(cout<<key<<" is present at index "<<pos<<endl);
    key = 8;
    pos = BinarySearch(arr, 0, n-1, key);
    (pos == -1)?(cout<<key<<" is not present in array"<<endl):(cout<<key<<" is present at index "<<pos<<endl);
    key = 40;
    pos = BinarySearch(arr, 0, n-1, key);
    (pos == -1)?(cout<<key<<" is not present in array"<<endl):(cout<<key<<" is present at index "<<pos<<endl);
    return 0;
}
