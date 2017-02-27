//to find a subset of size 2 or greater with greatest geometric mean
#include<bits/stdc++.h>
using namespace std;

void largestGeometricMean(int arr[], int n) {
    if (n < 2) {
        cout<<"Invalid Input\n";
    } else {
        int first = INT_MIN, second = INT_MIN;
        for (int i = 0; i < n ; i ++) {
            if (arr[i] > first) {
                second = first;
                first = arr[i];
            } else if (arr[i] > second) {
                second = arr[i];
            }
        }
        cout<<"Greatest Geometric Mean is produced by "<<second<<" & "<<first<<endl;
    }
}
 
int main() {
    int arr[] = {12, 13, 17, 10, 34, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    largestGeometricMean(arr, n);
    return 0;
}
