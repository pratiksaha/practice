//generate subarrays and subsequences
#include<bits/stdc++.h>
using namespace std;

void subArray(int arr[], int n) {
    for (int i=0; i <n; i++)
        for (int j=i; j<n; j++)
            for (int k=i; k<=j; k++)
                cout<<arr[k]<<" \n"[k==j];
}

void subSequence(int arr[], int n) {
    unsigned int p = pow(2, n);
    for (int i=1; i<p; i++) {
        for (int j=0; j<n; j++) {
            if (i & (1<<j))
                cout<<" "<<arr[j];
        }
        cout << endl;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"All Non-empty Subarrays :\n";
    subArray(arr, n);
    cout<<"All Non-empty Subsequences:\n";
    subSequence(arr, n);
    return 0;
}
