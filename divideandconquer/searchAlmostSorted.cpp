//to find an element in an almost sorted array where some elements are moved to either of the adjacent positions
#include<iostream>
using namespace std;

int searchAlmostSorted(int arr[], int l, int r, int key) {
    if (r>=l) {
        int m = (l+r)/2;
        if (arr[m] == key)
            return m;
        if (m>l && arr[m-1]==key)
            return m-1;
        if (m<r && arr[m+1]==key)
            return m+1;
        if (arr[m]>key)
            return searchAlmostSorted(arr, l, m-2, key);
        else
            return searchAlmostSorted(arr, m+2, r, key);
    }
    return -1;
}

int main() {
    int arr[] = {3, 2, 10, 4, 40};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 4;
    int result = searchAlmostSorted(arr, 0, n-1, key);
    (result == -1)?cout<<key<<" is not present in array\n":cout<<key<<" is present at index "<<result<<endl;
    return 0;
}
