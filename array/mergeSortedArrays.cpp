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
    return 0;
}
