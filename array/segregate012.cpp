//segregate 0s 1s & 2s
#include<iostream>
#include<algorithm>
using namespace std;

void printArray(int arr[], int size) {
    for (int i=0; i<size; i++)
        cout<<" "<<arr[i];
    cout<<endl;
}

void segregate012(int a[], int arr_size) {
    int lo = 0;
    int hi = arr_size - 1;
    int mid = 0;
    while(mid <= hi) {
        switch(a[mid]) {
            case 0:
                swap(a[lo++], a[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(a[mid], a[hi--]);
                break;
        }
    }
}

int main() {
    int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Input Array :\n";
    printArray(arr, n);
    segregate012(arr, n);
    cout<<"Array after segregation :\n";
    printArray(arr, n);
    return 0;
}
