//to find number of consecutive 0s in a sequence
#include<bits/stdc++.h>
using namespace std;
 
int countConsecutiveZeroPairs(int n) {
    if (n==1)
        return 0;
    if (n==2 || n==3)
        return 1;
    int q = (pow(2,n) / 12);
    return 2*q + 1;
}

int main() {
    int n = 5;
    cout<<countConsecutiveZeroPairs(n)<<endl;
    return 0;
}
