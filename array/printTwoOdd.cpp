//to find the two odd occurring elements
#include<iostream>
using namespace std;

void printTwoOdd(int arr[], int size) {
    int xor2 = arr[0]; //XOR of two odd occurring elements
    int set_bit_no;  //only single set bit of xor2
    for(int i=1; i<size; i++)
        xor2 = xor2 ^ arr[i];
    set_bit_no = xor2 & ~(xor2-1);
    int x=0, y=0;
    for(int i=0; i<size; i++) {
        if(arr[i] & set_bit_no)
            x = x ^ arr[i];
        else
            y = y ^ arr[i]; 
    }
    cout<<"Odd elements are "<<x<<" & "<<y<<endl;
}

int main() {
    int arr[] = {4, 2, 4, 5, 2, 3, 3, 1};
    printTwoOdd(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}
