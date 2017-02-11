//to count nos till n such that n+i = n^i
#include <bits/stdc++.h>
using namespace std;
 
int countValuesEqualSumAndXOR(int n) {
    int unset_bits=0;
    while (n) {
        if ((n & 1) == 0)
            unset_bits++;
        n=n>>1;
    }
    return 1 << unset_bits;
}
 
int main() {
    int n = 12;
    cout<<"No of i's till "<<n<<" for which n+i equals n^i is "<<countValuesEqualSumAndXOR(n)<<endl;
    return 0;
}
