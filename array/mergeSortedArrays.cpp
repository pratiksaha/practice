//merge 2 sorted arrays
#include<iostream>
#include<algorithm>
using namespace std;
#define NA -1

void moveToEnd(int A[], int size) {
    int i = 0;
    int j = size - 1;
    for (i = size-1; i >= 0; i--) {
        if (A[i] != NA) {
            A[j] = A[i];
            j--;
        }
    }
}

int mergeSortedArrays(int mPlusN[], int N[], int m, int n) {
    int i = n;
    int j = 0;
    int k = 0;
    while (k<m+n) {
        if ((i < (m+n) && mPlusN[i] <= N[j]) || (j == n)) {
            mPlusN[k] = mPlusN[i];
            k++;
            i++;
        } else {
            mPlusN[k] = N[j];
            k++;
            j++;
        }
    }
}

void merge(int ar1[], int ar2[], int m, int n) {
    for (int i=n-1; i>=0; i--) {
        int j, last = ar1[m-1];
        for (j=m-1; j >= 0 && ar1[j] > ar2[i]; j--) //find the smallest element greater than ar2[i]
            ar1[j+1] = ar1[j]; //move all elems one pos ahead till the smallest greater elem is not found
        if (j != m-1) { //if there was a greater element
            ar1[j+1] = ar2[i];
            ar2[i] = last;
        }
    }
}

void printArray(int arr[], int size) {
    for (int i=0; i<size; i++)
        cout<<" "<<arr[i];
    cout<<endl;
}

int main() {
    int mPlusN[] = {2, 8, NA, NA, NA, 13, NA, 15, 20};
    int N[] = {5, 7, 9, 25};
    int n = sizeof(N)/sizeof(N[0]);
    int m = sizeof(mPlusN)/sizeof(mPlusN[0]) - n;
    moveToEnd(mPlusN, m+n);
    mergeSortedArrays(mPlusN, N, m, n);
    cout<<"Merged Array :";
    printArray(mPlusN, m+n);
    int ar1[] = {1, 5, 9, 10, 15, 20};
    int ar2[] = {2, 3, 8, 13};
    m = sizeof(ar1)/sizeof(ar1[0]);
    n = sizeof(ar2)/sizeof(ar2[0]);
    merge(ar1, ar2, m, n);
    cout<<"After Merging\n";
    cout<<"First Array :";
    printArray(ar1, m);
    cout<<"Second Array :";
    printArray(ar2, n);
    return 0;
}
