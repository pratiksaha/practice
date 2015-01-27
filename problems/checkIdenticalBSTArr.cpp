// A C program to check for Identical BSTs without building the trees
#include<iostream>
#include<climits>
using namespace std;

bool checkIdenticalBSTUtil(int a[], int b[], int n, int i1, int i2, int min, int max) {
    int j;
    for (j=i1; j<n; j++) //search for a value satisfying the constraints of min and max in a[]
        if (a[j]>min && a[j]<max)
            break; //if the parent is a leaf then there must be some element in a[]
    int k;
    for (k=i2; k<n; k++) //search for a value satisfying the constraints of min and max in b[]
        if (b[k]>min && b[k]<max)
            break; //if the parent is a leaf then there must be some element in b[]
    
    if (j==n && k==n) //if the parent is leaf in both arrays
        return true;
    else if (((j==n)^(k==n)) || a[j]!=b[k]) //if the parent is leaf in one but non-leaf in other or the elements satisfying the constraints are not same
        return false;
    else //recur
        return checkIdenticalBSTUtil(a, b, n, j+1, k+1, a[j], max) && checkIdenticalBSTUtil(a, b, n, j+1, k+1, min, a[j]);
}

bool checkIdenticalBST(int a[], int b[], int m, int n) {
    if (m == n)
        return checkIdenticalBSTUtil(a, b, n, 0, 0, INT_MIN, INT_MAX);
    else
        return false;
}

int main() {
    int a[] = {8, 3, 6, 1, 4, 7, 10, 14, 13};
    int b[] = {8, 10, 14, 3, 6, 4, 1, 7, 13};
    cout<<(checkIdenticalBST(a, b, sizeof(a)/sizeof(a[0]), sizeof(b)/sizeof(b[0]))?"BSTs are same":"BSTs not same")<<endl;
    return 0;
}
