//given arr[], find the max diff between any two elements such that larger element appears after the smaller number in arr[]
#include<iostream>
using namespace std;

int maxDiff(int arr[], int n) {
    int max_diff = arr[1] - arr[0];
    int min_element = arr[0];
    int i;
    for(i=1; i<n; i++) {       
        if(arr[i] - min_element > max_diff)                               
            max_diff = arr[i] - min_element;
        if(arr[i] < min_element)
            min_element = arr[i];                     
    }
    return max_diff;
}    

int main() {
    int arr[] = {1, 2, 6, 80, 100};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Maximum difference is "<<maxDiff(arr, sizeof(arr)/sizeof(arr[0]))<<endl;
    return 0;
}
