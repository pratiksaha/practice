//to find all elements in array which have atleast two greater elements itself
#include<bits/stdc++.h>
using namespace std;

void printElemAtleastTwoGreater(int arr[], int n) {
    int first = INT_MIN, second = INT_MIN;
    for (int i=0; i<n; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > second) {
            second = arr[i];
        }
    }
    for (int i=0; i<n; i++)
        if (arr[i] < second)
            cout<<" "<<arr[i];
    cout<<endl;
}

int main() {
    int arr[] = { 2, -6, 3, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    printElemAtleastTwoGreater(arr, n);
    return 0;
}
