//to find a partition point in an array
#include<bits/stdc++.h>
using namespace std;

int findPartition(int A[], int n) {
    int SE[n];
    int GE[n];
    GE[0] = A[0];
    SE[n-1] = A[n-1];
    for (int i=1; i<n ; i++)
        if (GE[i-1] < A[i])
            GE[i] = A[i];
        else
            GE[i] = GE[i-1];
    for (int i = n-2 ; i >= 0 ; i-- )
        if (A[i] < SE[i+1])
            SE[i] = A[i];
        else
            SE[i] = SE[i+1];
    for (int j =0 ; j <n ; j++)
        if ( ( j == 0  && A[j] < SE[j+1] ) || ( j == n-1 && A[j] > GE[j-1] ) || ( A[j] < SE[j+1] && A[j] > GE[j-1] ) )
            return A[j];
    return -1;
}

int main() {
    int A[] = {4, 3, 2, 5 , 8 ,6 , 7 } ;
    int n = sizeof(A)/sizeof(A[0]);
    cout<<findPartition(A, n)<<endl;
    return 0;
}
