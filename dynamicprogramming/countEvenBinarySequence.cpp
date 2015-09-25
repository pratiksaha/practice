//to count even length binary sequences such that the sum of first and second half bits is same
#include<iostream>
using namespace std;

int countEvenBinarySequence(int n) {
    int nCr=1, res = 1;
    for (int r = 1; r<=n ; r++) {
        nCr = (nCr * (n+1-r))/r;
        res += nCr*nCr;
    }
 
    return res;
}

int main() {
    int n = 4;
    cout<<"Count of even length binary sequences such that the sum of first and second half bits is same is "<<countEvenBinarySequence(n)<<endl;
    return 0;
}
