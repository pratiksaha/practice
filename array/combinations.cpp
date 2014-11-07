//find all combinations of size r in an array of size n
#include<iostream>
using namespace std;

void combinationUtil(int arr[], int data[], int start, int end, int index, int r) {
    if (index == r) { //curr combination is ready to be printed
        for (int j=0; j<r; j++)
            cout<<data[j];
        cout<<endl;
    } else {
        for (int i=start; i<=end && end-i+1 >= r-index; i++) {// replace index with all possible elements
            data[index] = arr[i];
            combinationUtil(arr, data, i+1, end, index+1, r);
        }
    }
}

void combinations(int arr[], int n, int r) {
    int data[r];
    combinationUtil(arr, data, 0, n-1, 0, r);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    combinations(arr, sizeof(arr)/sizeof(arr[0]), 3);
    return 0;
}
