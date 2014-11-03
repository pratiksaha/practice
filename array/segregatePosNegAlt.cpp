//segregate +ve and -ve alternately
#include<iostream>
#include<algorithm>
using namespace std;

void printArray(int arr[], int size) {
    for (int i=0; i<size; i++)
        cout<<" "<<arr[i];
    cout<<endl;
}

void segregatePosNegAlt(int arr[], int size) {
    int i = -1;
    for (int j=0; j<size; j++) {//Segregate into -ve & +ve nos
        if (arr[j] < 0) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    int neg = 0;
    int pos = i+1;
    while (pos<size && neg<pos && arr[neg]<0) {
        swap(arr[neg], arr[pos]);
        pos++;
        neg += 2;
    }
}

int main() {
    int arr[] =  {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Input Array :\n";
    printArray(arr, n);
    segregatePosNegAlt(arr, n);
    cout<<"Array after segregation :\n";
    printArray(arr, n);
    return 0;
}
