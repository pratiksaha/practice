//to sort even-placed elements in increasing and odd-placed in decreasing order
#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n) {
    for (int i=0; i<n; i++)
        cout<<" "<<arr[i];
    cout<<endl;
}

void bitonicGeneratorEvenOdd(int  arr[], int n) {
    vector<int> evenArr;
    vector<int> oddArr;
    for (int i = 0; i < n; i++) {
        if (!( i % 2 ))
            evenArr.push_back(arr[i]);
        else
            oddArr.push_back(arr[i]);
    }
    sort(evenArr.begin(), evenArr.end() );
    sort(oddArr.begin(), oddArr.end(), greater<int>());
    int i = 0;
    for (int j=0; j<evenArr.size(); j++)
        arr[i++] = evenArr[j];
    for (int j=0; j<oddArr.size(); j++)
        arr[i++] = oddArr[j];
}

int main() {
    int arr[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);
    bitonicGeneratorEvenOdd(arr, n);
    printArray(arr, n);
    return 0;
}
