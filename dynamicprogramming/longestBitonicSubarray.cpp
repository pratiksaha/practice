//Longest Bitonic Subarray
#include<iostream>
#include<cstdlib>
using namespace std;
 
void longestBitonicSubarray(int arr[], int n) {
    int i;
    
    int *inc = new int[n];
    inc[0] = 1;
    for(i=1; i<n; i++) {
        if (arr[i] > arr[i-1])
            inc[i] = inc[i-1]+1;
        else
            inc[i] = 1;
    }

    int *dec = new int[n];
    dec[n-1] = 1;
    for (i=n-2; i>=0; i--) {
        if (arr[i] > arr[i+1])
            dec[i] = dec[i+1] + 1;
        else
            dec[i] = 1;
    }
 
    int max = inc[0] + dec[0] - 1;
    for (i=1; i<n; i++) {
        if (inc[i]+dec[i]-1 > max)
            max = inc[i]+dec[i]-1;
    }

    delete [] inc;
    delete [] dec;
    cout<<"Length of max length Bitonic Subarray is "<<max<<endl;
}

int main() {
    int arr[] = {12, 4, 78, 90, 45, 23};
    longestBitonicSubarray(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}
