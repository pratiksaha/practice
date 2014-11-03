//print leaders in an array. An element is leader if it is greater than all the elements to its right
#include<iostream>
using namespace std;

void printLeaders(int arr[], int size) {
    int max_from_right = arr[size-1];
    cout<<"Leaders in the array are: "<<max_from_right; //rightmost element is always a leader     
    for(int i=size-2; i>=0; i--) {
        if(max_from_right<arr[i]) {
            cout<<" "<<arr[i];
            max_from_right = arr[i];
        }
    }
    cout<<endl;   
}

int main() {
    int arr[] = {16, 17, 4, 3, 5, 2};
    printLeaders(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;  
}    
