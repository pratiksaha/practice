#include<iostream>
#include<algorithm>
using namespace std;

//Returns median of two integers
float median2( int a, int b ) {
    return (a+b)/2.0; 
}
 
//Returns median of three integers
float median3( int a, int b, int c ) {
    return a+b+c-max(a,max(b,c))-min(a,min(b,c));
}
 
//Returns median of four integers
float median4( int a, int b, int c, int d ) {
    return (a+b+c+d-max(a,max(b,max(c,d)))-min(a,min(b,min(c,d))))/2.0;
}

//Returns median of a sorted array arr of length size
float median(int arr[], int size) {
    if (size%2 == 0)
        return (arr[size/2] + arr[size/2 - 1])/2;
    else
        return arr[size/2];
}

//Returns medians of 2 sorted arrays A & B of equal length N
float getMedianEqual(int A[], int B[], int N) {
    int m1, m2;
    
    //Invalid input
    if (N <= 0)
        return -1;
    //Base Cases
    if (N == 1)
        return (A[0] + B[0])/2;
    if (N == 2)
        return (max(A[0], B[0]) + min(A[1], B[1])) / 2;
 
    m1 = median(A, N);
    m2 = median(B, N);
    
    if (m1 == m2) {//if medians are equal then return
        return m1;
    } else if (m1 < m2) {// if m1 < m2 then median must exist in ar1[m1....] and ar2[....m2]
        if (N % 2 == 0)
            return getMedianEqual(A + N/2 - 1, B, N- N/2 + 1);
        else
            return getMedianEqual(A + N/2, B, N - N/2);
    } else {//if m1 > m2 then median must exist in ar1[....m1] and ar2[m2...]
        if (N % 2 == 0)
            return getMedianEqual(B + N/2 - 1, A, N - N/2 + 1);
        else
            return getMedianEqual(B + N/2, A, N - N/2);
    }
}

//Function that returns the median of 2 unequal sorted arrays A of size N and B ofsize M
//Ensure that size of A is less than that of B before calling
float getMedianUnEqual(int A[], int N, int B[], int M ) {
    //Invalid Input
    if(N<=0 || M<=0)
        return -1;
    //Base Cases
    if( N == 1 ) {//If the smaller array has only one element
        if( M == 1 )//If the larger array also has one element
            return median2( A[0], B[0] );
        if( M & 1 )//If the larger array has odd number of elements
            return median2( B[M/2], median3(A[0], B[M/2 - 1], B[M/2 + 1]) );
        else//If the larger array has even number of element
            return median3( B[M/2], B[M/2 - 1], A[0] );
    } else if( N == 2 ) {// If the smaller array has two elements
        if( M == 2 )//If the larger array also has two elements
            return median4( A[0], A[1], B[0], B[1] );
        if( M & 1 )//If the larger array has odd number of elements
            return median3( B[M/2], max( A[0], B[M/2 - 1] ), min( A[1], B[M/2 + 1] ));
        else//If the larger array has even number of elements
            return median4( B[M/2], B[M/2 - 1], max( A[0], B[M/2 - 2] ), min( A[1], B[M/2 + 1] ) );
    }
 
    //General cases
    int iA = (N-1)/2; //mid of A[]
    int iB = (M-1)/2; //mid of B[]    
    if ( A[iA] <= B[iB] )//If A[iA] <= B[iB], then median must exist in A[iA....] and B[....iB]
        return getMedianUnEqual( A+iA, N/2 + 1, B, M-iA );
    else//If A[iA] > B[idxB], then median must exist in A[...iA] and B[iB....]
        return getMedianUnEqual( A, N/2 + 1, B+iA, M-iA );
}

//Master function that call other functions appropriately
float getMedian(int A[], int N, int B[], int M) {
    if(N == M)
        return getMedianEqual(A, B, N);
    else if (N > M)
        return getMedianUnEqual(B, M, A, N);
    else
        return getMedianUnEqual(A, N, B, M);
}

int main() {
    int a1[] = {1, 2, 3, 6};
    int a2[] = {4, 6, 8, 10};
    int a3[] = {900};
    int a4[] = {5, 8, 10, 20};
    cout<<"Median is "<<getMedian(a1, sizeof(a1)/sizeof(a1[0]), a2, sizeof(a2)/sizeof(a2[0]))<<endl;
    cout<<"Median is "<<getMedian(a3, sizeof(a3)/sizeof(a3[0]), a4, sizeof(a4)/sizeof(a4[0]))<<endl;
    return 0;
}
