//sort an array according to the order defined by another array
#include<iostream>
#include<algorithm>
using namespace std;
#define SIZE 5

int ref[SIZE];

void printArray(int arr[], int n) {
    for (int i=0; i<n; i++)
        cout<<" "<<arr[i];
    cout << endl;
}

int first(int arr[], int low, int high, int x, int n) {
    if (high >= low) {
        int mid = (high+low)/2;
        if ((mid == 0 || x > arr[mid-1]) && arr[mid] == x)
            return mid;
        else if (x > arr[mid])
            return first(arr, (mid + 1), high, x, n);
        else
            return first(arr, low, (mid -1), x, n);
    }
    return -1;
}

void sortAccording(int A1[], int A2[], int m, int n) {
    int temp[m], visited[m];
    for (int i=0; i<m; i++) {
        temp[i] = A1[i];
        visited[i] = 0;
    }
    sort(temp, temp + m);
    int ind = 0;
    for (int i=0; i<n; i++) {
        int f = first(temp, 0, m-1, A2[i], m);
        if (f == -1)
            continue;
        for (int j = f; (j<m && temp[j]==A2[i]); j++) {
            A1[ind++] = temp[j];
            visited[j] = 1;
        }
    }
    for (int i=0; i<m; i++)
        if (visited[i] == 0)
            A1[ind++] = temp[i];
}

int search(int key) {
    for (int i=0; i<SIZE; i++)
        if (ref[i] == key)
            return i;
    return -1;
}

int customComp(const void * a, const void * b) {
    int idx1 = search(*(int*)a);
    int idx2 = search(*(int*)b);
    if (idx1 != -1 && idx2 != -1)
        return idx1 - idx2;
    else if(idx1 != -1)
        return -1;
    else if(idx2 != -1)
        return 1;
    else
        return ( *(int*)a - *(int*)b );
}

void sortAccording(int A1[], int size1) {
    qsort(A1, size1, sizeof (int), customComp);
}

int main() {
    int A1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8};
    int A2[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8};
    ref[0] = 2;
    ref[1] = 1;
    ref[2] = 8;
    ref[3] = 3;
    ref[4] = 4;
    int m = sizeof(A1)/sizeof(A1[0]);
    int n = sizeof(A2)/sizeof(A2[0]);
    sortAccording(A1, ref, m, SIZE);
    cout<<"Sorted array is :"; printArray(A1, m);
    sortAccording(A2, n);
    cout<<"Sorted array is :"; printArray(A2, n);
    return 0;
}
