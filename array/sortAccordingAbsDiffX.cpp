//to sort an array according absolute difference with x
#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n) {
    for (int i=0; i<n; i++)
        cout<<" "<<arr[i];
    cout<<endl;
}

void sortAccordingAbsDiffX(int arr[], int n, int x) {
    multimap<int, int> m;
    for (int i = 0 ; i < n; i++)
        m.insert(make_pair(abs(x-arr[i]),arr[i]));
    int i = 0;
    for (multimap<int, int>::iterator it = m.begin(); it != m.end(); it++)
        arr[i++] = (*it).second ;
}

int main() {
    int arr[] = {10, 5, 3, 9 ,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 7;
    printArray(arr, n);
    sortAccordingAbsDiffX(arr, n, x);
    printArray(arr, n);
    return 0;
}
