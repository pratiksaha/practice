//rearrange an array so that arr[i] becomes arr[arr[i]] with O(1) extra space
#include<iostream>
using namespace std;

void rearrangeInplace(int arr[], int n) {
    for (int i=0; i<n; i++)
        arr[i] += (arr[arr[i]]%n)*n; //increase all values by (arr[arr[i]]%n)*n
    for (int i=0; i<n; i++)
        arr[i] /= n; //divide all values by n
}

void printArray(int arr[], int n) {
    for (int i=0; i<n; i++)
        cout<<" "<<arr[i];
    cout<<endl;
}

int main() {
    int arr[] = {3, 2, 0, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Given array is :", printArray(arr, n);
    rearrangeInplace(arr, n);
    cout<<"Modified array is :", printArray(arr, n);
    return 0;
}
