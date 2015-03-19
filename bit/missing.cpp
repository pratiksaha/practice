//to find the missing no 
#include<iostream>
using namespace std;

int missing(int a[], int n) {
    int total  = (n+1)*(n+2)/2;
    for (int i=0; i<n; i++)
        total -= a[i];
    return total;
}

int missingBit(int a[], int n) {
    int x1 = a[0]; //xor of all the elemets in arary
    int x2 = 1; //xor of all the elemets from 1 to n+1
    int i;
    for (i=1; i< n; i++)
        x1 = x1^a[i]; 
    for (i=2; i<=n+1; i++)
        x2 = x2^i;
    return (x1^x2);
}

int main() {
    int a[] = {1, 2, 4, 5, 6};
    cout<<"Missing no is "<<missing(a, 5)<<endl;
    cout<<"Missing no is "<<missingBit(a, 5)<<endl;
    return 0;
}
