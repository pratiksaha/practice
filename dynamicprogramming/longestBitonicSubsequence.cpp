//Longest Bitonic Subsequence
#include<iostream>
#include<cstdlib>
using namespace std;

void lbsDP(int arr[], int n) {//this is a DP based O(n^2) solution
    int i, j;
    
    int *lis = new int[n];
    for ( i = 0; i < n; i++ )
        lis[i] = 1;
        
    int *lds = new int[n];
    for ( i = 0; i < n; i++ )
        lds[i] = 1;
        
    for ( i = 1; i < n; i++ )
        for ( j = 0; j < i; j++ )
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
 
    for ( i = n-2; i >= 0; i-- )
        for ( j = n-1; j > i; j-- )
            if ( arr[i] > arr[j] && lds[i] < lds[j] + 1)
                lds[i] = lds[j] + 1;
 
    int lbs_length = lis[0] + lds[0] - 1;
    for (i = 1; i < n; i++)
        if (lis[i] + lds[i] - 1 > lbs_length)
           lbs_length = lis[i] + lds[i] - 1;
    cout<<"Length of longest bitonic subsequnce = "<<lbs_length<<endl;
    delete[] lis;
    delete[] lds;
}

int main() {
    int a[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    lbsDP(a, sizeof(a)/sizeof(a[0]));
    return 0;
}
