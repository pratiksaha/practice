//Largest subarray with equal number of 0s and 1s
#include<iostream>
using namespace std;

int largestSubarray01(int arr[], int n) {
    int maxsize = -1, startindex;
  
    int sumleft[n]; //sumleft[i] = sum of array elements from arr[0] to arr[i]
    int min, max; //min and max values in sumleft[]
    int i;
  
    sumleft[0] = ((arr[0]==0)?-1:1); //considering all 0 values as -1, problem reduces to finding out the max length subarray with sum = 0
    min = arr[0];
    max = arr[0];
    for (i=1; i<n; i++) {     
        sumleft[i] = sumleft[i-1] + ((arr[i] == 0)? -1: 1);
        if (sumleft[i] < min)
            min = sumleft[i];
        if (sumleft[i] > max)
            max = sumleft[i];
    }
    
    int hash[max-min+1];
    for (i=0; i<max-min+1; i++)
        hash[i] = -1;
  
    for (i=0; i<n; i++) {
        if (sumleft[i] == 0) {
            maxsize = i+1;
            startindex = 0;
        }
        if (hash[sumleft[i]-min] == -1) {
            hash[sumleft[i]-min] = i;
        } else {
            if ( (i - hash[sumleft[i]-min]) > maxsize ) {
                maxsize = i - hash[sumleft[i]-min];
                startindex = hash[sumleft[i]-min] + 1;
            }
        }
    }
    if ( maxsize == -1 )
        cout<<"No such subarray\n";
    else
        cout<<startindex<<" to "<<startindex+maxsize-1<<endl;
}

int main() {
    int arr[] =  {1, 0, 0, 1, 0, 1, 1};
    largestSubarray01(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}
