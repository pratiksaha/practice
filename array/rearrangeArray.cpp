//rearrange arr[0..n-1] so that arr[j] becomes i if arr[i] is j
#include<iostream>
using namespace std;

void rearrangeUtil(int arr[], int n, int i) {
    int val = -(i+1);  //next value is determined using curr index
    i = arr[i] - 1;  //next index is determined using current value 
    while (arr[i] > 0) { //while all elements in cycle are not processed
        int new_i = arr[i] - 1; //store value at index as it is going to be used as next index
        arr[i] = val;
        val = -(i + 1); //update val for next iteration
        i = new_i; //update index for next iteration
    }
}
 
void rearrangeOpt(int arr[], int n) { // Time: O(n) Space: O(1)   
    int i;
    for (i=0; i<n; i++)
        arr[i]++; //increment all values by 1 so that all elements can be made negative to mark them as visited
    for (i=0; i<n; i++) { //process all cycles
       if (arr[i] > 0) //process cycle starting at arr[i] if this cycle is not already processed
          rearrangeUtil(arr, n, i);
    }
    for (i=0; i<n; i++) //change sign and values of arr[] to get the original values back
          arr[i] = (-arr[i])-1;
}

void rearrange(int arr[], int n) { // Time: O(n) Space: O(n)
    int temp[n], i;
    for (i=0; i<n; i++)
        temp[arr[i]] = i;
    for (i=0; i<n; i++)
        arr[i] = temp[i];
}

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++)
        cout<<" "<<arr[i];
    cout<<endl;
}

int main() {
    int a[] =  {2, 0, 1, 4, 5, 3};
    int b[] =  {2, 0, 1, 4, 5, 3};
    int n = sizeof(a)/sizeof(a[0]);   
    cout<<"Given array is ", printArray(a, n);
    rearrange(a, n);
    cout<<"Modified array is ", printArray(a, n);
    cout<<"Given array is ", printArray(b, n);
    rearrangeOpt(b, n);
    cout<<"Modified array is ", printArray(b, n);
    return 0;
}
