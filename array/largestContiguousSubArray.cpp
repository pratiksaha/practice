//find the largest contiguous subarray
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;

void largestContiguousSubArray(int arr[], int n) {
    int maxLen = 1, idx = 0, jdx = 0;
    for (int i=0; i<n-1; i++) {
        int mn = arr[i];
        int mx = arr[i];
        for (int j=i+1; j<n; j++) {
            mn = min(mn, arr[j]);
            mx = max(mx, arr[j]);
            if ((mx-mn == j-i) && (mx-mn+1 > maxLen)) { //curr subarray has all contiguous elements and it is max seen so far
                maxLen = mx-mn+1;
                idx = i;
                jdx = j;
            }
        }
    }
    cout<<"Largest Contiguous subarray of length "<<maxLen<<" is :";
    for (int i=idx; i<=jdx; i++)
        cout<<" "<<arr[i];
    cout<<endl;
}

int main() {
    int arr[] = {1, 56, 58, 57, 90, 92, 94, 93, 91, 45};
    largestContiguousSubArray(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}
