//to find 3 elements such that max(abs(A[i]-B[j]), abs(B[j]-C[k]), abs(C[k]-A[i])) is minimized
#include<iostream>
#include<climits>
using namespace std;
 
void findClosestSorted(int A[], int B[], int C[], int p, int q, int r) {
    int diff = INT_MAX;
    int res_i =0, res_j = 0, res_k = 0;
    int i=0,j=0,k=0;
    while (i<p && j<q && k<r) {
        int minimum = min(A[i], min(B[j], C[k]));
        int maximum = max(A[i], max(B[j], C[k]));
        if (maximum-minimum < diff) {
             res_i = i, res_j = j, res_k = k;
             diff = maximum - minimum;
        }
        if (diff == 0)
            break;
        if (A[i] == minimum)
            i++;
        else if (B[j] == minimum)
            j++;
        else
            k++;
    }
    cout<<A[res_i]<<" "<<B[res_j]<<" "<<C[res_k]<<endl;
}
 
// Driver program
int main() {
    int A[] = {1, 4, 10};
    int B[] = {2, 15, 20};
    int C[] = {10, 12};
    findClosestSorted(A, B, C, sizeof(A)/sizeof(A[0]), sizeof(B)/sizeof(B[0]), sizeof(C)/sizeof(C[0]));
    return 0;
}
