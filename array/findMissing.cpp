//find the smallest positive missing number
#include<iostream>
#include<cstdlib>
using namespace std;
 
int segregate(int arr[], int size) {
    int j = 0, i;
    for(i = 0; i < size; i++) {
        if (arr[i] <= 0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }
    return j;
}

int findMissingPositive(int arr[], int size) {
    int i;
    for(i=0; i<size; i++) {
        if(abs(arr[i])-1 < size && arr[abs(arr[i])-1] > 0)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
    }
    for(i = 0; i < size; i++)
        if (arr[i] > 0)
            return i+1;
    return size+1;
}
 

int findMissing(int arr[], int size) {
    int shift = segregate (arr, size);
    return findMissingPositive(arr+shift, size-shift);
}
 
int main() {
    int arr[] = {0, 10, 2, -10, -20};
    cout<<"The smallest positive missing number is "<<findMissing(arr, sizeof(arr)/sizeof(arr[0]))<<endl;
    return 0;
}
