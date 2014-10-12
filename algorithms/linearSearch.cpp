#include<iostream>
using namespace std;

//Returns a 0 indexed position if key is found, -1 otherwise
int linearSearch(int arr[], int n, int key) {
    for(int i=0; i<n; i++)
        if(arr[i] == key)
            return i;
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int key, pos;
    key = 4;
    pos = linearSearch(arr, sizeof(arr)/sizeof(arr[0]), key);
    (pos == -1)?(cout<<"Element is not present in array"<<endl):(cout<<"Element is present at index "<<pos<<endl);
    key = 8;
    pos = linearSearch(arr, sizeof(arr)/sizeof(arr[0]), key);
    (pos == -1)?(cout<<"Element is not present in array"<<endl):(cout<<"Element is present at index "<<pos<<endl);
    return 0;
}
