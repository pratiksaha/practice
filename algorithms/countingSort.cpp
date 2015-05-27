//counting sort
#include<iostream>
#include<cstring>
using namespace std;
#define RANGE 10

void countingSort(int *a, int n) {
    int i, count[RANGE+1], out[n];
    memset(count, 0, sizeof(count));
    for (i=0; i<n; i++)
        count[a[i]]++;
    for (i=1; i<=RANGE; i++)
        count[i] += count[i-1];;
    for (i=0; i<n; i++) {
        out[count[a[i]]-1] = a[i];
        count[a[i]]--;
    }
    for (i=0; i<n; i++)
        a[i] = out[i];
}

void printArray(int *a, int n) {
    for (int i=0; i<n; i++)
        cout<<" "<<*(a+i);
    cout<<endl;
}

int main() {
    int arr[] = {1, 4, 1, 2, 7, 5, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Input Array :"; printArray(arr, n);
    countingSort(arr, n);
    cout<<"Output Array :"; printArray(arr, n);
    return 0;
}
