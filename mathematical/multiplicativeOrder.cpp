//to implement multiplicative order
#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0 )
        return a;
    return gcd( b , a%b ) ;
}
 
int multiplicativeOrder(int A, int  N) {
    if (gcd(A, N ) != 1)
        return -1;
    unsigned int result = 1;
    int K = 1 ;
    while (K < N) {
        result = (result * A) % N ;
        if (result  == 1)
            return K;
        K++;
    }
    return -1 ;
}
 
int main() {
    int A = 4, N = 7;
    cout<<"Multiplicative Order for A = "<<A<<" and N = "<<N<<" is "<<multiplicativeOrder(A, N)<<endl;
    return 0;
}
