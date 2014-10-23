#include<iostream>
using namespace std;

int maxSumISDP( int arr[], int n ) {//this is a DP based O(n^2) solution
    int *msis = new int[n];
    int i, j;
    for (i=0; i<n; i++ )
        msis[i] = arr[i];

    for ( i=1; i<n; i++ )
        for ( j=0; j<i; j++ )
            if ( arr[i]>arr[j] && msis[i]<msis[j] + arr[i])
                msis[i] = msis[j] + arr[i];
 
    int max_sum = msis[0];
    for ( i=1; i<n; i++ )
        if ( max_sum < msis[i] )
            max_sum = msis[i];
 
    cout<<"Max Sum = "<<max_sum<<endl;
    delete[] msis;
}

int main() {
    int a[] = {1, 101, 2, 3, 100, 4, 5};
    maxSumISDP( a, sizeof(a)/sizeof(a[0]) );
    return 0;
}
