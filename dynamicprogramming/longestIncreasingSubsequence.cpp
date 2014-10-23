//Longest Increasing subsequence
#include<iostream>
#include<cstdlib>
using namespace std;

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++)
        cout<<" "<<arr[i];
}

void lisDP(int arr[], int n) {//this is a DP based O(n^2) solution
    int *lis;
    lis = (int*)malloc(sizeof(int)*n);

    int i, j;
    for (i=0; i<n; i++)
        lis[i] = 1;

    for (i=1; i<n; i++)
        for (j=0; j<i; j++)
            if ( arr[i]>arr[j] && lis[i]<lis[j]+1)
                lis[i] = lis[j]+1;

    int max = lis[0];
    for (i=1; i<n; i++)
        if (max<lis[i])
            max = lis[i];

    cout<<"Length of LIS is "<<max<<endl;
    free(lis);//let us be nice and free the memory
}


void lis(int X[], int n) {//this is a O(nlogn) solution
 
    int *M = new int[n+1];//M[j] stores the index k of the smallest value X[k] such that there is an increasing subsequence of length j ending at X[k] on the range k ≤ i
    
    int *P = new int[n];//P[k] stores the index of the predecessor of X[k] in the longest increasing subsequence ending at arr[k]
    
    int i;
    int max_len = 0;
    for(i=0; i<n; i++ ) {
        int low = 1;
        int high = max_len;
        while(low<=high){//binary search for the largest positive j ≤ max_len such that X[M[j]] < arr[i]
            int mid = (low+high)/2;
            if( X[M[mid]] < X[i] )
                low = mid+1;
            else
                high = mid-1;
        }
        int len = low;
        P[i] = M[len-1];//predecessor of X[i] is the last index of the subsequence of length len-1
        M[len] = i;
        if (len>max_len)
            max_len = len;   
    }

    int *S = new int[max_len];//stores the elements in lis
    int k = M[max_len];
    for(i=max_len-1; i>=0; i--) {
        S[i] = X[k];
        k = P[k];
    }
    
    cout<<"For input array:";
    printArray(X, n);
    cout<<", the "<<max_len<<" elements in LIS are:";
    printArray(S, max_len);
    cout<<endl;
    
    delete[] M;
    delete[] P;
    delete[] S;
}

int main() {
    int a[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int b[] = { 2, 5, 3, 7, 11, 8, 10, 13, 6 };
    int c[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    lisDP(a, sizeof(a)/sizeof(a[0]));
    lis(a, sizeof(a)/sizeof(a[0]));
    lis(b, sizeof(b)/sizeof(b[0]));
    lis(c, sizeof(c)/sizeof(c[0]));
    return 0;
}
