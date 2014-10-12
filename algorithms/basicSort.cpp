#include<iostream>
using namespace std;

void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

void selectionSort(int arr[], int n) {
    int i, j, m_in;
    for (i = 0; i < n-1; i++) {
        m_in = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[m_in])
                m_in = j;
        if (m_in != i)
            swap(&arr[m_in], &arr[i]);
    }
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
   }
}

void printArray(int arr[], int size) {
    cout<<"Array:";
    for (int i=0; i < size; i++)
        cout<<" "<<arr[i];
    cout<<endl;
}

int main() {

    int a1[] = {64, 34, 25, 12, 22, 11, 90};
    bubbleSort(a1, sizeof(a1)/sizeof(a1[0]));
    printArray(a1, sizeof(a1)/sizeof(a1[0]));
    
    int a2[] = {64, 25, 12, 22, 11};
    selectionSort(a2, sizeof(a2)/sizeof(a2[0]));
    printArray(a2, sizeof(a2)/sizeof(a2[0]));
    
    int a3[] = {12, 11, 13, 5, 6};
    insertionSort(a3, sizeof(a3)/sizeof(a3[0]));
    printArray(a3, sizeof(a3)/sizeof(a3[0]));
    
    return 0;
}
