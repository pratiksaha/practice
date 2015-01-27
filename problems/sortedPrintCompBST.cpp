//prints in ascending order an array that stores level order traversal of a complete BST, write a function that efficiently 
#include<iostream>
using namespace std;
 
void printSorted(int arr[], int start, int end) {     
    if(start <= end) {
        printSorted(arr, start*2+1, end);
        cout<<" "<<arr[start];
        printSorted(arr, start*2+2, end);
    } 
}
 
int main() {
    int arr[] = {4, 2, 5, 1, 3};
    cout<<"Sorted print ", printSorted(arr, 0, sizeof(arr)/sizeof(arr[0])-1), cout<<endl;
    return 0;
}
