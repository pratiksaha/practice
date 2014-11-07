//find the maximum j–i such that arr[j] > arr[i]
#include<iostream>
#include<algorithm>
using namespace std;

int maxIndexDiff(int arr[], int n) {
    int maxDiff;
    int i, j;
 
    int LMin[n], RMax[n];
 
    LMin[0] = arr[0];
    for (i=1; i<n; i++)
        LMin[i] = min(arr[i], LMin[i-1]);
 
    RMax[n-1] = arr[n-1];
    for (j=n-2; j>=0; j--)
        RMax[j] = max(arr[j], RMax[j+1]);
 
    i=0;
    j=0;
    maxDiff=-1;
    while (i<n && j<n) {
        if (LMin[i]<RMax[j]) {
            maxDiff = max(maxDiff, j-i);
            j++;
        } else {
            i++;
        }
    }
    return maxDiff;
}

int main() {
    int arr[] = {9, 2, 3, 4, 5, 6, 7, 8, 18, 0};
    cout<<maxIndexDiff(arr, sizeof(arr)/sizeof(arr[0]))<<endl;
    return 0;
}
