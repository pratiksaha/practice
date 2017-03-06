//to find third Largest element in an array
#include<bits/stdc++.h>
using namespace std;

void thirdLargest(int arr[], int arr_size) {
    if (arr_size < 3) {
        cout<<"Invalid Input\n";
    } else {
        int first = arr[0], second = INT_MIN, third = INT_MIN;
        for (int i = 1; i < arr_size ; i ++) {
            if (arr[i] > first) {
                third  = second;
                second = first;
                first  = arr[i];
            } else if (arr[i] > second) {
                third = second;
                second = arr[i];
            } else if (arr[i] > third) {
                third = arr[i];
            }
        }
        cout<<"The third largest element is "<<third<<endl;
    }
}

int main() {
    int arr[] = {12, 13, 1, 10, 34, 16};
    int n = sizeof(arr)/sizeof(arr[0]);
    thirdLargest(arr, n);
    return 0;
}
