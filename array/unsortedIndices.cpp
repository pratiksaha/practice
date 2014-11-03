//find the min length unsorted subarray, sorting which makes the complete array sorted
#include<iostream>
using namespace std;

void unsortedIndices(int arr[], int n) {
    int i, max, min;
    int s = 0;
    int e = n-1; 
 
    for (s=0; s<n-1; s++) //find the first elem which is greater than the next
        if (arr[s] > arr[s+1])
            break;
    
    if (s == n-1) {
        cout<<"The complete array is sorted\n";
        return;
    }
    
    for (e=n-1; e>0; e--) //find the first elem from the end which is smaller than the next
        if(arr[e] < arr[e-1])
            break;
 
    max = arr[s];
    min = arr[s];
    for (i = s + 1; i <= e; i++) {//find the min and max in arr[s..e]
        if(arr[i] > max)
            max = arr[i];
        if(arr[i] < min)
         min = arr[i];
    }
 
    for (i=0; i<s; i++) { //find the first ele (if any) in arr[0..s-1] which is greater than min
        if(arr[i] > min) {  
            s = i;
            break;
        }      
    } 

    for (i=n-1; i>=e+1; i--) { //find the last elem (if any) in arr[e+1..n-1] which is smaller than max
        if(arr[i] < max) {
            e = i;
            break;
        } 
    }  
     
    cout<<"The unsorted subarray which makes the given array sorted lies between indices "<<s<<" & "<<e<<endl;
}
 
int main() {
    int arr[] = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
    unsortedIndices(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}
