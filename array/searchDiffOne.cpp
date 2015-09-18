//to search an element in an array where difference between all elements is 1
#include<iostream>
#include<cmath>
using namespace std;

int searchDiffOne(int arr[], int n, int x) {
    int i = 0;
    while (i<n) {
        if (arr[i] == x)
            return i;
        i = i + abs(arr[i]-x);
    }
    cout<<x<<" is not present! ";
    return -1;
}

int main() {
    int arr[] = {8 ,7, 6, 7, 6, 5, 4, 3, 2, 3, 4, 3 };
    int x = 3;
    cout<<"Element "<<x << " is present at index "<<searchDiffOne(arr, sizeof(arr)/sizeof(arr[0]), x)<<endl;
    return 0;
}
