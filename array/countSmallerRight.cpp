//to count no of smaller elems on right of each elem
#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;

void countSmallerRight(int *in, int *out, int n) {
    vector<int> v;
    vector<int>::iterator it;
    int min = INT_MAX, max = INT_MIN;
    for (int i=n-1; i>=0; i--) {
        int curr = in[i];
        if (curr < min) {
            min = curr;
            out[i] = 0;
            v.insert(v.begin(), curr);
        } else if (curr > max) {
            max = curr;
            out[i] = n - i -1;
            v.insert(v.end(), curr);
        } else {
            it = lower_bound(v.begin(), v.end(), curr);
            out[i] = it - v.begin();
            v.insert(it+1, curr);
        }
    }
}

void printArray(int arr[], int size) {
    for (int i=0; i<size; i++)
        cout<<" "<<arr[i];
    cout<<endl;
}

int main() {
    int arr[] = {10, 6, 15, 2, 40, 20, 30, 5, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int *count = new int[n];
    countSmallerRight(arr, count, n);
    cout<<"Input Array :"; printArray(arr, n);
    cout<<"Output Array :"; printArray(count, n);
    delete []count;
    return 0;
}
