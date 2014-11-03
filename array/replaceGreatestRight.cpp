//replace every element with the greatest element on the right side in the array
#include<iostream>
using namespace std;

void replaceGreatestRight(int arr[], int size) {
    int max_from_right =  arr[size-1];
    arr[size-1] = -1;//Right most greatest element for the rightmost element is always -1

    for(int i=size-2; i>=0; i--) {
        int temp = arr[i];
        arr[i] = max_from_right;
        if(max_from_right < temp)
            max_from_right = temp;
    }
}

void printArray(int arr[], int size) {
    for (int i=0; i < size; i++)
        cout<<" "<<arr[i];
    cout<<endl;
}

int main() {
    int arr[] = {16, 17, 4, 3, 5, 2};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    cout<<"Input array is:";
    printArray (arr, size);
  
    replaceGreatestRight(arr, size);
    
    cout<<"Modified array is:";
    printArray (arr, size);
    
    return 0;
}
