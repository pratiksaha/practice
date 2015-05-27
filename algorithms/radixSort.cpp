//radix sort
#include<iostream>
using namespace std;

int getMax(int *a , int n) {
    int mx = a[0];
    for (int i=1; i<n; i++)
        if (a[i]>mx)
            mx = a[i];
    return mx;
}

void countingSort(int *a, int n, int exp) {
    int out[n], i, count[10] = {0}; //RANGE is always 0-9 in this case
    for (i=0; i<n; i++)
        count[(a[i]/exp)%10]++;
    for (i=1; i<10; i++)
        count[i] += count[i-1];;
    for (i=n-1; i>=0; i--) {
        out[count[(a[i]/exp)%10]-1] = a[i];
        count[(a[i]/exp)%10]--;
    }
    for (i=0; i<n; i++)
        a[i] = out[i];
}

void radixSort(int *a, int n) {
    int m = getMax(a, n);
    for (int exp=1; m/exp > 0; exp *= 10) //do counting sort for each digit
        countingSort(a, n, exp);
}
 
void printArray(int *a, int n) {
    for (int i=0; i<n; i++)
        cout<<" "<<*(a+i);
    cout<<endl;
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Input Array :"; printArray(arr, n);
    radixSort(arr, n);
    cout<<"Output Array :"; printArray(arr, n);
    return 0;
}
