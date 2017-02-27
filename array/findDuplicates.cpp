//find duplicates in an array
#include<iostream>
#include<cstdlib>
using namespace std;
 
void findDuplicates(int arr[], int size) {
    int i;
    
    cout<<"The duplicate elements are:";
    for (i=0; i<size; i++) {
        if (arr[abs(arr[i])] >= 0)
            arr[abs(arr[i])] = -arr[abs(arr[i])];
        else
            cout<<" "<<abs(arr[i]);
    }
    cout<<endl;
    
    for (i=0; i<size; i++) //let us be nice and regenerate the original array
        if (arr[abs(arr[i])] < 0)
            arr[abs(arr[i])] = -arr[abs(arr[i])];
}

void printRepeating( int arr[], int n) {
    cout<<"The repeating elements are:";
    for (int i = 0; i < n; i++) {
        int index = arr[i] % n;
        arr[index] += n;
    }
    for (int i = 0; i < n; i++)
        if ((arr[i]/n) > 1)
            cout<<" "<<i;
    cout<<endl;
}
 
int main() {
    int arr[] = {1, 2, 3, 1, 3, 6, 6};
    findDuplicates(arr, sizeof(arr)/sizeof(arr[0]));
    printRepeating(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}
