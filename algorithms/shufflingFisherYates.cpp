//Fisher Yates shuffling algorithm
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

void printArray(int arr[], int size) {
    for (int i=0; i < size; i++)
        cout<<" "<<arr[i];
    cout<<endl;
}

void FisherYates(int arr[], int size){
    srand(time(0));
    for (int i=size-1; i>0; i--) {
        int j = rand()%(i+1); //j = a random integer with 0 <= j <= i
        swap(&arr[i], &arr[j]);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr)/ sizeof(arr[0]);
    cout<<"Input array is:";
    printArray(arr, n);
    
    FisherYates(arr, n);
    cout<<"After shuffling array is:";
    printArray(arr, n);

    return 0;
}
