//easy array prgs
#include<iostream>
#include<climits>
using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i<size; i++)
        cout<<" "<<arr[i];
    cout<<endl;
}

void print2Smallest(int arr[], int arr_size) {
    int i, first, second;
    if (arr_size < 2) {
        cout<<"Invalid Input\n";
        return;
    }
 
    first = second = INT_MAX;
    for (i = 0; i < arr_size ; i ++) {
        if (arr[i] < first) {
            second = first;
            first = arr[i];
        } else if (arr[i] < second && arr[i] != first) {
            second = arr[i];
        }
    }
    if (second == INT_MAX)
        cout<<"There is no second smallest element\n";
    cout<<"The smallest element is "<<first<<" & second smallest element is "<<second<<endl;
}

void reverseItr(int arr[], int start, int end) {
    int temp;
    while(start < end) {
        temp = arr[start];  
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }  
}

void reverseRec(int arr[], int start, int end) {
    int temp;
    if(start >= end)
        return;
    temp = arr[start];  
    arr[start] = arr[end];
    arr[end] = temp;
    reverseRec(arr, start+1, end-1);  
}

void leftRotatebyOne(int arr[], int n) {
    int i;
    int temp = arr[0];
    for (i = 0; i < n-1; i++)
        arr[i] = arr[i+1];
    arr[i] = temp;
}

void leftRotate(int arr[], int n, int d) {
    for (int i = 0; i < d; i++)
        leftRotatebyOne(arr, n);
}

int gcd(int a, int b) {
    if(b==0)
        return a;
    else
        return gcd(b, a%b);
}

void leftRotateJuggle(int arr[], int n, int d) {
    int i, j, k, temp;
    for (i = 0; i < gcd(d, n); i++) {
        temp = arr[i];
        j = i;
        while(1) {
            k = j + d;
            if (k >= n)
                k = k - n;
            if (k == i)
                break;
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
}

void leftRotateReversal(int arr[], int n, int d) {
    reverseItr(arr, 0, d-1);
    reverseItr(arr, d, n-1);
    reverseItr(arr, 0, n-1);
}

void blockswap(int arr[], int fi, int si, int d) {
    int i, temp;
    for(i = 0; i<d; i++) {
        temp = arr[fi + i];
        arr[fi + i] = arr[si + i];
        arr[si + i] = temp;
    }    
}

void leftRotateBlockSwap(int arr[], int n, int d) { 
    if(d == 0 || d == n)
        return;
     
    if(n-d == d) {
        blockswap(arr, 0, n-d, d);  
        return;
    } else if(d < n-d) { 
        blockswap(arr, 0, n-d, d);
        leftRotateBlockSwap(arr, d, n-d);   
    } else {
        blockswap(arr, 0, d, n-d);
        leftRotateBlockSwap(arr+n-d, 2*d-n, d);
    }
}

int main() {
    int arr[] = {12, 13, 5, 10, 34, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Input array :\n";
    printArray(arr,n);
    
    print2Smallest(arr, n);
    
    reverseRec(arr, 0, n-1);
    cout<<"Reversed array :\n";
    printArray(arr,n);
    
    reverseRec(arr, 0, n-1);
    cout<<"Reversed array :\n";
    printArray(arr,n);
    
    leftRotate(arr, n, 3);
    cout<<"left Rotated by 3 :\n";
    printArray(arr,n);
    
    leftRotateJuggle(arr, n, 2);
    cout<<"left Rotated by 2 :\n";
    printArray(arr,n);
    
    leftRotateReversal(arr, n, 4);
    cout<<"left Rotated by 4 :\n";
    printArray(arr,n);
    
    leftRotateBlockSwap(arr, n, 3);
    cout<<"left Rotated by 3 :\n";
    printArray(arr,n);
    
    return 0;
}
