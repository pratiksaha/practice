//to find a sorted subsequence of size 3 using constant space
#include<bits/stdc++.h>
using namespace std;

void sortedSubsequenceSize3(int arr[], int n) {
    int small = INT_MAX, large = INT_MAX;
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] <= small)
            small = arr[i];
        else if (arr[i] <= large)
            large = arr[i];
        else
            break;
    }
    if (i == n) {
        cout<<"No such triplet found\n";
        return;
    }
    for (int j = 0; j <= i; j++) {
        if (arr[j] < large) {
            small = arr[j];
            break;
        }
    }
    cout<<"Sorted subsequence of size 3 is "<<small<<" "<<large<<" "<<arr[i]<<endl;
}

int main() {
    int arr[] = {5, 7, 4, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    sortedSubsequenceSize3(arr, n);
    return 0;
}
