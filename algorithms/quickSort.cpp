//Quick Sort
#include<iostream>
#include<cstdlib>
using namespace std;

int partition(int arr[], int l, int r) { //CLRS partition
    int x = arr[r]; //pivot
    int i = l-1;
    for (int j=l; j<=r-1; j++) {
        if (arr[j] < x) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[r]);
    return i+1;
}

void quickSort(int arr[], int l, int r) { //CLRS quick sort
    if (l<r) {
        int p = partition(arr, l, r);
        quickSort(arr, l, p-1);
        quickSort(arr, p+1, r);
    }
}

void quickSortIterative(int arr[], int l, int r) {
    int stack[r-l+1];
    int top = -1;
    stack[++top] = l;
    stack[++top] = r;
    while (top>=0) {
        r = stack[top--];
        l = stack[top--];
        int p = partition(arr, l, r);
        if (p-1>l) { //push left side to stack if there are elems on left side of pivot
            stack[++top] = l;
            stack[++top] = p-1;
        }
        if (p+1<r) { //push right side to stack if there are elems on right side of pivot
            stack[++top] = p+1;
            stack[++top] = r;
        }
    }
}

void printArray(int arr[], int size) {
    for (int i=0; i<size; i++)
        cout<<" "<<arr[i];
    cout<<endl;
}

int main() {
    int a1[] = {10, 7, 8, 9, 1, 5};
    int n1 = sizeof(a1)/sizeof(a1[0]);
    cout<<"Input Array :";
    printArray(a1, n1);
    quickSort(a1, 0, n1-1);
    cout<<"Sorted Array :";
    printArray(a1, n1);
    int a2[] = {10, 7, 8, 9, 1, 5};
    int n2 = sizeof(a2)/sizeof(a2[0]);
    cout<<"Input Array :";
    printArray(a2, n2);
    quickSortIterative(a2, 0, n2-1);
    cout<<"Sorted Array :";
    printArray(a2, n2);
    return 0;
}
