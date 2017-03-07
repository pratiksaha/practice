//to count elements that are greater than all previous elements
#include<bits/stdc++.h>
using namespace std;

int countElementsLargerThanAllPrevious(int arr[], int n) {
    int result = 1;
    int max_elem = arr[0];
    for (int i=1; i<n; i++) {
        if (arr[i] > max_elem) {
            max_elem = arr[i];
            result++;
        }
    }
    return result;
}

int main() {
    int arr[] = {10, 40, 23, 35, 50, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<countElementsLargerThanAllPrevious(arr, n)<<endl;
    return 0;
}
