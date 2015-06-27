//to multiply two polynomials : revisit
#include<iostream>
using namespace std;

int *multiply(int A[], int m, int B[], int n) {
    int *prod = new int[m+n-1];
    for (int i=0; i<m+n-1; i++)
        prod[i] = 0;
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            prod[i+j] += A[i]*B[j];
    return prod;
}

void printPolynomial(int poly[], int n) {
    for (int i=0; i<n; i++) {
        cout<<poly[i];
        if (i != 0)
            cout<<"x^"<<i;
        if (i != n-1)
            cout<<" + ";
    }
}

int main() { 
    int A[] = {5, 0, 10, 6};
    int m = sizeof(A)/sizeof(A[0]);
    cout<<"First polynomial is : ", printPolynomial(A, m), cout<<endl;
    int B[] = {1, 2, 4};
    int n = sizeof(B)/sizeof(B[0]);
    cout<<"Second polynomial is : ", printPolynomial(B, n), cout<<endl;
    int *prod = multiply(A, m, B, n);
    cout<<"Product polynomial is : ", printPolynomial(prod, m+n-1), cout<<endl;
    delete[] prod;
    return 0;
}
