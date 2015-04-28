#include<iostream>
using namespace std;

void merge(int arr[], int l, int m, int r) {
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1], R[n2];
    int i, j, k;
    for (i=0; i<n1; i++)
        L[i] = arr[l+i];
    for (j=0; j<n2; j++)
        R[j] = arr[m+j+1];
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2) { //merge from both arrays
        if (L[i] <= R[j] ) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i<n1) { //leftover from left array (if any)
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j<n2) { //leftover from right array (if any)
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int l, int r) {
    if (l<r) {
        int m = (l+r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int size) {
    for (int i=0; i<size; i++)
        cout<<" "<<arr[i];
    cout<<endl;
}

int main() {
    int a1[] = {12, 11, 13, 5, 6, 7};
    int n1 = sizeof(a1)/sizeof(a1[0]);
    cout<<"Input Array :";
    printArray(a1, n1);
    mergeSort(a1, 0, n1-1);
    cout<<"Sorted Array :";
    printArray(a1, n1);
    return 0;
}
