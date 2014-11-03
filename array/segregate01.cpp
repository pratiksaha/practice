//segregate 0s on left side and 1s on right side of the array
#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    for (int i=0; i<size; i++)
        cout<<" "<<arr[i];
    cout<<endl;
}

void segregate01(int arr[], int size) {
    int left = 0;
    int right = size-1;
    while(left < right) {
        while(arr[left]==0 && left<right) //increment left index while we see 0 at left 
            left++;
        while(arr[right]==1 && left<right) //decrement right index while we see 1 at right
            right--;
        if(left < right) { //if left is smaller than right then there is a 1 at left and a 0 at right
            arr[left] = 0;
            arr[right] = 1;
            left++;
            right--;
        }
    }
}

int main() {
    int arr[] = {0, 1, 0, 1, 1, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Input Array :\n";
    printArray(arr, n);
    segregate01(arr, n);
    cout<<"Array after segregation :\n";
    printArray(arr, n);
    return 0;
}
