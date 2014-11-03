//segregate evens and odds
#include<iostream>
#include<algorithm>
using namespace std;

void printArray(int arr[], int size) {
    for (int i=0; i<size; i++)
        cout<<" "<<arr[i];
    cout<<endl;
}

void segregateEvenOdd(int arr[], int size) {
    int left = 0;
    int right = size-1;
    while(left<right) {
        while(arr[left]%2==0 && left<right)//increment left index while we see even at left
            left++;
        while(arr[right]%2==1 && left<right) //decrement right index while we see odd at right
            right--;
        if(left<right) {//if left is smaller than right then there is a odd at left and a even at right
            swap(arr[left],arr[right]);
            left++;
            right--;
        }
    }
}

int main() {
    int arr[] = {12, 34, 45, 9, 8, 90, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Input Array :\n";
    printArray(arr, n);
    segregateEvenOdd(arr, n);
    cout<<"Array after segregation :\n";
    printArray(arr, n);
    return 0;
}
